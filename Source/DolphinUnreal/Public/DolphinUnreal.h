// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Modules/ModuleManager.h"

DECLARE_LOG_CATEGORY_EXTERN(Dolphin, Log, All);

class UDolphinInstance;

class FDolphinUnrealModule : public IModuleInterface
{
public:
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

	UDolphinInstance* CreateNewInstance();
	void TerminateInstance(UDolphinInstance* InDolphinInstance);
	void TrackInstance(UDolphinInstance* InDolphinInstance);
	void UntrackInstance(UDolphinInstance* InDolphinInstance);
	void SetDefaultDolphinInstance(UDolphinInstance* InDefaultDolphinInstance);
	UDolphinInstance* GetDefaultDolphinInstance() const;
	TArray<UDolphinInstance*> GetDolphinInstances() const;

	static const FName ModuleName;

private:
	void RegisterQuickSettingsMenu();

	UPROPERTY()
	TArray<UDolphinInstance*> DolphinInstances;

	UPROPERTY()
	UDolphinInstance* DefaultDolphinInstance = nullptr;
};
