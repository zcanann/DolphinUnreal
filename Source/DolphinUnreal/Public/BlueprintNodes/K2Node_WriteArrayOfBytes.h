#pragma once

#include "CoreMinimal.h"
#include "UObject/ObjectMacros.h"
#include "K2Node_BaseAsyncTask.h"

#include "DataTypes/DolphinDataTypes.h"

#include "K2Node_WriteArrayOfBytes.generated.h"

UCLASS()
class UK2Node_WriteArrayOfBytes : public UK2Node_BaseAsyncTask
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

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FDolphinWriteArrayOfBytesMulticastDelegate, UDolphinInstance*, DolphinInstance, bool, bSuccess);

UCLASS(meta = (HideThen))
class UK2Node_WriteArrayOfBytesProxy : public UObject
{
	GENERATED_UCLASS_BODY()

public:
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", AutoCreateRefTerm = "Offsets"))
	static UK2Node_WriteArrayOfBytesProxy* CreateProxyObjectForWait(UDolphinInstance* DolphinInstance, FDolphinUInt32 Address, TArray<FDolphinInt32> Offsets, const TArray<FDolphinUInt8>& Bytes);
	
	UPROPERTY(BlueprintAssignable)
	FDolphinWriteArrayOfBytesMulticastDelegate OnSuccess;

private:
	void OnInstanceMemoryWrite(UDolphinInstance* InInstance, bool bInSuccess);
	void OnInstanceReady(UDolphinInstance* InInstance, uint64 CommandId);

	UPROPERTY()
	bool bSuccess = false;
};