#pragma once

#include "CoreMinimal.h"
#include "Windows/WindowsPlatformProcess.h"

struct FWindowsSimpleProcessSpawner
{
public:
	static void CreateProc(const TCHAR* URL, const TCHAR* Params, const TCHAR* OptionalWorkingDirectory);
	static void CreateProc(const char* Command);
};
