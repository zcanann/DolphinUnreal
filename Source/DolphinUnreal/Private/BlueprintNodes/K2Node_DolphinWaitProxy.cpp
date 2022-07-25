#include "BlueprintNodes/K2Node_DolphinWaitProxy.h"

#include "DolphinInstance.h"

UK2Node_DolphinWaitProxy* UK2Node_DolphinWaitProxy::CreateProxyObjectForWait(UDolphinInstance* DolphinInstance)
{
	UK2Node_DolphinWaitProxy* Proxy = NewObject<UK2Node_DolphinWaitProxy>();
	Proxy->SetFlags(RF_StrongRefOnFrame);
	Proxy->WaitForDolphin(DolphinInstance);
	return Proxy;
}

UK2Node_DolphinWaitProxy::UK2Node_DolphinWaitProxy(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UK2Node_DolphinWaitProxy::WaitForDolphin(UDolphinInstance* DolphinInstance)
{
	// WaitForDolphinDelegate = FOnDolphinWaitComplete::FDelegate::CreateUObject(this, &UK2Node_DolphinWaitProxy::OnDolphinReady);
}


void UK2Node_DolphinWaitProxy::OnDolphinReady(UDolphinInstance* DolphinInstance)
{
	RemoveDelegate();

	OnComplete.Broadcast(DolphinInstance);
}

void UK2Node_DolphinWaitProxy::RemoveDelegate()
{
}

void UK2Node_DolphinWaitProxy::BeginDestroy()
{
	RemoveDelegate();

	Super::BeginDestroy();
}
