#include "BlueprintNodes/K2Node_WriteInt32.h"

#include "DataTypes/DolphinDataTypesBlueprintLibrary.h"
#include "DolphinUnrealBlueprintLibrary.h"

#define LOCTEXT_NAMESPACE "UK2Node_WriteInt32"

UK2Node_WriteInt32::UK2Node_WriteInt32(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	ProxyFactoryFunctionName = GET_FUNCTION_NAME_CHECKED(UK2Node_WriteInt32Proxy, CreateProxyObjectForWait);
	ProxyFactoryClass = UK2Node_WriteInt32Proxy::StaticClass();
	ProxyClass = UK2Node_WriteInt32Proxy::StaticClass();
}

FText UK2Node_WriteInt32::GetTooltipText() const
{
	return LOCTEXT("K2Node_WriteInt32_Tooltip", "Writes an int32 from the specified (or default) Dolphin instance.");
}

FText UK2Node_WriteInt32::GetNodeTitle(ENodeTitleType::Type TitleType) const
{
	return LOCTEXT("K2Node_WriteInt32_Title", "Write Int32 from Memory");
}

FText UK2Node_WriteInt32::GetMenuCategory() const
{
	return LOCTEXT("K2Node_WriteInt32_Category", "Dolphin");
}

UK2Node_WriteInt32Proxy* UK2Node_WriteInt32Proxy::CreateProxyObjectForWait(UDolphinInstance* DolphinInstance, FDolphinUInt32 Address, TArray<FDolphinInt32> Offsets, FDolphinInt32 Value)
{
	UK2Node_WriteInt32Proxy* Proxy = NewObject<UK2Node_WriteInt32Proxy>();
	Proxy->SetFlags(RF_StrongRefOnFrame);
	Proxy->bSuccess = false;

	if (DolphinInstance != nullptr)
	{
		DolphinInstance->OnInstanceCommandCompleteEvent.AddUObject(Proxy, &UK2Node_WriteInt32Proxy::OnInstanceWritey);
		DolphinInstance->OnInstanceMemoryWrite.AddUObject(Proxy, &UK2Node_WriteInt32Proxy::OnInstanceMemoryWrite);
		DolphinInstance->RequestWriteMemory(Address, Offsets, UDolphinDataTypesBlueprintLibrary::MakeUInt8ArrayFromInt32(Value.Value));
	}

	return Proxy;
}

UK2Node_WriteInt32Proxy::UK2Node_WriteInt32Proxy(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
}

void UK2Node_WriteInt32Proxy::OnInstanceMemoryWrite(UDolphinInstance* InInstance, TArray<FDolphinUInt8> InValue)
{
	if (InInstance)
	{
		InInstance->OnInstanceMemoryWrite.RemoveAll(this);
	}

	if (InValue.Num() == sizeof(int32))
	{
		Value = UDolphinDataTypesBlueprintLibrary::MakeInt32FromBytes(InValue[0], InValue[1], InValue[2], InValue[3], true);
	}

	bSuccess = true;
}

void UK2Node_WriteInt32Proxy::OnInstanceWritey(UDolphinInstance* InInstance, uint64 CommandId)
{
	if (InInstance)
	{
		InInstance->OnInstanceCommandCompleteEvent.RemoveAll(this);
	}

	OnSuccess.Broadcast(InInstance, Value, bSuccess);
}

#undef LOCTEXT_NAMESPACE
