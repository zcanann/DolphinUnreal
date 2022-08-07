#include "BlueprintNodes/K2Node_ReadUInt64.h"

#include "DolphinUnrealBlueprintLibrary.h"

#define LOCTEXT_NAMESPACE "UK2Node_ReadUInt64"

UK2Node_ReadUInt64::UK2Node_ReadUInt64(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	ProxyFactoryFunctionName = GET_FUNCTION_NAME_CHECKED(UK2Node_ReadUInt64Proxy, CreateProxyObjectForWait);
	ProxyFactoryClass = UK2Node_ReadUInt64Proxy::StaticClass();
	ProxyClass = UK2Node_ReadUInt64Proxy::StaticClass();
}

FText UK2Node_ReadUInt64::GetTooltipText() const
{
	return LOCTEXT("K2Node_ReadUInt64_Tooltip", "Reads an uint64 from the specified (or default) Dolphin instance.");
}

FText UK2Node_ReadUInt64::GetNodeTitle(ENodeTitleType::Type TitleType) const
{
	return LOCTEXT("K2Node_ReadUInt64_Title", "Read UInt64 from Memory");
}

FText UK2Node_ReadUInt64::GetMenuCategory() const
{
	return LOCTEXT("K2Node_ReadUInt64_Category", "Dolphin");
}

UK2Node_ReadUInt64Proxy* UK2Node_ReadUInt64Proxy::CreateProxyObjectForWait(UDolphinInstance* DolphinInstance, FDolphinUInt32 Address, TArray<FDolphinInt32> Offsets)
{
	UK2Node_ReadUInt64Proxy* Proxy = NewObject<UK2Node_ReadUInt64Proxy>();
	Proxy->SetFlags(RF_StrongRefOnFrame);
	Proxy->bSuccess = false;

	DolphinInstance = UDolphinUnrealBlueprintLibrary::GetDolphinInstanceOrDefault(DolphinInstance);

	if (DolphinInstance != nullptr)
	{
		DolphinInstance->OnInstanceCommandCompleteEvent.AddUObject(Proxy, &UK2Node_ReadUInt64Proxy::OnInstanceReady);
		DolphinInstance->OnInstanceMemoryReadUInt64.AddUObject(Proxy, &UK2Node_ReadUInt64Proxy::OnInstanceMemoryReadUInt64);
		DolphinInstance->RequestReadUInt64(Address, Offsets);
	}

	return Proxy;
}

UK2Node_ReadUInt64Proxy::UK2Node_ReadUInt64Proxy(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
}

void UK2Node_ReadUInt64Proxy::OnInstanceMemoryReadUInt64(UDolphinInstance* InInstance, FDolphinUInt64 InValue)
{
	if (InInstance)
	{
		InInstance->OnInstanceMemoryReadUInt64.RemoveAll(this);
	}

	Value = InValue;
	bSuccess = true;
}

void UK2Node_ReadUInt64Proxy::OnInstanceReady(UDolphinInstance* InInstance, uint64 CommandId)
{
	if (InInstance)
	{
		InInstance->OnInstanceCommandCompleteEvent.RemoveAll(this);
	}

	OnSuccess.Broadcast(InInstance, Value, bSuccess);
}

#undef LOCTEXT_NAMESPACE
