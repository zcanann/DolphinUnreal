#pragma once

#include "CoreMinimal.h"
#include "UObject/ObjectMacros.h"
#include "K2Node_BaseAsyncTask.h"

#include "K2Node_LoadSaveState.generated.h"

UCLASS()
class UK2Node_LoadSaveState : public UK2Node_BaseAsyncTask
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

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDolphinLoadSaveStateMulticastDelegate, UDolphinInstance*, DolphinInstance);

UCLASS(meta = (HideThen))
class UK2Node_LoadSaveStateProxy : public UObject
{
	GENERATED_UCLASS_BODY()

public:
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"))
	static UK2Node_LoadSaveStateProxy* CreateProxyObjectForWait(FString SaveName, UDolphinInstance* DolphinInstance);
	
	UPROPERTY(BlueprintAssignable)
	FDolphinLoadSaveStateMulticastDelegate OnSuccess;

private:
	void OnInstanceReady(UDolphinInstance* InInstance);
};