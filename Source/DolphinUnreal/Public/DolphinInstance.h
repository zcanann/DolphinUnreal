#pragma once

#include "UObject/Object.h"

// Prevent errors in cereal that propagate to Unreal where __GNUC__ is not defined
#define __GNUC__ (false)
#include "dolphin-ipc/DolphinIpcHandlerBase.h"

#include "DolphinInstance.generated.h"

class UIsoAsset;
struct FProcHandle;

UCLASS(BlueprintType)
class UDolphinInstance : public UObject, public DolphinIpcHandlerBase, public FTickableGameObject
{
	GENERATED_UCLASS_BODY()

public:
	UFUNCTION()
	void Initialize(UIsoAsset* InIsoAsset, bool bBeginRecording);
	virtual ~UDolphinInstance();

	void PausePIE(const bool bIsSimulating);
	void EndPIE(const bool bIsSimulating);

	bool IsTickable() const override { return true; }
	bool IsTickableInEditor() const override { return true; }
	bool IsTickableWhenPaused() const override { return true; }
	TStatId GetStatId() const override { return TStatId(); }
	void Tick(float DeltaTime) override;
	
	UFUNCTION(BlueprintCallable)
	void RequestLoadSaveState(FString SaveName);
	
	UFUNCTION(BlueprintCallable)
	void RequestCreateSaveState(FString SaveName);

	UFUNCTION(BlueprintCallable)
	void RequestPause();

	UFUNCTION(BlueprintCallable)
	void RequestUnpause();

	UFUNCTION(BlueprintPure)
	bool IsPaused() const;

	UFUNCTION(BlueprintCallable)
	void RequestStartRecording();

	UFUNCTION(BlueprintCallable)
	void RequestStopRecording();

	UFUNCTION(BlueprintPure)
	bool IsRecording() const;

	UFUNCTION(BlueprintCallable)
	void RequestPlayInputs(UDataTable* FrameInputsTable);

	UFUNCTION(BlueprintCallable)
	void Terminate();

protected:
	virtual void DolphinServer_OnInstanceConnected(const ToServerParams_OnInstanceConnected& OnInstanceConnectedParams) override;
	virtual void DolphinServer_OnInstanceHeartbeatAcknowledged(const ToServerParams_OnInstanceHeartbeatAcknowledged& onInstanceHeartbeatAcknowledgedParams) override;
	virtual void DolphinServer_OnInstanceTerminated(const ToServerParams_OnInstanceTerminated& OnInstanceTerminatedParams) override;
	virtual void DolphinServer_OnInstanceRecordingStopped(const ToServerParams_OnInstanceRecordingStopped& onInstanceRecordingStopped) override;

private:
	void LaunchInstance(UIsoAsset* InIsoAsset, bool bBeginRecording);

	FString InstanceId;

	bool bIsRecordingInput = false;
	bool bIsPaused = false;
};
