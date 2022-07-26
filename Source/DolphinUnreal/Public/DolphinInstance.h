#pragma once

#include "UObject/Object.h"

// Prevent errors in cereal that propagate to Unreal where __GNUC__ is not defined
#define __GNUC__ (false)
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
};

class UIsoAsset;
struct FProcHandle;

UCLASS(BlueprintType)
class UDolphinInstance : public UObject, public DolphinIpcHandlerBase, public FTickableGameObject
{
	GENERATED_UCLASS_BODY()

public:
	UFUNCTION()
	void Initialize(UIsoAsset* InIsoAsset, const FDolphinGraphicsSettings& InGraphicsSettings, const FDolphinRuntimeSettings& InRuntimeSettings);
	virtual ~UDolphinInstance();

	void PausePIE(const bool bIsSimulating);

	bool IsTickable() const override { return true; }
	bool IsTickableInEditor() const override { return true; }
	bool IsTickableWhenPaused() const override { return true; }
	TStatId GetStatId() const override { return TStatId(); }
	void Tick(float DeltaTime) override;

	void WaitFrames(int32 Frames);

protected:
	virtual void DolphinServer_OnInstanceConnected(const ToServerParams_OnInstanceConnected& OnInstanceConnectedParams) override;
	virtual void DolphinServer_OnInstanceTerminated(const ToServerParams_OnInstanceTerminated& OnInstanceTerminatedParams) override;

private:
	void LaunchInstance(UIsoAsset* InIsoAsset, const FDolphinGraphicsSettings& InGraphicsSettings, const FDolphinRuntimeSettings& InRuntimeSettings);

	FString InstanceId;
	FProcHandle DolphinProcHandle;
};
