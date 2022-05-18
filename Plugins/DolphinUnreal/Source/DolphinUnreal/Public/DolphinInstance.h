#pragma once

#include "UObject/Object.h"
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

class DolphinIPC;

UCLASS(BlueprintType)
class UDolphinInstance : public UObject
{
	GENERATED_UCLASS_BODY()

public:
	UFUNCTION()
	void Initialize(FDolphinGraphicsSettings InGraphicsSettings, FDolphinRuntimeSettings InRuntimeSettings);
	~UDolphinInstance();

private:
	FString MakeInstanceId() const;

	FString InstanceId;
	DolphinIPC* DolphinIPCInstance = nullptr;
	FProcHandle DolphinProcess;
};
