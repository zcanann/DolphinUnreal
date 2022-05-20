#pragma once

#include "UObject/Object.h"

#include "dolphin-ipc/DolphinIpcHandlerBase.h"

#include "DolphinInstance.generated.h"

USTRUCT(BlueprintType)
struct FDolphinGraphicsSettings
{
	GENERATED_BODY()

public:
	FDolphinGraphicsSettings() { }

	bool bIsHeadless = false;
};

USTRUCT(BlueprintType)
struct FDolphinRuntimeSettings
{
	GENERATED_BODY()

public:
	FDolphinRuntimeSettings() { }

	float Speed = 1.0f;
};

class FMonitoredProcess;
struct FProcHandle;

UCLASS(BlueprintType)
class UDolphinInstance : public UObject, public DolphinIpcHandlerBase, public FTickableGameObject
{
	GENERATED_UCLASS_BODY()

public:
	UFUNCTION()
	void Initialize(FDolphinGraphicsSettings InGraphicsSettings, FDolphinRuntimeSettings InRuntimeSettings);
	virtual ~UDolphinInstance();

	bool IsTickable() const override { return true; }
	bool IsTickableInEditor() const override { return true; }
	bool IsTickableWhenPaused() const override { return true; }
	TStatId GetStatId() const override { return TStatId(); }
	void Tick(float DeltaTime) override;

	void WaitFrames(int32 Frames);

protected:
	virtual void DolphinServer_OnInstanceConnected(const ToServerParams_OnInstanceConnected& onInstanceConnectedParams) override;
	virtual void DolphinServer_OnInstanceTerminated(const ToServerParams_OnInstanceTerminated& onInstanceTerminatedParams) override;

private:
	void LaunchInstance();

	FString InstanceId;
	TSharedPtr<FMonitoredProcess> DolphinProcess = nullptr;
	FProcHandle DolphinProcHandle;
};
