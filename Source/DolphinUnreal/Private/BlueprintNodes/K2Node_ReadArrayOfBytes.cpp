#include "BlueprintNodes/K2Node_ReadArrayOfBytes.h"

#include "DataTypes/DolphinDataTypesBlueprintLibrary.h"
#include "DolphinUnrealBlueprintLibrary.h"

#define LOCTEXT_NAMESPACE "UK2Node_ReadArrayOfBytes"

UK2Node_ReadArrayOfBytes::UK2Node_ReadArrayOfBytes(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	ProxyFactoryFunctionName = GET_FUNCTION_NAME_CHECKED(UK2Node_ReadArrayOfBytesProxy, CreateProxyObjectForWait);
	ProxyFactoryClass = UK2Node_ReadArrayOfBytesProxy::StaticClass();
	ProxyClass = UK2Node_ReadArrayOfBytesProxy::StaticClass();
}

FText UK2Node_ReadArrayOfBytes::GetTooltipText() const
{
	return LOCTEXT("K2Node_ReadArrayOfBytes_Tooltip", "Reads an array of bytes from the specified (or default) Dolphin instance.");
}

FText UK2Node_ReadArrayOfBytes::GetNodeTitle(ENodeTitleType::Type TitleType) const
{
	return LOCTEXT("K2Node_ReadArrayOfBytes_Title", "Read Array of Bytes from Memory");
}

FText UK2Node_ReadArrayOfBytes::GetMenuCategory() const
{
	return LOCTEXT("K2Node_ReadArrayOfBytes_Category", "Dolphin");
}

UK2Node_ReadArrayOfBytesProxy* UK2Node_ReadArrayOfBytesProxy::CreateProxyObjectForWait(UDolphinInstance* DolphinInstance, FDolphinUInt32 Address, TArray<FDolphinInt32> Offsets, int32 NumberOfBytes)
{
	UK2Node_ReadArrayOfBytesProxy* Proxy = NewObject<UK2Node_ReadArrayOfBytesProxy>();
	Proxy->SetFlags(RF_StrongRefOnFrame);
	Proxy->bSuccess = false;

	if (DolphinInstance != nullptr)
	{
		DolphinInstance->OnInstanceCommandCompleteEvent.AddUObject(Proxy, &UK2Node_ReadArrayOfBytesProxy::OnInstanceReady);
		DolphinInstance->OnInstanceMemoryRead.AddUObject(Proxy, &UK2Node_ReadArrayOfBytesProxy::OnInstanceMemoryRead);
		DolphinInstance->RequestReadMemory(Address, Offsets, NumberOfBytes);
	}

	return Proxy;
}

UK2Node_ReadArrayOfBytesProxy::UK2Node_ReadArrayOfBytesProxy(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
}

void UK2Node_ReadArrayOfBytesProxy::OnInstanceMemoryRead(UDolphinInstance* InInstance, TArray<FDolphinUInt8> InValue)
{
	if (InInstance)
	{
		InInstance->OnInstanceMemoryRead.RemoveAll(this);
	}

	Value = UDolphinDataTypesBlueprintLibrary::CastUInt8ArrayToInt8Array(InValue);
	bSuccess = true;
}

void UK2Node_ReadArrayOfBytesProxy::OnInstanceReady(UDolphinInstance* InInstance, uint64 CommandId)
{
	if (InInstance)
	{
		InInstance->OnInstanceCommandCompleteEvent.RemoveAll(this);
	}

	OnSuccess.Broadcast(InInstance, Value, bSuccess);
}

#undef LOCTEXT_NAMESPACE
