#include "DolphinUnrealBlueprintLibrary.h"

#include "DolphinUnreal.h"

#include "DolphinInstance.h"

UDolphinUnrealBlueprintLibrary::UDolphinUnrealBlueprintLibrary(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
{
}

UDolphinInstance* UDolphinUnrealBlueprintLibrary::CreateDolphinInstance(bool bRegisterAsDefaultInstance, bool bStartPaused, bool bBeginRecording, UIsoAsset* IsoAsset)
{
    FDolphinUnrealModule& DolphinUnreal = FModuleManager::GetModuleChecked<FDolphinUnrealModule>(FDolphinUnrealModule::ModuleName);
    UDolphinInstance* Instance = DolphinUnreal.CreateNewInstance();

    Instance->Initialize(IsoAsset, bStartPaused, bBeginRecording);

    if (bRegisterAsDefaultInstance)
    {
        DolphinUnreal.SetDefaultDolphinInstance(Instance);
    }

    return Instance;
}

UDolphinInstance* UDolphinUnrealBlueprintLibrary::GetDefaultDolphinInstance()
{
    FDolphinUnrealModule& DolphinUnreal = FModuleManager::GetModuleChecked<FDolphinUnrealModule>(FDolphinUnrealModule::ModuleName);
    UDolphinInstance* Instance =  DolphinUnreal.GetDefaultDolphinInstance();

    return Instance;
}

UDolphinInstance* UDolphinUnrealBlueprintLibrary::GetDolphinInstanceOrDefault(UDolphinInstance* DolphinInstance)
{
    return DolphinInstance ? DolphinInstance : GetDefaultDolphinInstance();
}

TArray<UDolphinInstance*> UDolphinUnrealBlueprintLibrary::GetDolphinInstances()
{
    FDolphinUnrealModule& DolphinUnreal = FModuleManager::GetModuleChecked<FDolphinUnrealModule>(FDolphinUnrealModule::ModuleName);
    TArray<UDolphinInstance*> Instances = DolphinUnreal.GetDolphinInstances();

    return Instances;
}

void UDolphinUnrealBlueprintLibrary::ResumeEmulation(UDolphinInstance* DolphinInstance)
{
    DolphinInstance = UDolphinUnrealBlueprintLibrary::GetDolphinInstanceOrDefault(DolphinInstance);

    if (DolphinInstance != nullptr)
    {
        DolphinInstance->RequestResume();
    }
}

void UDolphinUnrealBlueprintLibrary::PauseEmulation(UDolphinInstance* DolphinInstance)
{
    DolphinInstance = UDolphinUnrealBlueprintLibrary::GetDolphinInstanceOrDefault(DolphinInstance);

    DolphinInstance = UDolphinUnrealBlueprintLibrary::GetDolphinInstanceOrDefault(DolphinInstance);

    if (DolphinInstance != nullptr)
    {
        DolphinInstance->RequestPause();
    }
}

void UDolphinUnrealBlueprintLibrary::LoadSaveState(USavAsset* SavAsset, UDolphinInstance* DolphinInstance)
{
    DolphinInstance = UDolphinUnrealBlueprintLibrary::GetDolphinInstanceOrDefault(DolphinInstance);

    if (DolphinInstance != nullptr)
    {
        DolphinInstance->RequestLoadSaveState(SavAsset);
    }
}

void UDolphinUnrealBlueprintLibrary::CreateSaveState(FString SaveName, UDolphinInstance* DolphinInstance)
{
    DolphinInstance = UDolphinUnrealBlueprintLibrary::GetDolphinInstanceOrDefault(DolphinInstance);

    if (DolphinInstance != nullptr)
    {
        DolphinInstance->RequestCreateSaveState(SaveName);
    }
}

void UDolphinUnrealBlueprintLibrary::StartRecording(UDolphinInstance* DolphinInstance)
{
    DolphinInstance = UDolphinUnrealBlueprintLibrary::GetDolphinInstanceOrDefault(DolphinInstance);

    if (DolphinInstance != nullptr)
    {
        DolphinInstance->RequestStartRecording();
    }
}

void UDolphinUnrealBlueprintLibrary::StopRecording(UDolphinInstance* DolphinInstance)
{
    DolphinInstance = UDolphinUnrealBlueprintLibrary::GetDolphinInstanceOrDefault(DolphinInstance);

    if (DolphinInstance != nullptr)
    {
        DolphinInstance->RequestStopRecording();
    }
}

void UDolphinUnrealBlueprintLibrary::PlayInputTable(UDataTable* FrameInputsTable, UDolphinInstance* DolphinInstance)
{
    DolphinInstance = UDolphinUnrealBlueprintLibrary::GetDolphinInstanceOrDefault(DolphinInstance);

    if (DolphinInstance != nullptr)
    {
        DolphinInstance->RequestPlayInputTable(FrameInputsTable);
    }
}

void UDolphinUnrealBlueprintLibrary::PlayInputs(TArray<FFrameInputs> FrameInputs, UDolphinInstance* DolphinInstance)
{
    DolphinInstance = UDolphinUnrealBlueprintLibrary::GetDolphinInstanceOrDefault(DolphinInstance);

    if (DolphinInstance != nullptr)
    {
        DolphinInstance->RequestPlayInputs(FrameInputs);
    }
}

void UDolphinUnrealBlueprintLibrary::FrameAdvance(int32 NumberOfFrames, UDolphinInstance* DolphinInstance)
{
    DolphinInstance = UDolphinUnrealBlueprintLibrary::GetDolphinInstanceOrDefault(DolphinInstance);

    if (DolphinInstance != nullptr)
    {
        DolphinInstance->RequestFrameAdvance(NumberOfFrames);
    }
}

void UDolphinUnrealBlueprintLibrary::FrameAdvanceWithInput(int32 NumberOfFrames, FFrameInputs FrameInputs, UDolphinInstance* DolphinInstance)
{
    DolphinInstance = UDolphinUnrealBlueprintLibrary::GetDolphinInstanceOrDefault(DolphinInstance);

    if (DolphinInstance != nullptr)
    {
        DolphinInstance->RequestFrameAdvanceWithInput(NumberOfFrames, FrameInputs);
    }
}

void UDolphinUnrealBlueprintLibrary::Terminate(UDolphinInstance* DolphinInstance)
{
    DolphinInstance = UDolphinUnrealBlueprintLibrary::GetDolphinInstanceOrDefault(DolphinInstance);

    if (DolphinInstance != nullptr)
    {
        DolphinInstance->RequestTerminate();
    }
}
