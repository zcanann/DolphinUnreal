#include "DolphinIpcHandlerBase.h"

#include "cereal/cereal.hpp"
#include "cereal/access.hpp"
#include "cereal/types/common.hpp"
#include "cereal/types/string.hpp"
#include "cereal/types/map.hpp"
#include "cereal/types/vector.hpp"
#include "cereal/types/memory.hpp"
#include "cereal/archives/binary.hpp"

struct MemoryStream : std::streambuf
{
    MemoryStream(char* buffer, size_t size)
    {
        setp(buffer, buffer + size);
    }
    size_t written() { return pptr() - pbase(); }
};

const std::string DolphinIpcHandlerBase::ChannelNameInstanceBase = "dol-c2s-";
const std::string DolphinIpcHandlerBase::ChannelNameServerBase = "dol-s2c-";

DolphinIpcHandlerBase::DolphinIpcHandlerBase()
{
}

DolphinIpcHandlerBase::~DolphinIpcHandlerBase()
{
    delete(_instanceToServer);
    delete(_serverToInstance);
    _instanceToServer = nullptr;
    _serverToInstance = nullptr;
}

void DolphinIpcHandlerBase::initializeChannels(const std::string& uniqueChannelId)
{
    std::string uniqueInstanceChannel = ChannelNameInstanceBase + uniqueChannelId;
    std::string uniqueServerChannel = ChannelNameServerBase + uniqueChannelId;

    std::cout << __func__ << ": instance channel: " << uniqueInstanceChannel << std::endl;
    std::cout << __func__ << ": server channel: " << uniqueServerChannel << std::endl;

    _instanceToServer = new IpcChannel(uniqueInstanceChannel.c_str());
    _serverToInstance = new IpcChannel(uniqueServerChannel.c_str());

    ipcListen();
}

void DolphinIpcHandlerBase::ipcSendToInstance(DolphinIpcInstanceData params)
{
    ipcSendData(_serverToInstance, params);
}

void DolphinIpcHandlerBase::ipcSendToServer(DolphinIpcServerData params)
{
    ipcSendData(_instanceToServer, params);
}

template<class T>
void DolphinIpcHandlerBase::ipcSendData(IpcChannel* channel, T params)
{
    if (channel != nullptr || channel->reconnect(ipc::sender))
    {
        MemoryStream memoryStream = MemoryStream((char*)&_sharedBuffer, sizeof(_sharedBuffer));
        std::ostream out(&memoryStream);
        cereal::BinaryOutputArchive archive(out);

        archive(params);

        if (!_exitRequested.load(std::memory_order_acquire))
        {
            if (!channel->send(ipc::buff_t(_sharedBuffer, memoryStream.written())))
            {
                std::cerr << __func__ << ": send failed." << std::endl;
                std::cout << __func__ << ": waiting for receiver..." << std::endl;
                if (!channel->wait_for_recv(1))
                {
                    std::cerr << __func__ << ": wait receiver failed." << std::endl;
                    _exitRequested.store(true, std::memory_order_release);
                    // break;
                }
            }
            // std::this_thread::yield();
        }
    }
    else
    {
        std::cerr << __func__ << ": connect failed.\n";
    }
}

void DolphinIpcHandlerBase::ipcListen()
{
    _instanceListener = std::thread
    {
        [=]
        {
            std::cout << __func__ << ": Listening for client to server events" << std::endl;
            if (_instanceToServer != nullptr && _instanceToServer->reconnect(ipc::receiver))
            {
                while (!_exitRequested.load(std::memory_order_acquire))
                {
                    ipc::buff_t rawData = _instanceToServer->recv();

                    if (rawData.empty())
                    {
                        break;
                    }

                    MemoryStream memoryStream = MemoryStream((char*)&rawData, rawData.size());
                    std::istream in(&memoryStream);
                    cereal::BinaryInputArchive archive(in);
                    DolphinIpcInstanceData data;

                    archive(data);

                    onServerToInstanceDataReceived(data);
                }
            }
            else
            {
                std::cerr << __func__ << ": client to server connect failed." << std::endl;
            }
            std::cout << __func__ << ": client to server quit..." << std::endl;
        }
    };
    _serverListener = std::thread
    {
        [=]
        {
            std::cout << __func__ << ": Listening for server to client events" << std::endl;
            if (_serverToInstance != nullptr && _serverToInstance->reconnect(ipc::receiver))
            {
                while (!_exitRequested.load(std::memory_order_acquire))
                {
                    ipc::buff_t rawData = _instanceToServer->recv();

                    if (rawData.empty())
                    {
                        break;
                    }

                    MemoryStream memoryStream = MemoryStream((char*)&rawData, rawData.size());
                    std::istream in(&memoryStream);
                    cereal::BinaryInputArchive archive(in);
                    DolphinIpcServerData data;

                    archive(data);

                    onInstanceToServerDataReceived(data);
                }
            }
            else
            {
                std::cerr << __func__ << ": server to client connect failed.\n";
            }
            std::cout << __func__ << ": server to client quit...\n";
        }
    };
}

void DolphinIpcHandlerBase::onInstanceToServerDataReceived(const DolphinIpcServerData& data)
{
    switch (data._call)
    {
        case DolphinServerIpcCall::DolphinServer_OnInstanceConnected: DolphinServer_OnInstanceConnected(*data._params._onInstanceConnectedParams); break;
        case DolphinServerIpcCall::DolphinServer_OnInstanceTerminated: DolphinServer_OnInstanceTerminated(*data._params._onInstanceTerminatedParams); break;
        case DolphinServerIpcCall::Null: default: break;
    }
}

void DolphinIpcHandlerBase::onServerToInstanceDataReceived(const DolphinIpcInstanceData& data)
{
    switch (data._call)
    {
    case DolphinInstanceIpcCall::DolphinInstance_Connect: DolphinInstance_Connect(*data._params._connectParams); break;
    case DolphinInstanceIpcCall::DolphinInstance_LoadGame: DolphinInstance_LoadGame(*data._params._loadGameParams); break;
    case DolphinInstanceIpcCall::Null: default: break;
    }
}
