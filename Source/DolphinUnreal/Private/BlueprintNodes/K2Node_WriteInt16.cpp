#include "BlueprintNodes/K2Node_WriteInt16.h"

#include "DataTypes/DolphinDataTypesBlueprintLibrary.h"
#include "DolphinUnrealBlueprintLibrary.h"

#define LOCTEXT_NAMESPACE "UK2Node_WriteInt16"

UK2Node_WriteInt16::UK2Node_WriteInt16(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	ProxyFactoryFunctionName = GET_FUNCTION_NAME_CHECKED(UK2Node_WriteInt16Proxy, CreateProxyObjectForWait);
	ProxyFactoryClass = UK2Node_WriteInt16Proxy::StaticClass();
	ProxyClass = UK2Node_WriteInt16Proxy::StaticClass();
}

FText UK2Node_WriteInt16::GetTooltipText() const
{
	return LOCTEXT("K2Node_WriteInt16_Tooltip", "Writes an int16 from the specified (or default) Dolphin instance.");
}

FText UK2Node_WriteInt16::GetNodeTitle(ENodeTitleType::Type TitleType) const
{
	return LOCTEXT("K2Node_WriteInt16_Title", "Write Int16 from Memory");
}

FText UK2Node_WriteInt16::GetMenuCategory() const
{
	return LOCTEXT("K2Node_WriteInt16_Category", "Dolphin");
}

UK2Node_WriteInt16Proxy* UK2Node_WriteInt16Proxy::CreateProxyObjectForWait(UDolphinInstance* DolphinInstance, FDolphinUInt32 Address, TArray<FDolphinInt32> Offsets, FDolphinInt16 Value)
{
	UK2Node_WriteInt16Proxy* Proxy = NewObject<UK2Node_WriteInt16Proxy>();
	Proxy->SetFlags(RF_StrongRefOnFrame);
	Proxy->bSuccess = false;

	if (DolphinInstance != nullptr)
	{
		DolphinInstance->OnInstanceCommandCompleteEvent.AddUObject(Proxy, &UK2Node_WriteInt16Proxy::OnInstanceWritey);
		DolphinInstance->OnInstanceMemoryWrite.AddUObject(Proxy, &UK2Node_WriteInt16Proxy::OnInstanceMemoryWrite);
		DolphinInstance->RequestWriteMemory(Address, Offsets, UDolphinDataTypesBlueprintLibrary::MakeUInt8ArrayFromInt16(Value.Value));
	}

	return Proxy;
}

UK2Node_WriteInt16Proxy::UK2Node_WriteInt16Proxy(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
}

void UK2Node_WriteInt16Proxy::OnInstanceMemoryWrite(UDolphinInstance* InInstance, TArray<FDolphinUInt8> InValue)
{
	if (InInstance)
	{
		InInstance->OnInstanceMemoryWrite.RemoveAll(this);
	}

	if (InValue.Num() == sizeof(int16))
	{
		Value = UDolphinDataTypesBlueprintLibrary::MakeInt16FromBytes(InValue[0], InValue[1], true);
	}

	bSuccess = true;
}

void UK2Node_WriteInt16Proxy::OnInstanceWritey(UDolphinInstance* InInstance, uint64 CommandId)
{
	if (InInstance)
	{
		InInstance->OnInstanceCommandCompleteEvent.RemoveAll(this);
	}

	OnSuccess.Broadcast(InInstance, Value, bSuccess);
}

#undef LOCTEXT_NAMESPACE
