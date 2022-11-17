#include "BlueprintNodes/K2Node_WriteInt64.h"

#include "DataTypes/DolphinDataTypesBlueprintLibrary.h"
#include "DolphinUnrealBlueprintLibrary.h"

#define LOCTEXT_NAMESPACE "UK2Node_WriteInt64"

UK2Node_WriteInt64::UK2Node_WriteInt64(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	ProxyFactoryFunctionName = GET_FUNCTION_NAME_CHECKED(UK2Node_WriteInt64Proxy, CreateProxyObjectForWait);
	ProxyFactoryClass = UK2Node_WriteInt64Proxy::StaticClass();
	ProxyClass = UK2Node_WriteInt64Proxy::StaticClass();
}

FText UK2Node_WriteInt64::GetTooltipText() const
{
	return LOCTEXT("K2Node_WriteInt64_Tooltip", "Writes an int64 from the specified (or default) Dolphin instance.");
}

FText UK2Node_WriteInt64::GetNodeTitle(ENodeTitleType::Type TitleType) const
{
	return LOCTEXT("K2Node_WriteInt64_Title", "Write Int64 from Memory");
}

FText UK2Node_WriteInt64::GetMenuCategory() const
{
	return LOCTEXT("K2Node_WriteInt64_Category", "Dolphin");
}

UK2Node_WriteInt64Proxy* UK2Node_WriteInt64Proxy::CreateProxyObjectForWait(UDolphinInstance* DolphinInstance, FDolphinUInt32 Address, TArray<FDolphinInt32> Offsets, FDolphinInt64 Value)
{
	UK2Node_WriteInt64Proxy* Proxy = NewObject<UK2Node_WriteInt64Proxy>();
	Proxy->SetFlags(RF_StrongRefOnFrame);
	Proxy->bSuccess = false;

	if (DolphinInstance != nullptr)
	{
		DolphinInstance->OnInstanceCommandCompleteEvent.AddUObject(Proxy, &UK2Node_WriteInt64Proxy::OnInstanceWritey);
		DolphinInstance->OnInstanceMemoryWrite.AddUObject(Proxy, &UK2Node_WriteInt64Proxy::OnInstanceMemoryWrite);
		DolphinInstance->RequestWriteMemory(Address, Offsets, UDolphinDataTypesBlueprintLibrary::MakeUInt8ArrayFromInt64(Value.Value));
	}

	return Proxy;
}

UK2Node_WriteInt64Proxy::UK2Node_WriteInt64Proxy(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
}

void UK2Node_WriteInt64Proxy::OnInstanceMemoryWrite(UDolphinInstance* InInstance, TArray<FDolphinUInt8> InValue)
{
	if (InInstance)
	{
		InInstance->OnInstanceMemoryWrite.RemoveAll(this);
	}

	if (InValue.Num() == sizeof(int64))
	{
		Value = UDolphinDataTypesBlueprintLibrary::MakeInt64FromBytes(InValue[0], InValue[1], InValue[2], InValue[3], InValue[4], InValue[5], InValue[6], InValue[7], true);
	}

	bSuccess = true;
}

void UK2Node_WriteInt64Proxy::OnInstanceWritey(UDolphinInstance* InInstance, uint64 CommandId)
{
	if (InInstance)
	{
		InInstance->OnInstanceCommandCompleteEvent.RemoveAll(this);
	}

	OnSuccess.Broadcast(InInstance, Value, bSuccess);
}

#undef LOCTEXT_NAMESPACE
