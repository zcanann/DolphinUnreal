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
