#pragma once

#include "UObject/Object.h"

// Prevent errors in cereal that propagate to Unreal where __GNUC__ is not defined
#define __GNUC__ (false)
#include "dolphin-ipc/DolphinIpcHandlerBase.h"

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

	DECLARE_MULTICAST_DELEGATE_OneParam(FOnInstanceCommandComplete, UDolphinInstance*);
	FOnInstanceCommandComplete OnInstanceCommandCompleteEvent;

	DECLARE_MULTICAST_DELEGATE_TwoParams(FOnSaveStateCreated, UDolphinInstance*, USavAsset*);
	FOnSaveStateCreated OnInstanceSaveStateCreated;
	
	UFUNCTION()
	void RequestCreateSaveState(FString SaveName);
	
	UFUNCTION()
	void RequestLoadSaveState(USavAsset* SavAsset);

	UFUNCTION()
	void RequestPause();

	UFUNCTION()
	void RequestResume();

	UFUNCTION(BlueprintPure)
	bool IsPaused() const;

	UFUNCTION()
	void RequestStartRecording();

	UFUNCTION()
	void RequestStopRecording();

	UFUNCTION(BlueprintPure)
	bool IsRecording() const;

	UFUNCTION()
	void RequestPlayInputTable(UDataTable* FrameInputsTable);

	UFUNCTION()
	void RequestPlayInputs(const TArray<FFrameInputs>& FrameInputs);

	UFUNCTION()
	void RequestFrameAdvance(int32 NumberOfFrames);

	UFUNCTION()
	void RequestFrameAdvanceWithInput(int32 NumberOfFrames, FFrameInputs FrameInputs);

	UFUNCTION()
	void RequestTerminate();

protected:
	SERVER_FUNC_OVERRIDE(OnInstanceConnected)
	SERVER_FUNC_OVERRIDE(OnInstanceCommandCompleted)
	SERVER_FUNC_OVERRIDE(OnInstanceHeartbeatAcknowledged)
	SERVER_FUNC_OVERRIDE(OnInstanceLogOutput)
	SERVER_FUNC_OVERRIDE(OnInstanceTerminated)
	SERVER_FUNC_OVERRIDE(OnInstanceRecordingStopped)
	SERVER_FUNC_OVERRIDE(OnInstanceSaveStateCreated)
	SERVER_FUNC_OVERRIDE(OnInstanceMemoryCardFormatted)

private:
	void LaunchInstance(UIsoAsset* InIsoAsset, bool bStartPaused, bool bBeginRecording);

	FString InstanceId;
	FProcHandle DolphinProcHandle;

	bool bIsRecordingInput = false;
	bool bIsPaused = false;
};
