#include "BlueprintNodes/K2Node_LoadMemoryCardData.h"

#include "AssetTypes/Gci/GciAsset.h"
#include "DolphinUnrealBlueprintLibrary.h"

#define LOCTEXT_NAMESPACE "UK2Node_LoadMemoryCardData"

UK2Node_LoadMemoryCardData::UK2Node_LoadMemoryCardData(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	ProxyFactoryFunctionName = GET_FUNCTION_NAME_CHECKED(UK2Node_LoadMemoryCardDataProxy, CreateProxyObjectForWait);
	ProxyFactoryClass = UK2Node_LoadMemoryCardDataProxy::StaticClass();
	ProxyClass = UK2Node_LoadMemoryCardDataProxy::StaticClass();
}

FText UK2Node_LoadMemoryCardData::GetTooltipText() const
{
	return LOCTEXT("K2Node_LoadMemoryCardData_Tooltip", "Loads memory card data from a Dolphin GCI file.");
}

FText UK2Node_LoadMemoryCardData::GetNodeTitle(ENodeTitleType::Type TitleType) const
{
	return LOCTEXT("K2Node_LoadMemoryCardData_Title", "Load Memory Card Data");
}

FText UK2Node_LoadMemoryCardData::GetMenuCategory() const
{
	return LOCTEXT("K2Node_LoadMemoryCardData_Category", "Dolphin");
}

UK2Node_LoadMemoryCardDataProxy* UK2Node_LoadMemoryCardDataProxy::CreateProxyObjectForWait(UDolphinInstance* DolphinInstance, UGciAsset* OptionalMemoryCardSlotAAsset, UGciAsset* OptionalMemoryCardSlotBAsset)
{
	UK2Node_LoadMemoryCardDataProxy* Proxy = NewObject<UK2Node_LoadMemoryCardDataProxy>();
	Proxy->SetFlags(RF_StrongRefOnFrame);

	if (DolphinInstance != nullptr)
	{
		DolphinInstance->OnInstanceCommandCompleteEvent.AddUObject(Proxy, &UK2Node_LoadMemoryCardDataProxy::OnInstanceReady);
		DolphinInstance->RequestLoadMemoryCardData(OptionalMemoryCardSlotAAsset, OptionalMemoryCardSlotBAsset);
	}

	return Proxy;
}

UK2Node_LoadMemoryCardDataProxy::UK2Node_LoadMemoryCardDataProxy(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
}

void UK2Node_LoadMemoryCardDataProxy::OnInstanceReady(UDolphinInstance* InInstance, uint64 CommandId)
{
	if (InInstance)
	{
		InInstance->OnInstanceCommandCompleteEvent.RemoveAll(this);
	}

	OnSuccess.Broadcast(InInstance);
}

#undef LOCTEXT_NAMESPACE
