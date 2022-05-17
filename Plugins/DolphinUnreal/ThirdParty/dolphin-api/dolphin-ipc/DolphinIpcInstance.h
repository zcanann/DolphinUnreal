#pragma once
// Defines the IPC methods that are called from the controlling library (server) to an individual Dolphin instance (client)

#include "DolphinIpcInstanceData.h"

#include <string>

// Externally Implemented
void DolphinInstance_Connect(const DolphinParams_Connect& connectParams);
void DolphinInstance_LoadGame(const DolphinParams_LoadGame& loadGameParams);
