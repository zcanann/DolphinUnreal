#include "BlueprintNodes/K2Node_ReadString.h"

#include "DataTypes/DolphinDataTypesBlueprintLibrary.h"
#include "DolphinUnrealBlueprintLibrary.h"

#define LOCTEXT_NAMESPACE "UK2Node_ReadString"

UK2Node_ReadString::UK2Node_ReadString(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	ProxyFactoryFunctionName = GET_FUNCTION_NAME_CHECKED(UK2Node_ReadStringProxy, CreateProxyObjectForWait);
	ProxyFactoryClass = UK2Node_ReadStringProxy::StaticClass();
	ProxyClass = UK2Node_ReadStringProxy::StaticClass();
}

FText UK2Node_ReadString::GetTooltipText() const
{
	return LOCTEXT("K2Node_ReadString_Tooltip", "Reads a string from the specified (or default) Dolphin instance.");
}

FText UK2Node_ReadString::GetNodeTitle(ENodeTitleType::Type TitleType) const
{
	return LOCTEXT("K2Node_ReadString_Title", "Read String from Memory");
}

FText UK2Node_ReadString::GetMenuCategory() const
{
	return LOCTEXT("K2Node_ReadString_Category", "Dolphin");
}

UK2Node_ReadStringProxy* UK2Node_ReadStringProxy::CreateProxyObjectForWait(UDolphinInstance* DolphinInstance, FDolphinUInt32 Address, TArray<FDolphinInt32> Offsets, int32 StringLength)
{
	UK2Node_ReadStringProxy* Proxy = NewObject<UK2Node_ReadStringProxy>();
	Proxy->SetFlags(RF_StrongRefOnFrame);
	Proxy->bSuccess = false;

	if (DolphinInstance != nullptr)
	{
		DolphinInstance->OnInstanceCommandCompleteEvent.AddUObject(Proxy, &UK2Node_ReadStringProxy::OnInstanceReady);
		DolphinInstance->OnInstanceMemoryRead.AddUObject(Proxy, &UK2Node_ReadStringProxy::OnInstanceMemoryRead);
		DolphinInstance->RequestReadMemory(Address, Offsets, StringLength);
	}

	return Proxy;
}

UK2Node_ReadStringProxy::UK2Node_ReadStringProxy(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
}

void UK2Node_ReadStringProxy::OnInstanceMemoryRead(UDolphinInstance* InInstance, TArray<FDolphinUInt8> InValue)
{
	if (InInstance)
	{
		InInstance->OnInstanceMemoryRead.RemoveAll(this);
	}

	TArray<uint8> Bytes = UDolphinDataTypesBlueprintLibrary::CastUInt8ArrayToUnrealUInt8Array(InValue);
	Value.Empty();
	for (const uint8 Byte : Bytes)
	{
		Value += TCHAR(Byte);
	}
	bSuccess = true;
}

void UK2Node_ReadStringProxy::OnInstanceReady(UDolphinInstance* InInstance, uint64 CommandId)
{
	if (InInstance)
	{
		InInstance->OnInstanceCommandCompleteEvent.RemoveAll(this);
	}

	OnSuccess.Broadcast(InInstance, Value, bSuccess);
}

#undef LOCTEXT_NAMESPACE
