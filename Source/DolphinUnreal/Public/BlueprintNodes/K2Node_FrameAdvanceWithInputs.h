#pragma once

#include "CoreMinimal.h"
#include "UObject/ObjectMacros.h"
#include "K2Node_BaseAsyncTask.h"

#include "K2Node_FrameAdvanceWithInputs.generated.h"

UCLASS()
class UK2Node_FrameAdvanceWithInputs : public UK2Node_BaseAsyncTask
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

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDolphinFrameAdvanceWithInputsMulticastDelegate, UDolphinInstance*, DolphinInstance);

UCLASS(meta = (HideThen))
class UK2Node_FrameAdvanceWithInputsProxy : public UObject
{
	GENERATED_UCLASS_BODY()

public:
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"))
	static UK2Node_FrameAdvanceWithInputsProxy* CreateProxyObjectForWait(UDolphinInstance* DolphinInstance, FFrameInputs FrameInputs, int32 NumberOfFrames = 1);
	
	UPROPERTY(BlueprintAssignable)
	FDolphinFrameAdvanceWithInputsMulticastDelegate OnSuccess;

private:
	void OnInstanceReady(UDolphinInstance* InInstance, uint64 CommandId);
};