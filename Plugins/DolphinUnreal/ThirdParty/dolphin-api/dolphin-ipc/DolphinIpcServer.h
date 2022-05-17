#pragma once

// Defines the IPC callbacks that are called from an individual Dolphin instance (client) to the controlling library (server)

#include "DolphinIpcServerData.h"

#include <string>

// Externally Implemented
void DolphinServer_OnClientTerminated(const std::string& param);
