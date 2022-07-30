#include "BlueprintNodes/K2Node_CreateDolphinInstanceProxy.h"

#include "DolphinInstance.h"
#include "DolphinUnrealBlueprintLibrary.h"

UK2Node_CreateDolphinInstanceProxy* UK2Node_CreateDolphinInstanceProxy::CreateProxyObjectForWait(bool bRegisterAsDefaultInstance, bool bStartPaused, bool bBeginRecording, UIsoAsset* IsoAsset)
{
	UK2Node_CreateDolphinInstanceProxy* Proxy = NewObject<UK2Node_CreateDolphinInstanceProxy>();
	Proxy->SetFlags(RF_StrongRefOnFrame);

	Proxy->Instance = UDolphinUnrealBlueprintLibrary::CreateDolphinInstance(bRegisterAsDefaultInstance, bStartPaused, bBeginRecording, IsoAsset);
	Proxy->Instance->OnInstanceReadyForNextCommandEvent.AddUObject(Proxy, &UK2Node_CreateDolphinInstanceProxy::OnInstanceReady);

	// Proxy->WaitForDolphin(DolphinInstance);
	return Proxy;
}

UK2Node_CreateDolphinInstanceProxy::UK2Node_CreateDolphinInstanceProxy(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
}

void UK2Node_CreateDolphinInstanceProxy::OnInstanceReady(UDolphinInstance* InInstance)
{
	OnSuccess.Broadcast(InInstance);
}
