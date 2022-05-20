#pragma once

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
#endif // !WIN32_LEAN_AND_MEAN

#include "DolphinIpcToInstanceData.h"
#include "DolphinIpcToServerData.h"

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
	void ipcSendToServer(const DolphinIpcToServerData& data);
	void ipcSendToInstance(const DolphinIpcToInstanceData& data);

	// Instance implemented functions
protected:
	virtual void DolphinInstance_WaitFrames(const ToInstanceParams_WaitFrames& waitFramesParam) { NOT_IMPLEMENTED(); }
	virtual void DolphinInstance_Connect(const ToInstanceParams_Connect& connectParams) { NOT_IMPLEMENTED(); }
	virtual void DolphinInstance_LoadGame(const ToInstanceParams_LoadGame& loadGameParams) { NOT_IMPLEMENTED(); }

	// Server implemented functions
protected:
	virtual void DolphinServer_OnInstanceConnected(const ToServerParams_OnInstanceConnected& onInstanceConnectedParams) { NOT_IMPLEMENTED(); }
	virtual void DolphinServer_OnInstanceTerminated(const ToServerParams_OnInstanceTerminated& onInstanceTerminatedParams) { NOT_IMPLEMENTED(); }

private:
	template<class T>
	void ipcSendData(ipc::channel* channel, const T& params);


	template<class T>
	void ipcReadData(ipc::channel* channel, std::function<void(const T&)> onDeserialize);

	void onInstanceToServerDataReceived(const DolphinIpcToServerData& data);
	void onServerToInstanceDataReceived(const DolphinIpcToInstanceData& data);

	bool _isInstance = true;
	ipc::byte_t _sendBuffer[1024 * 16];
	ipc::channel* _instanceToServer = nullptr;
	ipc::channel* _serverToInstance = nullptr;

	static const std::string ChannelNameInstanceToServerBase;
	static const std::string ChannelNameServerToInstanceBase;
};
