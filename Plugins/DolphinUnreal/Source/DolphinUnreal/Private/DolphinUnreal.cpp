// Copyright Epic Games, Inc. All Rights Reserved.

#include "DolphinUnreal.h"
#include "Core.h"
#include "Modules/ModuleManager.h"
#include "Interfaces/IPluginManager.h"

#include "dolphin-api.h"

#define LOCTEXT_NAMESPACE "FDolphinUnrealModule"

void FDolphinUnrealModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
	FString BaseDir = IPluginManager::Get().FindPlugin("DolphinUnreal")->GetBaseDir();

	// Add on the relative location of the third party dll and load it
	FString LibraryPath;
#if PLATFORM_WINDOWS
	LibraryPath = FPaths::Combine(*BaseDir, TEXT("Binaries/ThirdParty/DolphinAPI/Win64/DolphinAPI.dll"));
#elif PLATFORM_MAC
	LibraryPath = FPaths::Combine(*BaseDir, TEXT("Binaries/ThirdParty/DolphinAPI/Mac/Release/DolphinAPI.dylib"));
#elif PLATFORM_LINUX
	LibraryPath = FPaths::Combine(*BaseDir, TEXT("Binaries/ThirdParty/DolphinAPI/Linux/x86_64-unknown-linux-gnu/DolphinAPI.so"));
#endif // PLATFORM_WINDOWS

	DolphinAPIHandle = !LibraryPath.IsEmpty() ? FPlatformProcess::GetDllHandle(*LibraryPath) : nullptr;

	if (DolphinAPIHandle)
	{
		// Call the test function in the third party library that opens a message box
		// int why = GlobalFunction();
	}
	else
	{
		FMessageDialog::Open(EAppMsgType::Ok, LOCTEXT("ThirdPartyLibraryError", "Failed to load example third party library"));
	}
}

void FDolphinUnrealModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.

	// Free the dll handle
	FPlatformProcess::FreeDllHandle(DolphinAPIHandle);
	DolphinAPIHandle = nullptr;
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FDolphinUnrealModule, DolphinUnreal)
