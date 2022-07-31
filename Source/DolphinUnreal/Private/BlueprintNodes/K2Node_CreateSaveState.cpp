#include "BlueprintNodes/K2Node_CreateSaveState.h"

#include "DolphinUnrealBlueprintLibrary.h"

#define LOCTEXT_NAMESPACE "UK2Node_CreateSaveState"

UK2Node_CreateSaveState::UK2Node_CreateSaveState(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	ProxyFactoryFunctionName = GET_FUNCTION_NAME_CHECKED(UK2Node_CreateSaveStateProxy, CreateProxyObjectForWait);
	ProxyFactoryClass = UK2Node_CreateSaveStateProxy::StaticClass();
	ProxyClass = UK2Node_CreateSaveStateProxy::StaticClass();
}

FText UK2Node_CreateSaveState::GetTooltipText() const
{
	return LOCTEXT("K2Node_CreateSaveState_Tooltip", "Creates a new Dolphin instance.");
}

FText UK2Node_CreateSaveState::GetNodeTitle(ENodeTitleType::Type TitleType) const
{
	return LOCTEXT("K2Node_CreateSaveState_Title", "Create Dolphin Instance");
}

FText UK2Node_CreateSaveState::GetMenuCategory() const
{
	return LOCTEXT("K2Node_CreateSaveState_Category", "Dolphin");
}

UK2Node_CreateSaveStateProxy* UK2Node_CreateSaveStateProxy::CreateProxyObjectForWait(FString SaveName, UDolphinInstance* DolphinInstance)
{
	UK2Node_CreateSaveStateProxy* Proxy = NewObject<UK2Node_CreateSaveStateProxy>();
	Proxy->SetFlags(RF_StrongRefOnFrame);

	DolphinInstance = UDolphinUnrealBlueprintLibrary::GetDolphinInstanceOrDefault(DolphinInstance);

	if (DolphinInstance != nullptr)
	{
		DolphinInstance->OnInstanceReadyForNextCommandEvent.AddUObject(Proxy, &UK2Node_CreateSaveStateProxy::OnInstanceReady);
		UDolphinUnrealBlueprintLibrary::CreateSaveState(SaveName, DolphinInstance);
	}

	return Proxy;
}

UK2Node_CreateSaveStateProxy::UK2Node_CreateSaveStateProxy(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
}

void UK2Node_CreateSaveStateProxy::OnInstanceReady(UDolphinInstance* InInstance)
{
	if (InInstance)
	{
		InInstance->OnInstanceReadyForNextCommandEvent.RemoveAll(this);
	}

	OnSuccess.Broadcast(InInstance);
}

#undef LOCTEXT_NAMESPACE
