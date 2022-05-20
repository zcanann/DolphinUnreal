#include "IpcCommandHandler.h"

#include "dolphin-ipc/DolphinIpcToInstanceData.h"

IpcCommandHandler::IpcCommandHandler() : DolphinIpcHandlerBase()
{
}

IpcCommandHandler::~IpcCommandHandler()
{
}

void IpcCommandHandler::DolphinInstance_Connect(const ToInstanceParams_Connect& connectParams)
{

}

void IpcCommandHandler::DolphinInstance_LoadGame(const ToInstanceParams_LoadGame& loadGameParams)
{

}
