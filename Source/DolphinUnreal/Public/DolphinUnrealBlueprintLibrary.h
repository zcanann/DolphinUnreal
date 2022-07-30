#pragma once

#include "DolphinInstance.h"
#include "Kismet/BlueprintFunctionLibrary.h"

#include "DolphinUnrealBlueprintLibrary.generated.h"

class UIsoAsset;
class UDataTable;

UCLASS()
class UDolphinUnrealBlueprintLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_UCLASS_BODY()

	UFUNCTION() // UFUNCTION(BlueprintCallable, meta = (DisplayName = "Create Dolphin Instance", Keywords = "Create Initialize New Dolphin Instance"), Category = "Dolphin")
	static UDolphinInstance* CreateDolphinInstance(
		bool bRegisterAsDefaultInstance = false,
		bool bStartPaused = true,
		bool bBeginRecording = false,
		UIsoAsset* IsoAsset = nullptr
	);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Terminate Dolphin Instance", Keywords = "Terminate Dolphin Instance"), Category = "Dolphin")
	static void TerminateDolphinInstance(UDolphinInstance* DolphinInstance);

	UFUNCTION(BlueprintPure, meta = (DisplayName = "Get Default Dolphin Instance", Keywords = "Get Default Dolphin Instance"), Category = "Dolphin")
	static UDolphinInstance* GetDefaultDolphinInstance();

	UFUNCTION()
	static UDolphinInstance* GetDolphinInstanceOrDefault(UDolphinInstance* DolphinInstance);

	UFUNCTION(BlueprintPure, meta = (DisplayName = "Get All Dolphin Instances", Keywords = "Get All Dolphin Instances"), Category = "Dolphin")
	static TArray<UDolphinInstance*> GetDolphinInstances();

	UFUNCTION() // UFUNCTION(BlueprintCallable, meta = (DisplayName = "Resume Emulation", Keywords = "Resume Continue Unpause Play Emulation"), Category = "Dolphin")
	static void ResumeEmulation(UDolphinInstance* DolphinInstance = nullptr);

	UFUNCTION() // UFUNCTION(BlueprintCallable, meta = (DisplayName = "Pause Emulation", Keywords = "Pause Stop Emulation"), Category = "Dolphin")
	static void PauseEmulation(UDolphinInstance* DolphinInstance = nullptr);

	UFUNCTION() // UFUNCTION(BlueprintCallable, meta = (DisplayName = "Load Save State", Keywords = "Load Save State"), Category = "Dolphin")
	static void LoadSaveState(FString SaveName, UDolphinInstance* DolphinInstance);

	UFUNCTION() // UFUNCTION(BlueprintCallable, meta = (DisplayName = "Create Save State", Keywords = "Create Save State"), Category = "Dolphin")
	static void CreateSaveState(FString SaveName, UDolphinInstance* DolphinInstance);

	UFUNCTION() // UFUNCTION(BlueprintCallable, meta = (DisplayName = "Start Recording Input Table", Keywords = "Start Begin Recording Input Table Frames"), Category = "Dolphin")
	static void StartRecording(UDolphinInstance* DolphinInstance = nullptr);

	UFUNCTION() // UFUNCTION(BlueprintCallable, meta = (DisplayName = "Stop Recording Input Table", Keywords = "Stop End Finish Recording Input Table Frames"), Category = "Dolphin")
	static void StopRecording(UDolphinInstance* DolphinInstance = nullptr);

	UFUNCTION() // UFUNCTION(BlueprintCallable, meta = (DisplayName = "Play Input Table", Keywords = "Play Playback Recording Input Table Frames"), Category = "Dolphin")
	static void PlayInputTable(UDataTable* FrameInputsTable, UDolphinInstance* DolphinInstance = nullptr);

	UFUNCTION() // UFUNCTION(BlueprintCallable, meta = (DisplayName = "Terminate Dolphin Instance", Keywords = "Terminate Stop Destroy Dolphin Instance"), Category = "Dolphin")
	static void Terminate(UDolphinInstance* DolphinInstance = nullptr);

	/*
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Wait Frames", Keywords = "Wait Skip Frames"), Category = "Dolphin")
	static void WaitFrames(int32 Frames = 1, UDolphinInstance* DolphinInstance = nullptr);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Press A", Keywords = "Press Input A"), Category = "Dolphin")
	static void PressA(int32 Frames = 1, UDolphinInstance* DolphinInstance = nullptr);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Press B", Keywords = "Press Input B"), Category = "Dolphin")
	static void PressB(int32 Frames = 1, UDolphinInstance* DolphinInstance = nullptr);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Press X", Keywords = "Press Input X"), Category = "Dolphin")
	static void PressX(int32 Frames = 1, UDolphinInstance* DolphinInstance = nullptr);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Press Y", Keywords = "Press Input Y"), Category = "Dolphin")
	static void PressY(int32 Frames = 1, UDolphinInstance* DolphinInstance = nullptr);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Press Z", Keywords = "Press Input Z"), Category = "Dolphin")
	static void PressZ(int32 Frames = 1, UDolphinInstance* DolphinInstance = nullptr);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Press D-Pad Left", Keywords = "Press Input D-Pad Left"), Category = "Dolphin")
	static void PressDPadLeft(int32 Frames = 1, UDolphinInstance* DolphinInstance = nullptr);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Press D-Pad Right", Keywords = "Press Input D-Pad Right"), Category = "Dolphin")
	static void PressDPadRight(int32 Frames = 1, UDolphinInstance* DolphinInstance = nullptr);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Press D-Pad Up", Keywords = "Press Input D-Pad Up"), Category = "Dolphin")
	static void PressDPadUp(int32 Frames = 1, UDolphinInstance* DolphinInstance = nullptr);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Press D-Pad Down", Keywords = "Press Input D-Pad Down"), Category = "Dolphin")
	static void PressDPadDown(int32 Frames = 1, UDolphinInstance* DolphinInstance = nullptr);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Press R", Keywords = "Press Input R"), Category = "Dolphin")
	static void PressR(bool bIsPressed = true, uint8 AnalogAmount = 255, int32 Frames = 1, UDolphinInstance* DolphinInstance = nullptr);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Press L", Keywords = "Press Input L"), Category = "Dolphin")
	static void PressL(bool bIsPressed = true, uint8 AnalogAmount = 255, int32 Frames = 1, UDolphinInstance* DolphinInstance = nullptr);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Hold Analog Stick X", Keywords = "Hold Analog Input Stick X"), Category = "Dolphin")
	static void AnalogStickX(uint8 AnalogAmount = 255, int32 Frames = 1, UDolphinInstance* DolphinInstance = nullptr);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Hold Analog Stick Y", Keywords = "Hold Analog Input Stick Y"), Category = "Dolphin")
	static void AnalogStickY(uint8 AnalogAmount = 255, int32 Frames = 1, UDolphinInstance* DolphinInstance = nullptr);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Hold C-Stick Y", Keywords = "Hold Analog Input C-Stick Y"), Category = "Dolphin")
	static void CStickY(uint8 AnalogAmount = 255, int32 Frames = 1, UDolphinInstance* DolphinInstance = nullptr);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Hold C-Stick X", Keywords = "Hold Analog Input C-Stick X"), Category = "Dolphin")
	static void CStickX(uint8 AnalogAmount = 255, int32 Frames = 1, UDolphinInstance* DolphinInstance = nullptr);*/
};
