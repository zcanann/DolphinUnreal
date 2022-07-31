#include "DolphinInstance.h"

#include "Interfaces/IPluginManager.h"
#include "Misc/Guid.h"
#include "Misc/MonitoredProcess.h"
#include "Misc/Paths.h"

#include "AssetTypes/IsoAsset.h"
#include "DataTables/InputTableImporter.h"
#include "DolphinUnreal.h"
#include "DolphinUnrealBlueprintLibrary.h"
#include "FrameInput.h"
#include "Platform/WindowsSimpleProcessSpawner.h"

// STL
#include <string>

#pragma optimize("", off)

UDolphinInstance::UDolphinInstance(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
    FEditorDelegates::PausePIE.AddUObject(this, &UDolphinInstance::PausePIE);
    FEditorDelegates::EndPIE.AddUObject(this, &UDolphinInstance::EndPIE);
}

void UDolphinInstance::Initialize(UIsoAsset* InIsoAsset, bool bStartPaused, bool bBeginRecording)
{
    LaunchInstance(InIsoAsset, bStartPaused, bBeginRecording);
}

UDolphinInstance::~UDolphinInstance()
{
}

void UDolphinInstance::PausePIE(const bool bIsSimulating)
{
    DolphinIpcToInstanceData ipcData;
    std::shared_ptr<ToInstanceParams_StopRecordingInput> data = std::make_shared<ToInstanceParams_StopRecordingInput>();
    ipcData._call = DolphinInstanceIpcCall::DolphinInstance_StopRecordingInput;
    ipcSendToInstance(ipcData);
}

void UDolphinInstance::EndPIE(const bool bIsSimulating)
{
    UDolphinUnrealBlueprintLibrary::Terminate(this);
}

void UDolphinInstance::Tick(float DeltaTime)
{
    if (this == GetDefault<UDolphinInstance>())
    {
        return;
    }

    updateIpcListen();

    // Send a heartbeat to the running instance
    DolphinIpcToInstanceData ipcData;
    std::shared_ptr<ToInstanceParams_Heartbeat> data = std::make_shared<ToInstanceParams_Heartbeat>();
    ipcData._call = DolphinInstanceIpcCall::DolphinInstance_Heartbeat;
    ipcSendToInstance(ipcData);
}

void UDolphinInstance::DolphinServer_OnInstanceConnected(const ToServerParams_OnInstanceConnected& OnInstanceConnectedParams)
{
    if (GEngine)
    {
        GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Dolphin instance connected"));
    }
}

void UDolphinInstance::DolphinServer_OnInstanceReady(const ToServerParams_OnInstanceReady& OnInstanceReadyParams)
{
    OnInstanceReadyForNextCommandEvent.Broadcast(this);
}

void UDolphinInstance::DolphinServer_OnInstanceHeartbeatAcknowledged(const ToServerParams_OnInstanceHeartbeatAcknowledged& onInstanceHeartbeatAcknowledgedParams)
{
    bIsRecordingInput = onInstanceHeartbeatAcknowledgedParams._isRecording;
    bIsPaused = onInstanceHeartbeatAcknowledgedParams._isPaused;
}

void UDolphinInstance::DolphinServer_OnInstanceTerminated(const ToServerParams_OnInstanceTerminated& OnInstanceTerminatedParams)
{
    if (GEngine)
    {
        GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Dolphin instance terminated"));
    }
}

void UDolphinInstance::DolphinServer_OnInstanceRecordingStopped(const ToServerParams_OnInstanceRecordingStopped& onInstanceRecordingStopped)
{
    UDataTable* InputTable = NewObject<UDataTable>();

    InputTable->RowStruct = FFrameInput::StaticStruct();

    // TODO: This is slow and takes too much memory. Better to not to add the rows to the data table at all, and append each row to the CSV iteratively.
    for (const DolphinControllerState& Next : onInstanceRecordingStopped._inputStates)
    {
        FFrameInput FrameInput = FFrameInput::FromDolphinControllerState(Next);
        InputTable->AddRow(FName(FGuid::NewGuid().ToString()), FrameInput);
    }

    FInputTableImporter::ImportInputTableAsAsset(*InputTable);
}

void UDolphinInstance::LaunchInstance(UIsoAsset* InIsoAsset, bool bStartPaused, bool bBeginRecording)
{
    static FString PluginContentDirectory = FPaths::ConvertRelativePathToFull(IPluginManager::Get().FindPlugin(TEXT("DolphinUnreal"))->GetContentDir());
    static FString ProjectContentDirectory = FPaths::ConvertRelativePathToFull(FPaths::ProjectContentDir());

    InstanceId = FGuid::NewGuid().ToString();
    FString GamePath = InIsoAsset->Path;
    FString UserPath = FPaths::Combine(ProjectContentDirectory, "Dolphin");
    FString StartPausedFlag = bStartPaused ? TEXT("-z") : TEXT("");
    FString RecordingFlag = bBeginRecording ? TEXT("-r") : TEXT("");
    FString Params = FString::Format(TEXT("\"{0}\" -u \"{1}\" -p win32 -i {2} {3} {4}"), { GamePath, UserPath, InstanceId, StartPausedFlag, RecordingFlag });

    FString DolphinBinaryFolder = FPaths::Combine(PluginContentDirectory, TEXT("Dolphin/"));
    FString DolphinBinaryPath = FPaths::Combine(DolphinBinaryFolder, TEXT("DolphinInstance.exe"));
    FString OptionalWorkingDirectory = DolphinBinaryFolder;

    initializeChannels(std::string(TCHAR_TO_UTF8(*InstanceId)), false);

    /*
    FWindowsSimpleProcessSpawner::CreateProc(
        *DolphinBinaryPath,
        *Params,
        (OptionalWorkingDirectory != "") ? *OptionalWorkingDirectory : nullptr
    );*/

    FString ExecuteParams = "start " + DolphinBinaryPath + " " + Params;
    FWindowsSimpleProcessSpawner::CreateProc(TCHAR_TO_ANSI(*ExecuteParams));
}

void UDolphinInstance::RequestLoadSaveState(FString SaveName)
{

}

void UDolphinInstance::RequestCreateSaveState(FString SaveName)
{

}

void UDolphinInstance::RequestPause()
{
    bIsPaused = true;

    DolphinIpcToInstanceData ipcData;
    std::shared_ptr<ToInstanceParams_PauseEmulation> data = std::make_shared<ToInstanceParams_PauseEmulation>();
    ipcData._call = DolphinInstanceIpcCall::DolphinInstance_PauseEmulation;
    ipcSendToInstance(ipcData);
}

void UDolphinInstance::RequestResume()
{
    bIsPaused = false;

    DolphinIpcToInstanceData ipcData;
    std::shared_ptr<ToInstanceParams_ResumeEmulation> data = std::make_shared<ToInstanceParams_ResumeEmulation>();
    ipcData._call = DolphinInstanceIpcCall::DolphinInstance_ResumeEmulation;
    ipcSendToInstance(ipcData);
}

bool UDolphinInstance::IsPaused() const
{
    return bIsPaused;
}

void UDolphinInstance::RequestStartRecording()
{
    bIsRecordingInput = true;

    DolphinIpcToInstanceData ipcData;
    std::shared_ptr<ToInstanceParams_StartRecordingInput> data = std::make_shared<ToInstanceParams_StartRecordingInput>();
    ipcData._call = DolphinInstanceIpcCall::DolphinInstance_StartRecordingInput;
    ipcSendToInstance(ipcData);
}

void UDolphinInstance::RequestStopRecording()
{
    bIsRecordingInput = false;

    DolphinIpcToInstanceData ipcData;
    std::shared_ptr<ToInstanceParams_StopRecordingInput> data = std::make_shared<ToInstanceParams_StopRecordingInput>();
    ipcData._call = DolphinInstanceIpcCall::DolphinInstance_StopRecordingInput;
    ipcSendToInstance(ipcData);
}

bool UDolphinInstance::IsRecording() const
{
    return bIsRecordingInput;
}

void UDolphinInstance::RequestPlayInputs(UDataTable* FrameInputsTable)
{
    if (FrameInputsTable == nullptr)
    {
        return;
    }

    TArray<FFrameInput*> FrameInputs;
    FString ContextString = TEXT("PlayInputs");

    FrameInputsTable->GetAllRows(ContextString, FrameInputs);

    std::vector<DolphinControllerState> InputStates;
    for (const FFrameInput* Next : FrameInputs)
    {
        if (Next)
        {
            InputStates.push_back(FFrameInput::ToDolphinControllerState(*Next));
        }
    }

    DolphinIpcToInstanceData ipcData;
    std::shared_ptr<ToInstanceParams_PlayInputs> data = std::make_shared<ToInstanceParams_PlayInputs>();
    data->_inputStates = InputStates;
    ipcData._call = DolphinInstanceIpcCall::DolphinInstance_PlayInputs;
    ipcData._params._playInputsParams = data;
    ipcSendToInstance(ipcData);
}

void UDolphinInstance::RequestTerminate()
{
    DolphinIpcToInstanceData ipcData;
    std::shared_ptr<ToInstanceParams_Terminate> data = std::make_shared<ToInstanceParams_Terminate>();
    ipcData._call = DolphinInstanceIpcCall::DolphinInstance_Terminate;
    ipcSendToInstance(ipcData);

    ConditionalBeginDestroy();
}

#pragma optimize("", on)
