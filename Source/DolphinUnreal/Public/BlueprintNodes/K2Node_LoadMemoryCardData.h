#pragma once

#include "CoreMinimal.h"
#include "UObject/ObjectMacros.h"
#include "K2Node_BaseAsyncTask.h"

#include "K2Node_LoadMemoryCardData.generated.h"

UCLASS()
class UK2Node_LoadMemoryCardData : public UK2Node_BaseAsyncTask
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
class USavAsset;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDolphinLoadMemoryCardDataMulticastDelegate, UDolphinInstance*, DolphinInstance);

UCLASS(meta = (HideThen))
class UK2Node_LoadMemoryCardDataProxy : public UObject
{
	GENERATED_UCLASS_BODY()

public:
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"))
	static UK2Node_LoadMemoryCardDataProxy* CreateProxyObjectForWait(UDolphinInstance* DolphinInstance, UGciAsset* OptionalMemoryCardSlotAAsset, UGciAsset* OptionalMemoryCardSlotBAsset);

	UPROPERTY(BlueprintAssignable)
	FDolphinLoadMemoryCardDataMulticastDelegate OnSuccess;

private:
	void OnInstanceReady(UDolphinInstance* InInstance, uint64 CommandId);
};
