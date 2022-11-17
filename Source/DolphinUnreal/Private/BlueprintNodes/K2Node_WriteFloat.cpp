#include "BlueprintNodes/K2Node_WriteFloat.h"

#include "DataTypes/DolphinDataTypesBlueprintLibrary.h"
#include "DolphinUnrealBlueprintLibrary.h"

#define LOCTEXT_NAMESPACE "UK2Node_WriteFloat"

UK2Node_WriteFloat::UK2Node_WriteFloat(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	ProxyFactoryFunctionName = GET_FUNCTION_NAME_CHECKED(UK2Node_WriteFloatProxy, CreateProxyObjectForWait);
	ProxyFactoryClass = UK2Node_WriteFloatProxy::StaticClass();
	ProxyClass = UK2Node_WriteFloatProxy::StaticClass();
}

FText UK2Node_WriteFloat::GetTooltipText() const
{
	return LOCTEXT("K2Node_WriteFloat_Tooltip", "Writes an float from the specified (or default) Dolphin instance.");
}

FText UK2Node_WriteFloat::GetNodeTitle(ENodeTitleType::Type TitleType) const
{
	return LOCTEXT("K2Node_WriteFloat_Title", "Write Float from Memory");
}

FText UK2Node_WriteFloat::GetMenuCategory() const
{
	return LOCTEXT("K2Node_WriteFloat_Category", "Dolphin");
}

UK2Node_WriteFloatProxy* UK2Node_WriteFloatProxy::CreateProxyObjectForWait(UDolphinInstance* DolphinInstance, FDolphinUInt32 Address, TArray<FDolphinInt32> Offsets, FDolphinFloat Value)
{
	UK2Node_WriteFloatProxy* Proxy = NewObject<UK2Node_WriteFloatProxy>();
	Proxy->SetFlags(RF_StrongRefOnFrame);
	Proxy->bSuccess = false;

	if (DolphinInstance != nullptr)
	{
		DolphinInstance->OnInstanceCommandCompleteEvent.AddUObject(Proxy, &UK2Node_WriteFloatProxy::OnInstanceWritey);
		DolphinInstance->OnInstanceMemoryWrite.AddUObject(Proxy, &UK2Node_WriteFloatProxy::OnInstanceMemoryWrite);
		DolphinInstance->RequestWriteMemory(Address, Offsets, UDolphinDataTypesBlueprintLibrary::MakeUInt8ArrayFromFloat(Value.Value));
	}

	return Proxy;
}

UK2Node_WriteFloatProxy::UK2Node_WriteFloatProxy(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
}

void UK2Node_WriteFloatProxy::OnInstanceMemoryWrite(UDolphinInstance* InInstance, TArray<FDolphinUInt8> InValue)
{
	if (InInstance)
	{
		InInstance->OnInstanceMemoryWrite.RemoveAll(this);
	}

	if (InValue.Num() == sizeof(float))
	{
		Value = UDolphinDataTypesBlueprintLibrary::MakeFloatFromBytes(InValue[0], InValue[1], InValue[2], InValue[3], true);
	}

	bSuccess = true;
}

void UK2Node_WriteFloatProxy::OnInstanceWritey(UDolphinInstance* InInstance, uint64 CommandId)
{
	if (InInstance)
	{
		InInstance->OnInstanceCommandCompleteEvent.RemoveAll(this);
	}

	OnSuccess.Broadcast(InInstance, Value, bSuccess);
}

#undef LOCTEXT_NAMESPACE
