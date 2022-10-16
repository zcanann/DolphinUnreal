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
class UTexture2D;
struct FProcHandle;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnGbaTextureChanged, int32, GbaIndex, UTexture2D*, NewTexture);

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
	DECLARE_MULTICAST_DELEGATE_TwoParams(FOnMemoryReadArrayOfUBytes, UDolphinInstance*, TArray<FDolphinUInt8>);
	FOnMemoryReadArrayOfUBytes OnInstanceMemoryRead;

	UPROPERTY(BlueprintAssignable, Category = Gba)
	FOnGbaTextureChanged OnGbaTextureChanged;

	UFUNCTION(BlueprintPure)
	bool IsPaused() const;

	UFUNCTION(BlueprintPure)
	bool IsRecording() const;

	UFUNCTION(BlueprintPure)
	FFrameInputs GetControllerState(int32 Index) const;

	UFUNCTION(BlueprintCallable)
	void SetControllerStateOverride(FFrameInputs ControllerState, int32 Index);

	UFUNCTION(BlueprintCallable)
	void SetShouldUseHardwareController(bool bInShouldUseHardwareController);

	UFUNCTION(BlueprintPure)
	bool GetShouldUseHardwareController() const;

	UFUNCTION(BlueprintPure)
	int64 GetWindowIdentifier() const;

	void RequestCreateSaveState(FString SaveName);
	void RequestLoadSaveState(USavAsset* SavAsset);
	void RequestPause();
	void RequestResume();
	void RequestStartRecording(bool Unpause, bool RecordControllers[4]);
	void RequestStopRecording();
	void RequestPlayInputTable(UDataTable* FrameInputsTable[4]);
	void RequestPlayInputs(const TArray<FFrameInputs> FrameInputs[4]);
	void RequestFrameAdvance(int32 NumberOfFrames);
	void RequestSetTasInput(FFrameInputs FrameInputs[4]);
	void RequestFormatMemoryCard(EMemoryCardSlot MemoryCardSlot, EMemoryCardSize MemoryCardSize, EMemoryCardEncoding MemoryCardEncoding);
	void RequestReadMemory(FDolphinUInt32 Address, const TArray<FDolphinInt32>& Offsets, int32 ByteCount);
	void RequestWriteMemory(FDolphinUInt32 Address, const TArray<FDolphinInt32>& Offsets, const TArray<FDolphinUInt8>& Bytes);
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
	SERVER_FUNC_OVERRIDE(OnInstanceRenderGba)

	UFUNCTION(BlueprintPure)
	UTexture2D* GetGbaRender(int32 Index) const;

private:
	void LaunchInstance(UIsoAsset* InIsoAsset, bool bStartPaused, bool bBeginRecording);
	std::vector<int> ConvertPointerOffsets(const TArray<FDolphinInt32>& Offsets);

	FString InstanceId;
	FProcHandle DolphinProcHandle;
	int64 WindowIdentifier = 0;

	bool bIsRecordingInput = false;
	bool bIsPaused = false;
	bool bShouldUseHardwareController = false;
	uint64 NextCommandId = 0;

	UPROPERTY()
	UTexture2D* GbaRenders[4];

	FFrameInputs ControllerStates[4];
	FFrameInputs ControllerStateOverrides[4];
	TArray<uint8> GbaFrameBuffers[4];
	FUpdateTextureRegion2D TextureRegions[4];
};
