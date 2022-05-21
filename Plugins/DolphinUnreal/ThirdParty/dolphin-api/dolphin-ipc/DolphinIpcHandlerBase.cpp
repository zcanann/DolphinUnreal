#include "DolphinIpcHandlerBase.h"

// Prevent errors in cereal that propagate to Unreal where __GNUC__ is not defined
#define __GNUC__ (false)

#include "cereal/cereal.hpp"
#include "cereal/access.hpp"
#include "cereal/types/common.hpp"
#include "cereal/types/string.hpp"
#include "cereal/types/map.hpp"
#include "cereal/types/vector.hpp"
#include "cereal/types/memory.hpp"
#include "cereal/archives/binary.hpp"

#undef __GNUC__

const std::string DolphinIpcHandlerBase::ChannelNameInstanceToServerBase = "dol-i2s-";
const std::string DolphinIpcHandlerBase::ChannelNameServerToInstanceBase = "dol-s2i-";

DolphinIpcHandlerBase::DolphinIpcHandlerBase()
{
}

DolphinIpcHandlerBase::~DolphinIpcHandlerBase()
{
    if (_instanceToServer)
    {
        delete(_instanceToServer);
        _instanceToServer = nullptr;
    }

    if (_serverToInstance)
    {
        delete(_serverToInstance);
        _serverToInstance = nullptr;
    }
}

void DolphinIpcHandlerBase::initializeChannels(const std::string& uniqueChannelId, bool isInstance)
{
    std::string uniqueInstanceToServerChannel = ChannelNameInstanceToServerBase + uniqueChannelId;
    std::string uniqueServerToInstanceChannel = ChannelNameServerToInstanceBase + uniqueChannelId;
    _isInstance = isInstance;

    std::cout << __func__ << ": instance channel: " << uniqueInstanceToServerChannel << std::endl;
    std::cout << __func__ << ": server channel: " << uniqueServerToInstanceChannel << std::endl;

    if (isInstance)
    {
        _instanceToServer = new ipc::channel(uniqueInstanceToServerChannel.c_str(), ipc::sender);
        _serverToInstance = new ipc::channel(uniqueServerToInstanceChannel.c_str(), ipc::receiver);
    }
    else
    {
        _instanceToServer = new ipc::channel(uniqueInstanceToServerChannel.c_str(), ipc::receiver);
        _serverToInstance = new ipc::channel(uniqueServerToInstanceChannel.c_str(), ipc::sender);
    }
}

void DolphinIpcHandlerBase::ipcSendToInstance(const DolphinIpcToInstanceData& data)
{
    ipcSendData(_serverToInstance, data);
}

void DolphinIpcHandlerBase::ipcSendToServer(const DolphinIpcToServerData& data)
{
    ipcSendData(_instanceToServer, data);
}

template<class T>
void DolphinIpcHandlerBase::ipcSendData(ipc::channel* channel, const T& data)
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

template<class T>
void DolphinIpcHandlerBase::ipcReadData(ipc::channel* channel, std::function<void(const T&)> onDeserialize)
{
    if (channel == nullptr)
    {
        return;
    }

    ipc::buff_t rawData = channel->try_recv();

    while (!rawData.empty())
    {
        std::cout << __func__ << ": recv " << rawData.size() << " bytes" << std::endl;

        T data;
        std::stringstream memoryStream(std::ios::binary | std::ios::out | std::ios::in);
        cereal::BinaryOutputArchive bufferToMemoryStream = { memoryStream };
        bufferToMemoryStream(cereal::binary_data(rawData.data(), rawData.size()));
        cereal::BinaryInputArchive deserializer(memoryStream);
        deserializer(data);
        onDeserialize(data);

        rawData = channel->try_recv();
    }
}

void DolphinIpcHandlerBase::updateIpcListen()
{
    if (_isInstance)
    {
        ipcReadData<DolphinIpcToInstanceData>(_serverToInstance, [=](const DolphinIpcToInstanceData& data) { onServerToInstanceDataReceived(data); });
    }
    else
    {
        ipcReadData<DolphinIpcToServerData>(_instanceToServer, [=](const DolphinIpcToServerData& data) { onInstanceToServerDataReceived(data); });
    }
}

void DolphinIpcHandlerBase::onInstanceToServerDataReceived(const DolphinIpcToServerData& data)
{
    switch (data._call)
    {
        case DolphinServerIpcCall::DolphinServer_OnInstanceConnected: DolphinServer_OnInstanceConnected(*data._params._onInstanceConnectedParams); break;
        case DolphinServerIpcCall::DolphinServer_OnInstanceTerminated: DolphinServer_OnInstanceTerminated(*data._params._onInstanceTerminatedParams); break;
        case DolphinServerIpcCall::Null: default: std::cout << "NULL instance => server call!" << std::endl; break;
    }
}

void DolphinIpcHandlerBase::onServerToInstanceDataReceived(const DolphinIpcToInstanceData& data)
{
    switch (data._call)
    {
        case DolphinInstanceIpcCall::DolphinInstance_Connect: DolphinInstance_Connect(*data._params._connectParams); break;
        case DolphinInstanceIpcCall::DolphinInstance_LoadGame: DolphinInstance_LoadGame(*data._params._loadGameParams); break;
        case DolphinInstanceIpcCall::Null: default: std::cout << "NULL server => instance call!" << std::endl; break;
    }
}
