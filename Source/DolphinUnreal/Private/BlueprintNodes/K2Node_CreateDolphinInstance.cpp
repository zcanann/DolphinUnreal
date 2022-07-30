#include "BlueprintNodes/K2Node_CreateDolphinInstance.h"

#include "BlueprintNodes/K2Node_CreateDolphinInstanceProxy.h"

#define LOCTEXT_NAMESPACE "UK2Node_CreateDolphinInstance"

UK2Node_CreateDolphinInstance::UK2Node_CreateDolphinInstance(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	ProxyFactoryFunctionName = GET_FUNCTION_NAME_CHECKED(UK2Node_CreateDolphinInstanceProxy, CreateProxyObjectForWait);
	ProxyFactoryClass = UK2Node_CreateDolphinInstanceProxy::StaticClass();
	ProxyClass = UK2Node_CreateDolphinInstanceProxy::StaticClass();
}

FText UK2Node_CreateDolphinInstance::GetTooltipText() const
{
	return LOCTEXT("K2Node_CreateDolphinInstance_Tooltip", "Creates a new Dolphin instance.");
}

FText UK2Node_CreateDolphinInstance::GetNodeTitle(ENodeTitleType::Type TitleType) const
{
	return LOCTEXT("K2Node_CreateDolphinInstance_Title", "Create Dolphin Instance");
}

FText UK2Node_CreateDolphinInstance::GetMenuCategory() const
{
	return LOCTEXT("K2Node_CreateDolphinInstance_Category", "Dolphin");
}

#undef LOCTEXT_NAMESPACE
