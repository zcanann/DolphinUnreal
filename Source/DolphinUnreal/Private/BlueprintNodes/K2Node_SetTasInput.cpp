#include "BlueprintNodes/K2Node_SetTasInput.h"

#include "DolphinUnrealBlueprintLibrary.h"

#define LOCTEXT_NAMESPACE "UK2Node_SetTasInput"

UK2Node_SetTasInput::UK2Node_SetTasInput(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	ProxyFactoryFunctionName = GET_FUNCTION_NAME_CHECKED(UK2Node_SetTasInputProxy, CreateProxyObjectForWait);
	ProxyFactoryClass = UK2Node_SetTasInputProxy::StaticClass();
	ProxyClass = UK2Node_SetTasInputProxy::StaticClass();
}

FText UK2Node_SetTasInput::GetTooltipText() const
{
	return LOCTEXT("K2Node_SetTasInput_Tooltip", "Sets the TAS input that will be played on frame advance (if using hardware controllers is disabled).");
}

FText UK2Node_SetTasInput::GetNodeTitle(ENodeTitleType::Type TitleType) const
{
	return LOCTEXT("K2Node_SetTasInput_Title", "Set TAS Input");
}

FText UK2Node_SetTasInput::GetMenuCategory() const
{
	return LOCTEXT("K2Node_SetTasInput_Category", "Dolphin");
}

UK2Node_SetTasInputProxy* UK2Node_SetTasInputProxy::CreateProxyObjectForWait(UDolphinInstance* DolphinInstance, FFrameInputs FrameInputsController0,
	FFrameInputs FrameInputsController1, FFrameInputs FrameInputsController2, FFrameInputs FrameInputsController3)
{
	UK2Node_SetTasInputProxy* Proxy = NewObject<UK2Node_SetTasInputProxy>();
	Proxy->SetFlags(RF_StrongRefOnFrame);

	DolphinInstance = UDolphinUnrealBlueprintLibrary::GetDolphinInstanceOrDefault(DolphinInstance);

	if (DolphinInstance != nullptr)
	{
		FFrameInputs FrameInputs[4] = { FrameInputsController0, FrameInputsController1, FrameInputsController2, FrameInputsController3 };
		DolphinInstance->OnInstanceCommandCompleteEvent.AddUObject(Proxy, &UK2Node_SetTasInputProxy::OnInstanceReady);
		DolphinInstance->RequestSetTasInput(FrameInputs);
	}

	return Proxy;
}

UK2Node_SetTasInputProxy::UK2Node_SetTasInputProxy(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
}

void UK2Node_SetTasInputProxy::OnInstanceReady(UDolphinInstance* InInstance, uint64 CommandId)
{
	if (InInstance)
	{
		InInstance->OnInstanceCommandCompleteEvent.RemoveAll(this);
	}

	OnSuccess.Broadcast(InInstance);
}

#undef LOCTEXT_NAMESPACE
