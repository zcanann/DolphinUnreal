#pragma once

#include "K2Node_BaseAsyncTask.h"

#include "CoreMinimal.h"
#include "UObject/ObjectMacros.h"

#include "K2Node_PlayInputs.generated.h"

UCLASS()
class UK2Node_PlayInputs : public UK2Node_BaseAsyncTask
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

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDolphinPlayInputsMulticastDelegate, UDolphinInstance*, DolphinInstance);

UCLASS(meta = (HideThen))
class UK2Node_PlayInputsProxy : public UObject
{
	GENERATED_UCLASS_BODY()

public:
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", AutoCreateRefTerm = "FrameInputsController0,FrameInputsController1,FrameInputsController2,FrameInputsController3"))
	static UK2Node_PlayInputsProxy* CreateProxyObjectForWait(UDolphinInstance* DolphinInstance, const TArray<FFrameInputs>& FrameInputsController0,
		const TArray<FFrameInputs>& FrameInputsController1, const TArray<FFrameInputs>& FrameInputsController2, const TArray<FFrameInputs>& FrameInputsController3);
	
	UPROPERTY(BlueprintAssignable)
	FDolphinPlayInputsMulticastDelegate OnSuccess;

private:
	void OnInstanceReady(UDolphinInstance* InInstance, uint64 CommandId);
};