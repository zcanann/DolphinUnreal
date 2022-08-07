#include "BlueprintNodes/K2Node_ReadDouble.h"

#include "DolphinUnrealBlueprintLibrary.h"

#define LOCTEXT_NAMESPACE "UK2Node_ReadDouble"

UK2Node_ReadDouble::UK2Node_ReadDouble(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	ProxyFactoryFunctionName = GET_FUNCTION_NAME_CHECKED(UK2Node_ReadDoubleProxy, CreateProxyObjectForWait);
	ProxyFactoryClass = UK2Node_ReadDoubleProxy::StaticClass();
	ProxyClass = UK2Node_ReadDoubleProxy::StaticClass();
}

FText UK2Node_ReadDouble::GetTooltipText() const
{
	return LOCTEXT("K2Node_ReadDouble_Tooltip", "Reads an double from the specified (or default) Dolphin instance.");
}

FText UK2Node_ReadDouble::GetNodeTitle(ENodeTitleType::Type TitleType) const
{
	return LOCTEXT("K2Node_ReadDouble_Title", "Read Double from Memory");
}

FText UK2Node_ReadDouble::GetMenuCategory() const
{
	return LOCTEXT("K2Node_ReadDouble_Category", "Dolphin");
}

UK2Node_ReadDoubleProxy* UK2Node_ReadDoubleProxy::CreateProxyObjectForWait(UDolphinInstance* DolphinInstance, FDolphinUInt32 Address, TArray<FDolphinInt32> Offsets)
{
	UK2Node_ReadDoubleProxy* Proxy = NewObject<UK2Node_ReadDoubleProxy>();
	Proxy->SetFlags(RF_StrongRefOnFrame);
	Proxy->bSuccess = false;

	DolphinInstance = UDolphinUnrealBlueprintLibrary::GetDolphinInstanceOrDefault(DolphinInstance);

	if (DolphinInstance != nullptr)
	{
		DolphinInstance->OnInstanceCommandCompleteEvent.AddUObject(Proxy, &UK2Node_ReadDoubleProxy::OnInstanceReady);
		DolphinInstance->OnInstanceMemoryReadDouble.AddUObject(Proxy, &UK2Node_ReadDoubleProxy::OnInstanceMemoryReadDouble);
		DolphinInstance->RequestReadDouble(Address, Offsets);
	}

	return Proxy;
}

UK2Node_ReadDoubleProxy::UK2Node_ReadDoubleProxy(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
}

void UK2Node_ReadDoubleProxy::OnInstanceMemoryReadDouble(UDolphinInstance* InInstance, FDolphinDouble InValue)
{
	if (InInstance)
	{
		InInstance->OnInstanceMemoryReadDouble.RemoveAll(this);
	}

	Value = InValue;
	bSuccess = true;
}

void UK2Node_ReadDoubleProxy::OnInstanceReady(UDolphinInstance* InInstance, uint64 CommandId)
{
	if (InInstance)
	{
		InInstance->OnInstanceCommandCompleteEvent.RemoveAll(this);
	}

	OnSuccess.Broadcast(InInstance, Value, bSuccess);
}

#undef LOCTEXT_NAMESPACE
