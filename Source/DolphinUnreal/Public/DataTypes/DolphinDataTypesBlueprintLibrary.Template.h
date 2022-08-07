#ifdef DOLPHIN_DATA_TYPES_TEMPLATE

#pragma once

#include "BlueprintActionMenuItem.h"
#include "BlueprintFunctionNodeSpawner.h"
#include "BlueprintPaletteFavorites.h"
#include "Editor/EditorPerProjectUserSettings.h"

#include "DataTypes/DolphinDataTypes.h"

#include "DolphinDataTypesBlueprintLibrary.generated.h"

#define KCPPPWPLog(Level, Text) UE_LOG(LogDolphinDataTypesBlueprintLibraryPlugin, Level, TEXT(Text))
#define KCPPPWPLogF(Level, Format, ...) UE_LOG(LogDolphinDataTypesBlueprintLibraryPlugin, Level, TEXT(Format), __VA_ARGS__)

{{UE_HEADER}}
class UDolphinDataTypesBlueprintLibrary : public UObject
{
	GENERATED_BODY()

public:
	UDolphinDataTypesBlueprintLibrary(const class FObjectInitializer& ObjectInitializer);

	UFUNCTION()
	static void AutoFavoriteCommonDolphinFunctions()
	{
		UClass* DolphinDataTypesBlueprintLibrary = UDolphinDataTypesBlueprintLibrary::StaticClass();
		{{FAVORITES}}
	}

	{{MAKE}}
	{{CAST}}
	{{OPERATORS}}

private:
	static void AddFunctionToFavorites(UFunction* Function)
	{
		TSharedPtr<FEdGraphSchemaAction> ActionPtr = MakeShareable(new FBlueprintActionMenuItem(UBlueprintFunctionNodeSpawner::Create(Function)));
		GetMutableDefault<UEditorPerProjectUserSettings>()->BlueprintFavorites->AddFavorite(ActionPtr);
	}

	static TArray<uint8> CreateArrayFromHex(FString HexString, int32 ByteCount)
	{
		// TODO: This can probably be optimized significantly
		TArray<uint8> Bytes = TArray<uint8>();
		Bytes.AddDefaulted(ByteCount);
		HexString = HexString.TrimStartAndEnd().Replace(TEXT(" "), TEXT(""));

		if (HexString.StartsWith("0x") || HexString.StartsWith("0X"))
		{
			HexString.RightChopInline(2);
		}

		while (HexString.Len() < ByteCount)
		{
			HexString = "0" + HexString;
		}

		FString OriginalHexString = HexString;

		for (int32 Index = 0; Index < HexString.Len(); Index++)
		{
			int32 SwapIndex = Index % 2 == 0 ? Index + 1 : Index - 1;
			HexString[SwapIndex] = OriginalHexString[Index];
		}

		HexToBytes(HexString.Reverse(), Bytes.GetData());

		uint32 Okay = *reinterpret_cast<uint32*>(Bytes.GetData());

		return Bytes;
	}
};

#endif // DOLPHIN_DATA_TYPES_TEMPLATE
