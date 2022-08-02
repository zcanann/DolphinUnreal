#include "BlueprintNodes/K2Node_Terminate.h"

#include "DolphinUnrealBlueprintLibrary.h"

#define LOCTEXT_NAMESPACE "UK2Node_Terminate"

UK2Node_Terminate::UK2Node_Terminate(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	ProxyFactoryFunctionName = GET_FUNCTION_NAME_CHECKED(UK2Node_TerminateProxy, CreateProxyObjectForWait);
	ProxyFactoryClass = UK2Node_TerminateProxy::StaticClass();
	ProxyClass = UK2Node_TerminateProxy::StaticClass();
}

FText UK2Node_Terminate::GetTooltipText() const
{
	return LOCTEXT("K2Node_Terminate_Tooltip", "Terminates the specified (or default) Dolphin instance.");
}

FText UK2Node_Terminate::GetNodeTitle(ENodeTitleType::Type TitleType) const
{
	return LOCTEXT("K2Node_Terminate_Title", "Terminate Dolphin Instance");
}

FText UK2Node_Terminate::GetMenuCategory() const
{
	return LOCTEXT("K2Node_Terminate_Category", "Dolphin");
}

UK2Node_TerminateProxy* UK2Node_TerminateProxy::CreateProxyObjectForWait(UDolphinInstance* DolphinInstance)
{
	UK2Node_TerminateProxy* Proxy = NewObject<UK2Node_TerminateProxy>();
	Proxy->SetFlags(RF_StrongRefOnFrame);

	DolphinInstance = UDolphinUnrealBlueprintLibrary::GetDolphinInstanceOrDefault(DolphinInstance);

	if (DolphinInstance != nullptr)
	{
		DolphinInstance->OnInstanceCommandCompleteEvent.AddUObject(Proxy, &UK2Node_TerminateProxy::OnInstanceReady);
		UDolphinUnrealBlueprintLibrary::Terminate(DolphinInstance);
	}

	return Proxy;
}

UK2Node_TerminateProxy::UK2Node_TerminateProxy(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
}

void UK2Node_TerminateProxy::OnInstanceReady(UDolphinInstance* InInstance)
{
	if (InInstance)
	{
		InInstance->OnInstanceCommandCompleteEvent.RemoveAll(this);
	}

	OnSuccess.Broadcast(InInstance);
}

#undef LOCTEXT_NAMESPACE
