#pragma once

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
#endif // !WIN32_LEAN_AND_MEAN

// Prevent errors in cereal that propagate to Unreal where __GNUC__ is not defined
#define __GNUC__ 0

#include "DolphinIpcInstanceData.h"
#include "DolphinIpcServerData.h"

#include <atomic>
#include <iostream>
#include <chrono>
#include <cstddef>
#include <signal.h>
#include <streambuf>
#include <string>
#include <thread>

#include "libipc/ipc.h"

typedef ipc::chan<ipc::relat::single, ipc::relat::single, ipc::trans::unicast> IpcChannel;

class DolphinIPC
{
public:
	DolphinIPC(const std::string& uniqueChannelId);
	~DolphinIPC();

	void ipcSendToInstance(DolphinIpcInstanceData params);
	void ipcSendToServer(DolphinIpcServerData params);
	void ipcListen();

private:
	template<class T>
	void ipcSendData(IpcChannel* channel, T params);

	ipc::byte_t _sharedBuffer[1024 * 16];
	std::atomic<bool> _exitRequested{ false };
	IpcChannel* _clientToServer = nullptr;
	IpcChannel* _serverToClient = nullptr;

	static const std::string ChannelNameClientBase;
	static const std::string ChannelNameServerBase;
};
