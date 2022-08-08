#include "BlueprintNodes/K2Node_ReadArrayOfUBytes.h"

#include "DolphinUnrealBlueprintLibrary.h"

#define LOCTEXT_NAMESPACE "UK2Node_ReadArrayOfUBytes"

UK2Node_ReadArrayOfUBytes::UK2Node_ReadArrayOfUBytes(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	ProxyFactoryFunctionName = GET_FUNCTION_NAME_CHECKED(UK2Node_ReadArrayOfUBytesProxy, CreateProxyObjectForWait);
	ProxyFactoryClass = UK2Node_ReadArrayOfUBytesProxy::StaticClass();
	ProxyClass = UK2Node_ReadArrayOfUBytesProxy::StaticClass();
}

FText UK2Node_ReadArrayOfUBytes::GetTooltipText() const
{
	return LOCTEXT("K2Node_ReadArrayOfUBytes_Tooltip", "Reads an array of unsigned bytes from the specified (or default) Dolphin instance.");
}

FText UK2Node_ReadArrayOfUBytes::GetNodeTitle(ENodeTitleType::Type TitleType) const
{
	return LOCTEXT("K2Node_ReadArrayOfUBytes_Title", "Read Array of UBytes from Memory");
}

FText UK2Node_ReadArrayOfUBytes::GetMenuCategory() const
{
	return LOCTEXT("K2Node_ReadArrayOfUBytes_Category", "Dolphin");
}

UK2Node_ReadArrayOfUBytesProxy* UK2Node_ReadArrayOfUBytesProxy::CreateProxyObjectForWait(UDolphinInstance* DolphinInstance, FDolphinUInt32 Address, TArray<FDolphinInt32> Offsets, int32 NumberOfBytes)
{
	UK2Node_ReadArrayOfUBytesProxy* Proxy = NewObject<UK2Node_ReadArrayOfUBytesProxy>();
	Proxy->SetFlags(RF_StrongRefOnFrame);
	Proxy->bSuccess = false;

	DolphinInstance = UDolphinUnrealBlueprintLibrary::GetDolphinInstanceOrDefault(DolphinInstance);

	if (DolphinInstance != nullptr)
	{
		DolphinInstance->OnInstanceCommandCompleteEvent.AddUObject(Proxy, &UK2Node_ReadArrayOfUBytesProxy::OnInstanceReady);
		DolphinInstance->OnInstanceMemoryRead.AddUObject(Proxy, &UK2Node_ReadArrayOfUBytesProxy::OnInstanceMemoryRead);
		DolphinInstance->RequestReadMemory(Address, Offsets, NumberOfBytes);
	}

	return Proxy;
}

UK2Node_ReadArrayOfUBytesProxy::UK2Node_ReadArrayOfUBytesProxy(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
}

void UK2Node_ReadArrayOfUBytesProxy::OnInstanceMemoryRead(UDolphinInstance* InInstance, TArray<FDolphinUInt8> InValue)
{
	if (InInstance)
	{
		InInstance->OnInstanceMemoryRead.RemoveAll(this);
	}

	Value = InValue;
	bSuccess = true;
}

void UK2Node_ReadArrayOfUBytesProxy::OnInstanceReady(UDolphinInstance* InInstance, uint64 CommandId)
{
	if (InInstance)
	{
		InInstance->OnInstanceCommandCompleteEvent.RemoveAll(this);
	}

	OnSuccess.Broadcast(InInstance, Value, bSuccess);
}

#undef LOCTEXT_NAMESPACE
