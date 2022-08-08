#include "BlueprintNodes/K2Node_ReadUInt32.h"

#include "DolphinUnrealBlueprintLibrary.h"

#define LOCTEXT_NAMESPACE "UK2Node_ReadUInt32"

UK2Node_ReadUInt32::UK2Node_ReadUInt32(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	ProxyFactoryFunctionName = GET_FUNCTION_NAME_CHECKED(UK2Node_ReadUInt32Proxy, CreateProxyObjectForWait);
	ProxyFactoryClass = UK2Node_ReadUInt32Proxy::StaticClass();
	ProxyClass = UK2Node_ReadUInt32Proxy::StaticClass();
}

FText UK2Node_ReadUInt32::GetTooltipText() const
{
	return LOCTEXT("K2Node_ReadUInt32_Tooltip", "Reads an uint32 from the specified (or default) Dolphin instance.");
}

FText UK2Node_ReadUInt32::GetNodeTitle(ENodeTitleType::Type TitleType) const
{
	return LOCTEXT("K2Node_ReadUInt32_Title", "Read UInt32 from Memory");
}

FText UK2Node_ReadUInt32::GetMenuCategory() const
{
	return LOCTEXT("K2Node_ReadUInt32_Category", "Dolphin");
}

UK2Node_ReadUInt32Proxy* UK2Node_ReadUInt32Proxy::CreateProxyObjectForWait(UDolphinInstance* DolphinInstance, FDolphinUInt32 Address, TArray<FDolphinInt32> Offsets)
{
	UK2Node_ReadUInt32Proxy* Proxy = NewObject<UK2Node_ReadUInt32Proxy>();
	Proxy->SetFlags(RF_StrongRefOnFrame);
	Proxy->bSuccess = false;

	DolphinInstance = UDolphinUnrealBlueprintLibrary::GetDolphinInstanceOrDefault(DolphinInstance);

	if (DolphinInstance != nullptr)
	{
		DolphinInstance->OnInstanceCommandCompleteEvent.AddUObject(Proxy, &UK2Node_ReadUInt32Proxy::OnInstanceReady);
		DolphinInstance->OnInstanceMemoryRead.AddUObject(Proxy, &UK2Node_ReadUInt32Proxy::OnInstanceMemoryRead);
		DolphinInstance->RequestReadMemory(Address, Offsets, sizeof(uint32));
	}

	return Proxy;
}

UK2Node_ReadUInt32Proxy::UK2Node_ReadUInt32Proxy(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
}

void UK2Node_ReadUInt32Proxy::OnInstanceMemoryRead(UDolphinInstance* InInstance, TArray<FDolphinUInt8> InValue)
{
	if (InInstance)
	{
		InInstance->OnInstanceMemoryRead.RemoveAll(this);
	}

	if (InValue.Num() == sizeof(double))
	{
		Value = UDolphinDataTypesBlueprintLibrary::MakeUInt32FromBytes(InValue[0], InValue[1], InValue[2], InValue[3], true);
	}

	bSuccess = true;
}

void UK2Node_ReadUInt32Proxy::OnInstanceReady(UDolphinInstance* InInstance, uint64 CommandId)
{
	if (InInstance)
	{
		InInstance->OnInstanceCommandCompleteEvent.RemoveAll(this);
	}

	OnSuccess.Broadcast(InInstance, Value, bSuccess);
}

#undef LOCTEXT_NAMESPACE
