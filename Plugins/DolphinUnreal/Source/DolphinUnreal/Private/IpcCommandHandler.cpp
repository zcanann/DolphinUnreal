#include "IpcCommandHandler.h"

#define __GNUC__ 0

#include "dolphin-ipc/DolphinIpc.h"
#include "dolphin-ipc/DolphinIpcServer.h"
#include "dolphin-ipc/DolphinIpcServerData.h"

DolphinIPC* IpcCommandHandler::_dolphinIPC = nullptr;

IpcCommandHandler::IpcCommandHandler(const std::string& channelId)
{
	IpcCommandHandler::_dolphinIPC = new DolphinIPC(channelId);
}

IpcCommandHandler::~IpcCommandHandler()
{
	if (_dolphinIPC != nullptr)
	{
		delete(_dolphinIPC);
		_dolphinIPC = nullptr;
	}
}

void DolphinServer_OnClientTerminated(const std::string& param)
{

}
