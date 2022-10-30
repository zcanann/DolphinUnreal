#include "BlueprintNodes/K2Node_ReadDouble.h"

#include "DataTypes/DolphinDataTypesBlueprintLibrary.h"
#include "DolphinUnrealBlueprintLibrary.h"

#define LOCTEXT_NAMESPACE "UK2Node_ReadDouble"

UK2Node_ReadDouble::UK2Node_ReadDouble(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	ProxyFactoryFunctionName = GET_FUNCTION_NAME_CHECKED(UK2Node_ReadDoubleProxy, CreateProxyObjectForWait);
	ProxyFactoryClass = UK2Node_ReadDoubleProxy::StaticClass();
	ProxyClass = UK2Node_ReadDoubleProxy::StaticClass();
}

FText UK2Node_ReadDouble::GetTooltipText() const
{
	return LOCTEXT("K2Node_ReadDouble_Tooltip", "Reads an double from the specified (or default) Dolphin instance.");
}

FText UK2Node_ReadDouble::GetNodeTitle(ENodeTitleType::Type TitleType) const
{
	return LOCTEXT("K2Node_ReadDouble_Title", "Read Double from Memory");
}

FText UK2Node_ReadDouble::GetMenuCategory() const
{
	return LOCTEXT("K2Node_ReadDouble_Category", "Dolphin");
}

UK2Node_ReadDoubleProxy* UK2Node_ReadDoubleProxy::CreateProxyObjectForWait(UDolphinInstance* DolphinInstance, FDolphinUInt32 Address, TArray<FDolphinInt32> Offsets)
{
	UK2Node_ReadDoubleProxy* Proxy = NewObject<UK2Node_ReadDoubleProxy>();
	Proxy->SetFlags(RF_StrongRefOnFrame);
	Proxy->bSuccess = false;

	if (DolphinInstance != nullptr)
	{
		DolphinInstance->OnInstanceCommandCompleteEvent.AddUObject(Proxy, &UK2Node_ReadDoubleProxy::OnInstanceReady);
		DolphinInstance->OnInstanceMemoryRead.AddUObject(Proxy, &UK2Node_ReadDoubleProxy::OnInstanceMemoryRead);
		DolphinInstance->RequestReadMemory(Address, Offsets, sizeof(double));
	}

	return Proxy;
}

UK2Node_ReadDoubleProxy::UK2Node_ReadDoubleProxy(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
}

void UK2Node_ReadDoubleProxy::OnInstanceMemoryRead(UDolphinInstance* InInstance, TArray<FDolphinUInt8> InValue)
{
	if (InInstance)
	{
		InInstance->OnInstanceMemoryRead.RemoveAll(this);
	}

	if (InValue.Num() == sizeof(double))
	{
		Value = UDolphinDataTypesBlueprintLibrary::MakeDoubleFromBytes(InValue[0], InValue[1], InValue[2], InValue[3], InValue[4], InValue[5], InValue[6], InValue[7], true);
	}

	bSuccess = true;
}

void UK2Node_ReadDoubleProxy::OnInstanceReady(UDolphinInstance* InInstance, uint64 CommandId)
{
	if (InInstance)
	{
		InInstance->OnInstanceCommandCompleteEvent.RemoveAll(this);
	}

	OnSuccess.Broadcast(InInstance, Value, bSuccess);
}

#undef LOCTEXT_NAMESPACE
