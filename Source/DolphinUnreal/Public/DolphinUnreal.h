// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Modules/ModuleManager.h"

class UDolphinInstance;

class FDolphinUnrealModule : public IModuleInterface
{
public:
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

	void SetDefaultDolphinInstance(UDolphinInstance* InDefaultDolphinInstance);
	UDolphinInstance* GetDefaultDolphinInstance() const;

	static const FName Name;

private:
	UDolphinInstance* DefaultDolphinInstance = nullptr;
};
