#include "Platform/WindowsSimpleProcessSpawner.h"

#include "Windows/AllowWindowsPlatformTypes.h"
	#include <shellapi.h>
#include "Windows/HideWindowsPlatformTypes.h"

void FWindowsSimpleProcessSpawner::CreateProc(const TCHAR* URL, const TCHAR* Params, const TCHAR* OptionalWorkingDirectory)
{
	ShellExecute(NULL, TEXT("open"), URL, Params, OptionalWorkingDirectory, SW_SHOWDEFAULT);
	
	/*
	SHELLEXECUTEINFO ShellExecuteInfo;
	ZeroMemory(&ShellExecuteInfo, sizeof(ShellExecuteInfo));
	ShellExecuteInfo.cbSize = sizeof(ShellExecuteInfo);
	ShellExecuteInfo.fMask = NULL;
	ShellExecuteInfo.lpFile = URL;
	ShellExecuteInfo.lpVerb = TEXT("open");
	ShellExecuteInfo.nShow = SW_SHOWMINNOACTIVE; // Can potentially use SW_HIDE when we support window piping to unreal
	ShellExecuteInfo.lpParameters = Params;
	ShellExecuteInfo.lpDirectory = OptionalWorkingDirectory;

	ShellExecuteEx(&ShellExecuteInfo);*/
}

void FWindowsSimpleProcessSpawner::CreateProc(const char* Command)
{
	system(Command);
}
