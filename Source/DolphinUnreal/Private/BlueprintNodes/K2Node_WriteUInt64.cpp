#include "BlueprintNodes/K2Node_WriteUInt64.h"

#include "DataTypes/DolphinDataTypesBlueprintLibrary.h"
#include "DolphinUnrealBlueprintLibrary.h"

#define LOCTEXT_NAMESPACE "UK2Node_WriteUInt64"

UK2Node_WriteUInt64::UK2Node_WriteUInt64(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	ProxyFactoryFunctionName = GET_FUNCTION_NAME_CHECKED(UK2Node_WriteUInt64Proxy, CreateProxyObjectForWait);
	ProxyFactoryClass = UK2Node_WriteUInt64Proxy::StaticClass();
	ProxyClass = UK2Node_WriteUInt64Proxy::StaticClass();
}

FText UK2Node_WriteUInt64::GetTooltipText() const
{
	return LOCTEXT("K2Node_WriteUInt64_Tooltip", "Writes an uint64 to the specified (or default) Dolphin instance.");
}

FText UK2Node_WriteUInt64::GetNodeTitle(ENodeTitleType::Type TitleType) const
{
	return LOCTEXT("K2Node_WriteUInt64_Title", "Write UInt64 to Memory");
}

FText UK2Node_WriteUInt64::GetMenuCategory() const
{
	return LOCTEXT("K2Node_WriteUInt64_Category", "Dolphin");
}

UK2Node_WriteUInt64Proxy* UK2Node_WriteUInt64Proxy::CreateProxyObjectForWait(UDolphinInstance* DolphinInstance, FDolphinUInt32 Address, TArray<FDolphinInt32> Offsets, FDolphinUInt64 Value)
{
	UK2Node_WriteUInt64Proxy* Proxy = NewObject<UK2Node_WriteUInt64Proxy>();
	Proxy->SetFlags(RF_StrongRefOnFrame);
	Proxy->bSuccess = false;

	if (DolphinInstance != nullptr)
	{
		DolphinInstance->OnInstanceCommandCompleteEvent.AddUObject(Proxy, &UK2Node_WriteUInt64Proxy::OnInstanceReady);
		DolphinInstance->OnInstanceMemoryWrite.AddUObject(Proxy, &UK2Node_WriteUInt64Proxy::OnInstanceMemoryWrite);
		DolphinInstance->RequestWriteMemory(Address, Offsets, UDolphinDataTypesBlueprintLibrary::MakeUInt8ArrayFromUInt64(Value.Value));
	}

	return Proxy;
}

UK2Node_WriteUInt64Proxy::UK2Node_WriteUInt64Proxy(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
}

void UK2Node_WriteUInt64Proxy::OnInstanceMemoryWrite(UDolphinInstance* InInstance, bool bInSuccess)
{
	if (InInstance)
	{
		InInstance->OnInstanceMemoryWrite.RemoveAll(this);
	}

	bSuccess = bInSuccess;
}

void UK2Node_WriteUInt64Proxy::OnInstanceReady(UDolphinInstance* InInstance, uint64 CommandId)
{
	if (InInstance)
	{
		InInstance->OnInstanceCommandCompleteEvent.RemoveAll(this);
	}

	OnSuccess.Broadcast(InInstance, bSuccess);
}

#undef LOCTEXT_NAMESPACE
