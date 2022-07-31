#include "BlueprintNodes/K2Node_PauseEmulation.h"

#include "DolphinUnrealBlueprintLibrary.h"

#define LOCTEXT_NAMESPACE "UK2Node_PauseEmulation"

UK2Node_PauseEmulation::UK2Node_PauseEmulation(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	ProxyFactoryFunctionName = GET_FUNCTION_NAME_CHECKED(UK2Node_PauseEmulationProxy, CreateProxyObjectForWait);
	ProxyFactoryClass = UK2Node_PauseEmulationProxy::StaticClass();
	ProxyClass = UK2Node_PauseEmulationProxy::StaticClass();
}

FText UK2Node_PauseEmulation::GetTooltipText() const
{
	return LOCTEXT("K2Node_PauseEmulation_Tooltip", "Pause Dolphin emulation.");
}

FText UK2Node_PauseEmulation::GetNodeTitle(ENodeTitleType::Type TitleType) const
{
	return LOCTEXT("K2Node_PauseEmulation_Title", "Pause Emulation");
}

FText UK2Node_PauseEmulation::GetMenuCategory() const
{
	return LOCTEXT("K2Node_PauseEmulation_Category", "Dolphin");
}

UK2Node_PauseEmulationProxy* UK2Node_PauseEmulationProxy::CreateProxyObjectForWait(UDolphinInstance* DolphinInstance)
{
	UK2Node_PauseEmulationProxy* Proxy = NewObject<UK2Node_PauseEmulationProxy>();
	Proxy->SetFlags(RF_StrongRefOnFrame);

	DolphinInstance = UDolphinUnrealBlueprintLibrary::GetDolphinInstanceOrDefault(DolphinInstance);

	if (DolphinInstance != nullptr)
	{
		DolphinInstance->OnInstanceReadyForNextCommandEvent.AddUObject(Proxy, &UK2Node_PauseEmulationProxy::OnInstanceReady);
		UDolphinUnrealBlueprintLibrary::PauseEmulation(DolphinInstance);
	}

	return Proxy;
}

UK2Node_PauseEmulationProxy::UK2Node_PauseEmulationProxy(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
}

void UK2Node_PauseEmulationProxy::OnInstanceReady(UDolphinInstance* InInstance)
{
	if (InInstance)
	{
		InInstance->OnInstanceReadyForNextCommandEvent.RemoveAll(this);
	}

	OnSuccess.Broadcast(InInstance);
}

#undef LOCTEXT_NAMESPACE
