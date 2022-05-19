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
class UDolphinInstance : public UObject, public DolphinIpcHandlerBase
{
	GENERATED_UCLASS_BODY()

public:
	UFUNCTION()
	void Initialize(FDolphinGraphicsSettings InGraphicsSettings, FDolphinRuntimeSettings InRuntimeSettings);
	virtual ~UDolphinInstance();

protected:
	virtual void DolphinServer_OnInstanceConnected(const DolphinParams_OnInstanceConnected& onInstanceConnectedParams) override;
	virtual void DolphinServer_OnInstanceTerminated(const DolphinParams_OnInstanceTerminated& onInstanceTerminatedParams) override;

private:
	void LaunchInstance();
	FString MakeInstanceId() const;

	FString InstanceId;
	TSharedPtr<FMonitoredProcess> DolphinProcess = nullptr;
	FProcHandle DolphinProcHandle;
};
