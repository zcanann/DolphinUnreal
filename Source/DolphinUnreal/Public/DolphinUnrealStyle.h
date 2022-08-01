// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Styling/ISlateStyle.h"
#include "Styling/SlateStyle.h"

class FDolphinUnrealStyle : public FSlateStyleSet
{
public:
	static FDolphinUnrealStyle& Get();

protected:
	friend class FDolphinUnrealModule;

	static void Register();
	static void Unregister();

private:
	FDolphinUnrealStyle();
};
