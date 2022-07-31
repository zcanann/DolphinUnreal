#include "BlueprintNodes/K2Node_LoadSaveState.h"

#include "DolphinUnrealBlueprintLibrary.h"

#define LOCTEXT_NAMESPACE "UK2Node_LoadSaveState"

UK2Node_LoadSaveState::UK2Node_LoadSaveState(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	ProxyFactoryFunctionName = GET_FUNCTION_NAME_CHECKED(UK2Node_LoadSaveStateProxy, CreateProxyObjectForWait);
	ProxyFactoryClass = UK2Node_LoadSaveStateProxy::StaticClass();
	ProxyClass = UK2Node_LoadSaveStateProxy::StaticClass();
}

FText UK2Node_LoadSaveState::GetTooltipText() const
{
	return LOCTEXT("K2Node_LoadSaveState_Tooltip", "Loads a Dolphin save state.");
}

FText UK2Node_LoadSaveState::GetNodeTitle(ENodeTitleType::Type TitleType) const
{
	return LOCTEXT("K2Node_LoadSaveState_Title", "Load Save State");
}

FText UK2Node_LoadSaveState::GetMenuCategory() const
{
	return LOCTEXT("K2Node_LoadSaveState_Category", "Dolphin");
}

UK2Node_LoadSaveStateProxy* UK2Node_LoadSaveStateProxy::CreateProxyObjectForWait(FString SaveName, UDolphinInstance* DolphinInstance)
{
	UK2Node_LoadSaveStateProxy* Proxy = NewObject<UK2Node_LoadSaveStateProxy>();
	Proxy->SetFlags(RF_StrongRefOnFrame);

	DolphinInstance = UDolphinUnrealBlueprintLibrary::GetDolphinInstanceOrDefault(DolphinInstance);

	if (DolphinInstance != nullptr)
	{
		DolphinInstance->OnInstanceReadyForNextCommandEvent.AddUObject(Proxy, &UK2Node_LoadSaveStateProxy::OnInstanceReady);
		UDolphinUnrealBlueprintLibrary::LoadSaveState(SaveName, DolphinInstance);
	}

	return Proxy;
}

UK2Node_LoadSaveStateProxy::UK2Node_LoadSaveStateProxy(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
}

void UK2Node_LoadSaveStateProxy::OnInstanceReady(UDolphinInstance* InInstance)
{
	if (InInstance)
	{
		InInstance->OnInstanceReadyForNextCommandEvent.RemoveAll(this);
	}

	OnSuccess.Broadcast(InInstance);
}

#undef LOCTEXT_NAMESPACE
