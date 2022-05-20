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

#define NOT_IMPLEMENTED() std::cout << "CALLED UNIMPLEMENTED HANDLER FUNC" << std::endl;

class DolphinIpcHandlerBase
{
public:
	DolphinIpcHandlerBase();
	virtual ~DolphinIpcHandlerBase();

	void initializeChannels(const std::string& uniqueChannelId, bool isInstance);

	void updateIpcListen();
	void ipcSendToServer(DolphinIpcServerData data);
	void ipcSendToInstance(DolphinIpcInstanceData data);

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
	void ipcSendData(ipc::channel* channel, T params);

	void onInstanceToServerDataReceived(const DolphinIpcServerData& data);
	void onServerToInstanceDataReceived(const DolphinIpcInstanceData& data);

	bool _isInstance = true;
	ipc::byte_t _sendBuffer[1024 * 16];
	ipc::channel* _instanceToServer = nullptr;
	ipc::channel* _serverToInstance = nullptr;

	static const std::string ChannelNameInstanceBase;
	static const std::string ChannelNameServerBase;
};
