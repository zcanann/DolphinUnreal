#include "BlueprintNodes/K2Node_WriteArrayOfBytes.h"

#include "DataTypes/DolphinDataTypesBlueprintLibrary.h"
#include "DolphinUnrealBlueprintLibrary.h"

#define LOCTEXT_NAMESPACE "UK2Node_WriteArrayOfBytes"

UK2Node_WriteArrayOfBytes::UK2Node_WriteArrayOfBytes(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	ProxyFactoryFunctionName = GET_FUNCTION_NAME_CHECKED(UK2Node_WriteArrayOfBytesProxy, CreateProxyObjectForWait);
	ProxyFactoryClass = UK2Node_WriteArrayOfBytesProxy::StaticClass();
	ProxyClass = UK2Node_WriteArrayOfBytesProxy::StaticClass();
}

FText UK2Node_WriteArrayOfBytes::GetTooltipText() const
{
	return LOCTEXT("K2Node_WriteArrayOfBytes_Tooltip", "Writes an array of bytes to the specified (or default) Dolphin instance.");
}

FText UK2Node_WriteArrayOfBytes::GetNodeTitle(ENodeTitleType::Type TitleType) const
{
	return LOCTEXT("K2Node_WriteArrayOfBytes_Title", "Write Array of Bytes to Memory");
}

FText UK2Node_WriteArrayOfBytes::GetMenuCategory() const
{
	return LOCTEXT("K2Node_WriteArrayOfBytes_Category", "Dolphin");
}

UK2Node_WriteArrayOfBytesProxy* UK2Node_WriteArrayOfBytesProxy::CreateProxyObjectForWait(UDolphinInstance* DolphinInstance, FDolphinUInt32 Address, TArray<FDolphinInt32> Offsets, const TArray<FDolphinUInt8>& Bytes)
{
	UK2Node_WriteArrayOfBytesProxy* Proxy = NewObject<UK2Node_WriteArrayOfBytesProxy>();
	Proxy->SetFlags(RF_StrongRefOnFrame);
	Proxy->bSuccess = false;

	if (DolphinInstance != nullptr)
	{
		DolphinInstance->OnInstanceCommandCompleteEvent.AddUObject(Proxy, &UK2Node_WriteArrayOfBytesProxy::OnInstanceReady);
		DolphinInstance->OnInstanceMemoryWrite.AddUObject(Proxy, &UK2Node_WriteArrayOfBytesProxy::OnInstanceMemoryWrite);
		DolphinInstance->RequestWriteMemory(Address, Offsets, Bytes);
	}

	return Proxy;
}

UK2Node_WriteArrayOfBytesProxy::UK2Node_WriteArrayOfBytesProxy(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
}

void UK2Node_WriteArrayOfBytesProxy::OnInstanceMemoryWrite(UDolphinInstance* InInstance, bool bInSuccess)
{
	if (InInstance)
	{
		InInstance->OnInstanceMemoryWrite.RemoveAll(this);
	}

	bSuccess = bInSuccess;
}

void UK2Node_WriteArrayOfBytesProxy::OnInstanceReady(UDolphinInstance* InInstance, uint64 CommandId)
{
	if (InInstance)
	{
		InInstance->OnInstanceCommandCompleteEvent.RemoveAll(this);
	}

	OnSuccess.Broadcast(InInstance, bSuccess);
}

#undef LOCTEXT_NAMESPACE
