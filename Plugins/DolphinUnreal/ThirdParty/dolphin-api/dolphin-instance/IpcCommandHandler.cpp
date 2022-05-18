#include "IpcCommandHandler.h"

#include "dolphin-ipc/DolphinIPC.h"
#include "dolphin-ipc/DolphinIPCInstance.h"

DolphinIPC* IpcCommandHandler::_dolphinIPC = nullptr;

IpcCommandHandler::IpcCommandHandler(const std::string& channelId)
{
	IpcCommandHandler:_dolphinIPC = new DolphinIPC(channelId);
}

IpcCommandHandler::~IpcCommandHandler()
{
	if (_dolphinIPC != nullptr)
	{
		delete(_dolphinIPC);
		_dolphinIPC = nullptr;
	}
}

void DolphinInstance_Connect(const DolphinParams_Connect& connectParams)
{
	// Ipc post-connect callback
	DolphinIpcServerData ipcData;
	auto data = std::shared_ptr<DolphinServer_OnClientConnected>(new DolphinServer_OnClientConnected());
	ipcData._params._onClientConnectedParams = data.get();
	IpcCommandHandler::_dolphinIPC->ipcSendToServer(ipcData);
}

void DolphinInstance_LoadGame(const DolphinParams_LoadGame& loadGameParams)
{

}
