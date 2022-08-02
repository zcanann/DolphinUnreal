#include "BlueprintNodes/K2Node_FrameAdvanceWithInputs.h"

#include "DolphinUnrealBlueprintLibrary.h"

#define LOCTEXT_NAMESPACE "UK2Node_FrameAdvanceWithInputs"

UK2Node_FrameAdvanceWithInputs::UK2Node_FrameAdvanceWithInputs(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	ProxyFactoryFunctionName = GET_FUNCTION_NAME_CHECKED(UK2Node_FrameAdvanceWithInputsProxy, CreateProxyObjectForWait);
	ProxyFactoryClass = UK2Node_FrameAdvanceWithInputsProxy::StaticClass();
	ProxyClass = UK2Node_FrameAdvanceWithInputsProxy::StaticClass();
}

FText UK2Node_FrameAdvanceWithInputs::GetTooltipText() const
{
	return LOCTEXT("K2Node_FrameAdvanceWithInputs_Tooltip", "Sends an input table to the Dolphin instance for playback");
}

FText UK2Node_FrameAdvanceWithInputs::GetNodeTitle(ENodeTitleType::Type TitleType) const
{
	return LOCTEXT("K2Node_FrameAdvanceWithInputs_Title", "Play Input Table");
}

FText UK2Node_FrameAdvanceWithInputs::GetMenuCategory() const
{
	return LOCTEXT("K2Node_FrameAdvanceWithInputs_Category", "Dolphin");
}

UK2Node_FrameAdvanceWithInputsProxy* UK2Node_FrameAdvanceWithInputsProxy::CreateProxyObjectForWait(UDolphinInstance* DolphinInstance, int32 NumberOfFrames, FFrameInputs FrameInputs)
{
	UK2Node_FrameAdvanceWithInputsProxy* Proxy = NewObject<UK2Node_FrameAdvanceWithInputsProxy>();
	Proxy->SetFlags(RF_StrongRefOnFrame);

	DolphinInstance = UDolphinUnrealBlueprintLibrary::GetDolphinInstanceOrDefault(DolphinInstance);

	if (DolphinInstance != nullptr)
	{
		DolphinInstance->OnInstanceCommandCompleteEvent.AddUObject(Proxy, &UK2Node_FrameAdvanceWithInputsProxy::OnInstanceReady);
		UDolphinUnrealBlueprintLibrary::FrameAdvanceWithInput(NumberOfFrames, FrameInputs);
	}

	return Proxy;
}

UK2Node_FrameAdvanceWithInputsProxy::UK2Node_FrameAdvanceWithInputsProxy(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
}

void UK2Node_FrameAdvanceWithInputsProxy::OnInstanceReady(UDolphinInstance* InInstance)
{
	if (InInstance)
	{
		InInstance->OnInstanceCommandCompleteEvent.RemoveAll(this);
	}

	OnSuccess.Broadcast(InInstance);
}

#undef LOCTEXT_NAMESPACE
