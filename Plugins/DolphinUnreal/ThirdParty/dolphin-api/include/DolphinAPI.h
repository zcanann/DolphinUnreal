#pragma once

#ifdef DOLPHINAPI_EXPORTS
#define DOLPHINAPI_API __declspec(dllexport)
#else
#define DOLPHINAPI_API __declspec(dllimport)
#endif

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
#endif // !WIN32_LEAN_AND_MEAN

// Windows Header Files
#include <windows.h>

#include <string>
#include <vector>

class DOLPHINAPI_API DolphinInstance
{
public:
	DolphinInstance(std::function<void(DolphinInstance*)> onDestroyed);

private:
	// static std::unique_ptr<Platform> s_platform;

	std::function<void(DolphinInstance*)> _onDestroyed;
};

extern DOLPHINAPI_API std::vector<DolphinInstance*> Instances;

DOLPHINAPI_API DolphinInstance* CreateDolphinInstance(std::function<void(DolphinInstance*)> onDestroyed);
