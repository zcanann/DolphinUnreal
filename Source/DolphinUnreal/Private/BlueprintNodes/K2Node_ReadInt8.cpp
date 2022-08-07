#include "BlueprintNodes/K2Node_ReadInt8.h"

#include "DolphinUnrealBlueprintLibrary.h"

#define LOCTEXT_NAMESPACE "UK2Node_ReadInt8"

UK2Node_ReadInt8::UK2Node_ReadInt8(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	ProxyFactoryFunctionName = GET_FUNCTION_NAME_CHECKED(UK2Node_ReadInt8Proxy, CreateProxyObjectForWait);
	ProxyFactoryClass = UK2Node_ReadInt8Proxy::StaticClass();
	ProxyClass = UK2Node_ReadInt8Proxy::StaticClass();
}

FText UK2Node_ReadInt8::GetTooltipText() const
{
	return LOCTEXT("K2Node_ReadInt8_Tooltip", "Reads an int8 from the specified (or default) Dolphin instance.");
}

FText UK2Node_ReadInt8::GetNodeTitle(ENodeTitleType::Type TitleType) const
{
	return LOCTEXT("K2Node_ReadInt8_Title", "Read Int8 from Memory");
}

FText UK2Node_ReadInt8::GetMenuCategory() const
{
	return LOCTEXT("K2Node_ReadInt8_Category", "Dolphin");
}

UK2Node_ReadInt8Proxy* UK2Node_ReadInt8Proxy::CreateProxyObjectForWait(UDolphinInstance* DolphinInstance, FDolphinUInt32 Address, TArray<FDolphinInt32> Offsets)
{
	UK2Node_ReadInt8Proxy* Proxy = NewObject<UK2Node_ReadInt8Proxy>();
	Proxy->SetFlags(RF_StrongRefOnFrame);
	Proxy->bSuccess = false;

	DolphinInstance = UDolphinUnrealBlueprintLibrary::GetDolphinInstanceOrDefault(DolphinInstance);

	if (DolphinInstance != nullptr)
	{
		DolphinInstance->OnInstanceCommandCompleteEvent.AddUObject(Proxy, &UK2Node_ReadInt8Proxy::OnInstanceReady);
		DolphinInstance->OnInstanceMemoryReadInt8.AddUObject(Proxy, &UK2Node_ReadInt8Proxy::OnInstanceMemoryReadInt8);
		DolphinInstance->RequestReadInt8(Address, Offsets);
	}

	return Proxy;
}

UK2Node_ReadInt8Proxy::UK2Node_ReadInt8Proxy(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
}

void UK2Node_ReadInt8Proxy::OnInstanceMemoryReadInt8(UDolphinInstance* InInstance, FDolphinInt8 InValue)
{
	if (InInstance)
	{
		InInstance->OnInstanceMemoryReadInt8.RemoveAll(this);
	}

	Value = InValue;
	bSuccess = true;
}

void UK2Node_ReadInt8Proxy::OnInstanceReady(UDolphinInstance* InInstance, uint64 CommandId)
{
	if (InInstance)
	{
		InInstance->OnInstanceCommandCompleteEvent.RemoveAll(this);
	}

	OnSuccess.Broadcast(InInstance, Value, bSuccess);
}

#undef LOCTEXT_NAMESPACE
