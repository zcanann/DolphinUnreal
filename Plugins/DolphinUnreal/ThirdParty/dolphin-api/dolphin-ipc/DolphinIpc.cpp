#include "DolphinIPC.h"

#include "cereal/cereal.hpp"
#include "cereal/access.hpp"
#include "cereal/types/common.hpp"
#include "cereal/types/string.hpp"
#include "cereal/types/map.hpp"
#include "cereal/types/vector.hpp"
#include "cereal/types/memory.hpp"
#include "cereal/archives/binary.hpp"

const std::string DolphinIPC::ChannelNameClientBase = "dol-c2s-";
const std::string DolphinIPC::ChannelNameServerBase = "dol-s2c-";

DolphinIPC::DolphinIPC(const std::string& uniqueChannelId)
{
    std::string uniqueClientChannel = ChannelNameClientBase + uniqueChannelId;
    std::string uniqueServerChannel = ChannelNameServerBase + uniqueChannelId;

    _clientToServer = new IpcChannel(uniqueClientChannel.c_str());
    _serverToClient = new IpcChannel(uniqueServerChannel.c_str());

    ipcListen();
}

DolphinIPC::~DolphinIPC()
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

void DolphinIPC::ipcSendToInstance(DolphinIpcInstanceData params)
{
    ipcSendData(_serverToClient, params);
}

void DolphinIPC::ipcSendToServer(DolphinIpcServerData params)
{
    ipcSendData(_clientToServer, params);
}

template<class T>
void DolphinIPC::ipcSendData(IpcChannel* channel, T params)
{
    if (channel == nullptr || channel->reconnect(ipc::sender))
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

void DolphinIPC::ipcListen()
{
    std::thread clientToServerListener{
        [=] {
            if (_clientToServer != nullptr && _clientToServer->reconnect(ipc::receiver))
            {
                while (!_exitRequested.load(std::memory_order_acquire))
                {
                    ipc::buff_t rawData = _clientToServer->recv();
                    std::string dat{ rawData.get<char const*>(), rawData.size() - 1 };

                    if (rawData.empty())
                    {
                        break;
                    }
                }
            }
            else
            {
                std::cerr << __func__ << ": client to server connect failed.\n";
            }
            std::cout << __func__ << ": client to server quit...\n";
        }
    };

    std::thread serverToClientListener{
        [=] {
            if (_serverToClient != nullptr && _serverToClient->reconnect(ipc::receiver))
            {
                while (!_exitRequested.load(std::memory_order_acquire))
                {
                    ipc::buff_t rawData = _serverToClient->recv();
                    std::string dat{ rawData.get<char const*>(), rawData.size() - 1 };

                    if (rawData.empty())
                    {
                        break;
                    }
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
