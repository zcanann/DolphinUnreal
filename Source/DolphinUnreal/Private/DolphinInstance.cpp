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
    CREATE_TO_INSTANCE_DATA(Heartbeat, ipcData, data)
    ipcSendToInstance(ipcData);
}

SERVER_FUNC_BODY(UDolphinInstance, OnInstanceConnected, params)
{
    if (GEngine)
    {
        GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Dolphin instance connected"));
    }
}

SERVER_FUNC_BODY(UDolphinInstance, OnInstanceCommandCompleted, params)
{
    OnInstanceCommandCompleteEvent.Broadcast(this, NextCommandId++);
}

SERVER_FUNC_BODY(UDolphinInstance, OnInstanceHeartbeatAcknowledged, params)
{
    bIsRecordingInput = params._isRecording;
    bIsPaused = params._isPaused;
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

    InputTable->RowStruct = FFrameInputs::StaticStruct();

    // TODO: This is slow and takes too much memory. Better to not to add the rows to the data table at all, and append each row to the CSV iteratively.
    for (const DolphinControllerState& Next : params._inputStates)
    {
        FFrameInputs FrameInput = FFrameInputs::FromDolphinControllerState(Next);
        InputTable->AddRow(FName(FGuid::NewGuid().ToString()), FrameInput);
    }

    FInputTableImporter::ImportInputTableAsAsset(*InputTable);
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
    switch (params._dataType)
    {
        case DolphinDataType::Int8:
        {
            OnInstanceMemoryReadInt8.Broadcast(this, FDolphinInt8(params._dolphinValue._valueInt8));
            break;
        }
        case DolphinDataType::UInt8:
        {
            OnInstanceMemoryReadUInt8.Broadcast(this, FDolphinUInt8(params._dolphinValue._valueUInt8));
            break;
        }
        case DolphinDataType::Int16:
        {
            OnInstanceMemoryReadInt16.Broadcast(this, FDolphinInt16(params._dolphinValue._valueInt16));
            break;
        }
        case DolphinDataType::UInt16:
        {
            OnInstanceMemoryReadUInt16.Broadcast(this, FDolphinUInt16(params._dolphinValue._valueUInt16));
            break;
        }
        case DolphinDataType::Int32:
        {
            OnInstanceMemoryReadInt32.Broadcast(this, FDolphinInt32(params._dolphinValue._valueInt32));
            break;
        }
        case DolphinDataType::UInt32:
        {
            OnInstanceMemoryReadUInt32.Broadcast(this, FDolphinUInt32(params._dolphinValue._valueUInt32));
            break;
        }
        case DolphinDataType::Int64:
        {
            OnInstanceMemoryReadInt64.Broadcast(this, FDolphinInt64(params._dolphinValue._valueInt64));
            break;
        }
        case DolphinDataType::UInt64:
        {
            OnInstanceMemoryReadUInt64.Broadcast(this, FDolphinUInt64(params._dolphinValue._valueInt64));
            break;
        }
        case DolphinDataType::Float:
        {
            OnInstanceMemoryReadFloat.Broadcast(this, FDolphinFloat(params._dolphinValue._valueFloat));
            break;
        }
        case DolphinDataType::Double:
        {
            OnInstanceMemoryReadDouble.Broadcast(this, FDolphinDouble(params._dolphinValue._valueDouble));
            break;
        }
        case DolphinDataType::String:
        {
            OnInstanceMemoryReadString.Broadcast(this, FString(params._dolphinValue._valueString.c_str()));
            break;
        }
        case DolphinDataType::ArrayOfBytes:
        {
            TArray<FDolphinInt8> ArrayOfBytes;
            for (signed char Next : params._dolphinValue._valueArrayOfBytes)
            {
                ArrayOfBytes.Add(FDolphinInt8(Next));
            }
            OnInstanceMemoryReadArrayOfBytes.Broadcast(this, ArrayOfBytes);
            break;
        }
        case DolphinDataType::ArrayOfUBytes:
        {
            TArray<FDolphinUInt8> ArrayOfUBytes;
            for (signed char Next : params._dolphinValue._valueArrayOfUBytes)
            {
                ArrayOfUBytes.Add(FDolphinUInt8(Next));
            }
            OnInstanceMemoryReadArrayOfUBytes.Broadcast(this, ArrayOfUBytes);
            break;
        }
    }
}

SERVER_FUNC_BODY(UDolphinInstance, OnInstanceMemoryWrite, params)
{
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

    /*
    #include "Windows/AllowWindowsPlatformTypes.h"
    #include <shellapi.h>
    #include "Windows/HideWindowsPlatformTypes.h"
    */
    /*ShellExecute(NULL, TEXT("open"), *DolphinBinaryPath, *Params, *OptionalWorkingDirectory, SW_SHOWDEFAULT);*/
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

void UDolphinInstance::RequestStartRecording()
{
    bIsRecordingInput = true;

    CREATE_TO_INSTANCE_DATA(StartRecordingInput, ipcData, data)
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

void UDolphinInstance::RequestPlayInputTable(UDataTable* FrameInputsTable)
{
    if (FrameInputsTable == nullptr)
    {
        OnInstanceCommandCompleteEvent.Broadcast(this, NextCommandId++);
        return;
    }

    TArray<FFrameInputs*> FrameInputs;
    FString ContextString = TEXT("PlayInputs");

    FrameInputsTable->GetAllRows(ContextString, FrameInputs);

    TArray<FFrameInputs> FrameInputsValue;
    for (const FFrameInputs* Next : FrameInputs)
    {
        if (Next)
        {
            FrameInputsValue.Add(*Next);
        }
    }
    RequestPlayInputs(FrameInputsValue);
}

void UDolphinInstance::RequestPlayInputs(const TArray<FFrameInputs>& FrameInputs)
{
    std::vector<DolphinControllerState> InputStates;
    for (const FFrameInputs Next : FrameInputs)
    {
        InputStates.push_back(FFrameInputs::ToDolphinControllerState(Next));
    }

    CREATE_TO_INSTANCE_DATA(PlayInputs, ipcData, data)
    data->_inputStates = InputStates;
    ipcSendToInstance(ipcData);
}

void UDolphinInstance::RequestFrameAdvance(int32 NumberOfFrames)
{
    CREATE_TO_INSTANCE_DATA(FrameAdvance, ipcData, data)
    data->_numFrames = NumberOfFrames;
    ipcSendToInstance(ipcData);
}

void UDolphinInstance::RequestFrameAdvanceWithInput(FFrameInputs FrameInputs, int32 NumberOfFrames)
{
    CREATE_TO_INSTANCE_DATA(FrameAdvanceWithInput, ipcData, data)
    data->_numFrames = NumberOfFrames;
    data->_inputState = FFrameInputs::ToDolphinControllerState(FrameInputs);
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

void UDolphinInstance::RequestReadInt8(FDolphinUInt32 Address, TArray<FDolphinInt32> Offsets)
{
    CREATE_TO_INSTANCE_DATA(ReadMemory, ipcData, data)
    data->_dataType = DolphinDataType::Int8;
    data->_address = Address.Value;
    data->_pointerOffsets = ConvertPointerOffsets(Offsets);
    ipcSendToInstance(ipcData);
}

void UDolphinInstance::RequestReadInt16(FDolphinUInt32 Address, TArray<FDolphinInt32> Offsets)
{
    CREATE_TO_INSTANCE_DATA(ReadMemory, ipcData, data)
    data->_dataType = DolphinDataType::Int16;
    data->_address = Address.Value;
    data->_pointerOffsets = ConvertPointerOffsets(Offsets);
    ipcSendToInstance(ipcData);
}

void UDolphinInstance::RequestReadInt32(FDolphinUInt32 Address, TArray<FDolphinInt32> Offsets)
{
    CREATE_TO_INSTANCE_DATA(ReadMemory, ipcData, data)
    data->_dataType = DolphinDataType::Int32;
    data->_address = Address.Value;
    data->_pointerOffsets = ConvertPointerOffsets(Offsets);
    ipcSendToInstance(ipcData);
}

void UDolphinInstance::RequestReadInt64(FDolphinUInt32 Address, TArray<FDolphinInt32> Offsets)
{
    CREATE_TO_INSTANCE_DATA(ReadMemory, ipcData, data)
    data->_dataType = DolphinDataType::Int64;
    data->_address = Address.Value;
    data->_pointerOffsets = ConvertPointerOffsets(Offsets);
    ipcSendToInstance(ipcData);
}

void UDolphinInstance::RequestReadUInt8(FDolphinUInt32 Address, TArray<FDolphinInt32> Offsets)
{
    CREATE_TO_INSTANCE_DATA(ReadMemory, ipcData, data)
    data->_dataType = DolphinDataType::UInt8;
    data->_address = Address.Value;
    data->_pointerOffsets = ConvertPointerOffsets(Offsets);
    ipcSendToInstance(ipcData);
}

void UDolphinInstance::RequestReadUInt16(FDolphinUInt32 Address, TArray<FDolphinInt32> Offsets)
{
    CREATE_TO_INSTANCE_DATA(ReadMemory, ipcData, data)
    data->_dataType = DolphinDataType::UInt16;
    data->_address = Address.Value;
    data->_pointerOffsets = ConvertPointerOffsets(Offsets);
    ipcSendToInstance(ipcData);
}

void UDolphinInstance::RequestReadUInt32(FDolphinUInt32 Address, TArray<FDolphinInt32> Offsets)
{
    CREATE_TO_INSTANCE_DATA(ReadMemory, ipcData, data)
    data->_dataType = DolphinDataType::UInt32;
    data->_address = Address.Value;
    data->_pointerOffsets = ConvertPointerOffsets(Offsets);
    ipcSendToInstance(ipcData);
}

void UDolphinInstance::RequestReadUInt64(FDolphinUInt32 Address, TArray<FDolphinInt32> Offsets)
{
    CREATE_TO_INSTANCE_DATA(ReadMemory, ipcData, data)
    data->_dataType = DolphinDataType::UInt64;
    data->_address = Address.Value;
    data->_pointerOffsets = ConvertPointerOffsets(Offsets);
    ipcSendToInstance(ipcData);
}

void UDolphinInstance::RequestReadFloat(FDolphinUInt32 Address, TArray<FDolphinInt32> Offsets)
{
    CREATE_TO_INSTANCE_DATA(ReadMemory, ipcData, data)
    data->_dataType = DolphinDataType::Float;
    data->_address = Address.Value;
    data->_pointerOffsets = ConvertPointerOffsets(Offsets);
    ipcSendToInstance(ipcData);
}

void UDolphinInstance::RequestReadDouble(FDolphinUInt32 Address, TArray<FDolphinInt32> Offsets)
{
    CREATE_TO_INSTANCE_DATA(ReadMemory, ipcData, data)
    data->_dataType = DolphinDataType::Double;
    data->_address = Address.Value;
    data->_pointerOffsets = ConvertPointerOffsets(Offsets);
    ipcSendToInstance(ipcData);
}

void UDolphinInstance::RequestReadString(FDolphinUInt32 Address, TArray<FDolphinInt32> Offsets, int32 StringLength)
{
    CREATE_TO_INSTANCE_DATA(ReadMemory, ipcData, data)
    data->_dataType = DolphinDataType::String;
    data->_address = Address.Value;
    data->_pointerOffsets = ConvertPointerOffsets(Offsets);
    data->_stringOrVectorLength = StringLength;
    ipcSendToInstance(ipcData);
}

void UDolphinInstance::RequestReadArrayOfBytes(FDolphinUInt32 Address, TArray<FDolphinInt32> Offsets, int32 ByteCount)
{
    CREATE_TO_INSTANCE_DATA(ReadMemory, ipcData, data)
    data->_dataType = DolphinDataType::ArrayOfBytes;
    data->_address = Address.Value;
    data->_pointerOffsets = ConvertPointerOffsets(Offsets);
    data->_stringOrVectorLength = ByteCount;
    ipcSendToInstance(ipcData);
}

void UDolphinInstance::RequestReadArrayOfUBytes(FDolphinUInt32 Address, TArray<FDolphinInt32> Offsets, int32 ByteCount)
{
    CREATE_TO_INSTANCE_DATA(ReadMemory, ipcData, data)
    data->_dataType = DolphinDataType::ArrayOfUBytes;
    data->_address = Address.Value;
    data->_pointerOffsets = ConvertPointerOffsets(Offsets);
    data->_stringOrVectorLength = ByteCount;
    ipcSendToInstance(ipcData);
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

    ConditionalBeginDestroy();
}

#pragma optimize("", on)
