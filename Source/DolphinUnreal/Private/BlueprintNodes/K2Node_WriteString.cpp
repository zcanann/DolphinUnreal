#include "BlueprintNodes/K2Node_WriteString.h"

#include "DataTypes/DolphinDataTypesBlueprintLibrary.h"
#include "DolphinUnrealBlueprintLibrary.h"

#define LOCTEXT_NAMESPACE "UK2Node_WriteString"

UK2Node_WriteString::UK2Node_WriteString(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	ProxyFactoryFunctionName = GET_FUNCTION_NAME_CHECKED(UK2Node_WriteStringProxy, CreateProxyObjectForWait);
	ProxyFactoryClass = UK2Node_WriteStringProxy::StaticClass();
	ProxyClass = UK2Node_WriteStringProxy::StaticClass();
}

FText UK2Node_WriteString::GetTooltipText() const
{
	return LOCTEXT("K2Node_WriteString_Tooltip", "Writes a string from the specified (or default) Dolphin instance.");
}

FText UK2Node_WriteString::GetNodeTitle(ENodeTitleType::Type TitleType) const
{
	return LOCTEXT("K2Node_WriteString_Title", "Write String from Memory");
}

FText UK2Node_WriteString::GetMenuCategory() const
{
	return LOCTEXT("K2Node_WriteString_Category", "Dolphin");
}

UK2Node_WriteStringProxy* UK2Node_WriteStringProxy::CreateProxyObjectForWait(UDolphinInstance* DolphinInstance, FDolphinUInt32 Address, TArray<FDolphinInt32> Offsets, FString Value)
{
	UK2Node_WriteStringProxy* Proxy = NewObject<UK2Node_WriteStringProxy>();
	Proxy->SetFlags(RF_StrongRefOnFrame);
	Proxy->bSuccess = false;

	if (DolphinInstance != nullptr)
	{
		DolphinInstance->OnInstanceCommandCompleteEvent.AddUObject(Proxy, &UK2Node_WriteStringProxy::OnInstanceWritey);
		DolphinInstance->OnInstanceMemoryWrite.AddUObject(Proxy, &UK2Node_WriteStringProxy::OnInstanceMemoryWrite);
		DolphinInstance->RequestWriteMemory(Address, Offsets, UDolphinDataTypesBlueprintLibrary::StringToUInt8Array(Value));
	}

	return Proxy;
}

UK2Node_WriteStringProxy::UK2Node_WriteStringProxy(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
}

void UK2Node_WriteStringProxy::OnInstanceMemoryWrite(UDolphinInstance* InInstance, TArray<FDolphinUInt8> InValue)
{
	if (InInstance)
	{
		InInstance->OnInstanceMemoryWrite.RemoveAll(this);
	}

	TArray<uint8> Bytes = UDolphinDataTypesBlueprintLibrary::CastUInt8ArrayToUnrealUInt8Array(InValue);
	Value.Empty();
	for (const uint8 Byte : Bytes)
	{
		Value += TCHAR(Byte);
	}
	bSuccess = true;
}

void UK2Node_WriteStringProxy::OnInstanceWritey(UDolphinInstance* InInstance, uint64 CommandId)
{
	if (InInstance)
	{
		InInstance->OnInstanceCommandCompleteEvent.RemoveAll(this);
	}

	OnSuccess.Broadcast(InInstance, Value, bSuccess);
}

#undef LOCTEXT_NAMESPACE
