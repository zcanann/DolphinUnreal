#include "BlueprintNodes/K2Node_PlayInputs.h"

#include "DolphinUnrealBlueprintLibrary.h"

#define LOCTEXT_NAMESPACE "UK2Node_PlayInputs"

UK2Node_PlayInputs::UK2Node_PlayInputs(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	ProxyFactoryFunctionName = GET_FUNCTION_NAME_CHECKED(UK2Node_PlayInputsProxy, CreateProxyObjectForWait);
	ProxyFactoryClass = UK2Node_PlayInputsProxy::StaticClass();
	ProxyClass = UK2Node_PlayInputsProxy::StaticClass();
}

FText UK2Node_PlayInputs::GetTooltipText() const
{
	return LOCTEXT("K2Node_PlayInputs_Tooltip", "Sends an input table to the Dolphin instance for playback");
}

FText UK2Node_PlayInputs::GetNodeTitle(ENodeTitleType::Type TitleType) const
{
	return LOCTEXT("K2Node_PlayInputs_Title", "Play Input Table");
}

FText UK2Node_PlayInputs::GetMenuCategory() const
{
	return LOCTEXT("K2Node_PlayInputs_Category", "Dolphin");
}

UK2Node_PlayInputsProxy* UK2Node_PlayInputsProxy::CreateProxyObjectForWait(UDolphinInstance* DolphinInstance, TArray<FFrameInputs> FrameInputs)
{
	UK2Node_PlayInputsProxy* Proxy = NewObject<UK2Node_PlayInputsProxy>();
	Proxy->SetFlags(RF_StrongRefOnFrame);

	DolphinInstance = UDolphinUnrealBlueprintLibrary::GetDolphinInstanceOrDefault(DolphinInstance);

	if (DolphinInstance != nullptr)
	{
		DolphinInstance->OnInstanceCommandCompleteEvent.AddUObject(Proxy, &UK2Node_PlayInputsProxy::OnInstanceReady);
		DolphinInstance->RequestPlayInputs(FrameInputs);
	}

	return Proxy;
}

UK2Node_PlayInputsProxy::UK2Node_PlayInputsProxy(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
}

void UK2Node_PlayInputsProxy::OnInstanceReady(UDolphinInstance* InInstance, uint64 CommandId)
{
	if (InInstance)
	{
		InInstance->OnInstanceCommandCompleteEvent.RemoveAll(this);
	}

	OnSuccess.Broadcast(InInstance);
}

#undef LOCTEXT_NAMESPACE
