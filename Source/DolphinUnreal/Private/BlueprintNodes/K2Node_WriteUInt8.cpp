#include "BlueprintNodes/K2Node_WriteUInt8.h"

#include "DataTypes/DolphinDataTypesBlueprintLibrary.h"
#include "DolphinUnrealBlueprintLibrary.h"

#define LOCTEXT_NAMESPACE "UK2Node_WriteUInt8"

UK2Node_WriteUInt8::UK2Node_WriteUInt8(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	ProxyFactoryFunctionName = GET_FUNCTION_NAME_CHECKED(UK2Node_WriteUInt8Proxy, CreateProxyObjectForWait);
	ProxyFactoryClass = UK2Node_WriteUInt8Proxy::StaticClass();
	ProxyClass = UK2Node_WriteUInt8Proxy::StaticClass();
}

FText UK2Node_WriteUInt8::GetTooltipText() const
{
	return LOCTEXT("K2Node_WriteUInt8_Tooltip", "Writes an uint8 from the specified (or default) Dolphin instance.");
}

FText UK2Node_WriteUInt8::GetNodeTitle(ENodeTitleType::Type TitleType) const
{
	return LOCTEXT("K2Node_WriteUInt8_Title", "Write UInt8 from Memory");
}

FText UK2Node_WriteUInt8::GetMenuCategory() const
{
	return LOCTEXT("K2Node_WriteUInt8_Category", "Dolphin");
}

UK2Node_WriteUInt8Proxy* UK2Node_WriteUInt8Proxy::CreateProxyObjectForWait(UDolphinInstance* DolphinInstance, FDolphinUInt32 Address, TArray<FDolphinInt32> Offsets, FDolphinUInt8 Value)
{
	UK2Node_WriteUInt8Proxy* Proxy = NewObject<UK2Node_WriteUInt8Proxy>();
	Proxy->SetFlags(RF_StrongRefOnFrame);
	Proxy->bSuccess = false;

	if (DolphinInstance != nullptr)
	{
		DolphinInstance->OnInstanceCommandCompleteEvent.AddUObject(Proxy, &UK2Node_WriteUInt8Proxy::OnInstanceWritey);
		DolphinInstance->OnInstanceMemoryWrite.AddUObject(Proxy, &UK2Node_WriteUInt8Proxy::OnInstanceMemoryWrite);
		DolphinInstance->RequestWriteMemory(Address, Offsets, UDolphinDataTypesBlueprintLibrary::MakeUInt8ArrayFromUInt8(Value.Value));
	}

	return Proxy;
}

UK2Node_WriteUInt8Proxy::UK2Node_WriteUInt8Proxy(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
}

void UK2Node_WriteUInt8Proxy::OnInstanceMemoryWrite(UDolphinInstance* InInstance, TArray<FDolphinUInt8> InValue)
{
	if (InInstance)
	{
		InInstance->OnInstanceMemoryWrite.RemoveAll(this);
	}

	if (InValue.Num() == sizeof(double))
	{
		Value = InValue[0];
	}

	bSuccess = true;
}

void UK2Node_WriteUInt8Proxy::OnInstanceWritey(UDolphinInstance* InInstance, uint64 CommandId)
{
	if (InInstance)
	{
		InInstance->OnInstanceCommandCompleteEvent.RemoveAll(this);
	}

	OnSuccess.Broadcast(InInstance, Value, bSuccess);
}

#undef LOCTEXT_NAMESPACE
