#pragma once

#include <string>

#include "dolphin-ipc/DolphinIpcHandlerBase.h"

class IpcCommandHandler : public DolphinIpcHandlerBase
{
public:
	IpcCommandHandler();
	virtual ~IpcCommandHandler();

private:
	virtual void DolphinInstance_Connect(const DolphinParams_Connect& connectParams) override;
	virtual void DolphinInstance_LoadGame(const DolphinParams_LoadGame& loadGameParams) override;
};
