#include "BlueprintNodes/K2Node_ResumeEmulation.h"

#include "DolphinUnrealBlueprintLibrary.h"

#define LOCTEXT_NAMESPACE "UK2Node_ResumeEmulation"

UK2Node_ResumeEmulation::UK2Node_ResumeEmulation(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	ProxyFactoryFunctionName = GET_FUNCTION_NAME_CHECKED(UK2Node_ResumeEmulationProxy, CreateProxyObjectForWait);
	ProxyFactoryClass = UK2Node_ResumeEmulationProxy::StaticClass();
	ProxyClass = UK2Node_ResumeEmulationProxy::StaticClass();
}

FText UK2Node_ResumeEmulation::GetTooltipText() const
{
	return LOCTEXT("K2Node_ResumeEmulation_Tooltip", "Resumes emulation on the specified (or default) Dolphin instance.");
}

FText UK2Node_ResumeEmulation::GetNodeTitle(ENodeTitleType::Type TitleType) const
{
	return LOCTEXT("K2Node_ResumeEmulation_Title", "Resume Emulation");
}

FText UK2Node_ResumeEmulation::GetMenuCategory() const
{
	return LOCTEXT("K2Node_ResumeEmulation_Category", "Dolphin");
}

UK2Node_ResumeEmulationProxy* UK2Node_ResumeEmulationProxy::CreateProxyObjectForWait(UDolphinInstance* DolphinInstance)
{
	UK2Node_ResumeEmulationProxy* Proxy = NewObject<UK2Node_ResumeEmulationProxy>();
	Proxy->SetFlags(RF_StrongRefOnFrame);

	DolphinInstance = UDolphinUnrealBlueprintLibrary::GetDolphinInstanceOrDefault(DolphinInstance);

	if (DolphinInstance != nullptr)
	{
		DolphinInstance->OnInstanceReadyForNextCommandEvent.AddUObject(Proxy, &UK2Node_ResumeEmulationProxy::OnInstanceReady);
		UDolphinUnrealBlueprintLibrary::ResumeEmulation(DolphinInstance);
	}

	return Proxy;
}

UK2Node_ResumeEmulationProxy::UK2Node_ResumeEmulationProxy(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
}

void UK2Node_ResumeEmulationProxy::OnInstanceReady(UDolphinInstance* InInstance)
{
	if (InInstance)
	{
		InInstance->OnInstanceReadyForNextCommandEvent.RemoveAll(this);
	}

	OnSuccess.Broadcast(InInstance);
}

#undef LOCTEXT_NAMESPACE
