#include "DolphinUnrealBlueprintLibrary.h"

#include "DolphinUnreal.h"

#include "DolphinInstance.h"

UDolphinUnrealBlueprintLibrary::UDolphinUnrealBlueprintLibrary(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
{

}

UDolphinInstance* UDolphinUnrealBlueprintLibrary::CreateDolphinInstance(bool bRegisterAsDefaultInstance, UIsoAsset* IsoAsset, FDolphinGraphicsSettings GraphicsSettings, FDolphinRuntimeSettings RuntimeSettings)
{
    UDolphinInstance* Instance = NewObject<UDolphinInstance>();

    Instance->Initialize(IsoAsset, GraphicsSettings, RuntimeSettings);

    if (bRegisterAsDefaultInstance)
    {
        FDolphinUnrealModule& DolphinUnreal = FModuleManager::GetModuleChecked<FDolphinUnrealModule>(FDolphinUnrealModule::Name);

        DolphinUnreal.SetDefaultDolphinInstance(Instance);
    }

    return Instance;
}

UDolphinInstance* UDolphinUnrealBlueprintLibrary::GetDefaultDolphinInstance()
{
    FDolphinUnrealModule& DolphinUnreal = FModuleManager::GetModuleChecked<FDolphinUnrealModule>(FDolphinUnrealModule::Name);

    UDolphinInstance* Instance =  DolphinUnreal.GetDefaultDolphinInstance();

    return Instance;
}

void UDolphinUnrealBlueprintLibrary::LoadSaveState()
{

}

void UDolphinUnrealBlueprintLibrary::CreateSaveState()
{

}

void UDolphinUnrealBlueprintLibrary::PlayInputs(UDataTable* FrameInputs, UDolphinInstance* DolphinInstance)
{
    DolphinInstance = DolphinInstance ? DolphinInstance : GetDefaultDolphinInstance();
}

void UDolphinUnrealBlueprintLibrary::WaitFrames(int32 Frames, UDolphinInstance* DolphinInstance)
{
    DolphinInstance = DolphinInstance ? DolphinInstance : GetDefaultDolphinInstance();
}

void UDolphinUnrealBlueprintLibrary::PressA(int32 Frames, UDolphinInstance* DolphinInstance)
{
    DolphinInstance = DolphinInstance ? DolphinInstance : GetDefaultDolphinInstance();
}

void UDolphinUnrealBlueprintLibrary::PressB(int32 Frames, UDolphinInstance* DolphinInstance)
{
    DolphinInstance = DolphinInstance ? DolphinInstance : GetDefaultDolphinInstance();
}

void UDolphinUnrealBlueprintLibrary::PressX(int32 Frames, UDolphinInstance* DolphinInstance)
{
    DolphinInstance = DolphinInstance ? DolphinInstance : GetDefaultDolphinInstance();
}

void UDolphinUnrealBlueprintLibrary::PressY(int32 Frames, UDolphinInstance* DolphinInstance)
{
    DolphinInstance = DolphinInstance ? DolphinInstance : GetDefaultDolphinInstance();
}

void UDolphinUnrealBlueprintLibrary::PressZ(int32 Frames, UDolphinInstance* DolphinInstance)
{
    DolphinInstance = DolphinInstance ? DolphinInstance : GetDefaultDolphinInstance();
}

void UDolphinUnrealBlueprintLibrary::PressDPadLeft(int32 Frames, UDolphinInstance* DolphinInstance)
{
    DolphinInstance = DolphinInstance ? DolphinInstance : GetDefaultDolphinInstance();
}

void UDolphinUnrealBlueprintLibrary::PressDPadRight(int32 Frames, UDolphinInstance* DolphinInstance)
{
    DolphinInstance = DolphinInstance ? DolphinInstance : GetDefaultDolphinInstance();
}

void UDolphinUnrealBlueprintLibrary::PressDPadUp(int32 Frames, UDolphinInstance* DolphinInstance)
{
    DolphinInstance = DolphinInstance ? DolphinInstance : GetDefaultDolphinInstance();
}

void UDolphinUnrealBlueprintLibrary::PressDPadDown(int32 Frames, UDolphinInstance* DolphinInstance)
{
    DolphinInstance = DolphinInstance ? DolphinInstance : GetDefaultDolphinInstance();
}

void UDolphinUnrealBlueprintLibrary::PressR(bool bInIsPressed, uint8 InAnalogAmount, int32 Frames, UDolphinInstance* DolphinInstance)
{
    DolphinInstance = DolphinInstance ? DolphinInstance : GetDefaultDolphinInstance();
}

void UDolphinUnrealBlueprintLibrary::PressL(bool bInIsPressed, uint8 InAnalogAmount, int32 Frames, UDolphinInstance* DolphinInstance)
{
    DolphinInstance = DolphinInstance ? DolphinInstance : GetDefaultDolphinInstance();
}

void UDolphinUnrealBlueprintLibrary::AnalogStickX(uint8 AnalogAmount, int32 Frames, UDolphinInstance* DolphinInstance)
{
    DolphinInstance = DolphinInstance ? DolphinInstance : GetDefaultDolphinInstance();
}

void UDolphinUnrealBlueprintLibrary::AnalogStickY(uint8 AnalogAmount, int32 Frames, UDolphinInstance* DolphinInstance)
{
    DolphinInstance = DolphinInstance ? DolphinInstance : GetDefaultDolphinInstance();
}

void UDolphinUnrealBlueprintLibrary::CStickY(uint8 AnalogAmount, int32 Frames, UDolphinInstance* DolphinInstance)
{
    DolphinInstance = DolphinInstance ? DolphinInstance : GetDefaultDolphinInstance();
}

void UDolphinUnrealBlueprintLibrary::CStickX(uint8 AnalogAmount, int32 Frames, UDolphinInstance* DolphinInstance)
{
    DolphinInstance = DolphinInstance ? DolphinInstance : GetDefaultDolphinInstance();
}

