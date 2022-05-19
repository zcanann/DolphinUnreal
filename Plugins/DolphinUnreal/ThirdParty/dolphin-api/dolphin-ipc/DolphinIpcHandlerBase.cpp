#include "DolphinIpcHandlerBase.h"

#include "cereal/cereal.hpp"
#include "cereal/access.hpp"
#include "cereal/types/common.hpp"
#include "cereal/types/string.hpp"
#include "cereal/types/map.hpp"
#include "cereal/types/vector.hpp"
#include "cereal/types/memory.hpp"
#include "cereal/archives/binary.hpp"

const std::string DolphinIpcHandlerBase::ChannelNameClientBase = "dol-c2s-";
const std::string DolphinIpcHandlerBase::ChannelNameServerBase = "dol-s2c-";

DolphinIpcHandlerBase::DolphinIpcHandlerBase(const std::string& uniqueChannelId)
{
    std::string uniqueClientChannel = ChannelNameClientBase + uniqueChannelId;
    std::string uniqueServerChannel = ChannelNameServerBase + uniqueChannelId;

    _clientToServer = new IpcChannel(uniqueClientChannel.c_str());
    _serverToClient = new IpcChannel(uniqueServerChannel.c_str());

    ipcListen();
}

DolphinIpcHandlerBase::~DolphinIpcHandlerBase()
{
    delete(_clientToServer);
    delete(_serverToClient);
    _clientToServer = nullptr;
    _serverToClient = nullptr;
}

struct MemoryStream : std::streambuf
{
    MemoryStream(char* buffer, size_t size)
    {
        setp(buffer, buffer + size);
    }
    size_t written() { return pptr() - pbase(); }
};

void DolphinIpcHandlerBase::ipcSendToInstance(DolphinIpcInstanceData params)
{
    ipcSendData(_serverToClient, params);
}

void DolphinIpcHandlerBase::ipcSendToServer(DolphinIpcServerData params)
{
    ipcSendData(_clientToServer, params);
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
                std::cerr << __func__ << ": send failed.\n";
                std::cout << __func__ << ": waiting for receiver...\n";
                if (!channel->wait_for_recv(1))
                {
                    std::cerr << __func__ << ": wait receiver failed.\n";
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
    _clientListener = std::thread
    {
        [=]
        {
            std::cout << __func__ << ": Listening for client to server events\n";
            if (_clientToServer != nullptr && _clientToServer->reconnect(ipc::receiver))
            {
                while (!_exitRequested.load(std::memory_order_acquire))
                {
                    ipc::buff_t rawData = _clientToServer->recv();

                    if (rawData.empty())
                    {
                        break;
                    }

                    MemoryStream memoryStream = MemoryStream((char*)&rawData, rawData.size());
                    std::istream in(&memoryStream);
                    cereal::BinaryInputArchive archive(in);
                    DolphinIpcInstanceData data;

                    archive(data);

                    onServerToClientDataReceived(data);
                }
            }
            else
            {
                std::cerr << __func__ << ": client to server connect failed.\n";
            }
            std::cout << __func__ << ": client to server quit...\n";
        }
    };
    _serverListener = std::thread
    {
        [=]
        {
            std::cout << __func__ << ": Listening for server to client events\n";
            if (_serverToClient != nullptr && _serverToClient->reconnect(ipc::receiver))
            {
                while (!_exitRequested.load(std::memory_order_acquire))
                {
                    ipc::buff_t rawData = _clientToServer->recv();

                    if (rawData.empty())
                    {
                        break;
                    }

                    MemoryStream memoryStream = MemoryStream((char*)&rawData, rawData.size());
                    std::istream in(&memoryStream);
                    cereal::BinaryInputArchive archive(in);
                    DolphinIpcServerData data;

                    archive(data);

                    onClientToServerDataReceived(data);
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

void DolphinIpcHandlerBase::onClientToServerDataReceived(const DolphinIpcServerData& data)
{
    switch (data._call)
    {
        case DolphinServerIpcCall::DolphinServer_OnInstanceConnected: DolphinServer_OnInstanceConnected(*data._params._onInstanceConnectedParams); break;
        case DolphinServerIpcCall::DolphinServer_OnInstanceTerminated: DolphinServer_OnInstanceTerminated(*data._params._onInstanceTerminatedParams); break;
        case DolphinServerIpcCall::Null: default: break;
    }
}

void DolphinIpcHandlerBase::onServerToClientDataReceived(const DolphinIpcInstanceData& data)
{
    switch (data._call)
    {
    case DolphinInstanceIpcCall::DolphinInstance_Connect: DolphinInstance_Connect(*data._params._connectParams); break;
    case DolphinInstanceIpcCall::DolphinInstance_LoadGame: DolphinInstance_LoadGame(*data._params._loadGameParams); break;
    case DolphinInstanceIpcCall::Null: default: break;
    }
}
