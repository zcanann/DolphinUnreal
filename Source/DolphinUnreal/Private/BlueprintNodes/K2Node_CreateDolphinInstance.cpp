#include "BlueprintNodes/K2Node_CreateDolphinInstance.h"

#include "DolphinUnrealBlueprintLibrary.h"

#define LOCTEXT_NAMESPACE "UK2Node_CreateDolphinInstance"

UK2Node_CreateDolphinInstance::UK2Node_CreateDolphinInstance(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	ProxyFactoryFunctionName = GET_FUNCTION_NAME_CHECKED(UK2Node_CreateDolphinInstanceProxy, CreateProxyObjectForWait);
	ProxyFactoryClass = UK2Node_CreateDolphinInstanceProxy::StaticClass();
	ProxyClass = UK2Node_CreateDolphinInstanceProxy::StaticClass();
}

FText UK2Node_CreateDolphinInstance::GetTooltipText() const
{
	return LOCTEXT("K2Node_CreateDolphinInstance_Tooltip", "Creates a new Dolphin instance.");
}

FText UK2Node_CreateDolphinInstance::GetNodeTitle(ENodeTitleType::Type TitleType) const
{
	return LOCTEXT("K2Node_CreateDolphinInstance_Title", "Create Dolphin Instance");
}

FText UK2Node_CreateDolphinInstance::GetMenuCategory() const
{
	return LOCTEXT("K2Node_CreateDolphinInstance_Category", "Dolphin");
}

UK2Node_CreateDolphinInstanceProxy* UK2Node_CreateDolphinInstanceProxy::CreateProxyObjectForWait(bool bRegisterAsDefaultInstance, bool bStartPaused, bool bBeginRecording, UIsoAsset* IsoAsset)
{
	UK2Node_CreateDolphinInstanceProxy* Proxy = NewObject<UK2Node_CreateDolphinInstanceProxy>();
	Proxy->SetFlags(RF_StrongRefOnFrame);

	UDolphinInstance* Instance = UDolphinUnrealBlueprintLibrary::CreateDolphinInstance(bRegisterAsDefaultInstance, bStartPaused, bBeginRecording, IsoAsset);
	Instance->OnInstanceCommandCompleteEvent.AddUObject(Proxy, &UK2Node_CreateDolphinInstanceProxy::OnInstanceReady);

	return Proxy;
}

UK2Node_CreateDolphinInstanceProxy::UK2Node_CreateDolphinInstanceProxy(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
}

void UK2Node_CreateDolphinInstanceProxy::OnInstanceReady(UDolphinInstance* InInstance, uint64 CommandId)
{
	if (InInstance)
	{
		InInstance->OnInstanceCommandCompleteEvent.RemoveAll(this);
	}

	OnSuccess.Broadcast(InInstance);
}

#undef LOCTEXT_NAMESPACE
