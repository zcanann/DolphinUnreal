#include "BlueprintNodes/K2Node_WriteUInt16.h"

#include "DataTypes/DolphinDataTypesBlueprintLibrary.h"
#include "DolphinUnrealBlueprintLibrary.h"

#define LOCTEXT_NAMESPACE "UK2Node_WriteUInt16"

UK2Node_WriteUInt16::UK2Node_WriteUInt16(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	ProxyFactoryFunctionName = GET_FUNCTION_NAME_CHECKED(UK2Node_WriteUInt16Proxy, CreateProxyObjectForWait);
	ProxyFactoryClass = UK2Node_WriteUInt16Proxy::StaticClass();
	ProxyClass = UK2Node_WriteUInt16Proxy::StaticClass();
}

FText UK2Node_WriteUInt16::GetTooltipText() const
{
	return LOCTEXT("K2Node_WriteUInt16_Tooltip", "Writes an uint16 from the specified (or default) Dolphin instance.");
}

FText UK2Node_WriteUInt16::GetNodeTitle(ENodeTitleType::Type TitleType) const
{
	return LOCTEXT("K2Node_WriteUInt16_Title", "Write UInt16 from Memory");
}

FText UK2Node_WriteUInt16::GetMenuCategory() const
{
	return LOCTEXT("K2Node_WriteUInt16_Category", "Dolphin");
}

UK2Node_WriteUInt16Proxy* UK2Node_WriteUInt16Proxy::CreateProxyObjectForWait(UDolphinInstance* DolphinInstance, FDolphinUInt32 Address, TArray<FDolphinInt32> Offsets, FDolphinUInt16 Value)
{
	UK2Node_WriteUInt16Proxy* Proxy = NewObject<UK2Node_WriteUInt16Proxy>();
	Proxy->SetFlags(RF_StrongRefOnFrame);
	Proxy->bSuccess = false;

	if (DolphinInstance != nullptr)
	{
		DolphinInstance->OnInstanceCommandCompleteEvent.AddUObject(Proxy, &UK2Node_WriteUInt16Proxy::OnInstanceWritey);
		DolphinInstance->OnInstanceMemoryWrite.AddUObject(Proxy, &UK2Node_WriteUInt16Proxy::OnInstanceMemoryWrite);
		DolphinInstance->RequestWriteMemory(Address, Offsets, UDolphinDataTypesBlueprintLibrary::MakeUInt8ArrayFromUInt16(Value.Value));
	}

	return Proxy;
}

UK2Node_WriteUInt16Proxy::UK2Node_WriteUInt16Proxy(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
}

void UK2Node_WriteUInt16Proxy::OnInstanceMemoryWrite(UDolphinInstance* InInstance, TArray<FDolphinUInt8> InValue)
{
	if (InInstance)
	{
		InInstance->OnInstanceMemoryWrite.RemoveAll(this);
	}

	if (InValue.Num() == sizeof(double))
	{
		Value = UDolphinDataTypesBlueprintLibrary::MakeUInt16FromBytes(InValue[0], InValue[1], true);
	}

	bSuccess = true;
}

void UK2Node_WriteUInt16Proxy::OnInstanceWritey(UDolphinInstance* InInstance, uint64 CommandId)
{
	if (InInstance)
	{
		InInstance->OnInstanceCommandCompleteEvent.RemoveAll(this);
	}

	OnSuccess.Broadcast(InInstance, Value, bSuccess);
}

#undef LOCTEXT_NAMESPACE
