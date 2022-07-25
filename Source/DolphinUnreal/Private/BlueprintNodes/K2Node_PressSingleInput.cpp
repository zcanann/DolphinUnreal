#include "BlueprintNodes/K2Node_PressSingleInput.h"

#include "BlueprintNodes/K2Node_DolphinWaitProxy.h"

#define LOCTEXT_NAMESPACE "UK2Node_PressSingleInput"

UK2Node_PressSingleInput::UK2Node_PressSingleInput(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	ProxyFactoryFunctionName = GET_FUNCTION_NAME_CHECKED(UK2Node_DolphinWaitProxy, CreateProxyObjectForWait);
	ProxyFactoryClass = UK2Node_DolphinWaitProxy::StaticClass();
	ProxyClass = UK2Node_DolphinWaitProxy::StaticClass();
}

FText UK2Node_PressSingleInput::GetTooltipText() const
{
	return LOCTEXT("K2Node_PressSingleInput_Tooltip", "Presses a single input on the next frame.");
}

FText UK2Node_PressSingleInput::GetNodeTitle(ENodeTitleType::Type TitleType) const
{
	return LOCTEXT("K2Node_PressSingleInput_Title", "Play Single Input");
}

FText UK2Node_PressSingleInput::GetMenuCategory() const
{
	return LOCTEXT("K2Node_PressSingleInput_Category", "Dolphin");
}

#undef LOCTEXT_NAMESPACE
