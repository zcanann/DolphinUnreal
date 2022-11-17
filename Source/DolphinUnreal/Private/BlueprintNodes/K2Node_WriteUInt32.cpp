#include "BlueprintNodes/K2Node_WriteUInt32.h"

#include "DataTypes/DolphinDataTypesBlueprintLibrary.h"
#include "DolphinUnrealBlueprintLibrary.h"

#define LOCTEXT_NAMESPACE "UK2Node_WriteUInt32"

UK2Node_WriteUInt32::UK2Node_WriteUInt32(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	ProxyFactoryFunctionName = GET_FUNCTION_NAME_CHECKED(UK2Node_WriteUInt32Proxy, CreateProxyObjectForWait);
	ProxyFactoryClass = UK2Node_WriteUInt32Proxy::StaticClass();
	ProxyClass = UK2Node_WriteUInt32Proxy::StaticClass();
}

FText UK2Node_WriteUInt32::GetTooltipText() const
{
	return LOCTEXT("K2Node_WriteUInt32_Tooltip", "Writes an uint32 from the specified (or default) Dolphin instance.");
}

FText UK2Node_WriteUInt32::GetNodeTitle(ENodeTitleType::Type TitleType) const
{
	return LOCTEXT("K2Node_WriteUInt32_Title", "Write UInt32 from Memory");
}

FText UK2Node_WriteUInt32::GetMenuCategory() const
{
	return LOCTEXT("K2Node_WriteUInt32_Category", "Dolphin");
}

UK2Node_WriteUInt32Proxy* UK2Node_WriteUInt32Proxy::CreateProxyObjectForWait(UDolphinInstance* DolphinInstance, FDolphinUInt32 Address, TArray<FDolphinInt32> Offsets, FDolphinUInt32 Value)
{
	UK2Node_WriteUInt32Proxy* Proxy = NewObject<UK2Node_WriteUInt32Proxy>();
	Proxy->SetFlags(RF_StrongRefOnFrame);
	Proxy->bSuccess = false;

	if (DolphinInstance != nullptr)
	{
		DolphinInstance->OnInstanceCommandCompleteEvent.AddUObject(Proxy, &UK2Node_WriteUInt32Proxy::OnInstanceWritey);
		DolphinInstance->OnInstanceMemoryWrite.AddUObject(Proxy, &UK2Node_WriteUInt32Proxy::OnInstanceMemoryWrite);
		DolphinInstance->RequestWriteMemory(Address, Offsets, UDolphinDataTypesBlueprintLibrary::MakeUInt8ArrayFromUInt32(Value.Value));
	}

	return Proxy;
}

UK2Node_WriteUInt32Proxy::UK2Node_WriteUInt32Proxy(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
}

void UK2Node_WriteUInt32Proxy::OnInstanceMemoryWrite(UDolphinInstance* InInstance, TArray<FDolphinUInt8> InValue)
{
	if (InInstance)
	{
		InInstance->OnInstanceMemoryWrite.RemoveAll(this);
	}

	if (InValue.Num() == sizeof(double))
	{
		Value = UDolphinDataTypesBlueprintLibrary::MakeUInt32FromBytes(InValue[0], InValue[1], InValue[2], InValue[3], true);
	}

	bSuccess = true;
}

void UK2Node_WriteUInt32Proxy::OnInstanceWritey(UDolphinInstance* InInstance, uint64 CommandId)
{
	if (InInstance)
	{
		InInstance->OnInstanceCommandCompleteEvent.RemoveAll(this);
	}

	OnSuccess.Broadcast(InInstance, Value, bSuccess);
}

#undef LOCTEXT_NAMESPACE
