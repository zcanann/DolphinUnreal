#include "BlueprintNodes/K2Node_WriteArrayOfUBytes.h"

#include "DataTypes/DolphinDataTypesBlueprintLibrary.h"
#include "DolphinUnrealBlueprintLibrary.h"

#define LOCTEXT_NAMESPACE "UK2Node_WriteArrayOfUBytes"

UK2Node_WriteArrayOfUBytes::UK2Node_WriteArrayOfUBytes(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	ProxyFactoryFunctionName = GET_FUNCTION_NAME_CHECKED(UK2Node_WriteArrayOfUBytesProxy, CreateProxyObjectForWait);
	ProxyFactoryClass = UK2Node_WriteArrayOfUBytesProxy::StaticClass();
	ProxyClass = UK2Node_WriteArrayOfUBytesProxy::StaticClass();
}

FText UK2Node_WriteArrayOfUBytes::GetTooltipText() const
{
	return LOCTEXT("K2Node_WriteArrayOfUBytes_Tooltip", "Writes an array of unsigned bytes to the specified (or default) Dolphin instance.");
}

FText UK2Node_WriteArrayOfUBytes::GetNodeTitle(ENodeTitleType::Type TitleType) const
{
	return LOCTEXT("K2Node_WriteArrayOfUBytes_Title", "Write Array of UBytes to Memory");
}

FText UK2Node_WriteArrayOfUBytes::GetMenuCategory() const
{
	return LOCTEXT("K2Node_WriteArrayOfUBytes_Category", "Dolphin");
}

UK2Node_WriteArrayOfUBytesProxy* UK2Node_WriteArrayOfUBytesProxy::CreateProxyObjectForWait(UDolphinInstance* DolphinInstance, FDolphinUInt32 Address, TArray<FDolphinInt32> Offsets, const TArray<FDolphinUInt8>& Bytes)
{
	UK2Node_WriteArrayOfUBytesProxy* Proxy = NewObject<UK2Node_WriteArrayOfUBytesProxy>();
	Proxy->SetFlags(RF_StrongRefOnFrame);
	Proxy->bSuccess = false;

	if (DolphinInstance != nullptr)
	{
		DolphinInstance->OnInstanceCommandCompleteEvent.AddUObject(Proxy, &UK2Node_WriteArrayOfUBytesProxy::OnInstanceReady);
		DolphinInstance->OnInstanceMemoryWrite.AddUObject(Proxy, &UK2Node_WriteArrayOfUBytesProxy::OnInstanceMemoryWrite);
		DolphinInstance->RequestWriteMemory(Address, Offsets, Bytes);
	}

	return Proxy;
}

UK2Node_WriteArrayOfUBytesProxy::UK2Node_WriteArrayOfUBytesProxy(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
}

void UK2Node_WriteArrayOfUBytesProxy::OnInstanceMemoryWrite(UDolphinInstance* InInstance, bool bInSuccess)
{
	if (InInstance)
	{
		InInstance->OnInstanceMemoryWrite.RemoveAll(this);
	}

	bSuccess = bInSuccess;
}

void UK2Node_WriteArrayOfUBytesProxy::OnInstanceReady(UDolphinInstance* InInstance, uint64 CommandId)
{
	if (InInstance)
	{
		InInstance->OnInstanceCommandCompleteEvent.RemoveAll(this);
	}

	OnSuccess.Broadcast(InInstance, bSuccess);
}

#undef LOCTEXT_NAMESPACE
