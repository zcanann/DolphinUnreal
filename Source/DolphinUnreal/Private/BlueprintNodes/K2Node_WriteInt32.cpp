#include "BlueprintNodes/K2Node_WriteInt32.h"

#include "DataTypes/DolphinDataTypesBlueprintLibrary.h"
#include "DolphinUnrealBlueprintLibrary.h"

#define LOCTEXT_NAMESPACE "UK2Node_WriteInt32"

UK2Node_WriteInt32::UK2Node_WriteInt32(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	ProxyFactoryFunctionName = GET_FUNCTION_NAME_CHECKED(UK2Node_WriteInt32Proxy, CreateProxyObjectForWait);
	ProxyFactoryClass = UK2Node_WriteInt32Proxy::StaticClass();
	ProxyClass = UK2Node_WriteInt32Proxy::StaticClass();
}

FText UK2Node_WriteInt32::GetTooltipText() const
{
	return LOCTEXT("K2Node_WriteInt32_Tooltip", "Writes an int32 to the specified (or default) Dolphin instance.");
}

FText UK2Node_WriteInt32::GetNodeTitle(ENodeTitleType::Type TitleType) const
{
	return LOCTEXT("K2Node_WriteInt32_Title", "Write Int32 to Memory");
}

FText UK2Node_WriteInt32::GetMenuCategory() const
{
	return LOCTEXT("K2Node_WriteInt32_Category", "Dolphin");
}

UK2Node_WriteInt32Proxy* UK2Node_WriteInt32Proxy::CreateProxyObjectForWait(UDolphinInstance* DolphinInstance, FDolphinUInt32 Address, TArray<FDolphinInt32> Offsets, FDolphinInt32 Value)
{
	UK2Node_WriteInt32Proxy* Proxy = NewObject<UK2Node_WriteInt32Proxy>();
	Proxy->SetFlags(RF_StrongRefOnFrame);
	Proxy->bSuccess = false;

	if (DolphinInstance != nullptr)
	{
		DolphinInstance->OnInstanceCommandCompleteEvent.AddUObject(Proxy, &UK2Node_WriteInt32Proxy::OnInstanceReady);
		DolphinInstance->OnInstanceMemoryWrite.AddUObject(Proxy, &UK2Node_WriteInt32Proxy::OnInstanceMemoryWrite);
		DolphinInstance->RequestWriteMemory(Address, Offsets, UDolphinDataTypesBlueprintLibrary::MakeUInt8ArrayFromInt32(Value.Value));
	}

	return Proxy;
}

UK2Node_WriteInt32Proxy::UK2Node_WriteInt32Proxy(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
}

void UK2Node_WriteInt32Proxy::OnInstanceMemoryWrite(UDolphinInstance* InInstance, bool bInSuccess)
{
	if (InInstance)
	{
		InInstance->OnInstanceMemoryWrite.RemoveAll(this);
	}

	bSuccess = bInSuccess;
}

void UK2Node_WriteInt32Proxy::OnInstanceReady(UDolphinInstance* InInstance, uint64 CommandId)
{
	if (InInstance)
	{
		InInstance->OnInstanceCommandCompleteEvent.RemoveAll(this);
	}

	OnSuccess.Broadcast(InInstance, bSuccess);
}

#undef LOCTEXT_NAMESPACE
