#include "BlueprintNodes/K2Node_ReadUInt16.h"

#include "DataTypes/DolphinDataTypesBlueprintLibrary.h"
#include "DolphinUnrealBlueprintLibrary.h"

#define LOCTEXT_NAMESPACE "UK2Node_ReadUInt16"

UK2Node_ReadUInt16::UK2Node_ReadUInt16(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	ProxyFactoryFunctionName = GET_FUNCTION_NAME_CHECKED(UK2Node_ReadUInt16Proxy, CreateProxyObjectForWait);
	ProxyFactoryClass = UK2Node_ReadUInt16Proxy::StaticClass();
	ProxyClass = UK2Node_ReadUInt16Proxy::StaticClass();
}

FText UK2Node_ReadUInt16::GetTooltipText() const
{
	return LOCTEXT("K2Node_ReadUInt16_Tooltip", "Reads an uint16 from the specified (or default) Dolphin instance.");
}

FText UK2Node_ReadUInt16::GetNodeTitle(ENodeTitleType::Type TitleType) const
{
	return LOCTEXT("K2Node_ReadUInt16_Title", "Read UInt16 from Memory");
}

FText UK2Node_ReadUInt16::GetMenuCategory() const
{
	return LOCTEXT("K2Node_ReadUInt16_Category", "Dolphin");
}

UK2Node_ReadUInt16Proxy* UK2Node_ReadUInt16Proxy::CreateProxyObjectForWait(UDolphinInstance* DolphinInstance, FDolphinUInt32 Address, TArray<FDolphinInt32> Offsets)
{
	UK2Node_ReadUInt16Proxy* Proxy = NewObject<UK2Node_ReadUInt16Proxy>();
	Proxy->SetFlags(RF_StrongRefOnFrame);
	Proxy->bSuccess = false;

	if (DolphinInstance != nullptr)
	{
		DolphinInstance->OnInstanceCommandCompleteEvent.AddUObject(Proxy, &UK2Node_ReadUInt16Proxy::OnInstanceReady);
		DolphinInstance->OnInstanceMemoryRead.AddUObject(Proxy, &UK2Node_ReadUInt16Proxy::OnInstanceMemoryRead);
		DolphinInstance->RequestReadMemory(Address, Offsets, sizeof(uint16));
	}

	return Proxy;
}

UK2Node_ReadUInt16Proxy::UK2Node_ReadUInt16Proxy(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
}

void UK2Node_ReadUInt16Proxy::OnInstanceMemoryRead(UDolphinInstance* InInstance, TArray<FDolphinUInt8> InValue)
{
	if (InInstance)
	{
		InInstance->OnInstanceMemoryRead.RemoveAll(this);
	}

	if (InValue.Num() == sizeof(double))
	{
		Value = UDolphinDataTypesBlueprintLibrary::MakeUInt16FromBytes(InValue[0], InValue[1], true);
	}

	bSuccess = true;
}

void UK2Node_ReadUInt16Proxy::OnInstanceReady(UDolphinInstance* InInstance, uint64 CommandId)
{
	if (InInstance)
	{
		InInstance->OnInstanceCommandCompleteEvent.RemoveAll(this);
	}

	OnSuccess.Broadcast(InInstance, Value, bSuccess);
}

#undef LOCTEXT_NAMESPACE
