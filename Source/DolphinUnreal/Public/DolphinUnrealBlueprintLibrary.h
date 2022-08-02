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

	/// <summary>
	/// Functions below are no longer exposed in blueprints in favor of adding custom K2Nodes with delay as their own classes
	/// </summary>

	UFUNCTION()
	static void ResumeEmulation(UDolphinInstance* DolphinInstance = nullptr);

	UFUNCTION()
	static void PauseEmulation(UDolphinInstance* DolphinInstance = nullptr);

	UFUNCTION()
	static void CreateSaveState(FString SaveName, UDolphinInstance* DolphinInstance);

	UFUNCTION()
	static void LoadSaveState(USavAsset* SavAsset, UDolphinInstance* DolphinInstance);

	UFUNCTION()
	static void StartRecording(UDolphinInstance* DolphinInstance = nullptr);

	UFUNCTION()
	static void StopRecording(UDolphinInstance* DolphinInstance = nullptr);

	UFUNCTION()
	static void PlayInputTable(UDataTable* FrameInputsTable, UDolphinInstance* DolphinInstance = nullptr);

	UFUNCTION()
	static void PlayInputs(TArray<FFrameInputs> FrameInputs, UDolphinInstance* DolphinInstance = nullptr);

	UFUNCTION()
	static void FrameAdvance(int32 NumberOfFrames, UDolphinInstance* DolphinInstance = nullptr);

	UFUNCTION()
	static void FrameAdvanceWithInput(FFrameInputs FrameInputs, int32 NumberOfFrames = 1, UDolphinInstance* DolphinInstance = nullptr);

	UFUNCTION()
	static void Terminate(UDolphinInstance* DolphinInstance = nullptr);
};
