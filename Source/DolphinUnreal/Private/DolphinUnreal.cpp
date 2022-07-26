// Copyright Epic Games, Inc. All Rights Reserved.

#include "DolphinUnreal.h"
#include "Core.h"
#include "Modules/ModuleManager.h"
#include "Interfaces/IPluginManager.h"

#define LOCTEXT_NAMESPACE "FDolphinUnrealModule"

const FName FDolphinUnrealModule::Name = FName("DolphinUnreal");

void FDolphinUnrealModule::StartupModule()
{
	FEditorDelegates::PostPIEStarted.AddRaw(this, &FDolphinUnrealModule::PostPIEStarted);
}

void FDolphinUnrealModule::ShutdownModule()
{
}

void FDolphinUnrealModule::SetDefaultDolphinInstance(UDolphinInstance* InDefaultDolphinInstance)
{
	DefaultDolphinInstance = InDefaultDolphinInstance;
}

UDolphinInstance* FDolphinUnrealModule::GetDefaultDolphinInstance() const
{
	return DefaultDolphinInstance;
}

void FDolphinUnrealModule::PostPIEStarted(const bool bIsSimulating)
{
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FDolphinUnrealModule, DolphinUnreal)
