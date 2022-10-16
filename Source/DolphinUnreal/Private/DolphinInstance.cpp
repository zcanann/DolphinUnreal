#include "DolphinInstance.h"

#include "AssetTypes/Iso/IsoAsset.h"
#include "AssetTypes/Sav/SavAsset.h"
#include "DataTables/InputTableImporter.h"
#include "DolphinUnreal.h"
#include "DolphinUnrealBlueprintLibrary.h"
#include "FrameInputs.h"

// Engine includes
#include "Interfaces/IPluginManager.h"
#include "Misc/Guid.h"
#include "Misc/Paths.h"
#include "Windows/WindowsPlatformProcess.h"

// STL
#include <string>

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
    UDolphinUnrealBlueprintLibrary::UntrackDolpinInstance(this);
}

void UDolphinInstance::PausePIE(const bool bIsSimulating)
{
}

void UDolphinInstance::EndPIE(const bool bIsSimulating)
{
    RequestTerminate();
}

void UDolphinInstance::Tick(float DeltaTime)
{
    if (this == GetDefault<UDolphinInstance>())
    {
        return;
    }

    updateIpcListen();

    // Send a heartbeat to the running instance
    CREATE_TO_INSTANCE_DATA(Heartbeat, ipcData, data);
    data->_shouldUseHardwareController = bShouldUseHardwareController;
    ipcSendToInstance(ipcData);
}

SERVER_FUNC_BODY(UDolphinInstance, OnInstanceConnected, params)
{
    WindowIdentifier = *reinterpret_cast<const int64*>(&params._windowIdentifier);

    if (GEngine)
    {
        GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Dolphin instance connected"));
    }

    // Only start tracking the instance once IPC has been established
    UDolphinUnrealBlueprintLibrary::TrackDolpinInstance(this);
}

SERVER_FUNC_BODY(UDolphinInstance, OnInstanceCommandCompleted, params)
{
    OnInstanceCommandCompleteEvent.Broadcast(this, NextCommandId++);
}

SERVER_FUNC_BODY(UDolphinInstance, OnInstanceHeartbeatAcknowledged, params)
{
    bIsRecordingInput = params._isRecording;
    bIsPaused = params._isPaused;
    ControllerStates[0] = FFrameInputs::FromDolphinControllerState(params._hardwareInputStates[0]);
    ControllerStates[1] = FFrameInputs::FromDolphinControllerState(params._hardwareInputStates[1]);
    ControllerStates[2] = FFrameInputs::FromDolphinControllerState(params._hardwareInputStates[2]);
    ControllerStates[3] = FFrameInputs::FromDolphinControllerState(params._hardwareInputStates[3]);
}

SERVER_FUNC_BODY(UDolphinInstance, OnInstanceLogOutput, params)
{
    FString LogMessage = FString(params._logString.c_str());
    static constexpr TCHAR FormatString[] = TEXT("%s");

    switch (params._logLevel)
    {
        case ToServerParams_OnInstanceLogOutput::LogLevel::Notice: UE_LOG(Dolphin, Display, FormatString, *LogMessage); break;
        case ToServerParams_OnInstanceLogOutput::LogLevel::Error: UE_LOG(Dolphin, Error, FormatString, *LogMessage); break;
        case ToServerParams_OnInstanceLogOutput::LogLevel::Warning: UE_LOG(Dolphin, Warning, FormatString, *LogMessage); break;
        default: case ToServerParams_OnInstanceLogOutput::LogLevel::Info: UE_LOG(Dolphin, Log, FormatString, *LogMessage); break;
        case ToServerParams_OnInstanceLogOutput::LogLevel::Debug: UE_LOG(Dolphin, Verbose, FormatString, *LogMessage); break;
    }
}

SERVER_FUNC_BODY(UDolphinInstance, OnInstanceTerminated, params)
{
    if (GEngine)
    {
        GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Dolphin instance terminated"));
    }
}

SERVER_FUNC_BODY(UDolphinInstance, OnInstanceRecordingStopped, params)
{
    UDataTable* InputTable = NewObject<UDataTable>();
    FString ImportTimeStamp = FString::FromInt(FDateTime::Now().ToUnixTimestamp());
    FString ImportGuid =  FGuid::NewGuid().ToString().Mid(0, 4);

    for (int32 Index = 0; Index < 4; Index++)
    {
        DolphinInputRecording Recording = params._inputRecording[int(Index)];

        if (!Recording.HasNext())
        {
            continue;
        }

        InputTable->RowStruct = FFrameInputs::StaticStruct();

        // Optimization: Write directly to CSV maybe, then import?
        while (Recording.HasNext())
        {
            FFrameInputs FrameInput = FFrameInputs::FromDolphinControllerState(Recording.PopNext());
            InputTable->AddRow(FName(FGuid::NewGuid().ToString()), FrameInput);
        }

        FString UniqueName = ImportTimeStamp + TEXT("_Controller") + FString::FromInt(Index) + TEXT("_") + ImportGuid;
        FInputTableImporter::ImportInputTableAsAsset(UniqueName, *InputTable);
    }
}

SERVER_FUNC_BODY(UDolphinInstance, OnInstanceSaveStateCreated, params)
{
    FString FilePath = FString(params._filePathNoExtension.c_str()) + TEXT(".sav");
    FString DestinationPath = FPaths::Combine(FPaths::ProjectContentDir(), TEXT("SaveStates"));
    GEditor->GetEditorSubsystem<UImportSubsystem>()->ImportNextTick({ FilePath }, DestinationPath);

    // Create a virtual save asset so that we can fire an event immediately
    USavAsset* VirtualSavAsset = NewObject<USavAsset>(this);
    VirtualSavAsset->Path = FilePath;

    OnInstanceSaveStateCreated.Broadcast(this, VirtualSavAsset);
}

SERVER_FUNC_BODY(UDolphinInstance, OnInstanceMemoryCardFormatted, params)
{
}

SERVER_FUNC_BODY(UDolphinInstance, OnInstanceMemoryRead, params)
{
    TArray<FDolphinUInt8> ArrayOfUBytes;
    for (unsigned char Next : params._bytes)
    {
        ArrayOfUBytes.Add(FDolphinUInt8(Next));
    }
    OnInstanceMemoryRead.Broadcast(this, ArrayOfUBytes);
}

SERVER_FUNC_BODY(UDolphinInstance, OnInstanceMemoryWrite, params)
{
}

SERVER_FUNC_BODY(UDolphinInstance, OnInstanceRenderGba, params)
{
    UTexture2D** TextureTargetPtr = nullptr;
    int32 ControllerIndex = params._controllerIndex;

    switch (params._controllerIndex)
    {
        case 0: TextureTargetPtr = &Gba0Render; break;
        case 1: TextureTargetPtr = &Gba1Render; break;
        case 2: TextureTargetPtr = &Gba2Render; break;
        case 3: TextureTargetPtr = &Gba3Render; break;
        default: return;
    }

    UTexture2D* Texture = *TextureTargetPtr;

    if (*TextureTargetPtr == nullptr || (*TextureTargetPtr)->GetSizeX() != params._width || (*TextureTargetPtr)->GetSizeY() != params._height)
    {
        Texture = UTexture2D::CreateTransient(params._width, params._height, PF_B8G8R8A8);
        OnGbaTextureChanged.Broadcast(params._controllerIndex, Texture);
    }

    GbaFrameBuffers[ControllerIndex].SetNum(params._frameBuffer.size() * 4);
    FMemory::Memcpy(GbaFrameBuffers[ControllerIndex].GetData(), reinterpret_cast<const uint8*>(params._frameBuffer.data()), params._frameBuffer.size() * 4);

    Texture->UpdateResource();
    const FUpdateTextureRegion2D* Region = new FUpdateTextureRegion2D(0, 0, 0, 0, params._width, params._height);
    Texture->UpdateTextureRegions(0, 1, Region, 4 * params._width, 4, GbaFrameBuffers[ControllerIndex].GetData());
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

    bool bLaunchDetached = true;
    bool bLaunchHidden = false;
    bool bLaunchReallyHidden = false;

    uint32 OutProcessID = 0;
    uint32 PriorityModifier = 0;

    DolphinProcHandle = FWindowsPlatformProcess::CreateProc(
        *DolphinBinaryPath,
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

void UDolphinInstance::RequestCreateSaveState(FString SaveName)
{
    static const FString ProjectContentDirectory = FPaths::ConvertRelativePathToFull(FPaths::ProjectContentDir());
    const FString FilePath = FPaths::Combine(ProjectContentDirectory, "SaveStates/", SaveName);

    CREATE_TO_INSTANCE_DATA(CreateSaveState, ipcData, data)
    data->_filePathNoExtension = std::string(TCHAR_TO_UTF8(*FilePath));
    ipcSendToInstance(ipcData);
}

void UDolphinInstance::RequestLoadSaveState(USavAsset* SavAsset)
{
    if (SavAsset == nullptr)
    {
        OnInstanceCommandCompleteEvent.Broadcast(this, NextCommandId++);
        return;
    }

    const FString FilePath = SavAsset->Path;

    CREATE_TO_INSTANCE_DATA(LoadSaveState, ipcData, data)
    data->_filePath = std::string(TCHAR_TO_UTF8(*FilePath));
    ipcSendToInstance(ipcData);
}

void UDolphinInstance::RequestPause()
{
    bIsPaused = true;

    CREATE_TO_INSTANCE_DATA(PauseEmulation, ipcData, data)
    ipcSendToInstance(ipcData);
}

void UDolphinInstance::RequestResume()
{
    bIsPaused = false;

    CREATE_TO_INSTANCE_DATA(ResumeEmulation, ipcData, data)
    ipcSendToInstance(ipcData);
}

bool UDolphinInstance::IsPaused() const
{
    return bIsPaused;
}

void UDolphinInstance::RequestStartRecording(bool Unpause, bool RecordControllers[4])
{
    bIsRecordingInput = true;

    CREATE_TO_INSTANCE_DATA(StartRecordingInput, ipcData, data);
    data->_unpauseInstance = Unpause;
    data->_recordControllers[0] = RecordControllers[0];
    data->_recordControllers[1] = RecordControllers[1];
    data->_recordControllers[2] = RecordControllers[2];
    data->_recordControllers[3] = RecordControllers[3];
    ipcSendToInstance(ipcData);
}

void UDolphinInstance::RequestStopRecording()
{
    bIsRecordingInput = false;

    CREATE_TO_INSTANCE_DATA(StopRecordingInput, ipcData, data)
    ipcSendToInstance(ipcData);
}

bool UDolphinInstance::IsRecording() const
{
    return bIsRecordingInput;
}

FFrameInputs UDolphinInstance::GetControllerState(int32 Index) const
{
    return ControllerStates[FMath::Clamp(Index, 0, 3)];
}

void UDolphinInstance::SetControllerStateOverride(FFrameInputs ControllerState, int32 Index)
{
    ControllerStateOverrides[FMath::Clamp(Index, 0, 3)] = ControllerState;
}

void UDolphinInstance::SetShouldUseHardwareController(bool bInShouldUseHardwareController)
{
    bShouldUseHardwareController = bInShouldUseHardwareController;
}

bool UDolphinInstance::GetShouldUseHardwareController() const
{
    return bShouldUseHardwareController;
}

int64 UDolphinInstance::GetWindowIdentifier() const
{
    return WindowIdentifier;
}

void UDolphinInstance::RequestPlayInputTable(UDataTable* FrameInputsTable[4])
{
    if (FrameInputsTable == nullptr)
    {
        OnInstanceCommandCompleteEvent.Broadcast(this, NextCommandId++);
        return;
    }

    TArray<FFrameInputs*> FrameInputs[4];
    TArray<FFrameInputs> FrameInputsValue[4];
    FString ContextString = TEXT("PlayInputs");

    for (int32 Index = 0; Index < 4; Index++)
    {
        if (FrameInputsTable[Index] != nullptr)
        {
            FrameInputsTable[Index]->GetAllRows(ContextString, FrameInputs[Index]);

            for (const FFrameInputs* Next : FrameInputs[Index])
            {
                if (Next)
                {
                    FrameInputsValue[Index].Add(*Next);
                }
            }
        }
    }

    RequestPlayInputs(FrameInputsValue);
}

void UDolphinInstance::RequestPlayInputs(const TArray<FFrameInputs> FrameInputs[4])
{
    CREATE_TO_INSTANCE_DATA(PlayInputs, ipcData, data)

    for (int32 Index = 0; Index < 4; Index++)
    {
        for (const FFrameInputs Next : FrameInputs[Index])
        {
            data->_inputRecording[Index].PushNext(FFrameInputs::ToDolphinControllerState(Next));
        }
    }

    ipcSendToInstance(ipcData);
}

void UDolphinInstance::RequestFrameAdvance(int32 NumberOfFrames)
{
    CREATE_TO_INSTANCE_DATA(FrameAdvance, ipcData, data)
    data->_numFrames = NumberOfFrames;
    ipcSendToInstance(ipcData);
}

void UDolphinInstance::RequestSetTasInput(FFrameInputs FrameInputs[4])
{
    CREATE_TO_INSTANCE_DATA(SetTasInput, ipcData, data)
    data->_tasInputStates[0] = FFrameInputs::ToDolphinControllerState(FrameInputs[0]);
    data->_tasInputStates[1] = FFrameInputs::ToDolphinControllerState(FrameInputs[1]);
    data->_tasInputStates[2] = FFrameInputs::ToDolphinControllerState(FrameInputs[2]);
    data->_tasInputStates[3] = FFrameInputs::ToDolphinControllerState(FrameInputs[3]);
    ipcSendToInstance(ipcData);
}

void UDolphinInstance::RequestFormatMemoryCard(EMemoryCardSlot MemoryCardSlot, EMemoryCardSize MemoryCardSize, EMemoryCardEncoding MemoryCardEncoding)
{
    CREATE_TO_INSTANCE_DATA(FormatMemoryCard, ipcData, data)
    data->_slot = (DolphinSlot)MemoryCardSlot;
    data->_encoding = (ToInstanceParams_FormatMemoryCard::CardEncoding)MemoryCardEncoding;
    data->_cardSize = (ToInstanceParams_FormatMemoryCard::CardSize)MemoryCardSize;
    ipcSendToInstance(ipcData);
}

void UDolphinInstance::RequestReadMemory(FDolphinUInt32 Address, const TArray<FDolphinInt32>& Offsets, int32 ByteCount)
{
    CREATE_TO_INSTANCE_DATA(ReadMemory, ipcData, data)
    data->_address = Address.Value;
    data->_pointerOffsets = ConvertPointerOffsets(Offsets);
    data->_numberOfBytes = ByteCount;
    ipcSendToInstance(ipcData);
}

void UDolphinInstance::RequestWriteMemory(FDolphinUInt32 Address, const TArray<FDolphinInt32>& Offsets, const TArray<FDolphinUInt8>& Bytes)
{
    // TODO
}

std::vector<int> UDolphinInstance::ConvertPointerOffsets(const TArray<FDolphinInt32>& Offsets)
{
    std::vector<int> PointerOffsets;

    for (const FDolphinInt32& Offset : Offsets)
    {
        PointerOffsets.push_back(Offset.Value);
    }

    return PointerOffsets;
}

void UDolphinInstance::RequestTerminate()
{
    CREATE_TO_INSTANCE_DATA(Terminate, ipcData, data)
    ipcData._call = DolphinInstanceIpcCall::DolphinInstance_Terminate;
    ipcSendToInstance(ipcData);

    UDolphinUnrealBlueprintLibrary::TerminateDolpinInstance(this);
}
