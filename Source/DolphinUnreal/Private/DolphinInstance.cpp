#include "DolphinInstance.h"

#include "AssetTypes/Iso/IsoAsset.h"
#include "AssetTypes/Sav/SavAsset.h"
#include "DataTables/InputTableImporter.h"
#include "DolphinUnreal.h"
#include "DolphinUnrealBlueprintLibrary.h"
#include "FrameInputs.h"

#include "dolphin-ipc/external/jpeg-compressor/jpgd.h"

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

void UDolphinInstance::Initialize(UIsoAsset* InIsoAsset)
{
    LaunchInstance(InIsoAsset);
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

UTexture2D* UDolphinInstance::GetGbaRender(int32 Index) const
{
    if (Index >= 0 && Index < 4)
    {
        return GbaRenders[Index];
    }

    return nullptr;
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
    OnInstanceMemoryWrite.Broadcast(this, params._success);
}

inline uint32_t ConvertGbaColors(uint32_t argb)
{
    // Convert 0xBBRRGGAA => 0xRRGGBBAA
    /*
    return
        ((argb & 0xFF000000) >> 16) |
        ((argb & 0x00FF0000) << 8) |
        ((argb & 0x0000FF00) << 8) |
        ((argb & 0x000000FF));*/

    // Not sure how to conver this. Default seems OKish.
    return argb;
}

SERVER_FUNC_BODY(UDolphinInstance, OnInstanceRenderGba, params)
{
    int32 ControllerIndex = params._controllerIndex;

    if (GbaRenders[ControllerIndex] == nullptr || GbaRenders[ControllerIndex]->GetSizeX() != params._width || GbaRenders[ControllerIndex]->GetSizeY() != params._height)
    {
        // PF_B8G8R8A8
        // PF_R8G8B8A8
        // PF_A8R8G8B8
        /*
             m_core_info.height, QImage::Format_ARGB32)
            .convertToFormat(QImage::Format_RGB32)
            .rgbSwapped();
         */
        GbaRenders[ControllerIndex] = UTexture2D::CreateTransient(params._width, params._height, PF_R8G8B8A8);
        GbaRenders[ControllerIndex]->UpdateResource();
        OnGbaTextureChanged.Broadcast(params._controllerIndex, GbaRenders[ControllerIndex]);
    }

    GbaFrameBuffers[ControllerIndex].SetNum(params._width* params._height * 4);

    if (params._compressed)
    {
        static const int RequiredComps = 4; // 1 (grayscale), 3 (RGB), or 4 (RGBA)
        int actualComps = 4;
        int width = params._width;
        int height = params._height;

        // TODO: Optimization, in theory we should know how large the buffer is, and pass that in by ref, and avoid reallocating it unless the video buffer size changes
        unsigned char* decompressedData = jpgd::decompress_jpeg_image_from_memory(reinterpret_cast<const unsigned char*>(params._frameBuffer.data()),
            int(params._frameBuffer.size() * sizeof(unsigned int)), &width, &height, &actualComps, 3);

        if (decompressedData != nullptr)
        {
            FMemory::Memcpy(GbaFrameBuffers[ControllerIndex].GetData(), decompressedData, params._frameBuffer.size() * 4);
            free(decompressedData);
        }
    }
    else
    {
        FMemory::Memcpy(GbaFrameBuffers[ControllerIndex].GetData(), params._frameBuffer.data(), params._frameBuffer.size() * 4);

        for (int index = 0; index < params._frameBuffer.size(); index++)
        {
            unsigned int* DataPtr = (unsigned int*)GbaFrameBuffers[ControllerIndex].GetData();
            DataPtr[index] = ConvertGbaColors(params._frameBuffer[index]);
        }
    }

    TextureRegions[ControllerIndex].Width = params._width;
    TextureRegions[ControllerIndex].Height = params._height;
    GbaRenders[ControllerIndex]->UpdateTextureRegions(0, 1, &TextureRegions[ControllerIndex], 4 * params._width, 4, GbaFrameBuffers[ControllerIndex].GetData());
}

void UDolphinInstance::LaunchInstance(UIsoAsset* InIsoAsset)
{
    static FString PluginContentDirectory = FPaths::ConvertRelativePathToFull(IPluginManager::Get().FindPlugin(TEXT("DolphinUnreal"))->GetContentDir());
    static FString ProjectContentDirectory = FPaths::ConvertRelativePathToFull(FPaths::ProjectContentDir());

    InstanceId = FGuid::NewGuid().ToString();
    FString GamePath = InIsoAsset->Path;
    FString UserPath = FPaths::Combine(ProjectContentDirectory, "Dolphin");
    FString StartPausedFlag = TEXT("-z");
    FString Params = FString::Format(TEXT("\"{0}\" -u \"{1}\" -p win32 -i {2} {3}"), { GamePath, UserPath, InstanceId, StartPausedFlag });

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

void UDolphinInstance::RequestCreateSaveState(FString SaveName, bool bSaveMemoryCards)
{
    static const FString ProjectContentDirectory = FPaths::ConvertRelativePathToFull(FPaths::ProjectContentDir());
    const FString FilePath = FPaths::Combine(ProjectContentDirectory, "SaveStates/", SaveName);

    CREATE_TO_INSTANCE_DATA(CreateSaveState, ipcData, data);
    data->_filePathNoExtension = std::string(TCHAR_TO_UTF8(*FilePath));
    data->_saveMemoryCards = bSaveMemoryCards;
    ipcSendToInstance(ipcData);
}

void UDolphinInstance::RequestLoadSaveState(USavAsset* SavAsset, UGciAsset* OptionalMemoryCardSlotAAsset, UGciAsset* OptionalMemoryCardSlotBAsset)
{
    if (SavAsset == nullptr)
    {
        OnInstanceCommandCompleteEvent.Broadcast(this, NextCommandId++);
        return;
    }

    const FString SaveFilePath = SavAsset->Path;
    const FString MemoryCardAFilePath = OptionalMemoryCardSlotAAsset == nullptr ? TEXT("") : OptionalMemoryCardSlotAAsset->Path;
    const FString MemoryCardBFilePath = OptionalMemoryCardSlotBAsset == nullptr ? TEXT("") : OptionalMemoryCardSlotBAsset->Path;

    CREATE_TO_INSTANCE_DATA(LoadSaveState, ipcData, data);
    data->_saveFilePath = std::string(TCHAR_TO_UTF8(*SaveFilePath));
    data->_optionalMemoryCardDataAPath = std::string(TCHAR_TO_UTF8(*MemoryCardAFilePath));
    data->_optionalMemoryCardDataBPath = std::string(TCHAR_TO_UTF8(*MemoryCardBFilePath));
    ipcSendToInstance(ipcData);
}

void UDolphinInstance::RequestLoadMemoryCardData(UGciAsset* OptionalMemoryCardSlotAAsset, UGciAsset* OptionalMemoryCardSlotBAsset)
{
    const FString MemoryCardAFilePath = OptionalMemoryCardSlotAAsset == nullptr ? TEXT("") : OptionalMemoryCardSlotAAsset->Path;
    const FString MemoryCardBFilePath = OptionalMemoryCardSlotBAsset == nullptr ? TEXT("") : OptionalMemoryCardSlotBAsset->Path;

    CREATE_TO_INSTANCE_DATA(LoadMemoryCardData, ipcData, data);
    data->_optionalMemoryCardDataAPath = std::string(TCHAR_TO_UTF8(*MemoryCardAFilePath));
    data->_optionalMemoryCardDataBPath = std::string(TCHAR_TO_UTF8(*MemoryCardBFilePath));
    ipcSendToInstance(ipcData);
}

void UDolphinInstance::RequestPause()
{
    bIsPaused = true;

    CREATE_TO_INSTANCE_DATA(PauseEmulation, ipcData, data);
    ipcSendToInstance(ipcData);
}

void UDolphinInstance::RequestResume()
{
    bIsPaused = false;

    CREATE_TO_INSTANCE_DATA(ResumeEmulation, ipcData, data);
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

    CREATE_TO_INSTANCE_DATA(StopRecordingInput, ipcData, data);
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
    CREATE_TO_INSTANCE_DATA(PlayInputs, ipcData, data);

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
    CREATE_TO_INSTANCE_DATA(FrameAdvance, ipcData, data);
    data->_numFrames = NumberOfFrames;
    ipcSendToInstance(ipcData);
}

void UDolphinInstance::RequestSetTasInput(FFrameInputs FrameInputs[4])
{
    CREATE_TO_INSTANCE_DATA(SetTasInput, ipcData, data);
    data->_tasInputStates[0] = FFrameInputs::ToDolphinControllerState(FrameInputs[0]);
    data->_tasInputStates[1] = FFrameInputs::ToDolphinControllerState(FrameInputs[1]);
    data->_tasInputStates[2] = FFrameInputs::ToDolphinControllerState(FrameInputs[2]);
    data->_tasInputStates[3] = FFrameInputs::ToDolphinControllerState(FrameInputs[3]);
    ipcSendToInstance(ipcData);
}

void UDolphinInstance::RequestFormatMemoryCard(EMemoryCardSlot MemoryCardSlot, EMemoryCardSize MemoryCardSize, EMemoryCardEncoding MemoryCardEncoding)
{
    CREATE_TO_INSTANCE_DATA(FormatMemoryCard, ipcData, data);
    data->_slot = (DolphinSlot)MemoryCardSlot;
    data->_encoding = (CardEncoding)MemoryCardEncoding;
    data->_cardSize = (CardSize)MemoryCardSize;
    ipcSendToInstance(ipcData);
}

void UDolphinInstance::RequestReadMemory(FDolphinUInt32 Address, const TArray<FDolphinInt32>& Offsets, int32 ByteCount)
{
    CREATE_TO_INSTANCE_DATA(ReadMemory, ipcData, data);
    data->_address = Address.Value;
    data->_pointerOffsets = ConvertPointerOffsets(Offsets);
    data->_numberOfBytes = ByteCount;
    ipcSendToInstance(ipcData);
}

void UDolphinInstance::RequestWriteMemory(FDolphinUInt32 Address, const TArray<FDolphinInt32>& Offsets, const TArray<FDolphinUInt8>& Bytes)
{
    std::vector<unsigned char> Data;

    for (const FDolphinUInt8& Next : Bytes)
    {
        Data.push_back(Next.Value);
    }

    CREATE_TO_INSTANCE_DATA(WriteMemory, ipcData, data);
    data->_address = Address.Value;
    data->_pointerOffsets = ConvertPointerOffsets(Offsets);
    data->_bytes = Data;
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
    CREATE_TO_INSTANCE_DATA(Terminate, ipcData, data);
    ipcData._call = DolphinInstanceIpcCall::DolphinInstance_Terminate;
    ipcSendToInstance(ipcData);

    UDolphinUnrealBlueprintLibrary::TerminateDolpinInstance(this);
}

#pragma optimize("", on)
