// Copyright Epic Games, Inc. All Rights Reserved.

#include "DolphinUnreal.h"

#include "Core.h"
#include "Modules/ModuleManager.h"
#include "Interfaces/IPluginManager.h"

#include "DataTypes/DolphinDataTypesBlueprintLibrary.h"
#include "DolphinInstance.h"
#include "DolphinUnrealStyle.h"

#define LOCTEXT_NAMESPACE "FDolphinUnrealModule"

DEFINE_LOG_CATEGORY(Dolphin);

const FName FDolphinUnrealModule::ModuleName = FName("DolphinUnreal");

void FDolphinUnrealModule::StartupModule()
{
	FDolphinUnrealStyle::Register();
	UDolphinDataTypesBlueprintLibrary::AutoFavoriteCommonDolphinFunctions();
}

void FDolphinUnrealModule::ShutdownModule()
{
	FDolphinUnrealStyle::Unregister();
}

UDolphinInstance* FDolphinUnrealModule::CreateNewInstance()
{
	UDolphinInstance* Instance = NewObject<UDolphinInstance>();

	DolphinInstances.Add(Instance);

	Instance->AddToRoot();

	return Instance;
}

void FDolphinUnrealModule::TerminateInstance(UDolphinInstance* InDolphinInstance)
{
	if (InDolphinInstance != nullptr)
	{
		DolphinInstances.Remove(InDolphinInstance);
		InDolphinInstance->RemoveFromRoot();
		InDolphinInstance->RequestTerminate();
	}
}

void FDolphinUnrealModule::SetDefaultDolphinInstance(UDolphinInstance* InDefaultDolphinInstance)
{
	DefaultDolphinInstance = InDefaultDolphinInstance;
}

UDolphinInstance* FDolphinUnrealModule::GetDefaultDolphinInstance() const
{
	return DefaultDolphinInstance;
}

TArray<UDolphinInstance*> FDolphinUnrealModule::GetDolphinInstances() const
{
	return DolphinInstances;
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FDolphinUnrealModule, DolphinUnreal)
