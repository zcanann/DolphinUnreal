#pragma once

#include "DolphinInstance.h"
#include "FrameInputs.h"
#include "Kismet/BlueprintFunctionLibrary.h"

#include "DolphinUnrealBlueprintLibrary.generated.h"

class UIsoAsset;
class USavAsset;
class UDataTable;

UCLASS()
class UDolphinUnrealBlueprintLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_UCLASS_BODY()

public:
	UFUNCTION()
	static UDolphinInstance* CreateDolphinInstance(bool bRegisterAsDefaultInstance = false);

	UFUNCTION(BlueprintPure, meta = (DisplayName = "Get Default Dolphin Instance", Keywords = "Get Default Dolphin Instance"), Category = "Dolphin")
	static UDolphinInstance* GetDefaultDolphinInstance();

	UFUNCTION()
	static UDolphinInstance* GetDolphinInstanceOrDefault(UDolphinInstance* DolphinInstance);

	UFUNCTION(BlueprintPure, meta = (DisplayName = "Get All Dolphin Instances", Keywords = "Get All Dolphin Instances"), Category = "Dolphin")
	static TArray<UDolphinInstance*> GetDolphinInstances();
};
