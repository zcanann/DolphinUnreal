#include "DolphinIpcHandlerBase.h"

#include "cereal/cereal.hpp"
#include "cereal/access.hpp"
#include "cereal/types/common.hpp"
#include "cereal/types/string.hpp"
#include "cereal/types/map.hpp"
#include "cereal/types/vector.hpp"
#include "cereal/types/memory.hpp"
#include "cereal/archives/binary.hpp"

const std::string DolphinIpcHandlerBase::ChannelNameInstanceBase = "dol-i2s-";
const std::string DolphinIpcHandlerBase::ChannelNameServerBase = "dol-s2i-";

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

void DolphinIpcHandlerBase::initializeChannels(const std::string& uniqueChannelId, bool isInstance)
{
    std::string uniqueInstanceChannel = ChannelNameInstanceBase + uniqueChannelId;
    std::string uniqueServerChannel = ChannelNameServerBase + uniqueChannelId;
    _isInstance = isInstance;

    std::cout << __func__ << ": instance channel: " << uniqueInstanceChannel << std::endl;
    std::cout << __func__ << ": server channel: " << uniqueServerChannel << std::endl;

    _instanceToServer = new ipc::channel(uniqueInstanceChannel.c_str(), ipc::sender | ipc::receiver); // isInstance ? ipc::sender : ipc::receiver);
    _serverToInstance = new ipc::channel(uniqueInstanceChannel.c_str(), ipc::sender | ipc::receiver); // isInstance ? ipc::receiver : ipc::sender);
}

void DolphinIpcHandlerBase::ipcSendToInstance(DolphinIpcInstanceData data)
{
    ipcSendData(_serverToInstance, data);
}

void DolphinIpcHandlerBase::ipcSendToServer(DolphinIpcServerData data)
{
    ipcSendData(_instanceToServer, data);
}

template<class T>
void DolphinIpcHandlerBase::ipcSendData(ipc::channel* channel, T data)
{
    if (channel != nullptr)
    {
        std::stringstream memoryStream(std::ios::binary | std::ios::out | std::ios::in);
        cereal::BinaryOutputArchive serializer = { memoryStream };
        serializer(data);
        std::vector<uint8_t> buffer = std::vector<uint8_t>(std::istream_iterator<uint8_t>(memoryStream), std::istream_iterator<uint8_t>());

        std::cout << __func__ << ": try send..." << std::endl;
        if (channel->try_send(ipc::buff_t(buffer.data(), buffer.size())))
        {
            std::cout << __func__ << ": sent " << buffer.size() << " bytes" << std::endl;
        }
    }
    else
    {
        std::cerr << __func__ << ": connect failed.\n";
    }
}

void DolphinIpcHandlerBase::updateIpcListen()
{
    // if (_isInstance)
    {
        if (_serverToInstance)
        {
            ipc::buff_t rawData = _serverToInstance->try_recv();

            if (!rawData.empty())
            {
                std::cout << __func__ << ": recv " << rawData.size() << " bytes" << std::endl;

                DolphinIpcServerData data;
                std::stringstream memoryStream(std::ios::binary | std::ios::out | std::ios::in);
                cereal::BinaryOutputArchive bufferToMemoryStream = { memoryStream };
                bufferToMemoryStream(cereal::binary_data(rawData.data(), rawData.size()));
                cereal::BinaryInputArchive deserializer(memoryStream);
                deserializer(data);

                onInstanceToServerDataReceived(data);

            }
        }
    }
    // else
    {
        if (_instanceToServer)
        {
            ipc::buff_t rawData = _instanceToServer->try_recv();

            if (!rawData.empty())
            {
                std::cout << __func__ << ": recv " << rawData.size() << " bytes" << std::endl;

                /*
                MemoryStream memoryStream = MemoryStream((char*)&rawData, rawData.size());
                std::istream in(&memoryStream);
                cereal::BinaryInputArchive iarchive(in);
                DolphinIpcInstanceData data;

                iarchive(data);

                onServerToInstanceDataReceived(data);*/
            }
        }
    }
}

void DolphinIpcHandlerBase::onInstanceToServerDataReceived(const DolphinIpcServerData& data)
{
    switch (data._call)
    {
        case DolphinServerIpcCall::DolphinServer_OnInstanceConnected: DolphinServer_OnInstanceConnected(*data._params._onInstanceConnectedParams); break;
        case DolphinServerIpcCall::DolphinServer_OnInstanceTerminated: DolphinServer_OnInstanceTerminated(*data._params._onInstanceTerminatedParams); break;
        case DolphinServerIpcCall::Null: default: std::cout << "NULL instance => server call!" << std::endl; break;
    }
}

void DolphinIpcHandlerBase::onServerToInstanceDataReceived(const DolphinIpcInstanceData& data)
{
    switch (data._call)
    {
        case DolphinInstanceIpcCall::DolphinInstance_Connect: DolphinInstance_Connect(*data._params._connectParams); break;
        case DolphinInstanceIpcCall::DolphinInstance_LoadGame: DolphinInstance_LoadGame(*data._params._loadGameParams); break;
        case DolphinInstanceIpcCall::Null: default: std::cout << "NULL server => instance call!" << std::endl; break;
    }
}
