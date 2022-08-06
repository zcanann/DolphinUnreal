#pragma once

#include "UObject/Object.h"

// Prevent errors in cereal that propagate to Unreal where __GNUC__ is not defined
#define __GNUC__ (false)
#include "dolphin-ipc/DolphinIpcHandlerBase.h"

#include "DataTypes/DolphinDataTypes.h"
#include "FrameInputs.h"

#include "DolphinInstance.generated.h"

class UIsoAsset;
class USavAsset;
struct FProcHandle;

UCLASS(BlueprintType)
class UDolphinInstance : public UObject, public DolphinIpcHandlerBase, public FTickableGameObject
{
	GENERATED_UCLASS_BODY()

public:
	UFUNCTION()
	void Initialize(UIsoAsset* InIsoAsset, bool bStartPaused, bool bBeginRecording);
	virtual ~UDolphinInstance();

	void PausePIE(const bool bIsSimulating);
	void EndPIE(const bool bIsSimulating);

	bool IsTickable() const override { return true; }
	bool IsTickableInEditor() const override { return true; }
	bool IsTickableWhenPaused() const override { return true; }
	TStatId GetStatId() const override { return TStatId(); }
	void Tick(float DeltaTime) override;

	DECLARE_MULTICAST_DELEGATE_TwoParams(FOnInstanceCommandComplete, UDolphinInstance*, uint64);
	FOnInstanceCommandComplete OnInstanceCommandCompleteEvent;

	DECLARE_MULTICAST_DELEGATE_TwoParams(FOnSaveStateCreated, UDolphinInstance*, USavAsset*);
	FOnSaveStateCreated OnInstanceSaveStateCreated;

	DECLARE_MULTICAST_DELEGATE_TwoParams(FOnMemoryReadInt8, UDolphinInstance*, FDolphinInt8);
	FOnMemoryReadInt8 OnInstanceMemoryReadInt8;

	DECLARE_MULTICAST_DELEGATE_TwoParams(FOnMemoryReadInt16, UDolphinInstance*, FDolphinInt16);
	FOnMemoryReadInt16 OnInstanceMemoryReadInt16;

	DECLARE_MULTICAST_DELEGATE_TwoParams(FOnMemoryReadInt32, UDolphinInstance*, FDolphinInt32);
	FOnMemoryReadInt32 OnInstanceMemoryReadInt32;

	DECLARE_MULTICAST_DELEGATE_TwoParams(FOnMemoryReadInt64, UDolphinInstance*, FDolphinInt64);
	FOnMemoryReadInt64 OnInstanceMemoryReadInt64;

	DECLARE_MULTICAST_DELEGATE_TwoParams(FOnMemoryReadUInt8, UDolphinInstance*, FDolphinUInt8);
	FOnMemoryReadUInt8 OnInstanceMemoryReadUInt8;

	DECLARE_MULTICAST_DELEGATE_TwoParams(FOnMemoryReadUInt16, UDolphinInstance*, FDolphinUInt16);
	FOnMemoryReadUInt16 OnInstanceMemoryReadUInt16;

	DECLARE_MULTICAST_DELEGATE_TwoParams(FOnMemoryReadUInt32, UDolphinInstance*, FDolphinUInt32);
	FOnMemoryReadUInt32 OnInstanceMemoryReadUInt32;

	DECLARE_MULTICAST_DELEGATE_TwoParams(FOnMemoryReadUInt64, UDolphinInstance*, FDolphinUInt64);
	FOnMemoryReadUInt64 OnInstanceMemoryReadUInt64;

	DECLARE_MULTICAST_DELEGATE_TwoParams(FOnMemoryReadFloat, UDolphinInstance*, FDolphinFloat);
	FOnMemoryReadFloat OnInstanceMemoryReadFloat;

	DECLARE_MULTICAST_DELEGATE_TwoParams(FOnMemoryReadDouble, UDolphinInstance*, FDolphinDouble);
	FOnMemoryReadDouble OnInstanceMemoryReadDouble;

	DECLARE_MULTICAST_DELEGATE_TwoParams(FOnMemoryReadString, UDolphinInstance*, FString);
	FOnMemoryReadString OnInstanceMemoryReadString;

	DECLARE_MULTICAST_DELEGATE_TwoParams(FOnMemoryReadArrayOfBytes, UDolphinInstance*, TArray<FDolphinInt8>);
	FOnMemoryReadArrayOfBytes OnInstanceMemoryReadArrayOfBytes;

	DECLARE_MULTICAST_DELEGATE_TwoParams(FOnMemoryReadUnsignedArrayOfBytes, UDolphinInstance*, TArray<FDolphinUInt8>);
	FOnMemoryReadUnsignedArrayOfBytes OnInstanceMemoryReadUnsignedArrayOfBytes;
	
	void RequestCreateSaveState(FString SaveName);
	
	void RequestLoadSaveState(USavAsset* SavAsset);

	void RequestPause();

	void RequestResume();

	UFUNCTION(BlueprintPure)
	bool IsPaused() const;

	void RequestStartRecording();

	void RequestStopRecording();

	UFUNCTION(BlueprintPure)
	bool IsRecording() const;

	void RequestPlayInputTable(UDataTable* FrameInputsTable);

	void RequestPlayInputs(const TArray<FFrameInputs>& FrameInputs);

	void RequestFrameAdvance(int32 NumberOfFrames);

	void RequestFrameAdvanceWithInput(FFrameInputs FrameInputs, int32 NumberOfFrames = 1);

	void RequestFormatMemoryCard(EMemoryCardSlot MemoryCardSlot, EMemoryCardSize MemoryCardSize, EMemoryCardEncoding MemoryCardEncoding);

	void RequestTerminate();

	UFUNCTION()
	uint64 GetNextCommandId() const { return NextCommandId; }

protected:
	SERVER_FUNC_OVERRIDE(OnInstanceConnected)
	SERVER_FUNC_OVERRIDE(OnInstanceCommandCompleted)
	SERVER_FUNC_OVERRIDE(OnInstanceHeartbeatAcknowledged)
	SERVER_FUNC_OVERRIDE(OnInstanceLogOutput)
	SERVER_FUNC_OVERRIDE(OnInstanceTerminated)
	SERVER_FUNC_OVERRIDE(OnInstanceRecordingStopped)
	SERVER_FUNC_OVERRIDE(OnInstanceSaveStateCreated)
	SERVER_FUNC_OVERRIDE(OnInstanceMemoryCardFormatted)
	SERVER_FUNC_OVERRIDE(OnInstanceMemoryRead)
	SERVER_FUNC_OVERRIDE(OnInstanceMemoryWrite)

private:
	void LaunchInstance(UIsoAsset* InIsoAsset, bool bStartPaused, bool bBeginRecording);

	FString InstanceId;
	FProcHandle DolphinProcHandle;

	bool bIsRecordingInput = false;
	bool bIsPaused = false;
	uint64 NextCommandId = 0;
};
