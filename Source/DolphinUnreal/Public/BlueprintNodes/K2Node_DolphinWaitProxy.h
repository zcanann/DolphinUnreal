// Copyright Epic Games, Inc. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "UObject/ObjectMacros.h"
#include "UObject/Object.h"
#include "UObject/ScriptMacros.h"
#include "K2Node_DolphinWaitProxy.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnDolphinReady, UDolphinInstance*, DolphinInstance);
DECLARE_MULTICAST_DELEGATE_OneParam(FOnDolphinWaitComplete, UDolphinInstance*);

class UDolphinInstance;

UCLASS(MinimalAPI)
class UK2Node_DolphinWaitProxy : public UObject
{
	GENERATED_UCLASS_BODY()

	UPROPERTY(BlueprintAssignable)
	FOnDolphinReady OnComplete;

	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"))
	static UK2Node_DolphinWaitProxy* CreateProxyObjectForWait(UDolphinInstance* DolphinInstance);

public:
	//~ Begin UObject Interface
	virtual void BeginDestroy() override;
	//~ End UObject Interface

private:
	void WaitForDolphin(UDolphinInstance* DolphinInstance);
	void OnDolphinReady(UDolphinInstance* DolphinInstance);
	void RemoveDelegate();

private:
	FOnDolphinWaitComplete WaitForDolphinDelegate;
	FDelegateHandle WaitForDolphinDelegateHandle;
};
