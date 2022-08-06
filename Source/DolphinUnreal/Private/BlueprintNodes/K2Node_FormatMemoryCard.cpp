#include "BlueprintNodes/K2Node_FormatMemoryCard.h"

#include "DolphinUnrealBlueprintLibrary.h"

#define LOCTEXT_NAMESPACE "UK2Node_FormatMemoryCard"

UK2Node_FormatMemoryCard::UK2Node_FormatMemoryCard(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	ProxyFactoryFunctionName = GET_FUNCTION_NAME_CHECKED(UK2Node_FormatMemoryCardProxy, CreateProxyObjectForWait);
	ProxyFactoryClass = UK2Node_FormatMemoryCardProxy::StaticClass();
	ProxyClass = UK2Node_FormatMemoryCardProxy::StaticClass();
}

FText UK2Node_FormatMemoryCard::GetTooltipText() const
{
	return LOCTEXT("K2Node_FormatMemoryCard_Tooltip", "Formats the memory card in a given slot for the specified (or default) Dolphin instance.");
}

FText UK2Node_FormatMemoryCard::GetNodeTitle(ENodeTitleType::Type TitleType) const
{
	return LOCTEXT("K2Node_FormatMemoryCard_Title", "Format Memory Card");
}

FText UK2Node_FormatMemoryCard::GetMenuCategory() const
{
	return LOCTEXT("K2Node_FormatMemoryCard_Category", "Dolphin");
}

UK2Node_FormatMemoryCardProxy* UK2Node_FormatMemoryCardProxy::CreateProxyObjectForWait(UDolphinInstance* DolphinInstance, EMemoryCardSlot MemoryCardSlot, EMemoryCardSize MemoryCardSize, EMemoryCardEncoding MemoryCardEncoding)
{
	UK2Node_FormatMemoryCardProxy* Proxy = NewObject<UK2Node_FormatMemoryCardProxy>();
	Proxy->SetFlags(RF_StrongRefOnFrame);

	DolphinInstance = UDolphinUnrealBlueprintLibrary::GetDolphinInstanceOrDefault(DolphinInstance);

	if (DolphinInstance != nullptr)
	{
		DolphinInstance->OnInstanceCommandCompleteEvent.AddUObject(Proxy, &UK2Node_FormatMemoryCardProxy::OnInstanceReady);
		DolphinInstance->RequestFormatMemoryCard(MemoryCardSlot, MemoryCardSize, MemoryCardEncoding);
	}

	return Proxy;
}

UK2Node_FormatMemoryCardProxy::UK2Node_FormatMemoryCardProxy(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
}

void UK2Node_FormatMemoryCardProxy::OnInstanceReady(UDolphinInstance* InInstance, uint64 CommandId)
{
	if (InInstance)
	{
		InInstance->OnInstanceCommandCompleteEvent.RemoveAll(this);
	}

	OnSuccess.Broadcast(InInstance);
}

#undef LOCTEXT_NAMESPACE
