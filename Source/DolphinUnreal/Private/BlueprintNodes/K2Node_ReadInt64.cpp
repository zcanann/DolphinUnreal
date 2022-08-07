#include "BlueprintNodes/K2Node_ReadInt64.h"

#include "DolphinUnrealBlueprintLibrary.h"

#define LOCTEXT_NAMESPACE "UK2Node_ReadInt64"

UK2Node_ReadInt64::UK2Node_ReadInt64(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	ProxyFactoryFunctionName = GET_FUNCTION_NAME_CHECKED(UK2Node_ReadInt64Proxy, CreateProxyObjectForWait);
	ProxyFactoryClass = UK2Node_ReadInt64Proxy::StaticClass();
	ProxyClass = UK2Node_ReadInt64Proxy::StaticClass();
}

FText UK2Node_ReadInt64::GetTooltipText() const
{
	return LOCTEXT("K2Node_ReadInt64_Tooltip", "Reads an int64 from the specified (or default) Dolphin instance.");
}

FText UK2Node_ReadInt64::GetNodeTitle(ENodeTitleType::Type TitleType) const
{
	return LOCTEXT("K2Node_ReadInt64_Title", "Read Int64 from Memory");
}

FText UK2Node_ReadInt64::GetMenuCategory() const
{
	return LOCTEXT("K2Node_ReadInt64_Category", "Dolphin");
}

UK2Node_ReadInt64Proxy* UK2Node_ReadInt64Proxy::CreateProxyObjectForWait(UDolphinInstance* DolphinInstance, FDolphinUInt32 Address, TArray<FDolphinInt32> Offsets)
{
	UK2Node_ReadInt64Proxy* Proxy = NewObject<UK2Node_ReadInt64Proxy>();
	Proxy->SetFlags(RF_StrongRefOnFrame);
	Proxy->bSuccess = false;

	DolphinInstance = UDolphinUnrealBlueprintLibrary::GetDolphinInstanceOrDefault(DolphinInstance);

	if (DolphinInstance != nullptr)
	{
		DolphinInstance->OnInstanceCommandCompleteEvent.AddUObject(Proxy, &UK2Node_ReadInt64Proxy::OnInstanceReady);
		DolphinInstance->OnInstanceMemoryReadInt64.AddUObject(Proxy, &UK2Node_ReadInt64Proxy::OnInstanceMemoryReadInt64);
		DolphinInstance->RequestReadInt64(Address, Offsets);
	}

	return Proxy;
}

UK2Node_ReadInt64Proxy::UK2Node_ReadInt64Proxy(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
}

void UK2Node_ReadInt64Proxy::OnInstanceMemoryReadInt64(UDolphinInstance* InInstance, FDolphinInt64 InValue)
{
	if (InInstance)
	{
		InInstance->OnInstanceMemoryReadInt64.RemoveAll(this);
	}

	Value = InValue;
	bSuccess = true;
}

void UK2Node_ReadInt64Proxy::OnInstanceReady(UDolphinInstance* InInstance, uint64 CommandId)
{
	if (InInstance)
	{
		InInstance->OnInstanceCommandCompleteEvent.RemoveAll(this);
	}

	OnSuccess.Broadcast(InInstance, Value, bSuccess);
}

#undef LOCTEXT_NAMESPACE
