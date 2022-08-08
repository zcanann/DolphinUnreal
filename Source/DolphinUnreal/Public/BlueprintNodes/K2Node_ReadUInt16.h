#pragma once

#include "CoreMinimal.h"
#include "UObject/ObjectMacros.h"
#include "K2Node_BaseAsyncTask.h"

#include "DataTypes/DolphinDataTypes.h"

#include "K2Node_ReadUInt16.generated.h"

UCLASS()
class UK2Node_ReadUInt16 : public UK2Node_BaseAsyncTask
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

DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FDolphinReadUInt16MulticastDelegate, UDolphinInstance*, DolphinInstance, FDolphinUInt16, Value, bool, bSuccess);

UCLASS(meta = (HideThen))
class UK2Node_ReadUInt16Proxy : public UObject
{
	GENERATED_UCLASS_BODY()

public:
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", AutoCreateRefTerm = "Offsets"))
	static UK2Node_ReadUInt16Proxy* CreateProxyObjectForWait(UDolphinInstance* DolphinInstance, FDolphinUInt32 Address, TArray<FDolphinInt32> Offsets);
	
	UPROPERTY(BlueprintAssignable)
	FDolphinReadUInt16MulticastDelegate OnSuccess;

private:
	void OnInstanceMemoryRead(UDolphinInstance* InInstance, TArray<FDolphinUInt8> InValue);
	void OnInstanceReady(UDolphinInstance* InInstance, uint64 CommandId);

	UPROPERTY()
	FDolphinUInt16 Value;

	UPROPERTY()
	bool bSuccess = false;
};