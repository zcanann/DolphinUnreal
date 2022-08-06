#pragma once

#include "CoreMinimal.h"
#include "UObject/ObjectMacros.h"
#include "K2Node_BaseAsyncTask.h"

#include "DataTypes/DolphinDataTypes.h"

#include "K2Node_FormatMemoryCard.generated.h"

UCLASS()
class UK2Node_FormatMemoryCard : public UK2Node_BaseAsyncTask
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

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDolphinFormatMemoryCardMulticastDelegate, UDolphinInstance*, DolphinInstance);

UCLASS(meta = (HideThen))
class UK2Node_FormatMemoryCardProxy : public UObject
{
	GENERATED_UCLASS_BODY()

public:
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"))
	static UK2Node_FormatMemoryCardProxy* CreateProxyObjectForWait(UDolphinInstance* DolphinInstance, EMemoryCardSlot MemoryCardSlot, EMemoryCardSize MemoryCardSize, EMemoryCardEncoding MemoryCardEncoding);
	
	UPROPERTY(BlueprintAssignable)
	FDolphinFormatMemoryCardMulticastDelegate OnSuccess;

private:
	void OnInstanceReady(UDolphinInstance* InInstance, uint64 CommandId);
};
