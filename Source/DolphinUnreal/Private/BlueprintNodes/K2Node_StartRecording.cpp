#include "BlueprintNodes/K2Node_StartRecording.h"

#include "DolphinUnrealBlueprintLibrary.h"

#define LOCTEXT_NAMESPACE "UK2Node_StartRecording"

UK2Node_StartRecording::UK2Node_StartRecording(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	ProxyFactoryFunctionName = GET_FUNCTION_NAME_CHECKED(UK2Node_StartRecordingProxy, CreateProxyObjectForWait);
	ProxyFactoryClass = UK2Node_StartRecordingProxy::StaticClass();
	ProxyClass = UK2Node_StartRecordingProxy::StaticClass();
}

FText UK2Node_StartRecording::GetTooltipText() const
{
	return LOCTEXT("K2Node_StartRecording_Tooltip", "Start recording input for the specified (or default) Dolphin instance.");
}

FText UK2Node_StartRecording::GetNodeTitle(ENodeTitleType::Type TitleType) const
{
	return LOCTEXT("K2Node_StartRecording_Title", "Start Recording");
}

FText UK2Node_StartRecording::GetMenuCategory() const
{
	return LOCTEXT("K2Node_StartRecording_Category", "Dolphin");
}

UK2Node_StartRecordingProxy* UK2Node_StartRecordingProxy::CreateProxyObjectForWait(UDolphinInstance* DolphinInstance)
{
	UK2Node_StartRecordingProxy* Proxy = NewObject<UK2Node_StartRecordingProxy>();
	Proxy->SetFlags(RF_StrongRefOnFrame);

	DolphinInstance = UDolphinUnrealBlueprintLibrary::GetDolphinInstanceOrDefault(DolphinInstance);

	if (DolphinInstance != nullptr)
	{
		DolphinInstance->OnInstanceReadyForNextCommandEvent.AddUObject(Proxy, &UK2Node_StartRecordingProxy::OnInstanceReady);
		UDolphinUnrealBlueprintLibrary::StartRecording(DolphinInstance);
	}

	return Proxy;
}

UK2Node_StartRecordingProxy::UK2Node_StartRecordingProxy(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
}

void UK2Node_StartRecordingProxy::OnInstanceReady(UDolphinInstance* InInstance)
{
	if (InInstance)
	{
		InInstance->OnInstanceReadyForNextCommandEvent.RemoveAll(this);
	}

	OnSuccess.Broadcast(InInstance);
}

#undef LOCTEXT_NAMESPACE
