#pragma once

#include "CoreMinimal.h"
#include "K2Node_BaseAsyncTask.h"
#include "UObject/ObjectMacros.h"
#include "FrameInputs.h"

#include "K2Node_SetTasInput.generated.h"

UCLASS()
class UK2Node_SetTasInput : public UK2Node_BaseAsyncTask
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

class UDolphinInstance;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDolphinSetTasInputMulticastDelegate, UDolphinInstance*, DolphinInstance);

UCLASS(meta = (HideThen))
class UK2Node_SetTasInputProxy : public UObject
{
	GENERATED_UCLASS_BODY()

public:
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"))
	static UK2Node_SetTasInputProxy* CreateProxyObjectForWait(UDolphinInstance* DolphinInstance, FFrameInputs FrameInputsController0,
		FFrameInputs FrameInputsController1, FFrameInputs FrameInputsController2, FFrameInputs FrameInputsController3);
	
	UPROPERTY(BlueprintAssignable)
	FDolphinSetTasInputMulticastDelegate OnSuccess;

private:
	void OnInstanceReady(UDolphinInstance* InInstance, uint64 CommandId);
};