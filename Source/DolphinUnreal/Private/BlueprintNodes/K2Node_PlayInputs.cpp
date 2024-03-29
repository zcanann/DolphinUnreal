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
	return LOCTEXT("K2Node_PlayInputs_Tooltip", "Sends inputs to the Dolphin instance for playback");
}

FText UK2Node_PlayInputs::GetNodeTitle(ENodeTitleType::Type TitleType) const
{
	return LOCTEXT("K2Node_PlayInputs_Title", "Play Inputs");
}

FText UK2Node_PlayInputs::GetMenuCategory() const
{
	return LOCTEXT("K2Node_PlayInputs_Category", "Dolphin");
}

UK2Node_PlayInputsProxy* UK2Node_PlayInputsProxy::CreateProxyObjectForWait(UDolphinInstance* DolphinInstance, const TArray<FFrameInputs>& FrameInputsController0,
	const TArray<FFrameInputs>& FrameInputsController1, const TArray<FFrameInputs>& FrameInputsController2, const TArray<FFrameInputs>& FrameInputsController3)
{
	UK2Node_PlayInputsProxy* Proxy = NewObject<UK2Node_PlayInputsProxy>();
	Proxy->SetFlags(RF_StrongRefOnFrame);

	if (DolphinInstance != nullptr)
	{
		TArray<FFrameInputs> FrameInputs[4] = { FrameInputsController0, FrameInputsController1, FrameInputsController2, FrameInputsController3 };
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
