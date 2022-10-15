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
	return LOCTEXT("K2Node_FrameAdvanceWithInputs_Tooltip", "Advances the emulation and plays the given input for the specified Dolphin instance(or default) over a specified number of frames.");
}

FText UK2Node_FrameAdvanceWithInputs::GetNodeTitle(ENodeTitleType::Type TitleType) const
{
	return LOCTEXT("K2Node_FrameAdvanceWithInputs_Title", "Frame Advance With Input");
}

FText UK2Node_FrameAdvanceWithInputs::GetMenuCategory() const
{
	return LOCTEXT("K2Node_FrameAdvanceWithInputs_Category", "Dolphin");
}

UK2Node_FrameAdvanceWithInputsProxy* UK2Node_FrameAdvanceWithInputsProxy::CreateProxyObjectForWait(UDolphinInstance* DolphinInstance,
	FFrameInputs FrameInputsController0, FFrameInputs FrameInputsController1, FFrameInputs FrameInputsController2, FFrameInputs FrameInputsController3, int32 NumberOfFrames)
{
	UK2Node_FrameAdvanceWithInputsProxy* Proxy = NewObject<UK2Node_FrameAdvanceWithInputsProxy>();
	Proxy->SetFlags(RF_StrongRefOnFrame);

	DolphinInstance = UDolphinUnrealBlueprintLibrary::GetDolphinInstanceOrDefault(DolphinInstance);

	if (DolphinInstance != nullptr)
	{
		FFrameInputs FrameInputs[4] = { FrameInputsController0, FrameInputsController1, FrameInputsController2, FrameInputsController3 };
		DolphinInstance->OnInstanceCommandCompleteEvent.AddUObject(Proxy, &UK2Node_FrameAdvanceWithInputsProxy::OnInstanceReady);
		DolphinInstance->RequestFrameAdvanceWithInput(FrameInputs, NumberOfFrames);
	}

	return Proxy;
}

UK2Node_FrameAdvanceWithInputsProxy::UK2Node_FrameAdvanceWithInputsProxy(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
}

void UK2Node_FrameAdvanceWithInputsProxy::OnInstanceReady(UDolphinInstance* InInstance, uint64 CommandId)
{
	if (InInstance)
	{
		InInstance->OnInstanceCommandCompleteEvent.RemoveAll(this);
	}

	OnSuccess.Broadcast(InInstance);
}

#undef LOCTEXT_NAMESPACE
