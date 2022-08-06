#include "BlueprintNodes/K2Node_StopRecording.h"

#include "DolphinUnrealBlueprintLibrary.h"

#define LOCTEXT_NAMESPACE "UK2Node_StopRecording"

UK2Node_StopRecording::UK2Node_StopRecording(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	ProxyFactoryFunctionName = GET_FUNCTION_NAME_CHECKED(UK2Node_StopRecordingProxy, CreateProxyObjectForWait);
	ProxyFactoryClass = UK2Node_StopRecordingProxy::StaticClass();
	ProxyClass = UK2Node_StopRecordingProxy::StaticClass();
}

FText UK2Node_StopRecording::GetTooltipText() const
{
	return LOCTEXT("K2Node_StopRecording_Tooltip", "Stop recording input for the specified (or default) Dolphin instance and prompt saving the results.");
}

FText UK2Node_StopRecording::GetNodeTitle(ENodeTitleType::Type TitleType) const
{
	return LOCTEXT("K2Node_StopRecording_Title", "Stop Recording");
}

FText UK2Node_StopRecording::GetMenuCategory() const
{
	return LOCTEXT("K2Node_StopRecording_Category", "Dolphin");
}

UK2Node_StopRecordingProxy* UK2Node_StopRecordingProxy::CreateProxyObjectForWait(UDolphinInstance* DolphinInstance)
{
	UK2Node_StopRecordingProxy* Proxy = NewObject<UK2Node_StopRecordingProxy>();
	Proxy->SetFlags(RF_StrongRefOnFrame);

	DolphinInstance = UDolphinUnrealBlueprintLibrary::GetDolphinInstanceOrDefault(DolphinInstance);

	if (DolphinInstance != nullptr)
	{
		DolphinInstance->OnInstanceCommandCompleteEvent.AddUObject(Proxy, &UK2Node_StopRecordingProxy::OnInstanceReady);
		DolphinInstance->RequestStopRecording();
	}

	return Proxy;
}

UK2Node_StopRecordingProxy::UK2Node_StopRecordingProxy(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
}

void UK2Node_StopRecordingProxy::OnInstanceReady(UDolphinInstance* InInstance, uint64 CommandId)
{
	if (InInstance)
	{
		InInstance->OnInstanceCommandCompleteEvent.RemoveAll(this);
	}

	OnSuccess.Broadcast(InInstance);
}

#undef LOCTEXT_NAMESPACE
