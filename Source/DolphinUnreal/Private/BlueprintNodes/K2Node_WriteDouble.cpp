#include "BlueprintNodes/K2Node_WriteDouble.h"

#include "DataTypes/DolphinDataTypesBlueprintLibrary.h"
#include "DolphinUnrealBlueprintLibrary.h"

#define LOCTEXT_NAMESPACE "UK2Node_WriteDouble"

UK2Node_WriteDouble::UK2Node_WriteDouble(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	ProxyFactoryFunctionName = GET_FUNCTION_NAME_CHECKED(UK2Node_WriteDoubleProxy, CreateProxyObjectForWait);
	ProxyFactoryClass = UK2Node_WriteDoubleProxy::StaticClass();
	ProxyClass = UK2Node_WriteDoubleProxy::StaticClass();
}

FText UK2Node_WriteDouble::GetTooltipText() const
{
	return LOCTEXT("K2Node_WriteDouble_Tooltip", "Writes an double to the specified (or default) Dolphin instance.");
}

FText UK2Node_WriteDouble::GetNodeTitle(ENodeTitleType::Type TitleType) const
{
	return LOCTEXT("K2Node_WriteDouble_Title", "Write Double to Memory");
}

FText UK2Node_WriteDouble::GetMenuCategory() const
{
	return LOCTEXT("K2Node_WriteDouble_Category", "Dolphin");
}

UK2Node_WriteDoubleProxy* UK2Node_WriteDoubleProxy::CreateProxyObjectForWait(UDolphinInstance* DolphinInstance, FDolphinUInt32 Address, TArray<FDolphinInt32> Offsets, FDolphinDouble Value)
{
	UK2Node_WriteDoubleProxy* Proxy = NewObject<UK2Node_WriteDoubleProxy>();
	Proxy->SetFlags(RF_StrongRefOnFrame);
	Proxy->bSuccess = false;

	if (DolphinInstance != nullptr)
	{
		DolphinInstance->OnInstanceCommandCompleteEvent.AddUObject(Proxy, &UK2Node_WriteDoubleProxy::OnInstanceReady);
		DolphinInstance->OnInstanceMemoryWrite.AddUObject(Proxy, &UK2Node_WriteDoubleProxy::OnInstanceMemoryWrite);
		DolphinInstance->RequestWriteMemory(Address, Offsets, UDolphinDataTypesBlueprintLibrary::MakeUInt8ArrayFromDouble(Value.Value));
	}

	return Proxy;
}

UK2Node_WriteDoubleProxy::UK2Node_WriteDoubleProxy(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
}

void UK2Node_WriteDoubleProxy::OnInstanceMemoryWrite(UDolphinInstance* InInstance, bool bInSuccess)
{
	if (InInstance)
	{
		InInstance->OnInstanceMemoryWrite.RemoveAll(this);
	}

	bSuccess = bInSuccess;
}

void UK2Node_WriteDoubleProxy::OnInstanceReady(UDolphinInstance* InInstance, uint64 CommandId)
{
	if (InInstance)
	{
		InInstance->OnInstanceCommandCompleteEvent.RemoveAll(this);
	}

	OnSuccess.Broadcast(InInstance, bSuccess);
}

#undef LOCTEXT_NAMESPACE
