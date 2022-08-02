#include "BlueprintNodes/K2Node_FrameAdvance.h"

#include "DolphinUnrealBlueprintLibrary.h"

#define LOCTEXT_NAMESPACE "UK2Node_FrameAdvance"

UK2Node_FrameAdvance::UK2Node_FrameAdvance(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	ProxyFactoryFunctionName = GET_FUNCTION_NAME_CHECKED(UK2Node_FrameAdvanceProxy, CreateProxyObjectForWait);
	ProxyFactoryClass = UK2Node_FrameAdvanceProxy::StaticClass();
	ProxyClass = UK2Node_FrameAdvanceProxy::StaticClass();
}

FText UK2Node_FrameAdvance::GetTooltipText() const
{
	return LOCTEXT("K2Node_FrameAdvance_Tooltip", "Sends an input table to the Dolphin instance for playback");
}

FText UK2Node_FrameAdvance::GetNodeTitle(ENodeTitleType::Type TitleType) const
{
	return LOCTEXT("K2Node_FrameAdvance_Title", "Play Input Table");
}

FText UK2Node_FrameAdvance::GetMenuCategory() const
{
	return LOCTEXT("K2Node_FrameAdvance_Category", "Dolphin");
}

UK2Node_FrameAdvanceProxy* UK2Node_FrameAdvanceProxy::CreateProxyObjectForWait(UDolphinInstance* DolphinInstance, int32 NumberOfFrames)
{
	UK2Node_FrameAdvanceProxy* Proxy = NewObject<UK2Node_FrameAdvanceProxy>();
	Proxy->SetFlags(RF_StrongRefOnFrame);

	DolphinInstance = UDolphinUnrealBlueprintLibrary::GetDolphinInstanceOrDefault(DolphinInstance);

	if (DolphinInstance != nullptr)
	{
		DolphinInstance->OnInstanceCommandCompleteEvent.AddUObject(Proxy, &UK2Node_FrameAdvanceProxy::OnInstanceReady);
		UDolphinUnrealBlueprintLibrary::FrameAdvance(NumberOfFrames, DolphinInstance);
	}

	return Proxy;
}

UK2Node_FrameAdvanceProxy::UK2Node_FrameAdvanceProxy(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
}

void UK2Node_FrameAdvanceProxy::OnInstanceReady(UDolphinInstance* InInstance)
{
	if (InInstance)
	{
		InInstance->OnInstanceCommandCompleteEvent.RemoveAll(this);
	}

	OnSuccess.Broadcast(InInstance);
}

#undef LOCTEXT_NAMESPACE
