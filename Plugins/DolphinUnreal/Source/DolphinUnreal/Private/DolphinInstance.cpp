#include "DolphinInstance.h"

#include "DolphinUnreal.h"
#include "Interfaces/IPluginManager.h"
#include "Misc/MonitoredProcess.h"
#include "Misc/Paths.h"

// STL
#include <random>
#include <string>

UDolphinInstance::UDolphinInstance(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
{

}

void UDolphinInstance::Initialize(FDolphinGraphicsSettings InGraphicsSettings, FDolphinRuntimeSettings InRuntimeSettings)
{
    LaunchInstance();
}

UDolphinInstance::~UDolphinInstance()
{
}

void UDolphinInstance::LaunchInstance()
{
    static FString ContentDirectory = FPaths::ConvertRelativePathToFull(IPluginManager::Get().FindPlugin(TEXT("DolphinUnreal"))->GetContentDir());

    InstanceId = MakeInstanceId();
    FString DolphinPath = FPaths::Combine(ContentDirectory, TEXT("DolphinInstance.exe"));
    FString GamePath = TEXT("C:/Dolphin/Games/Star Fox Adventures (USA) (v1.00).iso");
    FString Params = FString::Format(TEXT("\"{0}\" -p win32 -i {1}"), { GamePath, InstanceId });

    bool bLaunchHidden = false;
    bool bCreatePipes = false;

    initializeChannels(std::string(TCHAR_TO_UTF8(*InstanceId)), false);

    DolphinProcess = TSharedPtr<FMonitoredProcess>(new FMonitoredProcess(DolphinPath, Params, bLaunchHidden, bCreatePipes));
    DolphinProcess->Launch();

    /*
    bool bLaunchDetached = true;
    bool bLaunchHidden = false;
    bool bLaunchReallyHidden = false;

    uint32 OutProcessID = 0;
    uint32 PriorityModifier = 0;
    FString OptionalWorkingDirectory;

    DolphinProcHandle = FPlatformProcess::CreateProc(
        *DolphinPath,
        *Params,
        bLaunchDetached,
        bLaunchHidden,
        bLaunchReallyHidden,
        &OutProcessID,
        PriorityModifier,
        (OptionalWorkingDirectory != "") ? *OptionalWorkingDirectory : nullptr,
        nullptr
    );
    */
}

void UDolphinInstance::Tick(float DeltaTime)
{
    updateIpcListen();
}

void UDolphinInstance::DolphinServer_OnInstanceConnected(const ToServerParams_OnInstanceConnected& onInstanceConnectedParams)
{
    if (GEngine)
    {
        GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Some debug message!"));
    }
}

void UDolphinInstance::DolphinServer_OnInstanceTerminated(const ToServerParams_OnInstanceTerminated& onInstanceTerminatedParams)
{
    if (GEngine)
    {
        GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Some debug message!"));
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
