#pragma once

#include <string>

class DolphinIPC;

class IpcCommandHandler
{
public:
	IpcCommandHandler(const std::string& channelId);
	~IpcCommandHandler();

	static DolphinIPC* _dolphinIPC;

private:
};
