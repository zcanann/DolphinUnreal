// Copyright Epic Games, Inc. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "UObject/ObjectMacros.h"
#include "UObject/Object.h"
#include "UObject/ScriptMacros.h"

#include "K2Node_CreateDolphinInstanceProxy.generated.h"

class UIsoAsset;
class UDolphinInstance;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDolphinCreateMulticastDelegate, UDolphinInstance*, DolphinInstance);

UCLASS(MinimalAPI)
class UK2Node_CreateDolphinInstanceProxy : public UObject
{
	GENERATED_UCLASS_BODY()

public:
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"))
	static UK2Node_CreateDolphinInstanceProxy* CreateProxyObjectForWait(bool bRegisterAsDefaultInstance, bool bStartPaused, bool bBeginRecording, UIsoAsset* IsoAsset);
	
	UPROPERTY(BlueprintAssignable)
	FDolphinCreateMulticastDelegate OnSuccess;

	UPROPERTY(BlueprintAssignable)
	FDolphinCreateMulticastDelegate OnFail;

private:
	void OnInstanceReady(UDolphinInstance* InInstance);

	UPROPERTY()
	UDolphinInstance* Instance;
};
