#include "BlueprintNodes/K2Node_Terminate.h"

#include "DolphinUnrealBlueprintLibrary.h"

#define LOCTEXT_NAMESPACE "UK2Node_Terminate"

UK2Node_Terminate::UK2Node_Terminate(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	ProxyFactoryFunctionName = GET_FUNCTION_NAME_CHECKED(UK2Node_TerminateProxy, CreateProxyObjectForWait);
	ProxyFactoryClass = UK2Node_TerminateProxy::StaticClass();
	ProxyClass = UK2Node_TerminateProxy::StaticClass();
}

FText UK2Node_Terminate::GetTooltipText() const
{
	return LOCTEXT("K2Node_Terminate_Tooltip", "Terminates the specified (or default) Dolphin instance.");
}

FText UK2Node_Terminate::GetNodeTitle(ENodeTitleType::Type TitleType) const
{
	return LOCTEXT("K2Node_Terminate_Title", "Terminate Dolphin Instance");
}

FText UK2Node_Terminate::GetMenuCategory() const
{
	return LOCTEXT("K2Node_Terminate_Category", "Dolphin");
}

UK2Node_TerminateProxy* UK2Node_TerminateProxy::CreateProxyObjectForWait(UDolphinInstance* DolphinInstance, bool bAggressive)
{
	UK2Node_TerminateProxy* Proxy = NewObject<UK2Node_TerminateProxy>();
	Proxy->SetFlags(RF_StrongRefOnFrame);

	if (DolphinInstance != nullptr)
	{
		// Assume successful immediately with aggressive termination. Slight delay to work with wait nodes.
		if (bAggressive)
		{
			FTimerHandle TimerHandler;
			GEngine->GameViewport->GetWorld()->GetTimerManager().SetTimer(TimerHandler, [Proxy]()
			{
				Proxy->OnInstanceReady(nullptr, -1);
			}, 0.01f, false);
		}
		else
		{
			// Otherwise wait for the Terminate IPC callback
			DolphinInstance->OnInstanceCommandCompleteEvent.AddUObject(Proxy, &UK2Node_TerminateProxy::OnInstanceReady);
		}

		DolphinInstance->RequestTerminate(bAggressive);
	}

	return Proxy;
}

UK2Node_TerminateProxy::UK2Node_TerminateProxy(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
}

void UK2Node_TerminateProxy::OnInstanceReady(UDolphinInstance* InInstance, uint64 CommandId)
{
	if (InInstance)
	{
		InInstance->OnInstanceCommandCompleteEvent.RemoveAll(this);
	}

	OnSuccess.Broadcast();
}

#undef LOCTEXT_NAMESPACE
