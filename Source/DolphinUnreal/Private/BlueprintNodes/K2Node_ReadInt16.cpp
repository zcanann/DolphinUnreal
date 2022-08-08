#include "BlueprintNodes/K2Node_ReadInt16.h"

#include "DolphinUnrealBlueprintLibrary.h"

#define LOCTEXT_NAMESPACE "UK2Node_ReadInt16"

UK2Node_ReadInt16::UK2Node_ReadInt16(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	ProxyFactoryFunctionName = GET_FUNCTION_NAME_CHECKED(UK2Node_ReadInt16Proxy, CreateProxyObjectForWait);
	ProxyFactoryClass = UK2Node_ReadInt16Proxy::StaticClass();
	ProxyClass = UK2Node_ReadInt16Proxy::StaticClass();
}

FText UK2Node_ReadInt16::GetTooltipText() const
{
	return LOCTEXT("K2Node_ReadInt16_Tooltip", "Reads an int16 from the specified (or default) Dolphin instance.");
}

FText UK2Node_ReadInt16::GetNodeTitle(ENodeTitleType::Type TitleType) const
{
	return LOCTEXT("K2Node_ReadInt16_Title", "Read Int16 from Memory");
}

FText UK2Node_ReadInt16::GetMenuCategory() const
{
	return LOCTEXT("K2Node_ReadInt16_Category", "Dolphin");
}

UK2Node_ReadInt16Proxy* UK2Node_ReadInt16Proxy::CreateProxyObjectForWait(UDolphinInstance* DolphinInstance, FDolphinUInt32 Address, TArray<FDolphinInt32> Offsets)
{
	UK2Node_ReadInt16Proxy* Proxy = NewObject<UK2Node_ReadInt16Proxy>();
	Proxy->SetFlags(RF_StrongRefOnFrame);
	Proxy->bSuccess = false;

	DolphinInstance = UDolphinUnrealBlueprintLibrary::GetDolphinInstanceOrDefault(DolphinInstance);

	if (DolphinInstance != nullptr)
	{
		DolphinInstance->OnInstanceCommandCompleteEvent.AddUObject(Proxy, &UK2Node_ReadInt16Proxy::OnInstanceReady);
		DolphinInstance->OnInstanceMemoryRead.AddUObject(Proxy, &UK2Node_ReadInt16Proxy::OnInstanceMemoryRead);
		DolphinInstance->RequestReadMemory(Address, Offsets, sizeof(int16));
	}

	return Proxy;
}

UK2Node_ReadInt16Proxy::UK2Node_ReadInt16Proxy(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
}

void UK2Node_ReadInt16Proxy::OnInstanceMemoryRead(UDolphinInstance* InInstance, TArray<FDolphinUInt8> InValue)
{
	if (InInstance)
	{
		InInstance->OnInstanceMemoryRead.RemoveAll(this);
	}

	if (InValue.Num() == sizeof(int16))
	{
		Value = UDolphinDataTypesBlueprintLibrary::MakeInt16FromBytes(InValue[0], InValue[1], true);
	}

	bSuccess = true;
}

void UK2Node_ReadInt16Proxy::OnInstanceReady(UDolphinInstance* InInstance, uint64 CommandId)
{
	if (InInstance)
	{
		InInstance->OnInstanceCommandCompleteEvent.RemoveAll(this);
	}

	OnSuccess.Broadcast(InInstance, Value, bSuccess);
}

#undef LOCTEXT_NAMESPACE
