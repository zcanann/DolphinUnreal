#pragma once

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
#endif // !WIN32_LEAN_AND_MEAN

#include "DolphinIpcInstanceData.h"
#include "DolphinIpcServerData.h"

class DolphinIPC
{
	DolphinIPC();

	static void ipcSendToInstance(DolphinIpcInstanceData params);
	static void ipcSendToServer(DolphinIpcServerData params);
	static void ipcListen();
};
