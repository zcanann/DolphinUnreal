#include "BlueprintNodes/K2Node_ReadUInt8.h"

#include "DataTypes/DolphinDataTypesBlueprintLibrary.h"
#include "DolphinUnrealBlueprintLibrary.h"

#define LOCTEXT_NAMESPACE "UK2Node_ReadUInt8"

UK2Node_ReadUInt8::UK2Node_ReadUInt8(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	ProxyFactoryFunctionName = GET_FUNCTION_NAME_CHECKED(UK2Node_ReadUInt8Proxy, CreateProxyObjectForWait);
	ProxyFactoryClass = UK2Node_ReadUInt8Proxy::StaticClass();
	ProxyClass = UK2Node_ReadUInt8Proxy::StaticClass();
}

FText UK2Node_ReadUInt8::GetTooltipText() const
{
	return LOCTEXT("K2Node_ReadUInt8_Tooltip", "Reads an uint8 from the specified (or default) Dolphin instance.");
}

FText UK2Node_ReadUInt8::GetNodeTitle(ENodeTitleType::Type TitleType) const
{
	return LOCTEXT("K2Node_ReadUInt8_Title", "Read UInt8 from Memory");
}

FText UK2Node_ReadUInt8::GetMenuCategory() const
{
	return LOCTEXT("K2Node_ReadUInt8_Category", "Dolphin");
}

UK2Node_ReadUInt8Proxy* UK2Node_ReadUInt8Proxy::CreateProxyObjectForWait(UDolphinInstance* DolphinInstance, FDolphinUInt32 Address, TArray<FDolphinInt32> Offsets)
{
	UK2Node_ReadUInt8Proxy* Proxy = NewObject<UK2Node_ReadUInt8Proxy>();
	Proxy->SetFlags(RF_StrongRefOnFrame);
	Proxy->bSuccess = false;

	DolphinInstance = UDolphinUnrealBlueprintLibrary::GetDolphinInstanceOrDefault(DolphinInstance);

	if (DolphinInstance != nullptr)
	{
		DolphinInstance->OnInstanceCommandCompleteEvent.AddUObject(Proxy, &UK2Node_ReadUInt8Proxy::OnInstanceReady);
		DolphinInstance->OnInstanceMemoryRead.AddUObject(Proxy, &UK2Node_ReadUInt8Proxy::OnInstanceMemoryRead);
		DolphinInstance->RequestReadMemory(Address, Offsets, sizeof(uint8));
	}

	return Proxy;
}

UK2Node_ReadUInt8Proxy::UK2Node_ReadUInt8Proxy(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
}

void UK2Node_ReadUInt8Proxy::OnInstanceMemoryRead(UDolphinInstance* InInstance, TArray<FDolphinUInt8> InValue)
{
	if (InInstance)
	{
		InInstance->OnInstanceMemoryRead.RemoveAll(this);
	}

	if (InValue.Num() == sizeof(double))
	{
		Value = InValue[0];
	}

	bSuccess = true;
}

void UK2Node_ReadUInt8Proxy::OnInstanceReady(UDolphinInstance* InInstance, uint64 CommandId)
{
	if (InInstance)
	{
		InInstance->OnInstanceCommandCompleteEvent.RemoveAll(this);
	}

	OnSuccess.Broadcast(InInstance, Value, bSuccess);
}

#undef LOCTEXT_NAMESPACE
