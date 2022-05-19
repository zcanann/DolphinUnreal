#include "IpcCommandHandler.h"

#include "dolphin-ipc/DolphinIpcInstanceData.h"

IpcCommandHandler::IpcCommandHandler() : DolphinIpcHandlerBase()
{
}

IpcCommandHandler::~IpcCommandHandler()
{
}

void IpcCommandHandler::DolphinInstance_Connect(const DolphinParams_Connect& connectParams)
{

}

void IpcCommandHandler::DolphinInstance_LoadGame(const DolphinParams_LoadGame& loadGameParams)
{

}
