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
	UFUNCTION() // UFUNCTION(BlueprintCallable, meta = (DisplayName = "Create Dolphin Instance", Keywords = "Create Initialize New Dolphin Instance"), Category = "Dolphin")
	static UDolphinInstance* CreateDolphinInstance(
		bool bRegisterAsDefaultInstance = false,
		bool bStartPaused = true,
		bool bBeginRecording = false,
		UIsoAsset* IsoAsset = nullptr
	);

	UFUNCTION(BlueprintPure, meta = (DisplayName = "Get Default Dolphin Instance", Keywords = "Get Default Dolphin Instance"), Category = "Dolphin")
	static UDolphinInstance* GetDefaultDolphinInstance();

	UFUNCTION()
	static UDolphinInstance* GetDolphinInstanceOrDefault(UDolphinInstance* DolphinInstance);

	UFUNCTION(BlueprintPure, meta = (DisplayName = "Get All Dolphin Instances", Keywords = "Get All Dolphin Instances"), Category = "Dolphin")
	static TArray<UDolphinInstance*> GetDolphinInstances();
};
