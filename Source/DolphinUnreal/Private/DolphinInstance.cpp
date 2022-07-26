#include "DolphinInstance.h"

#include "DolphinUnreal.h"
#include "Interfaces/IPluginManager.h"
#include "Misc/Guid.h"
#include "Misc/MonitoredProcess.h"
#include "Misc/Paths.h"
#include "Windows/WindowsPlatformProcess.h"

#include "AssetTypes/IsoAsset.h"

// STL
#include <string>

UDolphinInstance::UDolphinInstance(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
    FEditorDelegates::PausePIE.AddUObject(this, &UDolphinInstance::PausePIE);
}

void UDolphinInstance::Initialize(UIsoAsset* InIsoAsset, const FDolphinGraphicsSettings& InGraphicsSettings, const FDolphinRuntimeSettings& InRuntimeSettings)
{
    LaunchInstance(InIsoAsset, InGraphicsSettings, InRuntimeSettings);
}

UDolphinInstance::~UDolphinInstance()
{
    if (DolphinProcHandle.IsValid())
    {
        FWindowsPlatformProcess::TerminateProc(DolphinProcHandle);
    }
}

void UDolphinInstance::PausePIE(const bool bIsSimulating)
{
    DolphinIpcToInstanceData ipcData;
    std::shared_ptr<ToInstanceParams_StopRecordingInput> data = std::make_shared<ToInstanceParams_StopRecordingInput>();
    ipcData._call = DolphinInstanceIpcCall::DolphinInstance_StopRecordingInput;
    ipcSendToInstance(ipcData);
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

void UDolphinInstance::DolphinServer_OnInstanceConnected(const ToServerParams_OnInstanceConnected& OnInstanceConnectedParams)
{
    if (GEngine)
    {
        GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Dolphin instance connected"));
    }
}

void UDolphinInstance::DolphinServer_OnInstanceTerminated(const ToServerParams_OnInstanceTerminated& OnInstanceTerminatedParams)
{
    if (GEngine)
    {
        GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Dolphin instance terminated"));
    }
}

void UDolphinInstance::LaunchInstance(UIsoAsset* InIsoAsset, const FDolphinGraphicsSettings& InGraphicsSettings, const FDolphinRuntimeSettings& InRuntimeSettings)
{
    static FString PluginContentDirectory = FPaths::ConvertRelativePathToFull(IPluginManager::Get().FindPlugin(TEXT("DolphinUnreal"))->GetContentDir());
    static FString ProjectContentDirectory = FPaths::ConvertRelativePathToFull(FPaths::ProjectContentDir());

    InstanceId = FGuid::NewGuid().ToString();
    FString DolphinPath = FPaths::Combine(PluginContentDirectory, TEXT("DolphinInstance.exe"));
    FString GamePath = InIsoAsset->Path;
    FString UserPath = FPaths::Combine(ProjectContentDirectory, "Dolphin");
    FString Params = FString::Format(TEXT("\"{0}\" -u \"{1}\" -p win32 -i {2}"), { GamePath, UserPath, InstanceId });

    initializeChannels(std::string(TCHAR_TO_UTF8(*InstanceId)), false);

    bool bLaunchDetached = true;
    bool bLaunchHidden = false;
    bool bLaunchReallyHidden = false;

    uint32 OutProcessID = 0;
    uint32 PriorityModifier = 0;
    FString OptionalWorkingDirectory;

    DolphinProcHandle = FWindowsPlatformProcess::CreateProc(
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
}
