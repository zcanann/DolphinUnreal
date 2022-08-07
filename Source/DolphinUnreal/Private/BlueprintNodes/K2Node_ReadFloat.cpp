#include "BlueprintNodes/K2Node_ReadFloat.h"

#include "DolphinUnrealBlueprintLibrary.h"

#define LOCTEXT_NAMESPACE "UK2Node_ReadFloat"

UK2Node_ReadFloat::UK2Node_ReadFloat(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	ProxyFactoryFunctionName = GET_FUNCTION_NAME_CHECKED(UK2Node_ReadFloatProxy, CreateProxyObjectForWait);
	ProxyFactoryClass = UK2Node_ReadFloatProxy::StaticClass();
	ProxyClass = UK2Node_ReadFloatProxy::StaticClass();
}

FText UK2Node_ReadFloat::GetTooltipText() const
{
	return LOCTEXT("K2Node_ReadFloat_Tooltip", "Reads an float from the specified (or default) Dolphin instance.");
}

FText UK2Node_ReadFloat::GetNodeTitle(ENodeTitleType::Type TitleType) const
{
	return LOCTEXT("K2Node_ReadFloat_Title", "Read Float from Memory");
}

FText UK2Node_ReadFloat::GetMenuCategory() const
{
	return LOCTEXT("K2Node_ReadFloat_Category", "Dolphin");
}

UK2Node_ReadFloatProxy* UK2Node_ReadFloatProxy::CreateProxyObjectForWait(UDolphinInstance* DolphinInstance, FDolphinUInt32 Address, TArray<FDolphinInt32> Offsets)
{
	UK2Node_ReadFloatProxy* Proxy = NewObject<UK2Node_ReadFloatProxy>();
	Proxy->SetFlags(RF_StrongRefOnFrame);
	Proxy->bSuccess = false;

	DolphinInstance = UDolphinUnrealBlueprintLibrary::GetDolphinInstanceOrDefault(DolphinInstance);

	if (DolphinInstance != nullptr)
	{
		DolphinInstance->OnInstanceCommandCompleteEvent.AddUObject(Proxy, &UK2Node_ReadFloatProxy::OnInstanceReady);
		DolphinInstance->OnInstanceMemoryReadFloat.AddUObject(Proxy, &UK2Node_ReadFloatProxy::OnInstanceMemoryReadFloat);
		DolphinInstance->RequestReadFloat(Address, Offsets);
	}

	return Proxy;
}

UK2Node_ReadFloatProxy::UK2Node_ReadFloatProxy(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
}

void UK2Node_ReadFloatProxy::OnInstanceMemoryReadFloat(UDolphinInstance* InInstance, FDolphinFloat InValue)
{
	if (InInstance)
	{
		InInstance->OnInstanceMemoryReadFloat.RemoveAll(this);
	}

	Value = InValue;
	bSuccess = true;
}

void UK2Node_ReadFloatProxy::OnInstanceReady(UDolphinInstance* InInstance, uint64 CommandId)
{
	if (InInstance)
	{
		InInstance->OnInstanceCommandCompleteEvent.RemoveAll(this);
	}

	OnSuccess.Broadcast(InInstance, Value, bSuccess);
}

#undef LOCTEXT_NAMESPACE
