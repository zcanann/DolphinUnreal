#include "BlueprintNodes/K2Node_PlayInputTable.h"

#include "DolphinUnrealBlueprintLibrary.h"

#define LOCTEXT_NAMESPACE "UK2Node_PlayInputTable"

UK2Node_PlayInputTable::UK2Node_PlayInputTable(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	ProxyFactoryFunctionName = GET_FUNCTION_NAME_CHECKED(UK2Node_PlayInputTableProxy, CreateProxyObjectForWait);
	ProxyFactoryClass = UK2Node_PlayInputTableProxy::StaticClass();
	ProxyClass = UK2Node_PlayInputTableProxy::StaticClass();
}

FText UK2Node_PlayInputTable::GetTooltipText() const
{
	return LOCTEXT("K2Node_PlayInputTable_Tooltip", "Sends an input table to the Dolphin instance for playback");
}

FText UK2Node_PlayInputTable::GetNodeTitle(ENodeTitleType::Type TitleType) const
{
	return LOCTEXT("K2Node_PlayInputTable_Title", "Play Input Table");
}

FText UK2Node_PlayInputTable::GetMenuCategory() const
{
	return LOCTEXT("K2Node_PlayInputTable_Category", "Dolphin");
}

UK2Node_PlayInputTableProxy* UK2Node_PlayInputTableProxy::CreateProxyObjectForWait(UDataTable* FrameInputsTable, UDolphinInstance* DolphinInstance)
{
	UK2Node_PlayInputTableProxy* Proxy = NewObject<UK2Node_PlayInputTableProxy>();
	Proxy->SetFlags(RF_StrongRefOnFrame);

	DolphinInstance = UDolphinUnrealBlueprintLibrary::GetDolphinInstanceOrDefault(DolphinInstance);

	if (DolphinInstance != nullptr)
	{
		DolphinInstance->OnInstanceReadyForNextCommandEvent.AddUObject(Proxy, &UK2Node_PlayInputTableProxy::OnInstanceReady);
		UDolphinUnrealBlueprintLibrary::PlayInputTable(FrameInputsTable, DolphinInstance);
	}

	return Proxy;
}

UK2Node_PlayInputTableProxy::UK2Node_PlayInputTableProxy(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
}

void UK2Node_PlayInputTableProxy::OnInstanceReady(UDolphinInstance* InInstance)
{
	OnSuccess.Broadcast(InInstance);
}

#undef LOCTEXT_NAMESPACE
