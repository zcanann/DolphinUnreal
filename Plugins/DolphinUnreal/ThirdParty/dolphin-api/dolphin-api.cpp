// dolphin-api.cpp : Defines the exported functions for the DLL.
//

#include "framework.h"
#include "dolphin-api.h"

// This is the constructor of a class that has been exported.
CDolphinAPI::CDolphinAPI()
{
    return;
}

// This is an example of an exported function.
DOLPHINAPI_API int GlobalFunc(void)
{
    return 1;
}