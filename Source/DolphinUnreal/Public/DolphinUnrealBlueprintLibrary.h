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

	UFUNCTION()
	static UDolphinInstance* GetDolphinInstanceOrDefault(UDolphinInstance* DolphinInstance);

	UFUNCTION()
	static void TerminateDolpinInstance(UDolphinInstance* DolphinInstance);

	UFUNCTION()
	static void TrackDolpinInstance(UDolphinInstance* DolphinInstance);

	UFUNCTION()
	static void UntrackDolpinInstance(UDolphinInstance* DolphinInstance);

	UFUNCTION(BlueprintPure, meta = (DisplayName = "Get Default Dolphin Instance", Keywords = "Get Default Dolphin Instance"), Category = "Dolphin")
	static UDolphinInstance* GetDefaultDolphinInstance();

	UFUNCTION(BlueprintPure, meta = (DisplayName = "Get All Dolphin Instances", Keywords = "Get All Dolphin Instances"), Category = "Dolphin")
	static TArray<UDolphinInstance*> GetDolphinInstances();
};
