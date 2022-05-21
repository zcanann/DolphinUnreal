#include "DolphinInstance.h"

#include "DolphinUnreal.h"
#include "Interfaces/IPluginManager.h"
#include "Misc/Guid.h"
#include "Misc/MonitoredProcess.h"
#include "Misc/Paths.h"

// STL
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

void UDolphinInstance::Tick(float DeltaTime)
{
    updateIpcListen();
}

void UDolphinInstance::WaitFrames(int32 Frames)
{
    /*
    DolphinIpcToInstanceData ipcData;
    ToServerParams_OnInstanceConnected* data = new ToServerParams_OnInstanceConnected();
    data->_params = "123";
    ipcData._call = DolphinInstanceIpcCall::DolphinServer_OnInstanceConnected;
    ipcData._params._onInstanceConnectedParams = data;
    ipcSendToServer(ipcData);*/
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

void UDolphinInstance::LaunchInstance()
{
    static FString ContentDirectory = FPaths::ConvertRelativePathToFull(IPluginManager::Get().FindPlugin(TEXT("DolphinUnreal"))->GetContentDir());

    InstanceId = FGuid::NewGuid().ToString();
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
