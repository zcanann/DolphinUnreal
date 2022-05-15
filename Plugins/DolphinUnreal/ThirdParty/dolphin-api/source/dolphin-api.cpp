// dolphin-api.cpp : Defines the exported functions for the DLL.
//

#include "framework.h"
#include "dolphin-api.h"


// This is an example of an exported variable
DOLPHINAPI_API int GlobalVar = 0;

// This is an example of an exported function.
DOLPHINAPI_API int GlobalFunction(void)
{
    return 0;
}

// This is the constructor of a class that has been exported.
DolphinAPI::DolphinAPI()
{
    return;
}
