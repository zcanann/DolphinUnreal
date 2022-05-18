#include "DolphinUnrealBlueprintLibrary.h"

#include "DolphinUnreal.h"

#include "DolphinInstance.h"

UDolphinUnrealBlueprintLibrary::UDolphinUnrealBlueprintLibrary(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
{

}

UDolphinInstance* UDolphinUnrealBlueprintLibrary::CreateDolphinInstance(bool bRegisterAsDefaultInstance, FDolphinGraphicsSettings InGraphicsSettings, FDolphinRuntimeSettings InRuntimeSettings)
{
    UDolphinInstance* Instance = NewObject<UDolphinInstance>();

    Instance->Initialize(InGraphicsSettings, InRuntimeSettings);

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

void UDolphinUnrealBlueprintLibrary::WaitFrames(int32 Frames, UDolphinInstance* DolphinInstance)
{

}

void UDolphinUnrealBlueprintLibrary::PressA(int32 Frames, UDolphinInstance* DolphinInstance)
{

}

void UDolphinUnrealBlueprintLibrary::PressB(int32 Frames, UDolphinInstance* DolphinInstance)
{

}

void UDolphinUnrealBlueprintLibrary::PressX(int32 Frames, UDolphinInstance* DolphinInstance)
{

}

void UDolphinUnrealBlueprintLibrary::PressY(int32 Frames, UDolphinInstance* DolphinInstance)
{

}

void UDolphinUnrealBlueprintLibrary::PressZ(int32 Frames, UDolphinInstance* DolphinInstance)
{

}

void UDolphinUnrealBlueprintLibrary::PressDPadLeft(int32 Frames, UDolphinInstance* DolphinInstance)
{

}

void UDolphinUnrealBlueprintLibrary::PressDPadRight(int32 Frames, UDolphinInstance* DolphinInstance)
{

}

void UDolphinUnrealBlueprintLibrary::PressDPadUp(int32 Frames, UDolphinInstance* DolphinInstance)
{

}

void UDolphinUnrealBlueprintLibrary::PressDPadDown(int32 Frames, UDolphinInstance* DolphinInstance)
{

}

void UDolphinUnrealBlueprintLibrary::PressR(bool bInIsPressed, uint8 InAnalogAmount, int32 Frames, UDolphinInstance* DolphinInstance)
{

}

void UDolphinUnrealBlueprintLibrary::PressL(bool bInIsPressed, uint8 InAnalogAmount, int32 Frames, UDolphinInstance* DolphinInstance)
{

}

void UDolphinUnrealBlueprintLibrary::AnalogStickX(uint8 AnalogAmount, int32 Frames, UDolphinInstance* DolphinInstance)
{

}

void UDolphinUnrealBlueprintLibrary::AnalogStickY(uint8 AnalogAmount, int32 Frames, UDolphinInstance* DolphinInstance)
{

}

void UDolphinUnrealBlueprintLibrary::CStickY(uint8 AnalogAmount, int32 Frames, UDolphinInstance* DolphinInstance)
{

}

void UDolphinUnrealBlueprintLibrary::CStickX(uint8 AnalogAmount, int32 Frames, UDolphinInstance* DolphinInstance)
{

}

