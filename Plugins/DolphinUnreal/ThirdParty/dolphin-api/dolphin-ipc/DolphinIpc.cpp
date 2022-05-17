#include "DolphinIPC.h"

// IPC includes
#include <signal.h>

#include <atomic>
#include <iostream>
#include <chrono>
#include <cstddef>
#include <streambuf>
#include <string>
#include <thread>

#include "cereal/cereal.hpp"
#include "cereal/access.hpp"
#include "cereal/types/common.hpp"
#include "cereal/types/string.hpp"
#include "cereal/types/map.hpp"
#include "cereal/types/vector.hpp"
#include "cereal/types/memory.hpp"
#include "cereal/archives/binary.hpp"

#include "libipc/ipc.h"

constexpr char const channelName[] = "dol-ipc";
constexpr std::size_t const min_sz = 128;
constexpr std::size_t const max_sz = 1024 * 16;

ipc::chan<ipc::relat::single, ipc::relat::multi, ipc::trans::broadcast> channel{ channelName };
ipc::byte_t sharedBuffer[max_sz];
std::atomic<bool> exitRequested{ false };

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
    if (channel.reconnect(ipc::sender))
    {
        MemoryStream memoryStream = MemoryStream((char*)&sharedBuffer, sizeof(sharedBuffer));
        std::ostream out(&memoryStream);
        cereal::BinaryOutputArchive archive(out);

        archive(params);
        // params.save(archive);

        if (!exitRequested.load(std::memory_order_acquire))
        {
            if (!channel.send(ipc::buff_t(sharedBuffer, memoryStream.written())))
            {
                std::cerr << __func__ << ": send failed.\n";
                std::cout << __func__ << ": waiting for receiver...\n";
                if (!channel.wait_for_recv(1))
                {
                    std::cerr << __func__ << ": wait receiver failed.\n";
                    exitRequested.store(true, std::memory_order_release);
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
    if (channel.reconnect(ipc::receiver))
    {
        while (!exitRequested.load(std::memory_order_acquire))
        {
            ipc::buff_t msg = channel.recv();
            std::string dat{ msg.get<char const*>(), msg.size() - 1 };

            if (msg.empty())
            {
                break;
            }
        }
    }
    else
    {
        std::cerr << __func__ << ": connect failed.\n";
    }
    std::cout << __func__ << ": quit...\n";
}
