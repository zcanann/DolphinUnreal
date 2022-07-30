#pragma once

#include "CoreMinimal.h"
#include "UObject/ObjectMacros.h"
#include "K2Node_BaseAsyncTask.h"

#include "K2Node_StartRecording.generated.h"

UCLASS()
class UK2Node_StartRecording : public UK2Node_BaseAsyncTask
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

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDolphinStartRecordingMulticastDelegate, UDolphinInstance*, DolphinInstance);

UCLASS(MinimalAPI)
class UK2Node_StartRecordingProxy : public UObject
{
	GENERATED_UCLASS_BODY()

public:
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"))
	static UK2Node_StartRecordingProxy* CreateProxyObjectForWait(UDolphinInstance* DolphinInstance);
	
	UPROPERTY(BlueprintAssignable)
	FDolphinStartRecordingMulticastDelegate OnSuccess;

private:
	void OnInstanceReady(UDolphinInstance* InInstance);
};