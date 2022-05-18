#include "DolphinInstance.h"

#include "DolphinUnreal.h"
#include "Interfaces/IPluginManager.h"
#include "Misc/Paths.h"

#include "dolphin-ipc/DolphinIpc.h"
#include "dolphin-ipc/DolphinIpcServer.h"
#include "dolphin-ipc/DolphinIpcServerData.h"

// STL
#include <random>
#include <string>

UDolphinInstance::UDolphinInstance(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
{

}

void UDolphinInstance::Initialize(FDolphinGraphicsSettings InGraphicsSettings, FDolphinRuntimeSettings InRuntimeSettings)
{
    static FString ContentDirectory = IPluginManager::Get().FindPlugin(TEXT("DolphinUnreal"))->GetContentDir();
    InstanceId = MakeInstanceId();
	// DolphinIPCInstance = new DolphinIPC(TCHAR_TO_UTF8(*InstanceId));

    FString DolphinPath = FPaths::Combine(ContentDirectory, TEXT("DolphinInstance.exe"));
    FString GamePath = TEXT("C:/Dolphin/Games/Star Fox Adventures (USA) (v1.00).iso");
    FString Params = FString::Format(TEXT("\"{0}\" -p win32 channelId={1}"), { GamePath, InstanceId });
    bool bLaunchDetached = true;
    bool bLaunchHidden = false;
    bool bLaunchReallyHidden = false;
    uint32 OutProcessId;
    int32 PriorityModifier = 0;
    FString OptionalWorkingDirectory;
    void* PipeWriteChild = nullptr;
    void* PipeReadChild = nullptr;
    void* PipeStdErrChild = nullptr;

    DolphinProcess = FPlatformProcess::CreateProc(
        *DolphinPath,
        *Params,

        bLaunchDetached,
        bLaunchHidden,
        bLaunchReallyHidden,

        &OutProcessId,
        PriorityModifier,
        *OptionalWorkingDirectory,

        PipeWriteChild,
        PipeReadChild,
        PipeStdErrChild
    );

}

UDolphinInstance::~UDolphinInstance()
{
	if (DolphinIPCInstance != nullptr)
	{
		delete(DolphinIPCInstance);
		DolphinIPCInstance = nullptr;
	}
}

FString UDolphinInstance::MakeInstanceId() const
{
    static std::random_device Device;
    static std::mt19937 Rand(Device());

    std::uniform_int_distribution<int> dist(0, 15);

    const char* Chars = "0123456789abcdef";
    const bool Dash[] = { 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0 };

    FString Result;

    for (int Index = 0; Index < 16; Index++)
    {
        if (Dash[Index])
        {
            Result += "-";
        }

        Result += Chars[dist(Rand)];
        Result += Chars[dist(Rand)];
    }
    return Result;
}

void DolphinServer_OnClientTerminated(const std::string& param)
{

}
