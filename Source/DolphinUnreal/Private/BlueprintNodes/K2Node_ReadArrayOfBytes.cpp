#include "BlueprintNodes/K2Node_ReadArrayOfBytes.h"

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

	DolphinInstance = UDolphinUnrealBlueprintLibrary::GetDolphinInstanceOrDefault(DolphinInstance);

	if (DolphinInstance != nullptr)
	{
		DolphinInstance->OnInstanceCommandCompleteEvent.AddUObject(Proxy, &UK2Node_ReadArrayOfBytesProxy::OnInstanceReady);
		DolphinInstance->OnInstanceMemoryReadArrayOfBytes.AddUObject(Proxy, &UK2Node_ReadArrayOfBytesProxy::OnInstanceMemoryReadArrayOfBytes);
		DolphinInstance->RequestReadArrayOfBytes(Address, Offsets, NumberOfBytes);
	}

	return Proxy;
}

UK2Node_ReadArrayOfBytesProxy::UK2Node_ReadArrayOfBytesProxy(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
}

void UK2Node_ReadArrayOfBytesProxy::OnInstanceMemoryReadArrayOfBytes(UDolphinInstance* InInstance, TArray<FDolphinInt8> InValue)
{
	if (InInstance)
	{
		InInstance->OnInstanceMemoryReadArrayOfBytes.RemoveAll(this);
	}

	Value = InValue;
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
