#include "BlueprintNodes/K2Node_WriteInt64.h"

#include "DataTypes/DolphinDataTypesBlueprintLibrary.h"
#include "DolphinUnrealBlueprintLibrary.h"

#define LOCTEXT_NAMESPACE "UK2Node_WriteInt64"

UK2Node_WriteInt64::UK2Node_WriteInt64(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	ProxyFactoryFunctionName = GET_FUNCTION_NAME_CHECKED(UK2Node_WriteInt64Proxy, CreateProxyObjectForWait);
	ProxyFactoryClass = UK2Node_WriteInt64Proxy::StaticClass();
	ProxyClass = UK2Node_WriteInt64Proxy::StaticClass();
}

FText UK2Node_WriteInt64::GetTooltipText() const
{
	return LOCTEXT("K2Node_WriteInt64_Tooltip", "Writes an int64 to the specified (or default) Dolphin instance.");
}

FText UK2Node_WriteInt64::GetNodeTitle(ENodeTitleType::Type TitleType) const
{
	return LOCTEXT("K2Node_WriteInt64_Title", "Write Int64 to Memory");
}

FText UK2Node_WriteInt64::GetMenuCategory() const
{
	return LOCTEXT("K2Node_WriteInt64_Category", "Dolphin");
}

UK2Node_WriteInt64Proxy* UK2Node_WriteInt64Proxy::CreateProxyObjectForWait(UDolphinInstance* DolphinInstance, FDolphinUInt32 Address, TArray<FDolphinInt32> Offsets, FDolphinInt64 Value)
{
	UK2Node_WriteInt64Proxy* Proxy = NewObject<UK2Node_WriteInt64Proxy>();
	Proxy->SetFlags(RF_StrongRefOnFrame);
	Proxy->bSuccess = false;

	if (DolphinInstance != nullptr)
	{
		DolphinInstance->OnInstanceCommandCompleteEvent.AddUObject(Proxy, &UK2Node_WriteInt64Proxy::OnInstanceReady);
		DolphinInstance->OnInstanceMemoryWrite.AddUObject(Proxy, &UK2Node_WriteInt64Proxy::OnInstanceMemoryWrite);
		DolphinInstance->RequestWriteMemory(Address, Offsets, UDolphinDataTypesBlueprintLibrary::MakeUInt8ArrayFromInt64(Value.Value));
	}

	return Proxy;
}

UK2Node_WriteInt64Proxy::UK2Node_WriteInt64Proxy(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
}

void UK2Node_WriteInt64Proxy::OnInstanceMemoryWrite(UDolphinInstance* InInstance, bool bInSuccess)
{
	if (InInstance)
	{
		InInstance->OnInstanceMemoryWrite.RemoveAll(this);
	}

	bSuccess = bInSuccess;
}

void UK2Node_WriteInt64Proxy::OnInstanceReady(UDolphinInstance* InInstance, uint64 CommandId)
{
	if (InInstance)
	{
		InInstance->OnInstanceCommandCompleteEvent.RemoveAll(this);
	}

	OnSuccess.Broadcast(InInstance, bSuccess);
}

#undef LOCTEXT_NAMESPACE
