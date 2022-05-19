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

#define NOT_IMPLEMENTED() std::cout << "CALLED UNIMPLEMENTED HANDLER FUNC" << std::endl;

class DolphinIpcHandlerBase
{
public:
	DolphinIpcHandlerBase();
	virtual ~DolphinIpcHandlerBase();

	void initializeChannels(const std::string& uniqueChannelId);

	void ipcSendToServer(DolphinIpcServerData params);
	void ipcSendToInstance(DolphinIpcInstanceData params);

	// Instance implemented functions
protected:
	virtual void DolphinInstance_Connect(const DolphinParams_Connect& connectParams) { NOT_IMPLEMENTED(); }
	virtual void DolphinInstance_LoadGame(const DolphinParams_LoadGame& loadGameParams) { NOT_IMPLEMENTED(); }

	// Server implemented functions
protected:
	virtual void DolphinServer_OnInstanceConnected(const DolphinParams_OnInstanceConnected& onInstanceConnectedParams) { NOT_IMPLEMENTED(); }
	virtual void DolphinServer_OnInstanceTerminated(const DolphinParams_OnInstanceTerminated& onInstanceTerminatedParams) { NOT_IMPLEMENTED(); }

private:
	template<class T>
	void ipcSendData(IpcChannel* channel, T params);
	void ipcListen();

	void onInstanceToServerDataReceived(const DolphinIpcServerData& data);
	void onServerToInstanceDataReceived(const DolphinIpcInstanceData& data);

	ipc::byte_t _sharedBuffer[1024 * 16];
	std::atomic<bool> _exitRequested{ false };
	IpcChannel* _instanceToServer = nullptr;
	IpcChannel* _serverToInstance = nullptr;

	std::thread _instanceListener;
	std::thread _serverListener;
	
	static const std::string ChannelNameInstanceBase;
	static const std::string ChannelNameServerBase;
};
