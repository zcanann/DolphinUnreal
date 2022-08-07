#pragma once

#include "CoreMinimal.h"
#include "UObject/ObjectMacros.h"
#include "K2Node_BaseAsyncTask.h"

#include "K2Node_ReadInt8.generated.h"

UCLASS()
class UK2Node_ReadInt8 : public UK2Node_BaseAsyncTask
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

DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FDolphinReadInt8MulticastDelegate, UDolphinInstance*, DolphinInstance, FDolphinInt8, Value, bool, bSuccess);

UCLASS(meta = (HideThen))
class UK2Node_ReadInt8Proxy : public UObject
{
	GENERATED_UCLASS_BODY()

public:
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", AutoCreateRefTerm = "Offsets"))
	static UK2Node_ReadInt8Proxy* CreateProxyObjectForWait(UDolphinInstance* DolphinInstance, FDolphinUInt32 Address, TArray<FDolphinInt32> Offsets);
	
	UPROPERTY(BlueprintAssignable)
	FDolphinReadInt8MulticastDelegate OnSuccess;

private:
	void OnInstanceMemoryReadInt8(UDolphinInstance* InInstance, FDolphinInt8 InValue);
	void OnInstanceReady(UDolphinInstance* InInstance, uint64 CommandId);

	UPROPERTY()
	FDolphinInt8 Value;

	UPROPERTY()
	bool bSuccess = false;
};