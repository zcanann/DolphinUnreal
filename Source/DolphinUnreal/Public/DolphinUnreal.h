// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Modules/ModuleManager.h"

class UDolphinInstance;

class FDolphinUnrealModule : public IModuleInterface
{
public:
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

	UDolphinInstance* CreateNewInstance();
	void TerminateInstance(UDolphinInstance* InDolphinInstance);
	void SetDefaultDolphinInstance(UDolphinInstance* InDefaultDolphinInstance);
	UDolphinInstance* GetDefaultDolphinInstance() const;
	TArray<UDolphinInstance*> GetDolphinInstances() const;

	static const FName ModuleName;

private:
	UPROPERTY()
	TArray<UDolphinInstance*> DolphinInstances;

	UPROPERTY()
	UDolphinInstance* DefaultDolphinInstance = nullptr;
};
