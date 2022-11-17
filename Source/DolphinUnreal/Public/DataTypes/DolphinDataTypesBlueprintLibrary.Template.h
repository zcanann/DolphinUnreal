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

	UFUNCTION(BlueprintPure, Category = "Dolphin|Dolphin Data Types", DisplayName = "Make Offset", meta = (Keywords = "Make Create Int32 int integer Offsets Array"))
	static TArray<FDolphinInt32> MakeOffset(int32 A)
	{
		return TArray<FDolphinInt32> { FDolphinInt32(A) };
	}

	UFUNCTION(BlueprintPure, Category = "Dolphin|Dolphin Data Types", DisplayName = "Make Offsets", meta = (CommutativeAssociativeBinaryOperator = "true", Keywords = "Make Create Int32 int integer Offsets Array"))
	static TArray<FDolphinInt32> MakeOffsets(int32 A, int32 B)
	{
		return TArray<FDolphinInt32> { FDolphinInt32(A), FDolphinInt32(B) };
	}

	UFUNCTION(BlueprintPure, Category = "Dolphin|Dolphin Data Types", DisplayName = "Make Offset from Hex", meta = (Keywords = "Make Create Int32 int integer Offsets Array from Hex Hexadecimal"))
	static TArray<FDolphinInt32> MakeOffsetFromHex(FString A)
	{
		return TArray<FDolphinInt32> { FDolphinInt32(FParse::HexNumber(*CleanHexString(A, 4))) };
	}

	UFUNCTION(BlueprintPure, Category = "Dolphin|Dolphin Data Types", DisplayName = "Make Offsets from Hex", meta = (CommutativeAssociativeBinaryOperator = "true", Keywords = "Make Create Int32 int integer Offsets Array from Hex Hexadecimal"))
	static TArray<FDolphinInt32> MakeOffsetsFromHex(const FString& A, const FString& B)
	{
		return TArray<FDolphinInt32> { FDolphinInt32(FParse::HexNumber(*CleanHexString(A, 4))), FDolphinInt32(FParse::HexNumber(*CleanHexString(B, 4))) };
	}

	static TArray<FDolphinUInt8> StringToUInt8Array(FString InString)
	{
		TArray<FDolphinUInt8> Result;

		for (int32 StrIdx = 0; StrIdx < InString.Len(); StrIdx++)
		{
			Result.Add(InString[StrIdx]);
		}

		return Result;
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

		HexString = CleanHexString(HexString, ByteCount);
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

	static FString CleanHexString(FString HexString, int32 ByteCount)
	{
		HexString = HexString.TrimStartAndEnd().Replace(TEXT(" "), TEXT(""));

		if (HexString.StartsWith("0x") || HexString.StartsWith("0X"))
		{
			HexString.RightChopInline(2);
		}

		while (HexString.Len() < ByteCount)
		{
			HexString = "0" + HexString;
		}

		if (HexString.Len() > ByteCount)
		{
			HexString.LeftChopInline(HexString.Len() - ByteCount);
		}

		for (int32 Index = 0; Index < HexString.Len(); Index++)
		{
			if (!CheckTCharIsHex(HexString[Index]))
			{
				HexString[Index] = '0';
			}
		}

		return HexString;
	}
};

#endif // DOLPHIN_DATA_TYPES_TEMPLATE
