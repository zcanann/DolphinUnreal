#pragma once

#include "CoreMinimal.h"
#include "UObject/ObjectMacros.h"
#include "K2Node_BaseAsyncTask.h"

#include "K2Node_CreateDolphinInstance.generated.h"

UCLASS()
class UK2Node_CreateDolphinInstance : public UK2Node_BaseAsyncTask
{
	GENERATED_UCLASS_BODY()

	//~ Begin UEdGraphNode Interface
	virtual FText GetTooltipText() const override;
	virtual FText GetNodeTitle(ENodeTitleType::Type TitleType) const override;
	//~ End UEdGraphNode Interface

	//~ Begin UK2Node Interface
	virtual FText GetMenuCategory() const override;
	//~ End UK2Node Interface
};

class UIsoAsset;
class UDolphinInstance;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDolphinCreateInstanceMulticastDelegate, UDolphinInstance*, DolphinInstance);

UCLASS(meta = (HideThen))
class UK2Node_CreateDolphinInstanceProxy : public UObject
{
	GENERATED_UCLASS_BODY()

public:
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"))
	static UK2Node_CreateDolphinInstanceProxy* CreateProxyObjectForWait(bool bRegisterAsDefaultInstance, bool bStartPaused, bool bBeginRecording, UIsoAsset* IsoAsset);
	
	UPROPERTY(BlueprintAssignable)
	FDolphinCreateInstanceMulticastDelegate OnSuccess;

private:
	void OnInstanceReady(UDolphinInstance* InInstance, uint64 CommandId);
};