//////////////////////////////////////////////////////////////////////////////////
// THIS C++ FILE IS GENERATED DO NOT EDIT. RUN CodeGen.py TO GENERATE THIS FILE //
//////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "BlueprintActionMenuItem.h"
#include "BlueprintFunctionNodeSpawner.h"
#include "BlueprintPaletteFavorites.h"
#include "Editor/EditorPerProjectUserSettings.h"

#include "DataTypes/DolphinDataTypes.h"

#include "DolphinDataTypesBlueprintLibrary.generated.h"

#define KCPPPWPLog(Level, Text) UE_LOG(LogDolphinDataTypesBlueprintLibraryPlugin, Level, TEXT(Text))
#define KCPPPWPLogF(Level, Format, ...) UE_LOG(LogDolphinDataTypesBlueprintLibraryPlugin, Level, TEXT(Format), __VA_ARGS__)

UCLASS(ClassGroup = "Dolphin|CPP UE4FundamentalType Wrapper", BlueprintType)
class UDolphinDataTypesBlueprintLibrary : public UObject
{
	GENERATED_BODY()

public:
	UDolphinDataTypesBlueprintLibrary(const class FObjectInitializer& ObjectInitializer);

	UFUNCTION()
	static void AutoFavoriteCommonDolphinFunctions()
	{
		UClass* DolphinDataTypesBlueprintLibrary = UDolphinDataTypesBlueprintLibrary::StaticClass();
		
		AddFunctionToFavorites(DolphinDataTypesBlueprintLibrary->FindFunctionByName(GET_FUNCTION_NAME_CHECKED(UDolphinDataTypesBlueprintLibrary, MakeUInt8)));
		AddFunctionToFavorites(DolphinDataTypesBlueprintLibrary->FindFunctionByName(GET_FUNCTION_NAME_CHECKED(UDolphinDataTypesBlueprintLibrary, MakeUInt8FromHexString)));
		AddFunctionToFavorites(DolphinDataTypesBlueprintLibrary->FindFunctionByName(GET_FUNCTION_NAME_CHECKED(UDolphinDataTypesBlueprintLibrary, MakeUInt8ArrayFromUInt8)));
		AddFunctionToFavorites(DolphinDataTypesBlueprintLibrary->FindFunctionByName(GET_FUNCTION_NAME_CHECKED(UDolphinDataTypesBlueprintLibrary, MakeUInt16)));
		AddFunctionToFavorites(DolphinDataTypesBlueprintLibrary->FindFunctionByName(GET_FUNCTION_NAME_CHECKED(UDolphinDataTypesBlueprintLibrary, MakeUInt16FromHexString)));
		AddFunctionToFavorites(DolphinDataTypesBlueprintLibrary->FindFunctionByName(GET_FUNCTION_NAME_CHECKED(UDolphinDataTypesBlueprintLibrary, MakeUInt8ArrayFromUInt16)));
		AddFunctionToFavorites(DolphinDataTypesBlueprintLibrary->FindFunctionByName(GET_FUNCTION_NAME_CHECKED(UDolphinDataTypesBlueprintLibrary, MakeUInt16FromBytes)));
		AddFunctionToFavorites(DolphinDataTypesBlueprintLibrary->FindFunctionByName(GET_FUNCTION_NAME_CHECKED(UDolphinDataTypesBlueprintLibrary, MakeUInt32)));
		AddFunctionToFavorites(DolphinDataTypesBlueprintLibrary->FindFunctionByName(GET_FUNCTION_NAME_CHECKED(UDolphinDataTypesBlueprintLibrary, MakeUInt32FromHexString)));
		AddFunctionToFavorites(DolphinDataTypesBlueprintLibrary->FindFunctionByName(GET_FUNCTION_NAME_CHECKED(UDolphinDataTypesBlueprintLibrary, MakeUInt8ArrayFromUInt32)));
		AddFunctionToFavorites(DolphinDataTypesBlueprintLibrary->FindFunctionByName(GET_FUNCTION_NAME_CHECKED(UDolphinDataTypesBlueprintLibrary, MakeUInt32FromBytes)));
		AddFunctionToFavorites(DolphinDataTypesBlueprintLibrary->FindFunctionByName(GET_FUNCTION_NAME_CHECKED(UDolphinDataTypesBlueprintLibrary, MakeUInt64)));
		AddFunctionToFavorites(DolphinDataTypesBlueprintLibrary->FindFunctionByName(GET_FUNCTION_NAME_CHECKED(UDolphinDataTypesBlueprintLibrary, MakeUInt64FromHexString)));
		AddFunctionToFavorites(DolphinDataTypesBlueprintLibrary->FindFunctionByName(GET_FUNCTION_NAME_CHECKED(UDolphinDataTypesBlueprintLibrary, MakeUInt8ArrayFromUInt64)));
		AddFunctionToFavorites(DolphinDataTypesBlueprintLibrary->FindFunctionByName(GET_FUNCTION_NAME_CHECKED(UDolphinDataTypesBlueprintLibrary, MakeUInt64FromBytes)));
		AddFunctionToFavorites(DolphinDataTypesBlueprintLibrary->FindFunctionByName(GET_FUNCTION_NAME_CHECKED(UDolphinDataTypesBlueprintLibrary, MakeInt8)));
		AddFunctionToFavorites(DolphinDataTypesBlueprintLibrary->FindFunctionByName(GET_FUNCTION_NAME_CHECKED(UDolphinDataTypesBlueprintLibrary, MakeInt8FromHexString)));
		AddFunctionToFavorites(DolphinDataTypesBlueprintLibrary->FindFunctionByName(GET_FUNCTION_NAME_CHECKED(UDolphinDataTypesBlueprintLibrary, MakeUInt8ArrayFromInt8)));
		AddFunctionToFavorites(DolphinDataTypesBlueprintLibrary->FindFunctionByName(GET_FUNCTION_NAME_CHECKED(UDolphinDataTypesBlueprintLibrary, MakeInt16)));
		AddFunctionToFavorites(DolphinDataTypesBlueprintLibrary->FindFunctionByName(GET_FUNCTION_NAME_CHECKED(UDolphinDataTypesBlueprintLibrary, MakeInt16FromHexString)));
		AddFunctionToFavorites(DolphinDataTypesBlueprintLibrary->FindFunctionByName(GET_FUNCTION_NAME_CHECKED(UDolphinDataTypesBlueprintLibrary, MakeUInt8ArrayFromInt16)));
		AddFunctionToFavorites(DolphinDataTypesBlueprintLibrary->FindFunctionByName(GET_FUNCTION_NAME_CHECKED(UDolphinDataTypesBlueprintLibrary, MakeInt16FromBytes)));
		AddFunctionToFavorites(DolphinDataTypesBlueprintLibrary->FindFunctionByName(GET_FUNCTION_NAME_CHECKED(UDolphinDataTypesBlueprintLibrary, MakeInt32)));
		AddFunctionToFavorites(DolphinDataTypesBlueprintLibrary->FindFunctionByName(GET_FUNCTION_NAME_CHECKED(UDolphinDataTypesBlueprintLibrary, MakeInt32FromHexString)));
		AddFunctionToFavorites(DolphinDataTypesBlueprintLibrary->FindFunctionByName(GET_FUNCTION_NAME_CHECKED(UDolphinDataTypesBlueprintLibrary, MakeUInt8ArrayFromInt32)));
		AddFunctionToFavorites(DolphinDataTypesBlueprintLibrary->FindFunctionByName(GET_FUNCTION_NAME_CHECKED(UDolphinDataTypesBlueprintLibrary, MakeInt32FromBytes)));
		AddFunctionToFavorites(DolphinDataTypesBlueprintLibrary->FindFunctionByName(GET_FUNCTION_NAME_CHECKED(UDolphinDataTypesBlueprintLibrary, MakeInt64)));
		AddFunctionToFavorites(DolphinDataTypesBlueprintLibrary->FindFunctionByName(GET_FUNCTION_NAME_CHECKED(UDolphinDataTypesBlueprintLibrary, MakeInt64FromHexString)));
		AddFunctionToFavorites(DolphinDataTypesBlueprintLibrary->FindFunctionByName(GET_FUNCTION_NAME_CHECKED(UDolphinDataTypesBlueprintLibrary, MakeUInt8ArrayFromInt64)));
		AddFunctionToFavorites(DolphinDataTypesBlueprintLibrary->FindFunctionByName(GET_FUNCTION_NAME_CHECKED(UDolphinDataTypesBlueprintLibrary, MakeInt64FromBytes)));
		AddFunctionToFavorites(DolphinDataTypesBlueprintLibrary->FindFunctionByName(GET_FUNCTION_NAME_CHECKED(UDolphinDataTypesBlueprintLibrary, MakeFloat)));
		AddFunctionToFavorites(DolphinDataTypesBlueprintLibrary->FindFunctionByName(GET_FUNCTION_NAME_CHECKED(UDolphinDataTypesBlueprintLibrary, MakeFloatFromHexString)));
		AddFunctionToFavorites(DolphinDataTypesBlueprintLibrary->FindFunctionByName(GET_FUNCTION_NAME_CHECKED(UDolphinDataTypesBlueprintLibrary, MakeUInt8ArrayFromFloat)));
		AddFunctionToFavorites(DolphinDataTypesBlueprintLibrary->FindFunctionByName(GET_FUNCTION_NAME_CHECKED(UDolphinDataTypesBlueprintLibrary, MakeFloatFromBytes)));
		AddFunctionToFavorites(DolphinDataTypesBlueprintLibrary->FindFunctionByName(GET_FUNCTION_NAME_CHECKED(UDolphinDataTypesBlueprintLibrary, MakeDouble)));
		AddFunctionToFavorites(DolphinDataTypesBlueprintLibrary->FindFunctionByName(GET_FUNCTION_NAME_CHECKED(UDolphinDataTypesBlueprintLibrary, MakeDoubleFromHexString)));
		AddFunctionToFavorites(DolphinDataTypesBlueprintLibrary->FindFunctionByName(GET_FUNCTION_NAME_CHECKED(UDolphinDataTypesBlueprintLibrary, MakeUInt8ArrayFromDouble)));
		AddFunctionToFavorites(DolphinDataTypesBlueprintLibrary->FindFunctionByName(GET_FUNCTION_NAME_CHECKED(UDolphinDataTypesBlueprintLibrary, MakeDoubleFromBytes)));
		AddFunctionToFavorites(DolphinDataTypesBlueprintLibrary->FindFunctionByName(GET_FUNCTION_NAME_CHECKED(UDolphinDataTypesBlueprintLibrary, Dolphin_UInt8SubtractUInt8)));
		AddFunctionToFavorites(DolphinDataTypesBlueprintLibrary->FindFunctionByName(GET_FUNCTION_NAME_CHECKED(UDolphinDataTypesBlueprintLibrary, Dolphin_UInt8AddUInt8)));
		AddFunctionToFavorites(DolphinDataTypesBlueprintLibrary->FindFunctionByName(GET_FUNCTION_NAME_CHECKED(UDolphinDataTypesBlueprintLibrary, Dolphin_UInt8MultiplyUInt8)));
		AddFunctionToFavorites(DolphinDataTypesBlueprintLibrary->FindFunctionByName(GET_FUNCTION_NAME_CHECKED(UDolphinDataTypesBlueprintLibrary, Dolphin_UInt8DivideUInt8)));
		AddFunctionToFavorites(DolphinDataTypesBlueprintLibrary->FindFunctionByName(GET_FUNCTION_NAME_CHECKED(UDolphinDataTypesBlueprintLibrary, Dolphin_UInt8EqualToUInt8)));
		AddFunctionToFavorites(DolphinDataTypesBlueprintLibrary->FindFunctionByName(GET_FUNCTION_NAME_CHECKED(UDolphinDataTypesBlueprintLibrary, Dolphin_UInt8NotEqualToUInt8)));
		AddFunctionToFavorites(DolphinDataTypesBlueprintLibrary->FindFunctionByName(GET_FUNCTION_NAME_CHECKED(UDolphinDataTypesBlueprintLibrary, Dolphin_UInt8LessThanUInt8)));
		AddFunctionToFavorites(DolphinDataTypesBlueprintLibrary->FindFunctionByName(GET_FUNCTION_NAME_CHECKED(UDolphinDataTypesBlueprintLibrary, Dolphin_UInt8LessThanOrEqualToUInt8)));
		AddFunctionToFavorites(DolphinDataTypesBlueprintLibrary->FindFunctionByName(GET_FUNCTION_NAME_CHECKED(UDolphinDataTypesBlueprintLibrary, Dolphin_UInt8GreaterThanUInt8)));
		AddFunctionToFavorites(DolphinDataTypesBlueprintLibrary->FindFunctionByName(GET_FUNCTION_NAME_CHECKED(UDolphinDataTypesBlueprintLibrary, Dolphin_UInt8GreaterThanOrEqualToUInt8)));
		AddFunctionToFavorites(DolphinDataTypesBlueprintLibrary->FindFunctionByName(GET_FUNCTION_NAME_CHECKED(UDolphinDataTypesBlueprintLibrary, Dolphin_UInt16SubtractUInt16)));
		AddFunctionToFavorites(DolphinDataTypesBlueprintLibrary->FindFunctionByName(GET_FUNCTION_NAME_CHECKED(UDolphinDataTypesBlueprintLibrary, Dolphin_UInt16AddUInt16)));
		AddFunctionToFavorites(DolphinDataTypesBlueprintLibrary->FindFunctionByName(GET_FUNCTION_NAME_CHECKED(UDolphinDataTypesBlueprintLibrary, Dolphin_UInt16MultiplyUInt16)));
		AddFunctionToFavorites(DolphinDataTypesBlueprintLibrary->FindFunctionByName(GET_FUNCTION_NAME_CHECKED(UDolphinDataTypesBlueprintLibrary, Dolphin_UInt16DivideUInt16)));
		AddFunctionToFavorites(DolphinDataTypesBlueprintLibrary->FindFunctionByName(GET_FUNCTION_NAME_CHECKED(UDolphinDataTypesBlueprintLibrary, Dolphin_UInt16EqualToUInt16)));
		AddFunctionToFavorites(DolphinDataTypesBlueprintLibrary->FindFunctionByName(GET_FUNCTION_NAME_CHECKED(UDolphinDataTypesBlueprintLibrary, Dolphin_UInt16NotEqualToUInt16)));
		AddFunctionToFavorites(DolphinDataTypesBlueprintLibrary->FindFunctionByName(GET_FUNCTION_NAME_CHECKED(UDolphinDataTypesBlueprintLibrary, Dolphin_UInt16LessThanUInt16)));
		AddFunctionToFavorites(DolphinDataTypesBlueprintLibrary->FindFunctionByName(GET_FUNCTION_NAME_CHECKED(UDolphinDataTypesBlueprintLibrary, Dolphin_UInt16LessThanOrEqualToUInt16)));
		AddFunctionToFavorites(DolphinDataTypesBlueprintLibrary->FindFunctionByName(GET_FUNCTION_NAME_CHECKED(UDolphinDataTypesBlueprintLibrary, Dolphin_UInt16GreaterThanUInt16)));
		AddFunctionToFavorites(DolphinDataTypesBlueprintLibrary->FindFunctionByName(GET_FUNCTION_NAME_CHECKED(UDolphinDataTypesBlueprintLibrary, Dolphin_UInt16GreaterThanOrEqualToUInt16)));
		AddFunctionToFavorites(DolphinDataTypesBlueprintLibrary->FindFunctionByName(GET_FUNCTION_NAME_CHECKED(UDolphinDataTypesBlueprintLibrary, Dolphin_UInt32SubtractUInt32)));
		AddFunctionToFavorites(DolphinDataTypesBlueprintLibrary->FindFunctionByName(GET_FUNCTION_NAME_CHECKED(UDolphinDataTypesBlueprintLibrary, Dolphin_UInt32AddUInt32)));
		AddFunctionToFavorites(DolphinDataTypesBlueprintLibrary->FindFunctionByName(GET_FUNCTION_NAME_CHECKED(UDolphinDataTypesBlueprintLibrary, Dolphin_UInt32MultiplyUInt32)));
		AddFunctionToFavorites(DolphinDataTypesBlueprintLibrary->FindFunctionByName(GET_FUNCTION_NAME_CHECKED(UDolphinDataTypesBlueprintLibrary, Dolphin_UInt32DivideUInt32)));
		AddFunctionToFavorites(DolphinDataTypesBlueprintLibrary->FindFunctionByName(GET_FUNCTION_NAME_CHECKED(UDolphinDataTypesBlueprintLibrary, Dolphin_UInt32EqualToUInt32)));
		AddFunctionToFavorites(DolphinDataTypesBlueprintLibrary->FindFunctionByName(GET_FUNCTION_NAME_CHECKED(UDolphinDataTypesBlueprintLibrary, Dolphin_UInt32NotEqualToUInt32)));
		AddFunctionToFavorites(DolphinDataTypesBlueprintLibrary->FindFunctionByName(GET_FUNCTION_NAME_CHECKED(UDolphinDataTypesBlueprintLibrary, Dolphin_UInt32LessThanUInt32)));
		AddFunctionToFavorites(DolphinDataTypesBlueprintLibrary->FindFunctionByName(GET_FUNCTION_NAME_CHECKED(UDolphinDataTypesBlueprintLibrary, Dolphin_UInt32LessThanOrEqualToUInt32)));
		AddFunctionToFavorites(DolphinDataTypesBlueprintLibrary->FindFunctionByName(GET_FUNCTION_NAME_CHECKED(UDolphinDataTypesBlueprintLibrary, Dolphin_UInt32GreaterThanUInt32)));
		AddFunctionToFavorites(DolphinDataTypesBlueprintLibrary->FindFunctionByName(GET_FUNCTION_NAME_CHECKED(UDolphinDataTypesBlueprintLibrary, Dolphin_UInt32GreaterThanOrEqualToUInt32)));
		AddFunctionToFavorites(DolphinDataTypesBlueprintLibrary->FindFunctionByName(GET_FUNCTION_NAME_CHECKED(UDolphinDataTypesBlueprintLibrary, Dolphin_UInt64SubtractUInt64)));
		AddFunctionToFavorites(DolphinDataTypesBlueprintLibrary->FindFunctionByName(GET_FUNCTION_NAME_CHECKED(UDolphinDataTypesBlueprintLibrary, Dolphin_UInt64AddUInt64)));
		AddFunctionToFavorites(DolphinDataTypesBlueprintLibrary->FindFunctionByName(GET_FUNCTION_NAME_CHECKED(UDolphinDataTypesBlueprintLibrary, Dolphin_UInt64MultiplyUInt64)));
		AddFunctionToFavorites(DolphinDataTypesBlueprintLibrary->FindFunctionByName(GET_FUNCTION_NAME_CHECKED(UDolphinDataTypesBlueprintLibrary, Dolphin_UInt64DivideUInt64)));
		AddFunctionToFavorites(DolphinDataTypesBlueprintLibrary->FindFunctionByName(GET_FUNCTION_NAME_CHECKED(UDolphinDataTypesBlueprintLibrary, Dolphin_UInt64EqualToUInt64)));
		AddFunctionToFavorites(DolphinDataTypesBlueprintLibrary->FindFunctionByName(GET_FUNCTION_NAME_CHECKED(UDolphinDataTypesBlueprintLibrary, Dolphin_UInt64NotEqualToUInt64)));
		AddFunctionToFavorites(DolphinDataTypesBlueprintLibrary->FindFunctionByName(GET_FUNCTION_NAME_CHECKED(UDolphinDataTypesBlueprintLibrary, Dolphin_UInt64LessThanUInt64)));
		AddFunctionToFavorites(DolphinDataTypesBlueprintLibrary->FindFunctionByName(GET_FUNCTION_NAME_CHECKED(UDolphinDataTypesBlueprintLibrary, Dolphin_UInt64LessThanOrEqualToUInt64)));
		AddFunctionToFavorites(DolphinDataTypesBlueprintLibrary->FindFunctionByName(GET_FUNCTION_NAME_CHECKED(UDolphinDataTypesBlueprintLibrary, Dolphin_UInt64GreaterThanUInt64)));
		AddFunctionToFavorites(DolphinDataTypesBlueprintLibrary->FindFunctionByName(GET_FUNCTION_NAME_CHECKED(UDolphinDataTypesBlueprintLibrary, Dolphin_UInt64GreaterThanOrEqualToUInt64)));
		AddFunctionToFavorites(DolphinDataTypesBlueprintLibrary->FindFunctionByName(GET_FUNCTION_NAME_CHECKED(UDolphinDataTypesBlueprintLibrary, Dolphin_Int8SubtractInt8)));
		AddFunctionToFavorites(DolphinDataTypesBlueprintLibrary->FindFunctionByName(GET_FUNCTION_NAME_CHECKED(UDolphinDataTypesBlueprintLibrary, Dolphin_Int8AddInt8)));
		AddFunctionToFavorites(DolphinDataTypesBlueprintLibrary->FindFunctionByName(GET_FUNCTION_NAME_CHECKED(UDolphinDataTypesBlueprintLibrary, Dolphin_Int8MultiplyInt8)));
		AddFunctionToFavorites(DolphinDataTypesBlueprintLibrary->FindFunctionByName(GET_FUNCTION_NAME_CHECKED(UDolphinDataTypesBlueprintLibrary, Dolphin_Int8DivideInt8)));
		AddFunctionToFavorites(DolphinDataTypesBlueprintLibrary->FindFunctionByName(GET_FUNCTION_NAME_CHECKED(UDolphinDataTypesBlueprintLibrary, Dolphin_Int8EqualToInt8)));
		AddFunctionToFavorites(DolphinDataTypesBlueprintLibrary->FindFunctionByName(GET_FUNCTION_NAME_CHECKED(UDolphinDataTypesBlueprintLibrary, Dolphin_Int8NotEqualToInt8)));
		AddFunctionToFavorites(DolphinDataTypesBlueprintLibrary->FindFunctionByName(GET_FUNCTION_NAME_CHECKED(UDolphinDataTypesBlueprintLibrary, Dolphin_Int8LessThanInt8)));
		AddFunctionToFavorites(DolphinDataTypesBlueprintLibrary->FindFunctionByName(GET_FUNCTION_NAME_CHECKED(UDolphinDataTypesBlueprintLibrary, Dolphin_Int8LessThanOrEqualToInt8)));
		AddFunctionToFavorites(DolphinDataTypesBlueprintLibrary->FindFunctionByName(GET_FUNCTION_NAME_CHECKED(UDolphinDataTypesBlueprintLibrary, Dolphin_Int8GreaterThanInt8)));
		AddFunctionToFavorites(DolphinDataTypesBlueprintLibrary->FindFunctionByName(GET_FUNCTION_NAME_CHECKED(UDolphinDataTypesBlueprintLibrary, Dolphin_Int8GreaterThanOrEqualToInt8)));
		AddFunctionToFavorites(DolphinDataTypesBlueprintLibrary->FindFunctionByName(GET_FUNCTION_NAME_CHECKED(UDolphinDataTypesBlueprintLibrary, Dolphin_Int16SubtractInt16)));
		AddFunctionToFavorites(DolphinDataTypesBlueprintLibrary->FindFunctionByName(GET_FUNCTION_NAME_CHECKED(UDolphinDataTypesBlueprintLibrary, Dolphin_Int16AddInt16)));
		AddFunctionToFavorites(DolphinDataTypesBlueprintLibrary->FindFunctionByName(GET_FUNCTION_NAME_CHECKED(UDolphinDataTypesBlueprintLibrary, Dolphin_Int16MultiplyInt16)));
		AddFunctionToFavorites(DolphinDataTypesBlueprintLibrary->FindFunctionByName(GET_FUNCTION_NAME_CHECKED(UDolphinDataTypesBlueprintLibrary, Dolphin_Int16DivideInt16)));
		AddFunctionToFavorites(DolphinDataTypesBlueprintLibrary->FindFunctionByName(GET_FUNCTION_NAME_CHECKED(UDolphinDataTypesBlueprintLibrary, Dolphin_Int16EqualToInt16)));
		AddFunctionToFavorites(DolphinDataTypesBlueprintLibrary->FindFunctionByName(GET_FUNCTION_NAME_CHECKED(UDolphinDataTypesBlueprintLibrary, Dolphin_Int16NotEqualToInt16)));
		AddFunctionToFavorites(DolphinDataTypesBlueprintLibrary->FindFunctionByName(GET_FUNCTION_NAME_CHECKED(UDolphinDataTypesBlueprintLibrary, Dolphin_Int16LessThanInt16)));
		AddFunctionToFavorites(DolphinDataTypesBlueprintLibrary->FindFunctionByName(GET_FUNCTION_NAME_CHECKED(UDolphinDataTypesBlueprintLibrary, Dolphin_Int16LessThanOrEqualToInt16)));
		AddFunctionToFavorites(DolphinDataTypesBlueprintLibrary->FindFunctionByName(GET_FUNCTION_NAME_CHECKED(UDolphinDataTypesBlueprintLibrary, Dolphin_Int16GreaterThanInt16)));
		AddFunctionToFavorites(DolphinDataTypesBlueprintLibrary->FindFunctionByName(GET_FUNCTION_NAME_CHECKED(UDolphinDataTypesBlueprintLibrary, Dolphin_Int16GreaterThanOrEqualToInt16)));
		AddFunctionToFavorites(DolphinDataTypesBlueprintLibrary->FindFunctionByName(GET_FUNCTION_NAME_CHECKED(UDolphinDataTypesBlueprintLibrary, Dolphin_Int32SubtractInt32)));
		AddFunctionToFavorites(DolphinDataTypesBlueprintLibrary->FindFunctionByName(GET_FUNCTION_NAME_CHECKED(UDolphinDataTypesBlueprintLibrary, Dolphin_Int32AddInt32)));
		AddFunctionToFavorites(DolphinDataTypesBlueprintLibrary->FindFunctionByName(GET_FUNCTION_NAME_CHECKED(UDolphinDataTypesBlueprintLibrary, Dolphin_Int32MultiplyInt32)));
		AddFunctionToFavorites(DolphinDataTypesBlueprintLibrary->FindFunctionByName(GET_FUNCTION_NAME_CHECKED(UDolphinDataTypesBlueprintLibrary, Dolphin_Int32DivideInt32)));
		AddFunctionToFavorites(DolphinDataTypesBlueprintLibrary->FindFunctionByName(GET_FUNCTION_NAME_CHECKED(UDolphinDataTypesBlueprintLibrary, Dolphin_Int32EqualToInt32)));
		AddFunctionToFavorites(DolphinDataTypesBlueprintLibrary->FindFunctionByName(GET_FUNCTION_NAME_CHECKED(UDolphinDataTypesBlueprintLibrary, Dolphin_Int32NotEqualToInt32)));
		AddFunctionToFavorites(DolphinDataTypesBlueprintLibrary->FindFunctionByName(GET_FUNCTION_NAME_CHECKED(UDolphinDataTypesBlueprintLibrary, Dolphin_Int32LessThanInt32)));
		AddFunctionToFavorites(DolphinDataTypesBlueprintLibrary->FindFunctionByName(GET_FUNCTION_NAME_CHECKED(UDolphinDataTypesBlueprintLibrary, Dolphin_Int32LessThanOrEqualToInt32)));
		AddFunctionToFavorites(DolphinDataTypesBlueprintLibrary->FindFunctionByName(GET_FUNCTION_NAME_CHECKED(UDolphinDataTypesBlueprintLibrary, Dolphin_Int32GreaterThanInt32)));
		AddFunctionToFavorites(DolphinDataTypesBlueprintLibrary->FindFunctionByName(GET_FUNCTION_NAME_CHECKED(UDolphinDataTypesBlueprintLibrary, Dolphin_Int32GreaterThanOrEqualToInt32)));
		AddFunctionToFavorites(DolphinDataTypesBlueprintLibrary->FindFunctionByName(GET_FUNCTION_NAME_CHECKED(UDolphinDataTypesBlueprintLibrary, Dolphin_Int64SubtractInt64)));
		AddFunctionToFavorites(DolphinDataTypesBlueprintLibrary->FindFunctionByName(GET_FUNCTION_NAME_CHECKED(UDolphinDataTypesBlueprintLibrary, Dolphin_Int64AddInt64)));
		AddFunctionToFavorites(DolphinDataTypesBlueprintLibrary->FindFunctionByName(GET_FUNCTION_NAME_CHECKED(UDolphinDataTypesBlueprintLibrary, Dolphin_Int64MultiplyInt64)));
		AddFunctionToFavorites(DolphinDataTypesBlueprintLibrary->FindFunctionByName(GET_FUNCTION_NAME_CHECKED(UDolphinDataTypesBlueprintLibrary, Dolphin_Int64DivideInt64)));
		AddFunctionToFavorites(DolphinDataTypesBlueprintLibrary->FindFunctionByName(GET_FUNCTION_NAME_CHECKED(UDolphinDataTypesBlueprintLibrary, Dolphin_Int64EqualToInt64)));
		AddFunctionToFavorites(DolphinDataTypesBlueprintLibrary->FindFunctionByName(GET_FUNCTION_NAME_CHECKED(UDolphinDataTypesBlueprintLibrary, Dolphin_Int64NotEqualToInt64)));
		AddFunctionToFavorites(DolphinDataTypesBlueprintLibrary->FindFunctionByName(GET_FUNCTION_NAME_CHECKED(UDolphinDataTypesBlueprintLibrary, Dolphin_Int64LessThanInt64)));
		AddFunctionToFavorites(DolphinDataTypesBlueprintLibrary->FindFunctionByName(GET_FUNCTION_NAME_CHECKED(UDolphinDataTypesBlueprintLibrary, Dolphin_Int64LessThanOrEqualToInt64)));
		AddFunctionToFavorites(DolphinDataTypesBlueprintLibrary->FindFunctionByName(GET_FUNCTION_NAME_CHECKED(UDolphinDataTypesBlueprintLibrary, Dolphin_Int64GreaterThanInt64)));
		AddFunctionToFavorites(DolphinDataTypesBlueprintLibrary->FindFunctionByName(GET_FUNCTION_NAME_CHECKED(UDolphinDataTypesBlueprintLibrary, Dolphin_Int64GreaterThanOrEqualToInt64)));
		AddFunctionToFavorites(DolphinDataTypesBlueprintLibrary->FindFunctionByName(GET_FUNCTION_NAME_CHECKED(UDolphinDataTypesBlueprintLibrary, Dolphin_FloatSubtractFloat)));
		AddFunctionToFavorites(DolphinDataTypesBlueprintLibrary->FindFunctionByName(GET_FUNCTION_NAME_CHECKED(UDolphinDataTypesBlueprintLibrary, Dolphin_FloatAddFloat)));
		AddFunctionToFavorites(DolphinDataTypesBlueprintLibrary->FindFunctionByName(GET_FUNCTION_NAME_CHECKED(UDolphinDataTypesBlueprintLibrary, Dolphin_FloatMultiplyFloat)));
		AddFunctionToFavorites(DolphinDataTypesBlueprintLibrary->FindFunctionByName(GET_FUNCTION_NAME_CHECKED(UDolphinDataTypesBlueprintLibrary, Dolphin_FloatDivideFloat)));
		AddFunctionToFavorites(DolphinDataTypesBlueprintLibrary->FindFunctionByName(GET_FUNCTION_NAME_CHECKED(UDolphinDataTypesBlueprintLibrary, Dolphin_FloatEqualToFloat)));
		AddFunctionToFavorites(DolphinDataTypesBlueprintLibrary->FindFunctionByName(GET_FUNCTION_NAME_CHECKED(UDolphinDataTypesBlueprintLibrary, Dolphin_FloatNotEqualToFloat)));
		AddFunctionToFavorites(DolphinDataTypesBlueprintLibrary->FindFunctionByName(GET_FUNCTION_NAME_CHECKED(UDolphinDataTypesBlueprintLibrary, Dolphin_FloatLessThanFloat)));
		AddFunctionToFavorites(DolphinDataTypesBlueprintLibrary->FindFunctionByName(GET_FUNCTION_NAME_CHECKED(UDolphinDataTypesBlueprintLibrary, Dolphin_FloatLessThanOrEqualToFloat)));
		AddFunctionToFavorites(DolphinDataTypesBlueprintLibrary->FindFunctionByName(GET_FUNCTION_NAME_CHECKED(UDolphinDataTypesBlueprintLibrary, Dolphin_FloatGreaterThanFloat)));
		AddFunctionToFavorites(DolphinDataTypesBlueprintLibrary->FindFunctionByName(GET_FUNCTION_NAME_CHECKED(UDolphinDataTypesBlueprintLibrary, Dolphin_FloatGreaterThanOrEqualToFloat)));
		AddFunctionToFavorites(DolphinDataTypesBlueprintLibrary->FindFunctionByName(GET_FUNCTION_NAME_CHECKED(UDolphinDataTypesBlueprintLibrary, Dolphin_DoubleSubtractDouble)));
		AddFunctionToFavorites(DolphinDataTypesBlueprintLibrary->FindFunctionByName(GET_FUNCTION_NAME_CHECKED(UDolphinDataTypesBlueprintLibrary, Dolphin_DoubleAddDouble)));
		AddFunctionToFavorites(DolphinDataTypesBlueprintLibrary->FindFunctionByName(GET_FUNCTION_NAME_CHECKED(UDolphinDataTypesBlueprintLibrary, Dolphin_DoubleMultiplyDouble)));
		AddFunctionToFavorites(DolphinDataTypesBlueprintLibrary->FindFunctionByName(GET_FUNCTION_NAME_CHECKED(UDolphinDataTypesBlueprintLibrary, Dolphin_DoubleDivideDouble)));
		AddFunctionToFavorites(DolphinDataTypesBlueprintLibrary->FindFunctionByName(GET_FUNCTION_NAME_CHECKED(UDolphinDataTypesBlueprintLibrary, Dolphin_DoubleEqualToDouble)));
		AddFunctionToFavorites(DolphinDataTypesBlueprintLibrary->FindFunctionByName(GET_FUNCTION_NAME_CHECKED(UDolphinDataTypesBlueprintLibrary, Dolphin_DoubleNotEqualToDouble)));
		AddFunctionToFavorites(DolphinDataTypesBlueprintLibrary->FindFunctionByName(GET_FUNCTION_NAME_CHECKED(UDolphinDataTypesBlueprintLibrary, Dolphin_DoubleLessThanDouble)));
		AddFunctionToFavorites(DolphinDataTypesBlueprintLibrary->FindFunctionByName(GET_FUNCTION_NAME_CHECKED(UDolphinDataTypesBlueprintLibrary, Dolphin_DoubleLessThanOrEqualToDouble)));
		AddFunctionToFavorites(DolphinDataTypesBlueprintLibrary->FindFunctionByName(GET_FUNCTION_NAME_CHECKED(UDolphinDataTypesBlueprintLibrary, Dolphin_DoubleGreaterThanDouble)));
		AddFunctionToFavorites(DolphinDataTypesBlueprintLibrary->FindFunctionByName(GET_FUNCTION_NAME_CHECKED(UDolphinDataTypesBlueprintLibrary, Dolphin_DoubleGreaterThanOrEqualToDouble)));

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

	UFUNCTION(BlueprintPure, Category = "Dolphin|Dolphin Data Types", DisplayName = "Make Array of UInt8 from Array of Bytes Hex String", meta = (Keywords = "Make Create Int32 int integer Offsets Array from Hex Hexadecimal"))
	static TArray<FDolphinUInt8> MakeUInt8ArrayFromArrayOfBytesHex(const FString& ArrayOfBytes)
	{
		TArray<FString> RawBytes;
		ArrayOfBytes.ParseIntoArray(RawBytes, TEXT(" "), true);
		TArray<FDolphinUInt8> Result;

		for (int32 Index = 0; Index < RawBytes.Num(); Index++)
		{
			Result.Add(FDolphinUInt8(FDolphinUInt8(FParse::HexNumber(*CleanHexString(RawBytes[Index], 1)))));
		}

		return Result;
	}

	UFUNCTION(BlueprintPure, Category = "Dolphin|Dolphin Data Types", DisplayName = "Make Table of Array of UInt8 from Array of Bytes Hex Strings", meta = (CommutativeAssociativeBinaryOperator = "true", Keywords = "Make Create Int32 int integer Offsets Array from Hex Hexadecimal"))
	static TArray<FDolphinUInt8Array> MakeUInt8ArrayTableFromArrayOfBytesHex(const FString& A, const FString& B)
	{
		TArray<FString> RawBytesA;
		A.ParseIntoArray(RawBytesA, TEXT(" "), true);
		TArray<FDolphinUInt8> ResultA;

		TArray<FString> RawBytesB;
		B.ParseIntoArray(RawBytesB, TEXT(" "), true);
		TArray<FDolphinUInt8> ResultB;

		for (int32 Index = 0; Index < RawBytesA.Num(); Index++)
		{
			ResultA.Add(FDolphinUInt8(FDolphinUInt8(FParse::HexNumber(*CleanHexString(RawBytesA[Index], 1)))));
		}

		for (int32 Index = 0; Index < RawBytesB.Num(); Index++)
		{
			ResultB.Add(FDolphinUInt8(FDolphinUInt8(FParse::HexNumber(*CleanHexString(RawBytesB[Index], 1)))));
		}

		TArray<FDolphinUInt8Array> Results;

		if (!ResultA.IsEmpty())
		{
			Results.Add(ResultA);
		}

		if (!ResultB.IsEmpty())
		{
			Results.Add(ResultB);
		}

		return Results;
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

	UFUNCTION(BlueprintPure, Category = "Dolphin|Dolphin Data Types", DisplayName = "Make Int8 Array Wrapper", meta = (Keywords = "Make Create signed Int8 char character byte ubyte Array wrapper from array"))
	static FDolphinInt8Array MakeUInt8ArrayWrapperFromInt8Array(TArray<FDolphinInt8> Values)
	{
		FDolphinInt8Array Result;
		Result.Values = Values;
		return Result;
	}

	UFUNCTION(BlueprintPure, Category = "Dolphin|Dolphin Data Types", DisplayName = "Make UInt8 Array Wrapper", meta = (Keywords = "Make Create unsigned UInt8 char character byte Array wrapper from array"))
	static FDolphinUInt8Array MakeUInt8ArrayWrapperFromUInt8Array(TArray<FDolphinUInt8> Values)
	{
		FDolphinUInt8Array Result;
		Result.Values = Values;
		return Result;
	}

	//////////////////////////////////////////////////////////////////////////////////
    //                                     MAKE                                     //
    //////////////////////////////////////////////////////////////////////////////////

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Make Dolphin UInt8", meta = (Keywords = "Make Create unsigned uint8 char byte ubyte"))
	static FDolphinUInt8 MakeUInt8(int32 Value)
	{
		return static_cast<uint8>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Make Dolphin UInt8 from Hex String", meta = (ToolTip = "Creates a Dolphin-compatible uint8 from the given hex string. Hex prefix (0x) and spaces will be ignored.", Keywords = "Make Create unsigned uint8 char byte ubyte from FString String Hex Hexadecimal"))
	static FDolphinUInt8 MakeUInt8FromHexString(FString HexString)
	{
		TArray<uint8> Bytes = CreateArrayFromHex(HexString, 1);
		return *reinterpret_cast<uint8*>(Bytes.GetData());
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Make UInt8 Array from Dolphin UInt8", meta = (Keywords = "Make Create unsigned uint8 char byte ubyte from Array of Bytes int8 uint8 char"))
	static TArray<FDolphinUInt8> MakeUInt8ArrayFromUInt8(FDolphinUInt8 Value)
	{
		TArray<FDolphinUInt8> Result;
		char* NextByte = reinterpret_cast<char*>(&Value.Value);
		for (int32 Index = 0; Index < 1; Index++)
		{
			Result.Add(MakeUInt8(*NextByte));
			NextByte++;
		}
		return Result;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Make Dolphin UInt16", meta = (Keywords = "Make Create unsigned uint16 short ushort"))
	static FDolphinUInt16 MakeUInt16(int32 Value)
	{
		return static_cast<uint16>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Make Dolphin UInt16 from Hex String", meta = (ToolTip = "Creates a Dolphin-compatible uint16 from the given hex string. Hex prefix (0x) and spaces will be ignored.", Keywords = "Make Create unsigned uint16 short ushort from FString String Hex Hexadecimal"))
	static FDolphinUInt16 MakeUInt16FromHexString(FString HexString)
	{
		TArray<uint8> Bytes = CreateArrayFromHex(HexString, 2);
		return *reinterpret_cast<uint16*>(Bytes.GetData());
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Make UInt8 Array from Dolphin UInt16", meta = (Keywords = "Make Create unsigned uint16 short ushort from Array of Bytes int8 uint8 char"))
	static TArray<FDolphinUInt8> MakeUInt8ArrayFromUInt16(FDolphinUInt16 Value)
	{
		TArray<FDolphinUInt8> Result;
		char* NextByte = reinterpret_cast<char*>(&Value.Value);
		for (int32 Index = 0; Index < 2; Index++)
		{
			Result.Add(MakeUInt8(*NextByte));
			NextByte++;
		}
		return Result;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Make Dolphin UInt16 from Bytes", meta = (Keywords = "Make Create unsigned uint16 short ushort from Array of Bytes int8 uint8 char"))
	static FDolphinUInt16 MakeUInt16FromBytes(uint8 Byte1, uint8 Byte2, bool bFirstByteIsLeastSignificant = true)
	{
		TArray<uint8> Bytes = bFirstByteIsLeastSignificant
			? TArray<uint8>({ Byte2, Byte1 })
			: TArray<uint8>({ Byte1, Byte2 });
		return *reinterpret_cast<uint16*>(Bytes.GetData());
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Make Dolphin UInt32", meta = (Keywords = "Make Create unsigned uint32 int uint integer"))
	static FDolphinUInt32 MakeUInt32(int32 Value)
	{
		return static_cast<uint32>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Make Dolphin UInt32 from Hex String", meta = (ToolTip = "Creates a Dolphin-compatible uint32 from the given hex string. Hex prefix (0x) and spaces will be ignored.", Keywords = "Make Create unsigned uint32 int uint integer from FString String Hex Hexadecimal"))
	static FDolphinUInt32 MakeUInt32FromHexString(FString HexString)
	{
		TArray<uint8> Bytes = CreateArrayFromHex(HexString, 4);
		return *reinterpret_cast<uint32*>(Bytes.GetData());
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Make UInt8 Array from Dolphin UInt32", meta = (Keywords = "Make Create unsigned uint32 int uint integer from Array of Bytes int8 uint8 char"))
	static TArray<FDolphinUInt8> MakeUInt8ArrayFromUInt32(FDolphinUInt32 Value)
	{
		TArray<FDolphinUInt8> Result;
		char* NextByte = reinterpret_cast<char*>(&Value.Value);
		for (int32 Index = 0; Index < 4; Index++)
		{
			Result.Add(MakeUInt8(*NextByte));
			NextByte++;
		}
		return Result;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Make Dolphin UInt32 from Bytes", meta = (Keywords = "Make Create unsigned uint32 int uint integer from Array of Bytes int8 uint8 char"))
	static FDolphinUInt32 MakeUInt32FromBytes(uint8 Byte1, uint8 Byte2, uint8 Byte3, uint8 Byte4, bool bFirstByteIsLeastSignificant = true)
	{
		TArray<uint8> Bytes = bFirstByteIsLeastSignificant
			? TArray<uint8>({ Byte4, Byte3, Byte2, Byte1 })
			: TArray<uint8>({ Byte1, Byte2, Byte3, Byte4 });
		return *reinterpret_cast<uint32*>(Bytes.GetData());
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Make Dolphin UInt64", meta = (Keywords = "Make Create unsigned uint64 long int ulong integer"))
	static FDolphinUInt64 MakeUInt64(int64 Value)
	{
		return static_cast<uint64>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Make Dolphin UInt64 from Hex String", meta = (ToolTip = "Creates a Dolphin-compatible uint64 from the given hex string. Hex prefix (0x) and spaces will be ignored.", Keywords = "Make Create unsigned uint64 long int ulong integer from FString String Hex Hexadecimal"))
	static FDolphinUInt64 MakeUInt64FromHexString(FString HexString)
	{
		TArray<uint8> Bytes = CreateArrayFromHex(HexString, 8);
		return *reinterpret_cast<uint64*>(Bytes.GetData());
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Make UInt8 Array from Dolphin UInt64", meta = (Keywords = "Make Create unsigned uint64 long int ulong integer from Array of Bytes int8 uint8 char"))
	static TArray<FDolphinUInt8> MakeUInt8ArrayFromUInt64(FDolphinUInt64 Value)
	{
		TArray<FDolphinUInt8> Result;
		char* NextByte = reinterpret_cast<char*>(&Value.Value);
		for (int32 Index = 0; Index < 8; Index++)
		{
			Result.Add(MakeUInt8(*NextByte));
			NextByte++;
		}
		return Result;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Make Dolphin UInt64 from Bytes", meta = (Keywords = "Make Create unsigned uint64 long int ulong integer from Array of Bytes int8 uint8 char"))
	static FDolphinUInt64 MakeUInt64FromBytes(uint8 Byte1, uint8 Byte2, uint8 Byte3, uint8 Byte4, uint8 Byte5, uint8 Byte6, uint8 Byte7, uint8 Byte8, bool bFirstByteIsLeastSignificant = true)
	{
		TArray<uint8> Bytes = bFirstByteIsLeastSignificant
			? TArray<uint8>({ Byte8, Byte7, Byte6, Byte5, Byte4, Byte3, Byte2, Byte1 })
			: TArray<uint8>({ Byte1, Byte2, Byte3, Byte4, Byte5, Byte6, Byte7, Byte8 });
		return *reinterpret_cast<uint64*>(Bytes.GetData());
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Make Dolphin Int8", meta = (Keywords = "Make Create signed int8 char byte"))
	static FDolphinInt8 MakeInt8(int32 Value)
	{
		return static_cast<int8>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Make Dolphin Int8 from Hex String", meta = (ToolTip = "Creates a Dolphin-compatible int8 from the given hex string. Hex prefix (0x) and spaces will be ignored.", Keywords = "Make Create signed int8 char byte from FString String Hex Hexadecimal"))
	static FDolphinInt8 MakeInt8FromHexString(FString HexString)
	{
		TArray<uint8> Bytes = CreateArrayFromHex(HexString, 1);
		return *reinterpret_cast<int8*>(Bytes.GetData());
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Make UInt8 Array from Dolphin Int8", meta = (Keywords = "Make Create signed int8 char byte from Array of Bytes int8 uint8 char"))
	static TArray<FDolphinUInt8> MakeUInt8ArrayFromInt8(FDolphinInt8 Value)
	{
		TArray<FDolphinUInt8> Result;
		char* NextByte = reinterpret_cast<char*>(&Value.Value);
		for (int32 Index = 0; Index < 1; Index++)
		{
			Result.Add(MakeUInt8(*NextByte));
			NextByte++;
		}
		return Result;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Make Dolphin Int16", meta = (Keywords = "Make Create signed int16 short"))
	static FDolphinInt16 MakeInt16(int32 Value)
	{
		return static_cast<int16>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Make Dolphin Int16 from Hex String", meta = (ToolTip = "Creates a Dolphin-compatible int16 from the given hex string. Hex prefix (0x) and spaces will be ignored.", Keywords = "Make Create signed int16 short from FString String Hex Hexadecimal"))
	static FDolphinInt16 MakeInt16FromHexString(FString HexString)
	{
		TArray<uint8> Bytes = CreateArrayFromHex(HexString, 2);
		return *reinterpret_cast<int16*>(Bytes.GetData());
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Make UInt8 Array from Dolphin Int16", meta = (Keywords = "Make Create signed int16 short from Array of Bytes int8 uint8 char"))
	static TArray<FDolphinUInt8> MakeUInt8ArrayFromInt16(FDolphinInt16 Value)
	{
		TArray<FDolphinUInt8> Result;
		char* NextByte = reinterpret_cast<char*>(&Value.Value);
		for (int32 Index = 0; Index < 2; Index++)
		{
			Result.Add(MakeUInt8(*NextByte));
			NextByte++;
		}
		return Result;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Make Dolphin Int16 from Bytes", meta = (Keywords = "Make Create signed int16 short from Array of Bytes int8 uint8 char"))
	static FDolphinInt16 MakeInt16FromBytes(uint8 Byte1, uint8 Byte2, bool bFirstByteIsLeastSignificant = true)
	{
		TArray<uint8> Bytes = bFirstByteIsLeastSignificant
			? TArray<uint8>({ Byte2, Byte1 })
			: TArray<uint8>({ Byte1, Byte2 });
		return *reinterpret_cast<int16*>(Bytes.GetData());
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Make Dolphin Int32", meta = (Keywords = "Make Create signed int32 int int integer"))
	static FDolphinInt32 MakeInt32(int32 Value)
	{
		return static_cast<int32>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Make Dolphin Int32 from Hex String", meta = (ToolTip = "Creates a Dolphin-compatible int32 from the given hex string. Hex prefix (0x) and spaces will be ignored.", Keywords = "Make Create signed int32 int int integer from FString String Hex Hexadecimal"))
	static FDolphinInt32 MakeInt32FromHexString(FString HexString)
	{
		TArray<uint8> Bytes = CreateArrayFromHex(HexString, 4);
		return *reinterpret_cast<int32*>(Bytes.GetData());
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Make UInt8 Array from Dolphin Int32", meta = (Keywords = "Make Create signed int32 int int integer from Array of Bytes int8 uint8 char"))
	static TArray<FDolphinUInt8> MakeUInt8ArrayFromInt32(FDolphinInt32 Value)
	{
		TArray<FDolphinUInt8> Result;
		char* NextByte = reinterpret_cast<char*>(&Value.Value);
		for (int32 Index = 0; Index < 4; Index++)
		{
			Result.Add(MakeUInt8(*NextByte));
			NextByte++;
		}
		return Result;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Make Dolphin Int32 from Bytes", meta = (Keywords = "Make Create signed int32 int int integer from Array of Bytes int8 uint8 char"))
	static FDolphinInt32 MakeInt32FromBytes(uint8 Byte1, uint8 Byte2, uint8 Byte3, uint8 Byte4, bool bFirstByteIsLeastSignificant = true)
	{
		TArray<uint8> Bytes = bFirstByteIsLeastSignificant
			? TArray<uint8>({ Byte4, Byte3, Byte2, Byte1 })
			: TArray<uint8>({ Byte1, Byte2, Byte3, Byte4 });
		return *reinterpret_cast<int32*>(Bytes.GetData());
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Make Dolphin Int64", meta = (Keywords = "Make Create signed int64 long int integer"))
	static FDolphinInt64 MakeInt64(int64 Value)
	{
		return static_cast<int64>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Make Dolphin Int64 from Hex String", meta = (ToolTip = "Creates a Dolphin-compatible int64 from the given hex string. Hex prefix (0x) and spaces will be ignored.", Keywords = "Make Create signed int64 long int integer from FString String Hex Hexadecimal"))
	static FDolphinInt64 MakeInt64FromHexString(FString HexString)
	{
		TArray<uint8> Bytes = CreateArrayFromHex(HexString, 8);
		return *reinterpret_cast<int64*>(Bytes.GetData());
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Make UInt8 Array from Dolphin Int64", meta = (Keywords = "Make Create signed int64 long int integer from Array of Bytes int8 uint8 char"))
	static TArray<FDolphinUInt8> MakeUInt8ArrayFromInt64(FDolphinInt64 Value)
	{
		TArray<FDolphinUInt8> Result;
		char* NextByte = reinterpret_cast<char*>(&Value.Value);
		for (int32 Index = 0; Index < 8; Index++)
		{
			Result.Add(MakeUInt8(*NextByte));
			NextByte++;
		}
		return Result;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Make Dolphin Int64 from Bytes", meta = (Keywords = "Make Create signed int64 long int integer from Array of Bytes int8 uint8 char"))
	static FDolphinInt64 MakeInt64FromBytes(uint8 Byte1, uint8 Byte2, uint8 Byte3, uint8 Byte4, uint8 Byte5, uint8 Byte6, uint8 Byte7, uint8 Byte8, bool bFirstByteIsLeastSignificant = true)
	{
		TArray<uint8> Bytes = bFirstByteIsLeastSignificant
			? TArray<uint8>({ Byte8, Byte7, Byte6, Byte5, Byte4, Byte3, Byte2, Byte1 })
			: TArray<uint8>({ Byte1, Byte2, Byte3, Byte4, Byte5, Byte6, Byte7, Byte8 });
		return *reinterpret_cast<int64*>(Bytes.GetData());
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Make Dolphin Float", meta = (Keywords = "Make Create float decimal single single-precision"))
	static FDolphinFloat MakeFloat(float Value)
	{
		return static_cast<float>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Make Dolphin Float from Hex String", meta = (ToolTip = "Creates a Dolphin-compatible float from the given hex string. Hex prefix (0x) and spaces will be ignored.", Keywords = "Make Create float decimal single single-precision from FString String Hex Hexadecimal"))
	static FDolphinFloat MakeFloatFromHexString(FString HexString)
	{
		TArray<uint8> Bytes = CreateArrayFromHex(HexString, 4);
		return *reinterpret_cast<float*>(Bytes.GetData());
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Make UInt8 Array from Dolphin Float", meta = (Keywords = "Make Create float decimal single single-precision from Array of Bytes int8 uint8 char"))
	static TArray<FDolphinUInt8> MakeUInt8ArrayFromFloat(FDolphinFloat Value)
	{
		TArray<FDolphinUInt8> Result;
		char* NextByte = reinterpret_cast<char*>(&Value.Value);
		for (int32 Index = 0; Index < 4; Index++)
		{
			Result.Add(MakeUInt8(*NextByte));
			NextByte++;
		}
		return Result;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Make Dolphin Float from Bytes", meta = (Keywords = "Make Create float decimal single single-precision from Array of Bytes int8 uint8 char"))
	static FDolphinFloat MakeFloatFromBytes(uint8 Byte1, uint8 Byte2, uint8 Byte3, uint8 Byte4, bool bFirstByteIsLeastSignificant = true)
	{
		TArray<uint8> Bytes = bFirstByteIsLeastSignificant
			? TArray<uint8>({ Byte4, Byte3, Byte2, Byte1 })
			: TArray<uint8>({ Byte1, Byte2, Byte3, Byte4 });
		return *reinterpret_cast<float*>(Bytes.GetData());
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Make Dolphin Double", meta = (Keywords = "Make Create double decimal double-precision float"))
	static FDolphinDouble MakeDouble(float Value)
	{
		return static_cast<double>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Make Dolphin Double from Hex String", meta = (ToolTip = "Creates a Dolphin-compatible double from the given hex string. Hex prefix (0x) and spaces will be ignored.", Keywords = "Make Create double decimal double-precision float from FString String Hex Hexadecimal"))
	static FDolphinDouble MakeDoubleFromHexString(FString HexString)
	{
		TArray<uint8> Bytes = CreateArrayFromHex(HexString, 8);
		return *reinterpret_cast<double*>(Bytes.GetData());
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Make UInt8 Array from Dolphin Double", meta = (Keywords = "Make Create double decimal double-precision float from Array of Bytes int8 uint8 char"))
	static TArray<FDolphinUInt8> MakeUInt8ArrayFromDouble(FDolphinDouble Value)
	{
		TArray<FDolphinUInt8> Result;
		char* NextByte = reinterpret_cast<char*>(&Value.Value);
		for (int32 Index = 0; Index < 8; Index++)
		{
			Result.Add(MakeUInt8(*NextByte));
			NextByte++;
		}
		return Result;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Make Dolphin Double from Bytes", meta = (Keywords = "Make Create double decimal double-precision float from Array of Bytes int8 uint8 char"))
	static FDolphinDouble MakeDoubleFromBytes(uint8 Byte1, uint8 Byte2, uint8 Byte3, uint8 Byte4, uint8 Byte5, uint8 Byte6, uint8 Byte7, uint8 Byte8, bool bFirstByteIsLeastSignificant = true)
	{
		TArray<uint8> Bytes = bFirstByteIsLeastSignificant
			? TArray<uint8>({ Byte8, Byte7, Byte6, Byte5, Byte4, Byte3, Byte2, Byte1 })
			: TArray<uint8>({ Byte1, Byte2, Byte3, Byte4, Byte5, Byte6, Byte7, Byte8 });
		return *reinterpret_cast<double*>(Bytes.GetData());
	}


	//////////////////////////////////////////////////////////////////////////////////
    //                                     CAST                                     //
    //////////////////////////////////////////////////////////////////////////////////

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast UInt8 to UInt16", meta = (Keywords = "Cast Convert UInt8 unsigned uint8 char byte ubyte to UInt16 unsigned uint16 short ushort"))
	static FDolphinUInt16 CastUInt8ToUInt16(const FDolphinUInt8& Value)
	{
		return static_cast<uint16>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast UInt8 to UInt32", meta = (Keywords = "Cast Convert UInt8 unsigned uint8 char byte ubyte to UInt32 unsigned uint32 int uint integer"))
	static FDolphinUInt32 CastUInt8ToUInt32(const FDolphinUInt8& Value)
	{
		return static_cast<uint32>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast UInt8 to UInt64", meta = (Keywords = "Cast Convert UInt8 unsigned uint8 char byte ubyte to UInt64 unsigned uint64 long int ulong integer"))
	static FDolphinUInt64 CastUInt8ToUInt64(const FDolphinUInt8& Value)
	{
		return static_cast<uint64>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast UInt8 to Int8", meta = (Keywords = "Cast Convert UInt8 unsigned uint8 char byte ubyte to Int8 signed int8 char byte"))
	static FDolphinInt8 CastUInt8ToInt8(const FDolphinUInt8& Value)
	{
		return static_cast<int8>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast UInt8 to Int16", meta = (Keywords = "Cast Convert UInt8 unsigned uint8 char byte ubyte to Int16 signed int16 short"))
	static FDolphinInt16 CastUInt8ToInt16(const FDolphinUInt8& Value)
	{
		return static_cast<int16>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast UInt8 to Int32", meta = (Keywords = "Cast Convert UInt8 unsigned uint8 char byte ubyte to Int32 signed int32 int int integer"))
	static FDolphinInt32 CastUInt8ToInt32(const FDolphinUInt8& Value)
	{
		return static_cast<int32>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast UInt8 to Int64", meta = (Keywords = "Cast Convert UInt8 unsigned uint8 char byte ubyte to Int64 signed int64 long int integer"))
	static FDolphinInt64 CastUInt8ToInt64(const FDolphinUInt8& Value)
	{
		return static_cast<int64>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast UInt8 to Float", meta = (Keywords = "Cast Convert UInt8 unsigned uint8 char byte ubyte to Float float decimal single single-precision"))
	static FDolphinFloat CastUInt8ToFloat(const FDolphinUInt8& Value)
	{
		return static_cast<float>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast UInt8 to Double", meta = (Keywords = "Cast Convert UInt8 unsigned uint8 char byte ubyte to Double double decimal double-precision float"))
	static FDolphinDouble CastUInt8ToDouble(const FDolphinUInt8& Value)
	{
		return static_cast<double>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast UInt8 to Unreal uint8", meta = (Keywords = "Cast Convert UInt8 unsigned uint8 char byte ubyte to UInt8 unsigned uint8 char byte ubyte"))
	static uint8 CastUInt8ToUnrealuint8(const FDolphinUInt8& Value)
	{
		return static_cast<uint8>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast UInt8 to Unreal int32", meta = (Keywords = "Cast Convert UInt8 unsigned uint8 char byte ubyte to Int32 signed int32 int int integer"))
	static int32 CastUInt8ToUnrealint32(const FDolphinUInt8& Value)
	{
		return static_cast<int32>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast UInt8 to Unreal int64", meta = (Keywords = "Cast Convert UInt8 unsigned uint8 char byte ubyte to Int64 signed int64 long int integer"))
	static int64 CastUInt8ToUnrealint64(const FDolphinUInt8& Value)
	{
		return static_cast<int64>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast UInt8 to Unreal float", meta = (Keywords = "Cast Convert UInt8 unsigned uint8 char byte ubyte to Float float decimal single single-precision"))
	static float CastUInt8ToUnrealfloat(const FDolphinUInt8& Value)
	{
		return static_cast<float>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast UInt8 Array to UInt16 Array", meta = (Keywords = "Cast Convert Array UInt8 unsigned uint8 char byte ubyte to UInt16 unsigned uint16 short ushort"))
	static TArray<FDolphinUInt16> CastUInt8ArrayToUInt16Array(const TArray<FDolphinUInt8>& Value)
	{
		TArray<FDolphinUInt16> Results;
		for (const FDolphinUInt8& Next : Value)
		{
			Results.Add(CastUInt8ToUInt16(Next));
		}
		return Results;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast UInt8 Array to UInt32 Array", meta = (Keywords = "Cast Convert Array UInt8 unsigned uint8 char byte ubyte to UInt32 unsigned uint32 int uint integer"))
	static TArray<FDolphinUInt32> CastUInt8ArrayToUInt32Array(const TArray<FDolphinUInt8>& Value)
	{
		TArray<FDolphinUInt32> Results;
		for (const FDolphinUInt8& Next : Value)
		{
			Results.Add(CastUInt8ToUInt32(Next));
		}
		return Results;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast UInt8 Array to UInt64 Array", meta = (Keywords = "Cast Convert Array UInt8 unsigned uint8 char byte ubyte to UInt64 unsigned uint64 long int ulong integer"))
	static TArray<FDolphinUInt64> CastUInt8ArrayToUInt64Array(const TArray<FDolphinUInt8>& Value)
	{
		TArray<FDolphinUInt64> Results;
		for (const FDolphinUInt8& Next : Value)
		{
			Results.Add(CastUInt8ToUInt64(Next));
		}
		return Results;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast UInt8 Array to Int8 Array", meta = (Keywords = "Cast Convert Array UInt8 unsigned uint8 char byte ubyte to Int8 signed int8 char byte"))
	static TArray<FDolphinInt8> CastUInt8ArrayToInt8Array(const TArray<FDolphinUInt8>& Value)
	{
		TArray<FDolphinInt8> Results;
		for (const FDolphinUInt8& Next : Value)
		{
			Results.Add(CastUInt8ToInt8(Next));
		}
		return Results;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast UInt8 Array to Int16 Array", meta = (Keywords = "Cast Convert Array UInt8 unsigned uint8 char byte ubyte to Int16 signed int16 short"))
	static TArray<FDolphinInt16> CastUInt8ArrayToInt16Array(const TArray<FDolphinUInt8>& Value)
	{
		TArray<FDolphinInt16> Results;
		for (const FDolphinUInt8& Next : Value)
		{
			Results.Add(CastUInt8ToInt16(Next));
		}
		return Results;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast UInt8 Array to Int32 Array", meta = (Keywords = "Cast Convert Array UInt8 unsigned uint8 char byte ubyte to Int32 signed int32 int int integer"))
	static TArray<FDolphinInt32> CastUInt8ArrayToInt32Array(const TArray<FDolphinUInt8>& Value)
	{
		TArray<FDolphinInt32> Results;
		for (const FDolphinUInt8& Next : Value)
		{
			Results.Add(CastUInt8ToInt32(Next));
		}
		return Results;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast UInt8 Array to Int64 Array", meta = (Keywords = "Cast Convert Array UInt8 unsigned uint8 char byte ubyte to Int64 signed int64 long int integer"))
	static TArray<FDolphinInt64> CastUInt8ArrayToInt64Array(const TArray<FDolphinUInt8>& Value)
	{
		TArray<FDolphinInt64> Results;
		for (const FDolphinUInt8& Next : Value)
		{
			Results.Add(CastUInt8ToInt64(Next));
		}
		return Results;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast UInt8 Array to Float Array", meta = (Keywords = "Cast Convert Array UInt8 unsigned uint8 char byte ubyte to Float float decimal single single-precision"))
	static TArray<FDolphinFloat> CastUInt8ArrayToFloatArray(const TArray<FDolphinUInt8>& Value)
	{
		TArray<FDolphinFloat> Results;
		for (const FDolphinUInt8& Next : Value)
		{
			Results.Add(CastUInt8ToFloat(Next));
		}
		return Results;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast UInt8 Array to Double Array", meta = (Keywords = "Cast Convert Array UInt8 unsigned uint8 char byte ubyte to Double double decimal double-precision float"))
	static TArray<FDolphinDouble> CastUInt8ArrayToDoubleArray(const TArray<FDolphinUInt8>& Value)
	{
		TArray<FDolphinDouble> Results;
		for (const FDolphinUInt8& Next : Value)
		{
			Results.Add(CastUInt8ToDouble(Next));
		}
		return Results;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast UInt8 Array to Unreal uint8 Array", meta = (Keywords = "Cast Convert UInt8 unsigned uint8 char byte ubyte Array to UInt8 unsigned uint8 char byte ubyte"))
	static TArray<uint8> CastUInt8ArrayToUnrealUInt8Array(const TArray<FDolphinUInt8>& Value)
	{
		TArray<uint8> Results;
		for (const FDolphinUInt8& Next : Value)
		{
			Results.Add(static_cast<uint8>(Next));
		}
		return Results;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast UInt8 Array to Unreal int32 Array", meta = (Keywords = "Cast Convert UInt8 unsigned uint8 char byte ubyte Array to Int32 signed int32 int int integer"))
	static TArray<int32> CastUInt8ArrayToUnrealInt32Array(const TArray<FDolphinUInt8>& Value)
	{
		TArray<int32> Results;
		for (const FDolphinUInt8& Next : Value)
		{
			Results.Add(static_cast<int32>(Next));
		}
		return Results;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast UInt8 Array to Unreal int64 Array", meta = (Keywords = "Cast Convert UInt8 unsigned uint8 char byte ubyte Array to Int64 signed int64 long int integer"))
	static TArray<int64> CastUInt8ArrayToUnrealInt64Array(const TArray<FDolphinUInt8>& Value)
	{
		TArray<int64> Results;
		for (const FDolphinUInt8& Next : Value)
		{
			Results.Add(static_cast<int64>(Next));
		}
		return Results;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast UInt8 Array to Unreal float Array", meta = (Keywords = "Cast Convert UInt8 unsigned uint8 char byte ubyte Array to Float float decimal single single-precision"))
	static TArray<float> CastUInt8ArrayToUnrealFloatArray(const TArray<FDolphinUInt8>& Value)
	{
		TArray<float> Results;
		for (const FDolphinUInt8& Next : Value)
		{
			Results.Add(static_cast<float>(Next));
		}
		return Results;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Unreal uint8 Array to UInt8 Array", meta = (Keywords = "Cast Convert UInt8 unsigned uint8 char byte ubyte Array to UInt8 unsigned uint8 char byte ubyte"))
	static TArray<FDolphinUInt8> CastUnrealUInt8ArrayToUInt8Array(const TArray<uint8>& Value)
	{
		TArray<FDolphinUInt8> Results;
		for (const uint8& Next : Value)
		{
			Results.Add(static_cast<uint8>(Next));
		}
		return Results;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Unreal int32 Array to UInt8 Array", meta = (Keywords = "Cast Convert UInt8 unsigned uint8 char byte ubyte Array to Int32 signed int32 int int integer"))
	static TArray<FDolphinUInt8> CastUnrealInt32ArrayToUInt8Array(const TArray<int32>& Value)
	{
		TArray<FDolphinUInt8> Results;
		for (const int32& Next : Value)
		{
			Results.Add(static_cast<uint8>(Next));
		}
		return Results;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Unreal int64 Array to UInt8 Array", meta = (Keywords = "Cast Convert UInt8 unsigned uint8 char byte ubyte Array to Int64 signed int64 long int integer"))
	static TArray<FDolphinUInt8> CastUnrealInt64ArrayToUInt8Array(const TArray<int64>& Value)
	{
		TArray<FDolphinUInt8> Results;
		for (const int64& Next : Value)
		{
			Results.Add(static_cast<uint8>(Next));
		}
		return Results;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Unreal float Array to UInt8 Array", meta = (Keywords = "Cast Convert UInt8 unsigned uint8 char byte ubyte Array to Float float decimal single single-precision"))
	static TArray<FDolphinUInt8> CastUnrealFloatArrayToUInt8Array(const TArray<float>& Value)
	{
		TArray<FDolphinUInt8> Results;
		for (const float& Next : Value)
		{
			Results.Add(static_cast<uint8>(Next));
		}
		return Results;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast UInt16 to UInt8", meta = (Keywords = "Cast Convert UInt16 unsigned uint16 short ushort to UInt8 unsigned uint8 char byte ubyte"))
	static FDolphinUInt8 CastUInt16ToUInt8(const FDolphinUInt16& Value)
	{
		return static_cast<uint8>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast UInt16 to UInt32", meta = (Keywords = "Cast Convert UInt16 unsigned uint16 short ushort to UInt32 unsigned uint32 int uint integer"))
	static FDolphinUInt32 CastUInt16ToUInt32(const FDolphinUInt16& Value)
	{
		return static_cast<uint32>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast UInt16 to UInt64", meta = (Keywords = "Cast Convert UInt16 unsigned uint16 short ushort to UInt64 unsigned uint64 long int ulong integer"))
	static FDolphinUInt64 CastUInt16ToUInt64(const FDolphinUInt16& Value)
	{
		return static_cast<uint64>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast UInt16 to Int8", meta = (Keywords = "Cast Convert UInt16 unsigned uint16 short ushort to Int8 signed int8 char byte"))
	static FDolphinInt8 CastUInt16ToInt8(const FDolphinUInt16& Value)
	{
		return static_cast<int8>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast UInt16 to Int16", meta = (Keywords = "Cast Convert UInt16 unsigned uint16 short ushort to Int16 signed int16 short"))
	static FDolphinInt16 CastUInt16ToInt16(const FDolphinUInt16& Value)
	{
		return static_cast<int16>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast UInt16 to Int32", meta = (Keywords = "Cast Convert UInt16 unsigned uint16 short ushort to Int32 signed int32 int int integer"))
	static FDolphinInt32 CastUInt16ToInt32(const FDolphinUInt16& Value)
	{
		return static_cast<int32>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast UInt16 to Int64", meta = (Keywords = "Cast Convert UInt16 unsigned uint16 short ushort to Int64 signed int64 long int integer"))
	static FDolphinInt64 CastUInt16ToInt64(const FDolphinUInt16& Value)
	{
		return static_cast<int64>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast UInt16 to Float", meta = (Keywords = "Cast Convert UInt16 unsigned uint16 short ushort to Float float decimal single single-precision"))
	static FDolphinFloat CastUInt16ToFloat(const FDolphinUInt16& Value)
	{
		return static_cast<float>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast UInt16 to Double", meta = (Keywords = "Cast Convert UInt16 unsigned uint16 short ushort to Double double decimal double-precision float"))
	static FDolphinDouble CastUInt16ToDouble(const FDolphinUInt16& Value)
	{
		return static_cast<double>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast UInt16 to Unreal uint8", meta = (Keywords = "Cast Convert UInt16 unsigned uint16 short ushort to UInt8 unsigned uint8 char byte ubyte"))
	static uint8 CastUInt16ToUnrealuint8(const FDolphinUInt16& Value)
	{
		return static_cast<uint8>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast UInt16 to Unreal int32", meta = (Keywords = "Cast Convert UInt16 unsigned uint16 short ushort to Int32 signed int32 int int integer"))
	static int32 CastUInt16ToUnrealint32(const FDolphinUInt16& Value)
	{
		return static_cast<int32>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast UInt16 to Unreal int64", meta = (Keywords = "Cast Convert UInt16 unsigned uint16 short ushort to Int64 signed int64 long int integer"))
	static int64 CastUInt16ToUnrealint64(const FDolphinUInt16& Value)
	{
		return static_cast<int64>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast UInt16 to Unreal float", meta = (Keywords = "Cast Convert UInt16 unsigned uint16 short ushort to Float float decimal single single-precision"))
	static float CastUInt16ToUnrealfloat(const FDolphinUInt16& Value)
	{
		return static_cast<float>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast UInt16 Array to UInt8 Array", meta = (Keywords = "Cast Convert Array UInt16 unsigned uint16 short ushort to UInt8 unsigned uint8 char byte ubyte"))
	static TArray<FDolphinUInt8> CastUInt16ArrayToUInt8Array(const TArray<FDolphinUInt16>& Value)
	{
		TArray<FDolphinUInt8> Results;
		for (const FDolphinUInt16& Next : Value)
		{
			Results.Add(CastUInt16ToUInt8(Next));
		}
		return Results;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast UInt16 Array to UInt32 Array", meta = (Keywords = "Cast Convert Array UInt16 unsigned uint16 short ushort to UInt32 unsigned uint32 int uint integer"))
	static TArray<FDolphinUInt32> CastUInt16ArrayToUInt32Array(const TArray<FDolphinUInt16>& Value)
	{
		TArray<FDolphinUInt32> Results;
		for (const FDolphinUInt16& Next : Value)
		{
			Results.Add(CastUInt16ToUInt32(Next));
		}
		return Results;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast UInt16 Array to UInt64 Array", meta = (Keywords = "Cast Convert Array UInt16 unsigned uint16 short ushort to UInt64 unsigned uint64 long int ulong integer"))
	static TArray<FDolphinUInt64> CastUInt16ArrayToUInt64Array(const TArray<FDolphinUInt16>& Value)
	{
		TArray<FDolphinUInt64> Results;
		for (const FDolphinUInt16& Next : Value)
		{
			Results.Add(CastUInt16ToUInt64(Next));
		}
		return Results;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast UInt16 Array to Int8 Array", meta = (Keywords = "Cast Convert Array UInt16 unsigned uint16 short ushort to Int8 signed int8 char byte"))
	static TArray<FDolphinInt8> CastUInt16ArrayToInt8Array(const TArray<FDolphinUInt16>& Value)
	{
		TArray<FDolphinInt8> Results;
		for (const FDolphinUInt16& Next : Value)
		{
			Results.Add(CastUInt16ToInt8(Next));
		}
		return Results;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast UInt16 Array to Int16 Array", meta = (Keywords = "Cast Convert Array UInt16 unsigned uint16 short ushort to Int16 signed int16 short"))
	static TArray<FDolphinInt16> CastUInt16ArrayToInt16Array(const TArray<FDolphinUInt16>& Value)
	{
		TArray<FDolphinInt16> Results;
		for (const FDolphinUInt16& Next : Value)
		{
			Results.Add(CastUInt16ToInt16(Next));
		}
		return Results;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast UInt16 Array to Int32 Array", meta = (Keywords = "Cast Convert Array UInt16 unsigned uint16 short ushort to Int32 signed int32 int int integer"))
	static TArray<FDolphinInt32> CastUInt16ArrayToInt32Array(const TArray<FDolphinUInt16>& Value)
	{
		TArray<FDolphinInt32> Results;
		for (const FDolphinUInt16& Next : Value)
		{
			Results.Add(CastUInt16ToInt32(Next));
		}
		return Results;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast UInt16 Array to Int64 Array", meta = (Keywords = "Cast Convert Array UInt16 unsigned uint16 short ushort to Int64 signed int64 long int integer"))
	static TArray<FDolphinInt64> CastUInt16ArrayToInt64Array(const TArray<FDolphinUInt16>& Value)
	{
		TArray<FDolphinInt64> Results;
		for (const FDolphinUInt16& Next : Value)
		{
			Results.Add(CastUInt16ToInt64(Next));
		}
		return Results;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast UInt16 Array to Float Array", meta = (Keywords = "Cast Convert Array UInt16 unsigned uint16 short ushort to Float float decimal single single-precision"))
	static TArray<FDolphinFloat> CastUInt16ArrayToFloatArray(const TArray<FDolphinUInt16>& Value)
	{
		TArray<FDolphinFloat> Results;
		for (const FDolphinUInt16& Next : Value)
		{
			Results.Add(CastUInt16ToFloat(Next));
		}
		return Results;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast UInt16 Array to Double Array", meta = (Keywords = "Cast Convert Array UInt16 unsigned uint16 short ushort to Double double decimal double-precision float"))
	static TArray<FDolphinDouble> CastUInt16ArrayToDoubleArray(const TArray<FDolphinUInt16>& Value)
	{
		TArray<FDolphinDouble> Results;
		for (const FDolphinUInt16& Next : Value)
		{
			Results.Add(CastUInt16ToDouble(Next));
		}
		return Results;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast UInt16 Array to Unreal uint8 Array", meta = (Keywords = "Cast Convert UInt16 unsigned uint16 short ushort Array to UInt8 unsigned uint8 char byte ubyte"))
	static TArray<uint8> CastUInt16ArrayToUnrealUInt8Array(const TArray<FDolphinUInt16>& Value)
	{
		TArray<uint8> Results;
		for (const FDolphinUInt16& Next : Value)
		{
			Results.Add(static_cast<uint8>(Next));
		}
		return Results;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast UInt16 Array to Unreal int32 Array", meta = (Keywords = "Cast Convert UInt16 unsigned uint16 short ushort Array to Int32 signed int32 int int integer"))
	static TArray<int32> CastUInt16ArrayToUnrealInt32Array(const TArray<FDolphinUInt16>& Value)
	{
		TArray<int32> Results;
		for (const FDolphinUInt16& Next : Value)
		{
			Results.Add(static_cast<int32>(Next));
		}
		return Results;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast UInt16 Array to Unreal int64 Array", meta = (Keywords = "Cast Convert UInt16 unsigned uint16 short ushort Array to Int64 signed int64 long int integer"))
	static TArray<int64> CastUInt16ArrayToUnrealInt64Array(const TArray<FDolphinUInt16>& Value)
	{
		TArray<int64> Results;
		for (const FDolphinUInt16& Next : Value)
		{
			Results.Add(static_cast<int64>(Next));
		}
		return Results;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast UInt16 Array to Unreal float Array", meta = (Keywords = "Cast Convert UInt16 unsigned uint16 short ushort Array to Float float decimal single single-precision"))
	static TArray<float> CastUInt16ArrayToUnrealFloatArray(const TArray<FDolphinUInt16>& Value)
	{
		TArray<float> Results;
		for (const FDolphinUInt16& Next : Value)
		{
			Results.Add(static_cast<float>(Next));
		}
		return Results;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Unreal uint8 Array to UInt16 Array", meta = (Keywords = "Cast Convert UInt16 unsigned uint16 short ushort Array to UInt8 unsigned uint8 char byte ubyte"))
	static TArray<FDolphinUInt16> CastUnrealUInt8ArrayToUInt16Array(const TArray<uint8>& Value)
	{
		TArray<FDolphinUInt16> Results;
		for (const uint8& Next : Value)
		{
			Results.Add(static_cast<uint16>(Next));
		}
		return Results;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Unreal int32 Array to UInt16 Array", meta = (Keywords = "Cast Convert UInt16 unsigned uint16 short ushort Array to Int32 signed int32 int int integer"))
	static TArray<FDolphinUInt16> CastUnrealInt32ArrayToUInt16Array(const TArray<int32>& Value)
	{
		TArray<FDolphinUInt16> Results;
		for (const int32& Next : Value)
		{
			Results.Add(static_cast<uint16>(Next));
		}
		return Results;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Unreal int64 Array to UInt16 Array", meta = (Keywords = "Cast Convert UInt16 unsigned uint16 short ushort Array to Int64 signed int64 long int integer"))
	static TArray<FDolphinUInt16> CastUnrealInt64ArrayToUInt16Array(const TArray<int64>& Value)
	{
		TArray<FDolphinUInt16> Results;
		for (const int64& Next : Value)
		{
			Results.Add(static_cast<uint16>(Next));
		}
		return Results;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Unreal float Array to UInt16 Array", meta = (Keywords = "Cast Convert UInt16 unsigned uint16 short ushort Array to Float float decimal single single-precision"))
	static TArray<FDolphinUInt16> CastUnrealFloatArrayToUInt16Array(const TArray<float>& Value)
	{
		TArray<FDolphinUInt16> Results;
		for (const float& Next : Value)
		{
			Results.Add(static_cast<uint16>(Next));
		}
		return Results;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Extract UInt16 To Raw Bytes", meta = (Keywords = "Get Cast Convert Extract UInt16 unsigned uint16 short ushort to Raw Bytes"))
	static TArray<FDolphinInt8> ExtractUInt16ToRawBytes(const FDolphinUInt16& Value)
	{
		TArray<uint8> Bytes;
		Bytes.AddZeroed(sizeof(Value.Value));
		FMemory::Memcpy(Bytes.GetData(), &Value.Value, sizeof(Value.Value));
		return CastUnrealUInt8ArrayToInt8Array(Bytes);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Extract UInt16 To Raw UBytes", meta = (Keywords = "Get Cast Convert Extract UInt16 unsigned uint16 short ushort to Raw UBytes"))
	static TArray<FDolphinUInt8> ExtractUInt16ToRawUBytes(const FDolphinUInt16& Value)
	{
		TArray<uint8> Bytes;
		Bytes.AddZeroed(sizeof(Value.Value));
		FMemory::Memcpy(Bytes.GetData(), &Value.Value, sizeof(Value.Value));
		return CastUnrealUInt8ArrayToUInt8Array(Bytes);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast UInt32 to UInt8", meta = (Keywords = "Cast Convert UInt32 unsigned uint32 int uint integer to UInt8 unsigned uint8 char byte ubyte"))
	static FDolphinUInt8 CastUInt32ToUInt8(const FDolphinUInt32& Value)
	{
		return static_cast<uint8>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast UInt32 to UInt16", meta = (Keywords = "Cast Convert UInt32 unsigned uint32 int uint integer to UInt16 unsigned uint16 short ushort"))
	static FDolphinUInt16 CastUInt32ToUInt16(const FDolphinUInt32& Value)
	{
		return static_cast<uint16>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast UInt32 to UInt64", meta = (Keywords = "Cast Convert UInt32 unsigned uint32 int uint integer to UInt64 unsigned uint64 long int ulong integer"))
	static FDolphinUInt64 CastUInt32ToUInt64(const FDolphinUInt32& Value)
	{
		return static_cast<uint64>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast UInt32 to Int8", meta = (Keywords = "Cast Convert UInt32 unsigned uint32 int uint integer to Int8 signed int8 char byte"))
	static FDolphinInt8 CastUInt32ToInt8(const FDolphinUInt32& Value)
	{
		return static_cast<int8>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast UInt32 to Int16", meta = (Keywords = "Cast Convert UInt32 unsigned uint32 int uint integer to Int16 signed int16 short"))
	static FDolphinInt16 CastUInt32ToInt16(const FDolphinUInt32& Value)
	{
		return static_cast<int16>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast UInt32 to Int32", meta = (Keywords = "Cast Convert UInt32 unsigned uint32 int uint integer to Int32 signed int32 int int integer"))
	static FDolphinInt32 CastUInt32ToInt32(const FDolphinUInt32& Value)
	{
		return static_cast<int32>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast UInt32 to Int64", meta = (Keywords = "Cast Convert UInt32 unsigned uint32 int uint integer to Int64 signed int64 long int integer"))
	static FDolphinInt64 CastUInt32ToInt64(const FDolphinUInt32& Value)
	{
		return static_cast<int64>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast UInt32 to Float", meta = (Keywords = "Cast Convert UInt32 unsigned uint32 int uint integer to Float float decimal single single-precision"))
	static FDolphinFloat CastUInt32ToFloat(const FDolphinUInt32& Value)
	{
		return static_cast<float>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast UInt32 to Double", meta = (Keywords = "Cast Convert UInt32 unsigned uint32 int uint integer to Double double decimal double-precision float"))
	static FDolphinDouble CastUInt32ToDouble(const FDolphinUInt32& Value)
	{
		return static_cast<double>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast UInt32 to Unreal uint8", meta = (Keywords = "Cast Convert UInt32 unsigned uint32 int uint integer to UInt8 unsigned uint8 char byte ubyte"))
	static uint8 CastUInt32ToUnrealuint8(const FDolphinUInt32& Value)
	{
		return static_cast<uint8>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast UInt32 to Unreal int32", meta = (Keywords = "Cast Convert UInt32 unsigned uint32 int uint integer to Int32 signed int32 int int integer"))
	static int32 CastUInt32ToUnrealint32(const FDolphinUInt32& Value)
	{
		return static_cast<int32>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast UInt32 to Unreal int64", meta = (Keywords = "Cast Convert UInt32 unsigned uint32 int uint integer to Int64 signed int64 long int integer"))
	static int64 CastUInt32ToUnrealint64(const FDolphinUInt32& Value)
	{
		return static_cast<int64>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast UInt32 to Unreal float", meta = (Keywords = "Cast Convert UInt32 unsigned uint32 int uint integer to Float float decimal single single-precision"))
	static float CastUInt32ToUnrealfloat(const FDolphinUInt32& Value)
	{
		return static_cast<float>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast UInt32 Array to UInt8 Array", meta = (Keywords = "Cast Convert Array UInt32 unsigned uint32 int uint integer to UInt8 unsigned uint8 char byte ubyte"))
	static TArray<FDolphinUInt8> CastUInt32ArrayToUInt8Array(const TArray<FDolphinUInt32>& Value)
	{
		TArray<FDolphinUInt8> Results;
		for (const FDolphinUInt32& Next : Value)
		{
			Results.Add(CastUInt32ToUInt8(Next));
		}
		return Results;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast UInt32 Array to UInt16 Array", meta = (Keywords = "Cast Convert Array UInt32 unsigned uint32 int uint integer to UInt16 unsigned uint16 short ushort"))
	static TArray<FDolphinUInt16> CastUInt32ArrayToUInt16Array(const TArray<FDolphinUInt32>& Value)
	{
		TArray<FDolphinUInt16> Results;
		for (const FDolphinUInt32& Next : Value)
		{
			Results.Add(CastUInt32ToUInt16(Next));
		}
		return Results;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast UInt32 Array to UInt64 Array", meta = (Keywords = "Cast Convert Array UInt32 unsigned uint32 int uint integer to UInt64 unsigned uint64 long int ulong integer"))
	static TArray<FDolphinUInt64> CastUInt32ArrayToUInt64Array(const TArray<FDolphinUInt32>& Value)
	{
		TArray<FDolphinUInt64> Results;
		for (const FDolphinUInt32& Next : Value)
		{
			Results.Add(CastUInt32ToUInt64(Next));
		}
		return Results;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast UInt32 Array to Int8 Array", meta = (Keywords = "Cast Convert Array UInt32 unsigned uint32 int uint integer to Int8 signed int8 char byte"))
	static TArray<FDolphinInt8> CastUInt32ArrayToInt8Array(const TArray<FDolphinUInt32>& Value)
	{
		TArray<FDolphinInt8> Results;
		for (const FDolphinUInt32& Next : Value)
		{
			Results.Add(CastUInt32ToInt8(Next));
		}
		return Results;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast UInt32 Array to Int16 Array", meta = (Keywords = "Cast Convert Array UInt32 unsigned uint32 int uint integer to Int16 signed int16 short"))
	static TArray<FDolphinInt16> CastUInt32ArrayToInt16Array(const TArray<FDolphinUInt32>& Value)
	{
		TArray<FDolphinInt16> Results;
		for (const FDolphinUInt32& Next : Value)
		{
			Results.Add(CastUInt32ToInt16(Next));
		}
		return Results;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast UInt32 Array to Int32 Array", meta = (Keywords = "Cast Convert Array UInt32 unsigned uint32 int uint integer to Int32 signed int32 int int integer"))
	static TArray<FDolphinInt32> CastUInt32ArrayToInt32Array(const TArray<FDolphinUInt32>& Value)
	{
		TArray<FDolphinInt32> Results;
		for (const FDolphinUInt32& Next : Value)
		{
			Results.Add(CastUInt32ToInt32(Next));
		}
		return Results;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast UInt32 Array to Int64 Array", meta = (Keywords = "Cast Convert Array UInt32 unsigned uint32 int uint integer to Int64 signed int64 long int integer"))
	static TArray<FDolphinInt64> CastUInt32ArrayToInt64Array(const TArray<FDolphinUInt32>& Value)
	{
		TArray<FDolphinInt64> Results;
		for (const FDolphinUInt32& Next : Value)
		{
			Results.Add(CastUInt32ToInt64(Next));
		}
		return Results;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast UInt32 Array to Float Array", meta = (Keywords = "Cast Convert Array UInt32 unsigned uint32 int uint integer to Float float decimal single single-precision"))
	static TArray<FDolphinFloat> CastUInt32ArrayToFloatArray(const TArray<FDolphinUInt32>& Value)
	{
		TArray<FDolphinFloat> Results;
		for (const FDolphinUInt32& Next : Value)
		{
			Results.Add(CastUInt32ToFloat(Next));
		}
		return Results;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast UInt32 Array to Double Array", meta = (Keywords = "Cast Convert Array UInt32 unsigned uint32 int uint integer to Double double decimal double-precision float"))
	static TArray<FDolphinDouble> CastUInt32ArrayToDoubleArray(const TArray<FDolphinUInt32>& Value)
	{
		TArray<FDolphinDouble> Results;
		for (const FDolphinUInt32& Next : Value)
		{
			Results.Add(CastUInt32ToDouble(Next));
		}
		return Results;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast UInt32 Array to Unreal uint8 Array", meta = (Keywords = "Cast Convert UInt32 unsigned uint32 int uint integer Array to UInt8 unsigned uint8 char byte ubyte"))
	static TArray<uint8> CastUInt32ArrayToUnrealUInt8Array(const TArray<FDolphinUInt32>& Value)
	{
		TArray<uint8> Results;
		for (const FDolphinUInt32& Next : Value)
		{
			Results.Add(static_cast<uint8>(Next));
		}
		return Results;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast UInt32 Array to Unreal int32 Array", meta = (Keywords = "Cast Convert UInt32 unsigned uint32 int uint integer Array to Int32 signed int32 int int integer"))
	static TArray<int32> CastUInt32ArrayToUnrealInt32Array(const TArray<FDolphinUInt32>& Value)
	{
		TArray<int32> Results;
		for (const FDolphinUInt32& Next : Value)
		{
			Results.Add(static_cast<int32>(Next));
		}
		return Results;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast UInt32 Array to Unreal int64 Array", meta = (Keywords = "Cast Convert UInt32 unsigned uint32 int uint integer Array to Int64 signed int64 long int integer"))
	static TArray<int64> CastUInt32ArrayToUnrealInt64Array(const TArray<FDolphinUInt32>& Value)
	{
		TArray<int64> Results;
		for (const FDolphinUInt32& Next : Value)
		{
			Results.Add(static_cast<int64>(Next));
		}
		return Results;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast UInt32 Array to Unreal float Array", meta = (Keywords = "Cast Convert UInt32 unsigned uint32 int uint integer Array to Float float decimal single single-precision"))
	static TArray<float> CastUInt32ArrayToUnrealFloatArray(const TArray<FDolphinUInt32>& Value)
	{
		TArray<float> Results;
		for (const FDolphinUInt32& Next : Value)
		{
			Results.Add(static_cast<float>(Next));
		}
		return Results;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Unreal uint8 Array to UInt32 Array", meta = (Keywords = "Cast Convert UInt32 unsigned uint32 int uint integer Array to UInt8 unsigned uint8 char byte ubyte"))
	static TArray<FDolphinUInt32> CastUnrealUInt8ArrayToUInt32Array(const TArray<uint8>& Value)
	{
		TArray<FDolphinUInt32> Results;
		for (const uint8& Next : Value)
		{
			Results.Add(static_cast<uint32>(Next));
		}
		return Results;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Unreal int32 Array to UInt32 Array", meta = (Keywords = "Cast Convert UInt32 unsigned uint32 int uint integer Array to Int32 signed int32 int int integer"))
	static TArray<FDolphinUInt32> CastUnrealInt32ArrayToUInt32Array(const TArray<int32>& Value)
	{
		TArray<FDolphinUInt32> Results;
		for (const int32& Next : Value)
		{
			Results.Add(static_cast<uint32>(Next));
		}
		return Results;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Unreal int64 Array to UInt32 Array", meta = (Keywords = "Cast Convert UInt32 unsigned uint32 int uint integer Array to Int64 signed int64 long int integer"))
	static TArray<FDolphinUInt32> CastUnrealInt64ArrayToUInt32Array(const TArray<int64>& Value)
	{
		TArray<FDolphinUInt32> Results;
		for (const int64& Next : Value)
		{
			Results.Add(static_cast<uint32>(Next));
		}
		return Results;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Unreal float Array to UInt32 Array", meta = (Keywords = "Cast Convert UInt32 unsigned uint32 int uint integer Array to Float float decimal single single-precision"))
	static TArray<FDolphinUInt32> CastUnrealFloatArrayToUInt32Array(const TArray<float>& Value)
	{
		TArray<FDolphinUInt32> Results;
		for (const float& Next : Value)
		{
			Results.Add(static_cast<uint32>(Next));
		}
		return Results;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Extract UInt32 To Raw Bytes", meta = (Keywords = "Get Cast Convert Extract UInt32 unsigned uint32 int uint integer to Raw Bytes"))
	static TArray<FDolphinInt8> ExtractUInt32ToRawBytes(const FDolphinUInt32& Value)
	{
		TArray<uint8> Bytes;
		Bytes.AddZeroed(sizeof(Value.Value));
		FMemory::Memcpy(Bytes.GetData(), &Value.Value, sizeof(Value.Value));
		return CastUnrealUInt8ArrayToInt8Array(Bytes);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Extract UInt32 To Raw UBytes", meta = (Keywords = "Get Cast Convert Extract UInt32 unsigned uint32 int uint integer to Raw UBytes"))
	static TArray<FDolphinUInt8> ExtractUInt32ToRawUBytes(const FDolphinUInt32& Value)
	{
		TArray<uint8> Bytes;
		Bytes.AddZeroed(sizeof(Value.Value));
		FMemory::Memcpy(Bytes.GetData(), &Value.Value, sizeof(Value.Value));
		return CastUnrealUInt8ArrayToUInt8Array(Bytes);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast UInt64 to UInt8", meta = (Keywords = "Cast Convert UInt64 unsigned uint64 long int ulong integer to UInt8 unsigned uint8 char byte ubyte"))
	static FDolphinUInt8 CastUInt64ToUInt8(const FDolphinUInt64& Value)
	{
		return static_cast<uint8>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast UInt64 to UInt16", meta = (Keywords = "Cast Convert UInt64 unsigned uint64 long int ulong integer to UInt16 unsigned uint16 short ushort"))
	static FDolphinUInt16 CastUInt64ToUInt16(const FDolphinUInt64& Value)
	{
		return static_cast<uint16>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast UInt64 to UInt32", meta = (Keywords = "Cast Convert UInt64 unsigned uint64 long int ulong integer to UInt32 unsigned uint32 int uint integer"))
	static FDolphinUInt32 CastUInt64ToUInt32(const FDolphinUInt64& Value)
	{
		return static_cast<uint32>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast UInt64 to Int8", meta = (Keywords = "Cast Convert UInt64 unsigned uint64 long int ulong integer to Int8 signed int8 char byte"))
	static FDolphinInt8 CastUInt64ToInt8(const FDolphinUInt64& Value)
	{
		return static_cast<int8>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast UInt64 to Int16", meta = (Keywords = "Cast Convert UInt64 unsigned uint64 long int ulong integer to Int16 signed int16 short"))
	static FDolphinInt16 CastUInt64ToInt16(const FDolphinUInt64& Value)
	{
		return static_cast<int16>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast UInt64 to Int32", meta = (Keywords = "Cast Convert UInt64 unsigned uint64 long int ulong integer to Int32 signed int32 int int integer"))
	static FDolphinInt32 CastUInt64ToInt32(const FDolphinUInt64& Value)
	{
		return static_cast<int32>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast UInt64 to Int64", meta = (Keywords = "Cast Convert UInt64 unsigned uint64 long int ulong integer to Int64 signed int64 long int integer"))
	static FDolphinInt64 CastUInt64ToInt64(const FDolphinUInt64& Value)
	{
		return static_cast<int64>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast UInt64 to Float", meta = (Keywords = "Cast Convert UInt64 unsigned uint64 long int ulong integer to Float float decimal single single-precision"))
	static FDolphinFloat CastUInt64ToFloat(const FDolphinUInt64& Value)
	{
		return static_cast<float>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast UInt64 to Double", meta = (Keywords = "Cast Convert UInt64 unsigned uint64 long int ulong integer to Double double decimal double-precision float"))
	static FDolphinDouble CastUInt64ToDouble(const FDolphinUInt64& Value)
	{
		return static_cast<double>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast UInt64 to Unreal uint8", meta = (Keywords = "Cast Convert UInt64 unsigned uint64 long int ulong integer to UInt8 unsigned uint8 char byte ubyte"))
	static uint8 CastUInt64ToUnrealuint8(const FDolphinUInt64& Value)
	{
		return static_cast<uint8>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast UInt64 to Unreal int32", meta = (Keywords = "Cast Convert UInt64 unsigned uint64 long int ulong integer to Int32 signed int32 int int integer"))
	static int32 CastUInt64ToUnrealint32(const FDolphinUInt64& Value)
	{
		return static_cast<int32>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast UInt64 to Unreal int64", meta = (Keywords = "Cast Convert UInt64 unsigned uint64 long int ulong integer to Int64 signed int64 long int integer"))
	static int64 CastUInt64ToUnrealint64(const FDolphinUInt64& Value)
	{
		return static_cast<int64>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast UInt64 to Unreal float", meta = (Keywords = "Cast Convert UInt64 unsigned uint64 long int ulong integer to Float float decimal single single-precision"))
	static float CastUInt64ToUnrealfloat(const FDolphinUInt64& Value)
	{
		return static_cast<float>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast UInt64 Array to UInt8 Array", meta = (Keywords = "Cast Convert Array UInt64 unsigned uint64 long int ulong integer to UInt8 unsigned uint8 char byte ubyte"))
	static TArray<FDolphinUInt8> CastUInt64ArrayToUInt8Array(const TArray<FDolphinUInt64>& Value)
	{
		TArray<FDolphinUInt8> Results;
		for (const FDolphinUInt64& Next : Value)
		{
			Results.Add(CastUInt64ToUInt8(Next));
		}
		return Results;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast UInt64 Array to UInt16 Array", meta = (Keywords = "Cast Convert Array UInt64 unsigned uint64 long int ulong integer to UInt16 unsigned uint16 short ushort"))
	static TArray<FDolphinUInt16> CastUInt64ArrayToUInt16Array(const TArray<FDolphinUInt64>& Value)
	{
		TArray<FDolphinUInt16> Results;
		for (const FDolphinUInt64& Next : Value)
		{
			Results.Add(CastUInt64ToUInt16(Next));
		}
		return Results;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast UInt64 Array to UInt32 Array", meta = (Keywords = "Cast Convert Array UInt64 unsigned uint64 long int ulong integer to UInt32 unsigned uint32 int uint integer"))
	static TArray<FDolphinUInt32> CastUInt64ArrayToUInt32Array(const TArray<FDolphinUInt64>& Value)
	{
		TArray<FDolphinUInt32> Results;
		for (const FDolphinUInt64& Next : Value)
		{
			Results.Add(CastUInt64ToUInt32(Next));
		}
		return Results;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast UInt64 Array to Int8 Array", meta = (Keywords = "Cast Convert Array UInt64 unsigned uint64 long int ulong integer to Int8 signed int8 char byte"))
	static TArray<FDolphinInt8> CastUInt64ArrayToInt8Array(const TArray<FDolphinUInt64>& Value)
	{
		TArray<FDolphinInt8> Results;
		for (const FDolphinUInt64& Next : Value)
		{
			Results.Add(CastUInt64ToInt8(Next));
		}
		return Results;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast UInt64 Array to Int16 Array", meta = (Keywords = "Cast Convert Array UInt64 unsigned uint64 long int ulong integer to Int16 signed int16 short"))
	static TArray<FDolphinInt16> CastUInt64ArrayToInt16Array(const TArray<FDolphinUInt64>& Value)
	{
		TArray<FDolphinInt16> Results;
		for (const FDolphinUInt64& Next : Value)
		{
			Results.Add(CastUInt64ToInt16(Next));
		}
		return Results;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast UInt64 Array to Int32 Array", meta = (Keywords = "Cast Convert Array UInt64 unsigned uint64 long int ulong integer to Int32 signed int32 int int integer"))
	static TArray<FDolphinInt32> CastUInt64ArrayToInt32Array(const TArray<FDolphinUInt64>& Value)
	{
		TArray<FDolphinInt32> Results;
		for (const FDolphinUInt64& Next : Value)
		{
			Results.Add(CastUInt64ToInt32(Next));
		}
		return Results;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast UInt64 Array to Int64 Array", meta = (Keywords = "Cast Convert Array UInt64 unsigned uint64 long int ulong integer to Int64 signed int64 long int integer"))
	static TArray<FDolphinInt64> CastUInt64ArrayToInt64Array(const TArray<FDolphinUInt64>& Value)
	{
		TArray<FDolphinInt64> Results;
		for (const FDolphinUInt64& Next : Value)
		{
			Results.Add(CastUInt64ToInt64(Next));
		}
		return Results;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast UInt64 Array to Float Array", meta = (Keywords = "Cast Convert Array UInt64 unsigned uint64 long int ulong integer to Float float decimal single single-precision"))
	static TArray<FDolphinFloat> CastUInt64ArrayToFloatArray(const TArray<FDolphinUInt64>& Value)
	{
		TArray<FDolphinFloat> Results;
		for (const FDolphinUInt64& Next : Value)
		{
			Results.Add(CastUInt64ToFloat(Next));
		}
		return Results;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast UInt64 Array to Double Array", meta = (Keywords = "Cast Convert Array UInt64 unsigned uint64 long int ulong integer to Double double decimal double-precision float"))
	static TArray<FDolphinDouble> CastUInt64ArrayToDoubleArray(const TArray<FDolphinUInt64>& Value)
	{
		TArray<FDolphinDouble> Results;
		for (const FDolphinUInt64& Next : Value)
		{
			Results.Add(CastUInt64ToDouble(Next));
		}
		return Results;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast UInt64 Array to Unreal uint8 Array", meta = (Keywords = "Cast Convert UInt64 unsigned uint64 long int ulong integer Array to UInt8 unsigned uint8 char byte ubyte"))
	static TArray<uint8> CastUInt64ArrayToUnrealUInt8Array(const TArray<FDolphinUInt64>& Value)
	{
		TArray<uint8> Results;
		for (const FDolphinUInt64& Next : Value)
		{
			Results.Add(static_cast<uint8>(Next));
		}
		return Results;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast UInt64 Array to Unreal int32 Array", meta = (Keywords = "Cast Convert UInt64 unsigned uint64 long int ulong integer Array to Int32 signed int32 int int integer"))
	static TArray<int32> CastUInt64ArrayToUnrealInt32Array(const TArray<FDolphinUInt64>& Value)
	{
		TArray<int32> Results;
		for (const FDolphinUInt64& Next : Value)
		{
			Results.Add(static_cast<int32>(Next));
		}
		return Results;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast UInt64 Array to Unreal int64 Array", meta = (Keywords = "Cast Convert UInt64 unsigned uint64 long int ulong integer Array to Int64 signed int64 long int integer"))
	static TArray<int64> CastUInt64ArrayToUnrealInt64Array(const TArray<FDolphinUInt64>& Value)
	{
		TArray<int64> Results;
		for (const FDolphinUInt64& Next : Value)
		{
			Results.Add(static_cast<int64>(Next));
		}
		return Results;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast UInt64 Array to Unreal float Array", meta = (Keywords = "Cast Convert UInt64 unsigned uint64 long int ulong integer Array to Float float decimal single single-precision"))
	static TArray<float> CastUInt64ArrayToUnrealFloatArray(const TArray<FDolphinUInt64>& Value)
	{
		TArray<float> Results;
		for (const FDolphinUInt64& Next : Value)
		{
			Results.Add(static_cast<float>(Next));
		}
		return Results;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Unreal uint8 Array to UInt64 Array", meta = (Keywords = "Cast Convert UInt64 unsigned uint64 long int ulong integer Array to UInt8 unsigned uint8 char byte ubyte"))
	static TArray<FDolphinUInt64> CastUnrealUInt8ArrayToUInt64Array(const TArray<uint8>& Value)
	{
		TArray<FDolphinUInt64> Results;
		for (const uint8& Next : Value)
		{
			Results.Add(static_cast<uint64>(Next));
		}
		return Results;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Unreal int32 Array to UInt64 Array", meta = (Keywords = "Cast Convert UInt64 unsigned uint64 long int ulong integer Array to Int32 signed int32 int int integer"))
	static TArray<FDolphinUInt64> CastUnrealInt32ArrayToUInt64Array(const TArray<int32>& Value)
	{
		TArray<FDolphinUInt64> Results;
		for (const int32& Next : Value)
		{
			Results.Add(static_cast<uint64>(Next));
		}
		return Results;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Unreal int64 Array to UInt64 Array", meta = (Keywords = "Cast Convert UInt64 unsigned uint64 long int ulong integer Array to Int64 signed int64 long int integer"))
	static TArray<FDolphinUInt64> CastUnrealInt64ArrayToUInt64Array(const TArray<int64>& Value)
	{
		TArray<FDolphinUInt64> Results;
		for (const int64& Next : Value)
		{
			Results.Add(static_cast<uint64>(Next));
		}
		return Results;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Unreal float Array to UInt64 Array", meta = (Keywords = "Cast Convert UInt64 unsigned uint64 long int ulong integer Array to Float float decimal single single-precision"))
	static TArray<FDolphinUInt64> CastUnrealFloatArrayToUInt64Array(const TArray<float>& Value)
	{
		TArray<FDolphinUInt64> Results;
		for (const float& Next : Value)
		{
			Results.Add(static_cast<uint64>(Next));
		}
		return Results;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Extract UInt64 To Raw Bytes", meta = (Keywords = "Get Cast Convert Extract UInt64 unsigned uint64 long int ulong integer to Raw Bytes"))
	static TArray<FDolphinInt8> ExtractUInt64ToRawBytes(const FDolphinUInt64& Value)
	{
		TArray<uint8> Bytes;
		Bytes.AddZeroed(sizeof(Value.Value));
		FMemory::Memcpy(Bytes.GetData(), &Value.Value, sizeof(Value.Value));
		return CastUnrealUInt8ArrayToInt8Array(Bytes);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Extract UInt64 To Raw UBytes", meta = (Keywords = "Get Cast Convert Extract UInt64 unsigned uint64 long int ulong integer to Raw UBytes"))
	static TArray<FDolphinUInt8> ExtractUInt64ToRawUBytes(const FDolphinUInt64& Value)
	{
		TArray<uint8> Bytes;
		Bytes.AddZeroed(sizeof(Value.Value));
		FMemory::Memcpy(Bytes.GetData(), &Value.Value, sizeof(Value.Value));
		return CastUnrealUInt8ArrayToUInt8Array(Bytes);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Int8 to UInt8", meta = (Keywords = "Cast Convert Int8 signed int8 char byte to UInt8 unsigned uint8 char byte ubyte"))
	static FDolphinUInt8 CastInt8ToUInt8(const FDolphinInt8& Value)
	{
		return static_cast<uint8>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Int8 to UInt16", meta = (Keywords = "Cast Convert Int8 signed int8 char byte to UInt16 unsigned uint16 short ushort"))
	static FDolphinUInt16 CastInt8ToUInt16(const FDolphinInt8& Value)
	{
		return static_cast<uint16>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Int8 to UInt32", meta = (Keywords = "Cast Convert Int8 signed int8 char byte to UInt32 unsigned uint32 int uint integer"))
	static FDolphinUInt32 CastInt8ToUInt32(const FDolphinInt8& Value)
	{
		return static_cast<uint32>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Int8 to UInt64", meta = (Keywords = "Cast Convert Int8 signed int8 char byte to UInt64 unsigned uint64 long int ulong integer"))
	static FDolphinUInt64 CastInt8ToUInt64(const FDolphinInt8& Value)
	{
		return static_cast<uint64>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Int8 to Int16", meta = (Keywords = "Cast Convert Int8 signed int8 char byte to Int16 signed int16 short"))
	static FDolphinInt16 CastInt8ToInt16(const FDolphinInt8& Value)
	{
		return static_cast<int16>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Int8 to Int32", meta = (Keywords = "Cast Convert Int8 signed int8 char byte to Int32 signed int32 int int integer"))
	static FDolphinInt32 CastInt8ToInt32(const FDolphinInt8& Value)
	{
		return static_cast<int32>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Int8 to Int64", meta = (Keywords = "Cast Convert Int8 signed int8 char byte to Int64 signed int64 long int integer"))
	static FDolphinInt64 CastInt8ToInt64(const FDolphinInt8& Value)
	{
		return static_cast<int64>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Int8 to Float", meta = (Keywords = "Cast Convert Int8 signed int8 char byte to Float float decimal single single-precision"))
	static FDolphinFloat CastInt8ToFloat(const FDolphinInt8& Value)
	{
		return static_cast<float>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Int8 to Double", meta = (Keywords = "Cast Convert Int8 signed int8 char byte to Double double decimal double-precision float"))
	static FDolphinDouble CastInt8ToDouble(const FDolphinInt8& Value)
	{
		return static_cast<double>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Int8 to Unreal uint8", meta = (Keywords = "Cast Convert Int8 signed int8 char byte to UInt8 unsigned uint8 char byte ubyte"))
	static uint8 CastInt8ToUnrealuint8(const FDolphinInt8& Value)
	{
		return static_cast<uint8>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Int8 to Unreal int32", meta = (Keywords = "Cast Convert Int8 signed int8 char byte to Int32 signed int32 int int integer"))
	static int32 CastInt8ToUnrealint32(const FDolphinInt8& Value)
	{
		return static_cast<int32>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Int8 to Unreal int64", meta = (Keywords = "Cast Convert Int8 signed int8 char byte to Int64 signed int64 long int integer"))
	static int64 CastInt8ToUnrealint64(const FDolphinInt8& Value)
	{
		return static_cast<int64>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Int8 to Unreal float", meta = (Keywords = "Cast Convert Int8 signed int8 char byte to Float float decimal single single-precision"))
	static float CastInt8ToUnrealfloat(const FDolphinInt8& Value)
	{
		return static_cast<float>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Int8 Array to UInt8 Array", meta = (Keywords = "Cast Convert Array Int8 signed int8 char byte to UInt8 unsigned uint8 char byte ubyte"))
	static TArray<FDolphinUInt8> CastInt8ArrayToUInt8Array(const TArray<FDolphinInt8>& Value)
	{
		TArray<FDolphinUInt8> Results;
		for (const FDolphinInt8& Next : Value)
		{
			Results.Add(CastInt8ToUInt8(Next));
		}
		return Results;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Int8 Array to UInt16 Array", meta = (Keywords = "Cast Convert Array Int8 signed int8 char byte to UInt16 unsigned uint16 short ushort"))
	static TArray<FDolphinUInt16> CastInt8ArrayToUInt16Array(const TArray<FDolphinInt8>& Value)
	{
		TArray<FDolphinUInt16> Results;
		for (const FDolphinInt8& Next : Value)
		{
			Results.Add(CastInt8ToUInt16(Next));
		}
		return Results;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Int8 Array to UInt32 Array", meta = (Keywords = "Cast Convert Array Int8 signed int8 char byte to UInt32 unsigned uint32 int uint integer"))
	static TArray<FDolphinUInt32> CastInt8ArrayToUInt32Array(const TArray<FDolphinInt8>& Value)
	{
		TArray<FDolphinUInt32> Results;
		for (const FDolphinInt8& Next : Value)
		{
			Results.Add(CastInt8ToUInt32(Next));
		}
		return Results;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Int8 Array to UInt64 Array", meta = (Keywords = "Cast Convert Array Int8 signed int8 char byte to UInt64 unsigned uint64 long int ulong integer"))
	static TArray<FDolphinUInt64> CastInt8ArrayToUInt64Array(const TArray<FDolphinInt8>& Value)
	{
		TArray<FDolphinUInt64> Results;
		for (const FDolphinInt8& Next : Value)
		{
			Results.Add(CastInt8ToUInt64(Next));
		}
		return Results;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Int8 Array to Int16 Array", meta = (Keywords = "Cast Convert Array Int8 signed int8 char byte to Int16 signed int16 short"))
	static TArray<FDolphinInt16> CastInt8ArrayToInt16Array(const TArray<FDolphinInt8>& Value)
	{
		TArray<FDolphinInt16> Results;
		for (const FDolphinInt8& Next : Value)
		{
			Results.Add(CastInt8ToInt16(Next));
		}
		return Results;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Int8 Array to Int32 Array", meta = (Keywords = "Cast Convert Array Int8 signed int8 char byte to Int32 signed int32 int int integer"))
	static TArray<FDolphinInt32> CastInt8ArrayToInt32Array(const TArray<FDolphinInt8>& Value)
	{
		TArray<FDolphinInt32> Results;
		for (const FDolphinInt8& Next : Value)
		{
			Results.Add(CastInt8ToInt32(Next));
		}
		return Results;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Int8 Array to Int64 Array", meta = (Keywords = "Cast Convert Array Int8 signed int8 char byte to Int64 signed int64 long int integer"))
	static TArray<FDolphinInt64> CastInt8ArrayToInt64Array(const TArray<FDolphinInt8>& Value)
	{
		TArray<FDolphinInt64> Results;
		for (const FDolphinInt8& Next : Value)
		{
			Results.Add(CastInt8ToInt64(Next));
		}
		return Results;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Int8 Array to Float Array", meta = (Keywords = "Cast Convert Array Int8 signed int8 char byte to Float float decimal single single-precision"))
	static TArray<FDolphinFloat> CastInt8ArrayToFloatArray(const TArray<FDolphinInt8>& Value)
	{
		TArray<FDolphinFloat> Results;
		for (const FDolphinInt8& Next : Value)
		{
			Results.Add(CastInt8ToFloat(Next));
		}
		return Results;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Int8 Array to Double Array", meta = (Keywords = "Cast Convert Array Int8 signed int8 char byte to Double double decimal double-precision float"))
	static TArray<FDolphinDouble> CastInt8ArrayToDoubleArray(const TArray<FDolphinInt8>& Value)
	{
		TArray<FDolphinDouble> Results;
		for (const FDolphinInt8& Next : Value)
		{
			Results.Add(CastInt8ToDouble(Next));
		}
		return Results;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Int8 Array to Unreal uint8 Array", meta = (Keywords = "Cast Convert Int8 signed int8 char byte Array to UInt8 unsigned uint8 char byte ubyte"))
	static TArray<uint8> CastInt8ArrayToUnrealUInt8Array(const TArray<FDolphinInt8>& Value)
	{
		TArray<uint8> Results;
		for (const FDolphinInt8& Next : Value)
		{
			Results.Add(static_cast<uint8>(Next));
		}
		return Results;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Int8 Array to Unreal int32 Array", meta = (Keywords = "Cast Convert Int8 signed int8 char byte Array to Int32 signed int32 int int integer"))
	static TArray<int32> CastInt8ArrayToUnrealInt32Array(const TArray<FDolphinInt8>& Value)
	{
		TArray<int32> Results;
		for (const FDolphinInt8& Next : Value)
		{
			Results.Add(static_cast<int32>(Next));
		}
		return Results;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Int8 Array to Unreal int64 Array", meta = (Keywords = "Cast Convert Int8 signed int8 char byte Array to Int64 signed int64 long int integer"))
	static TArray<int64> CastInt8ArrayToUnrealInt64Array(const TArray<FDolphinInt8>& Value)
	{
		TArray<int64> Results;
		for (const FDolphinInt8& Next : Value)
		{
			Results.Add(static_cast<int64>(Next));
		}
		return Results;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Int8 Array to Unreal float Array", meta = (Keywords = "Cast Convert Int8 signed int8 char byte Array to Float float decimal single single-precision"))
	static TArray<float> CastInt8ArrayToUnrealFloatArray(const TArray<FDolphinInt8>& Value)
	{
		TArray<float> Results;
		for (const FDolphinInt8& Next : Value)
		{
			Results.Add(static_cast<float>(Next));
		}
		return Results;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Unreal uint8 Array to Int8 Array", meta = (Keywords = "Cast Convert Int8 signed int8 char byte Array to UInt8 unsigned uint8 char byte ubyte"))
	static TArray<FDolphinInt8> CastUnrealUInt8ArrayToInt8Array(const TArray<uint8>& Value)
	{
		TArray<FDolphinInt8> Results;
		for (const uint8& Next : Value)
		{
			Results.Add(static_cast<int8>(Next));
		}
		return Results;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Unreal int32 Array to Int8 Array", meta = (Keywords = "Cast Convert Int8 signed int8 char byte Array to Int32 signed int32 int int integer"))
	static TArray<FDolphinInt8> CastUnrealInt32ArrayToInt8Array(const TArray<int32>& Value)
	{
		TArray<FDolphinInt8> Results;
		for (const int32& Next : Value)
		{
			Results.Add(static_cast<int8>(Next));
		}
		return Results;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Unreal int64 Array to Int8 Array", meta = (Keywords = "Cast Convert Int8 signed int8 char byte Array to Int64 signed int64 long int integer"))
	static TArray<FDolphinInt8> CastUnrealInt64ArrayToInt8Array(const TArray<int64>& Value)
	{
		TArray<FDolphinInt8> Results;
		for (const int64& Next : Value)
		{
			Results.Add(static_cast<int8>(Next));
		}
		return Results;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Unreal float Array to Int8 Array", meta = (Keywords = "Cast Convert Int8 signed int8 char byte Array to Float float decimal single single-precision"))
	static TArray<FDolphinInt8> CastUnrealFloatArrayToInt8Array(const TArray<float>& Value)
	{
		TArray<FDolphinInt8> Results;
		for (const float& Next : Value)
		{
			Results.Add(static_cast<int8>(Next));
		}
		return Results;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Int16 to UInt8", meta = (Keywords = "Cast Convert Int16 signed int16 short to UInt8 unsigned uint8 char byte ubyte"))
	static FDolphinUInt8 CastInt16ToUInt8(const FDolphinInt16& Value)
	{
		return static_cast<uint8>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Int16 to UInt16", meta = (Keywords = "Cast Convert Int16 signed int16 short to UInt16 unsigned uint16 short ushort"))
	static FDolphinUInt16 CastInt16ToUInt16(const FDolphinInt16& Value)
	{
		return static_cast<uint16>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Int16 to UInt32", meta = (Keywords = "Cast Convert Int16 signed int16 short to UInt32 unsigned uint32 int uint integer"))
	static FDolphinUInt32 CastInt16ToUInt32(const FDolphinInt16& Value)
	{
		return static_cast<uint32>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Int16 to UInt64", meta = (Keywords = "Cast Convert Int16 signed int16 short to UInt64 unsigned uint64 long int ulong integer"))
	static FDolphinUInt64 CastInt16ToUInt64(const FDolphinInt16& Value)
	{
		return static_cast<uint64>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Int16 to Int8", meta = (Keywords = "Cast Convert Int16 signed int16 short to Int8 signed int8 char byte"))
	static FDolphinInt8 CastInt16ToInt8(const FDolphinInt16& Value)
	{
		return static_cast<int8>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Int16 to Int32", meta = (Keywords = "Cast Convert Int16 signed int16 short to Int32 signed int32 int int integer"))
	static FDolphinInt32 CastInt16ToInt32(const FDolphinInt16& Value)
	{
		return static_cast<int32>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Int16 to Int64", meta = (Keywords = "Cast Convert Int16 signed int16 short to Int64 signed int64 long int integer"))
	static FDolphinInt64 CastInt16ToInt64(const FDolphinInt16& Value)
	{
		return static_cast<int64>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Int16 to Float", meta = (Keywords = "Cast Convert Int16 signed int16 short to Float float decimal single single-precision"))
	static FDolphinFloat CastInt16ToFloat(const FDolphinInt16& Value)
	{
		return static_cast<float>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Int16 to Double", meta = (Keywords = "Cast Convert Int16 signed int16 short to Double double decimal double-precision float"))
	static FDolphinDouble CastInt16ToDouble(const FDolphinInt16& Value)
	{
		return static_cast<double>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Int16 to Unreal uint8", meta = (Keywords = "Cast Convert Int16 signed int16 short to UInt8 unsigned uint8 char byte ubyte"))
	static uint8 CastInt16ToUnrealuint8(const FDolphinInt16& Value)
	{
		return static_cast<uint8>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Int16 to Unreal int32", meta = (Keywords = "Cast Convert Int16 signed int16 short to Int32 signed int32 int int integer"))
	static int32 CastInt16ToUnrealint32(const FDolphinInt16& Value)
	{
		return static_cast<int32>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Int16 to Unreal int64", meta = (Keywords = "Cast Convert Int16 signed int16 short to Int64 signed int64 long int integer"))
	static int64 CastInt16ToUnrealint64(const FDolphinInt16& Value)
	{
		return static_cast<int64>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Int16 to Unreal float", meta = (Keywords = "Cast Convert Int16 signed int16 short to Float float decimal single single-precision"))
	static float CastInt16ToUnrealfloat(const FDolphinInt16& Value)
	{
		return static_cast<float>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Int16 Array to UInt8 Array", meta = (Keywords = "Cast Convert Array Int16 signed int16 short to UInt8 unsigned uint8 char byte ubyte"))
	static TArray<FDolphinUInt8> CastInt16ArrayToUInt8Array(const TArray<FDolphinInt16>& Value)
	{
		TArray<FDolphinUInt8> Results;
		for (const FDolphinInt16& Next : Value)
		{
			Results.Add(CastInt16ToUInt8(Next));
		}
		return Results;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Int16 Array to UInt16 Array", meta = (Keywords = "Cast Convert Array Int16 signed int16 short to UInt16 unsigned uint16 short ushort"))
	static TArray<FDolphinUInt16> CastInt16ArrayToUInt16Array(const TArray<FDolphinInt16>& Value)
	{
		TArray<FDolphinUInt16> Results;
		for (const FDolphinInt16& Next : Value)
		{
			Results.Add(CastInt16ToUInt16(Next));
		}
		return Results;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Int16 Array to UInt32 Array", meta = (Keywords = "Cast Convert Array Int16 signed int16 short to UInt32 unsigned uint32 int uint integer"))
	static TArray<FDolphinUInt32> CastInt16ArrayToUInt32Array(const TArray<FDolphinInt16>& Value)
	{
		TArray<FDolphinUInt32> Results;
		for (const FDolphinInt16& Next : Value)
		{
			Results.Add(CastInt16ToUInt32(Next));
		}
		return Results;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Int16 Array to UInt64 Array", meta = (Keywords = "Cast Convert Array Int16 signed int16 short to UInt64 unsigned uint64 long int ulong integer"))
	static TArray<FDolphinUInt64> CastInt16ArrayToUInt64Array(const TArray<FDolphinInt16>& Value)
	{
		TArray<FDolphinUInt64> Results;
		for (const FDolphinInt16& Next : Value)
		{
			Results.Add(CastInt16ToUInt64(Next));
		}
		return Results;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Int16 Array to Int8 Array", meta = (Keywords = "Cast Convert Array Int16 signed int16 short to Int8 signed int8 char byte"))
	static TArray<FDolphinInt8> CastInt16ArrayToInt8Array(const TArray<FDolphinInt16>& Value)
	{
		TArray<FDolphinInt8> Results;
		for (const FDolphinInt16& Next : Value)
		{
			Results.Add(CastInt16ToInt8(Next));
		}
		return Results;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Int16 Array to Int32 Array", meta = (Keywords = "Cast Convert Array Int16 signed int16 short to Int32 signed int32 int int integer"))
	static TArray<FDolphinInt32> CastInt16ArrayToInt32Array(const TArray<FDolphinInt16>& Value)
	{
		TArray<FDolphinInt32> Results;
		for (const FDolphinInt16& Next : Value)
		{
			Results.Add(CastInt16ToInt32(Next));
		}
		return Results;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Int16 Array to Int64 Array", meta = (Keywords = "Cast Convert Array Int16 signed int16 short to Int64 signed int64 long int integer"))
	static TArray<FDolphinInt64> CastInt16ArrayToInt64Array(const TArray<FDolphinInt16>& Value)
	{
		TArray<FDolphinInt64> Results;
		for (const FDolphinInt16& Next : Value)
		{
			Results.Add(CastInt16ToInt64(Next));
		}
		return Results;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Int16 Array to Float Array", meta = (Keywords = "Cast Convert Array Int16 signed int16 short to Float float decimal single single-precision"))
	static TArray<FDolphinFloat> CastInt16ArrayToFloatArray(const TArray<FDolphinInt16>& Value)
	{
		TArray<FDolphinFloat> Results;
		for (const FDolphinInt16& Next : Value)
		{
			Results.Add(CastInt16ToFloat(Next));
		}
		return Results;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Int16 Array to Double Array", meta = (Keywords = "Cast Convert Array Int16 signed int16 short to Double double decimal double-precision float"))
	static TArray<FDolphinDouble> CastInt16ArrayToDoubleArray(const TArray<FDolphinInt16>& Value)
	{
		TArray<FDolphinDouble> Results;
		for (const FDolphinInt16& Next : Value)
		{
			Results.Add(CastInt16ToDouble(Next));
		}
		return Results;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Int16 Array to Unreal uint8 Array", meta = (Keywords = "Cast Convert Int16 signed int16 short Array to UInt8 unsigned uint8 char byte ubyte"))
	static TArray<uint8> CastInt16ArrayToUnrealUInt8Array(const TArray<FDolphinInt16>& Value)
	{
		TArray<uint8> Results;
		for (const FDolphinInt16& Next : Value)
		{
			Results.Add(static_cast<uint8>(Next));
		}
		return Results;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Int16 Array to Unreal int32 Array", meta = (Keywords = "Cast Convert Int16 signed int16 short Array to Int32 signed int32 int int integer"))
	static TArray<int32> CastInt16ArrayToUnrealInt32Array(const TArray<FDolphinInt16>& Value)
	{
		TArray<int32> Results;
		for (const FDolphinInt16& Next : Value)
		{
			Results.Add(static_cast<int32>(Next));
		}
		return Results;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Int16 Array to Unreal int64 Array", meta = (Keywords = "Cast Convert Int16 signed int16 short Array to Int64 signed int64 long int integer"))
	static TArray<int64> CastInt16ArrayToUnrealInt64Array(const TArray<FDolphinInt16>& Value)
	{
		TArray<int64> Results;
		for (const FDolphinInt16& Next : Value)
		{
			Results.Add(static_cast<int64>(Next));
		}
		return Results;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Int16 Array to Unreal float Array", meta = (Keywords = "Cast Convert Int16 signed int16 short Array to Float float decimal single single-precision"))
	static TArray<float> CastInt16ArrayToUnrealFloatArray(const TArray<FDolphinInt16>& Value)
	{
		TArray<float> Results;
		for (const FDolphinInt16& Next : Value)
		{
			Results.Add(static_cast<float>(Next));
		}
		return Results;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Unreal uint8 Array to Int16 Array", meta = (Keywords = "Cast Convert Int16 signed int16 short Array to UInt8 unsigned uint8 char byte ubyte"))
	static TArray<FDolphinInt16> CastUnrealUInt8ArrayToInt16Array(const TArray<uint8>& Value)
	{
		TArray<FDolphinInt16> Results;
		for (const uint8& Next : Value)
		{
			Results.Add(static_cast<int16>(Next));
		}
		return Results;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Unreal int32 Array to Int16 Array", meta = (Keywords = "Cast Convert Int16 signed int16 short Array to Int32 signed int32 int int integer"))
	static TArray<FDolphinInt16> CastUnrealInt32ArrayToInt16Array(const TArray<int32>& Value)
	{
		TArray<FDolphinInt16> Results;
		for (const int32& Next : Value)
		{
			Results.Add(static_cast<int16>(Next));
		}
		return Results;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Unreal int64 Array to Int16 Array", meta = (Keywords = "Cast Convert Int16 signed int16 short Array to Int64 signed int64 long int integer"))
	static TArray<FDolphinInt16> CastUnrealInt64ArrayToInt16Array(const TArray<int64>& Value)
	{
		TArray<FDolphinInt16> Results;
		for (const int64& Next : Value)
		{
			Results.Add(static_cast<int16>(Next));
		}
		return Results;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Unreal float Array to Int16 Array", meta = (Keywords = "Cast Convert Int16 signed int16 short Array to Float float decimal single single-precision"))
	static TArray<FDolphinInt16> CastUnrealFloatArrayToInt16Array(const TArray<float>& Value)
	{
		TArray<FDolphinInt16> Results;
		for (const float& Next : Value)
		{
			Results.Add(static_cast<int16>(Next));
		}
		return Results;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Extract Int16 To Raw Bytes", meta = (Keywords = "Get Cast Convert Extract Int16 signed int16 short to Raw Bytes"))
	static TArray<FDolphinInt8> ExtractInt16ToRawBytes(const FDolphinInt16& Value)
	{
		TArray<uint8> Bytes;
		Bytes.AddZeroed(sizeof(Value.Value));
		FMemory::Memcpy(Bytes.GetData(), &Value.Value, sizeof(Value.Value));
		return CastUnrealUInt8ArrayToInt8Array(Bytes);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Extract Int16 To Raw UBytes", meta = (Keywords = "Get Cast Convert Extract Int16 signed int16 short to Raw UBytes"))
	static TArray<FDolphinUInt8> ExtractInt16ToRawUBytes(const FDolphinInt16& Value)
	{
		TArray<uint8> Bytes;
		Bytes.AddZeroed(sizeof(Value.Value));
		FMemory::Memcpy(Bytes.GetData(), &Value.Value, sizeof(Value.Value));
		return CastUnrealUInt8ArrayToUInt8Array(Bytes);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Int32 to UInt8", meta = (Keywords = "Cast Convert Int32 signed int32 int int integer to UInt8 unsigned uint8 char byte ubyte"))
	static FDolphinUInt8 CastInt32ToUInt8(const FDolphinInt32& Value)
	{
		return static_cast<uint8>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Int32 to UInt16", meta = (Keywords = "Cast Convert Int32 signed int32 int int integer to UInt16 unsigned uint16 short ushort"))
	static FDolphinUInt16 CastInt32ToUInt16(const FDolphinInt32& Value)
	{
		return static_cast<uint16>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Int32 to UInt32", meta = (Keywords = "Cast Convert Int32 signed int32 int int integer to UInt32 unsigned uint32 int uint integer"))
	static FDolphinUInt32 CastInt32ToUInt32(const FDolphinInt32& Value)
	{
		return static_cast<uint32>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Int32 to UInt64", meta = (Keywords = "Cast Convert Int32 signed int32 int int integer to UInt64 unsigned uint64 long int ulong integer"))
	static FDolphinUInt64 CastInt32ToUInt64(const FDolphinInt32& Value)
	{
		return static_cast<uint64>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Int32 to Int8", meta = (Keywords = "Cast Convert Int32 signed int32 int int integer to Int8 signed int8 char byte"))
	static FDolphinInt8 CastInt32ToInt8(const FDolphinInt32& Value)
	{
		return static_cast<int8>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Int32 to Int16", meta = (Keywords = "Cast Convert Int32 signed int32 int int integer to Int16 signed int16 short"))
	static FDolphinInt16 CastInt32ToInt16(const FDolphinInt32& Value)
	{
		return static_cast<int16>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Int32 to Int64", meta = (Keywords = "Cast Convert Int32 signed int32 int int integer to Int64 signed int64 long int integer"))
	static FDolphinInt64 CastInt32ToInt64(const FDolphinInt32& Value)
	{
		return static_cast<int64>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Int32 to Float", meta = (Keywords = "Cast Convert Int32 signed int32 int int integer to Float float decimal single single-precision"))
	static FDolphinFloat CastInt32ToFloat(const FDolphinInt32& Value)
	{
		return static_cast<float>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Int32 to Double", meta = (Keywords = "Cast Convert Int32 signed int32 int int integer to Double double decimal double-precision float"))
	static FDolphinDouble CastInt32ToDouble(const FDolphinInt32& Value)
	{
		return static_cast<double>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Int32 to Unreal uint8", meta = (Keywords = "Cast Convert Int32 signed int32 int int integer to UInt8 unsigned uint8 char byte ubyte"))
	static uint8 CastInt32ToUnrealuint8(const FDolphinInt32& Value)
	{
		return static_cast<uint8>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Int32 to Unreal int32", meta = (Keywords = "Cast Convert Int32 signed int32 int int integer to Int32 signed int32 int int integer"))
	static int32 CastInt32ToUnrealint32(const FDolphinInt32& Value)
	{
		return static_cast<int32>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Int32 to Unreal int64", meta = (Keywords = "Cast Convert Int32 signed int32 int int integer to Int64 signed int64 long int integer"))
	static int64 CastInt32ToUnrealint64(const FDolphinInt32& Value)
	{
		return static_cast<int64>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Int32 to Unreal float", meta = (Keywords = "Cast Convert Int32 signed int32 int int integer to Float float decimal single single-precision"))
	static float CastInt32ToUnrealfloat(const FDolphinInt32& Value)
	{
		return static_cast<float>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Int32 Array to UInt8 Array", meta = (Keywords = "Cast Convert Array Int32 signed int32 int int integer to UInt8 unsigned uint8 char byte ubyte"))
	static TArray<FDolphinUInt8> CastInt32ArrayToUInt8Array(const TArray<FDolphinInt32>& Value)
	{
		TArray<FDolphinUInt8> Results;
		for (const FDolphinInt32& Next : Value)
		{
			Results.Add(CastInt32ToUInt8(Next));
		}
		return Results;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Int32 Array to UInt16 Array", meta = (Keywords = "Cast Convert Array Int32 signed int32 int int integer to UInt16 unsigned uint16 short ushort"))
	static TArray<FDolphinUInt16> CastInt32ArrayToUInt16Array(const TArray<FDolphinInt32>& Value)
	{
		TArray<FDolphinUInt16> Results;
		for (const FDolphinInt32& Next : Value)
		{
			Results.Add(CastInt32ToUInt16(Next));
		}
		return Results;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Int32 Array to UInt32 Array", meta = (Keywords = "Cast Convert Array Int32 signed int32 int int integer to UInt32 unsigned uint32 int uint integer"))
	static TArray<FDolphinUInt32> CastInt32ArrayToUInt32Array(const TArray<FDolphinInt32>& Value)
	{
		TArray<FDolphinUInt32> Results;
		for (const FDolphinInt32& Next : Value)
		{
			Results.Add(CastInt32ToUInt32(Next));
		}
		return Results;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Int32 Array to UInt64 Array", meta = (Keywords = "Cast Convert Array Int32 signed int32 int int integer to UInt64 unsigned uint64 long int ulong integer"))
	static TArray<FDolphinUInt64> CastInt32ArrayToUInt64Array(const TArray<FDolphinInt32>& Value)
	{
		TArray<FDolphinUInt64> Results;
		for (const FDolphinInt32& Next : Value)
		{
			Results.Add(CastInt32ToUInt64(Next));
		}
		return Results;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Int32 Array to Int8 Array", meta = (Keywords = "Cast Convert Array Int32 signed int32 int int integer to Int8 signed int8 char byte"))
	static TArray<FDolphinInt8> CastInt32ArrayToInt8Array(const TArray<FDolphinInt32>& Value)
	{
		TArray<FDolphinInt8> Results;
		for (const FDolphinInt32& Next : Value)
		{
			Results.Add(CastInt32ToInt8(Next));
		}
		return Results;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Int32 Array to Int16 Array", meta = (Keywords = "Cast Convert Array Int32 signed int32 int int integer to Int16 signed int16 short"))
	static TArray<FDolphinInt16> CastInt32ArrayToInt16Array(const TArray<FDolphinInt32>& Value)
	{
		TArray<FDolphinInt16> Results;
		for (const FDolphinInt32& Next : Value)
		{
			Results.Add(CastInt32ToInt16(Next));
		}
		return Results;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Int32 Array to Int64 Array", meta = (Keywords = "Cast Convert Array Int32 signed int32 int int integer to Int64 signed int64 long int integer"))
	static TArray<FDolphinInt64> CastInt32ArrayToInt64Array(const TArray<FDolphinInt32>& Value)
	{
		TArray<FDolphinInt64> Results;
		for (const FDolphinInt32& Next : Value)
		{
			Results.Add(CastInt32ToInt64(Next));
		}
		return Results;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Int32 Array to Float Array", meta = (Keywords = "Cast Convert Array Int32 signed int32 int int integer to Float float decimal single single-precision"))
	static TArray<FDolphinFloat> CastInt32ArrayToFloatArray(const TArray<FDolphinInt32>& Value)
	{
		TArray<FDolphinFloat> Results;
		for (const FDolphinInt32& Next : Value)
		{
			Results.Add(CastInt32ToFloat(Next));
		}
		return Results;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Int32 Array to Double Array", meta = (Keywords = "Cast Convert Array Int32 signed int32 int int integer to Double double decimal double-precision float"))
	static TArray<FDolphinDouble> CastInt32ArrayToDoubleArray(const TArray<FDolphinInt32>& Value)
	{
		TArray<FDolphinDouble> Results;
		for (const FDolphinInt32& Next : Value)
		{
			Results.Add(CastInt32ToDouble(Next));
		}
		return Results;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Int32 Array to Unreal uint8 Array", meta = (Keywords = "Cast Convert Int32 signed int32 int int integer Array to UInt8 unsigned uint8 char byte ubyte"))
	static TArray<uint8> CastInt32ArrayToUnrealUInt8Array(const TArray<FDolphinInt32>& Value)
	{
		TArray<uint8> Results;
		for (const FDolphinInt32& Next : Value)
		{
			Results.Add(static_cast<uint8>(Next));
		}
		return Results;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Int32 Array to Unreal int32 Array", meta = (Keywords = "Cast Convert Int32 signed int32 int int integer Array to Int32 signed int32 int int integer"))
	static TArray<int32> CastInt32ArrayToUnrealInt32Array(const TArray<FDolphinInt32>& Value)
	{
		TArray<int32> Results;
		for (const FDolphinInt32& Next : Value)
		{
			Results.Add(static_cast<int32>(Next));
		}
		return Results;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Int32 Array to Unreal int64 Array", meta = (Keywords = "Cast Convert Int32 signed int32 int int integer Array to Int64 signed int64 long int integer"))
	static TArray<int64> CastInt32ArrayToUnrealInt64Array(const TArray<FDolphinInt32>& Value)
	{
		TArray<int64> Results;
		for (const FDolphinInt32& Next : Value)
		{
			Results.Add(static_cast<int64>(Next));
		}
		return Results;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Int32 Array to Unreal float Array", meta = (Keywords = "Cast Convert Int32 signed int32 int int integer Array to Float float decimal single single-precision"))
	static TArray<float> CastInt32ArrayToUnrealFloatArray(const TArray<FDolphinInt32>& Value)
	{
		TArray<float> Results;
		for (const FDolphinInt32& Next : Value)
		{
			Results.Add(static_cast<float>(Next));
		}
		return Results;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Unreal uint8 Array to Int32 Array", meta = (Keywords = "Cast Convert Int32 signed int32 int int integer Array to UInt8 unsigned uint8 char byte ubyte"))
	static TArray<FDolphinInt32> CastUnrealUInt8ArrayToInt32Array(const TArray<uint8>& Value)
	{
		TArray<FDolphinInt32> Results;
		for (const uint8& Next : Value)
		{
			Results.Add(static_cast<int32>(Next));
		}
		return Results;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Unreal int32 Array to Int32 Array", meta = (Keywords = "Cast Convert Int32 signed int32 int int integer Array to Int32 signed int32 int int integer"))
	static TArray<FDolphinInt32> CastUnrealInt32ArrayToInt32Array(const TArray<int32>& Value)
	{
		TArray<FDolphinInt32> Results;
		for (const int32& Next : Value)
		{
			Results.Add(static_cast<int32>(Next));
		}
		return Results;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Unreal int64 Array to Int32 Array", meta = (Keywords = "Cast Convert Int32 signed int32 int int integer Array to Int64 signed int64 long int integer"))
	static TArray<FDolphinInt32> CastUnrealInt64ArrayToInt32Array(const TArray<int64>& Value)
	{
		TArray<FDolphinInt32> Results;
		for (const int64& Next : Value)
		{
			Results.Add(static_cast<int32>(Next));
		}
		return Results;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Unreal float Array to Int32 Array", meta = (Keywords = "Cast Convert Int32 signed int32 int int integer Array to Float float decimal single single-precision"))
	static TArray<FDolphinInt32> CastUnrealFloatArrayToInt32Array(const TArray<float>& Value)
	{
		TArray<FDolphinInt32> Results;
		for (const float& Next : Value)
		{
			Results.Add(static_cast<int32>(Next));
		}
		return Results;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Extract Int32 To Raw Bytes", meta = (Keywords = "Get Cast Convert Extract Int32 signed int32 int int integer to Raw Bytes"))
	static TArray<FDolphinInt8> ExtractInt32ToRawBytes(const FDolphinInt32& Value)
	{
		TArray<uint8> Bytes;
		Bytes.AddZeroed(sizeof(Value.Value));
		FMemory::Memcpy(Bytes.GetData(), &Value.Value, sizeof(Value.Value));
		return CastUnrealUInt8ArrayToInt8Array(Bytes);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Extract Int32 To Raw UBytes", meta = (Keywords = "Get Cast Convert Extract Int32 signed int32 int int integer to Raw UBytes"))
	static TArray<FDolphinUInt8> ExtractInt32ToRawUBytes(const FDolphinInt32& Value)
	{
		TArray<uint8> Bytes;
		Bytes.AddZeroed(sizeof(Value.Value));
		FMemory::Memcpy(Bytes.GetData(), &Value.Value, sizeof(Value.Value));
		return CastUnrealUInt8ArrayToUInt8Array(Bytes);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Int64 to UInt8", meta = (Keywords = "Cast Convert Int64 signed int64 long int integer to UInt8 unsigned uint8 char byte ubyte"))
	static FDolphinUInt8 CastInt64ToUInt8(const FDolphinInt64& Value)
	{
		return static_cast<uint8>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Int64 to UInt16", meta = (Keywords = "Cast Convert Int64 signed int64 long int integer to UInt16 unsigned uint16 short ushort"))
	static FDolphinUInt16 CastInt64ToUInt16(const FDolphinInt64& Value)
	{
		return static_cast<uint16>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Int64 to UInt32", meta = (Keywords = "Cast Convert Int64 signed int64 long int integer to UInt32 unsigned uint32 int uint integer"))
	static FDolphinUInt32 CastInt64ToUInt32(const FDolphinInt64& Value)
	{
		return static_cast<uint32>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Int64 to UInt64", meta = (Keywords = "Cast Convert Int64 signed int64 long int integer to UInt64 unsigned uint64 long int ulong integer"))
	static FDolphinUInt64 CastInt64ToUInt64(const FDolphinInt64& Value)
	{
		return static_cast<uint64>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Int64 to Int8", meta = (Keywords = "Cast Convert Int64 signed int64 long int integer to Int8 signed int8 char byte"))
	static FDolphinInt8 CastInt64ToInt8(const FDolphinInt64& Value)
	{
		return static_cast<int8>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Int64 to Int16", meta = (Keywords = "Cast Convert Int64 signed int64 long int integer to Int16 signed int16 short"))
	static FDolphinInt16 CastInt64ToInt16(const FDolphinInt64& Value)
	{
		return static_cast<int16>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Int64 to Int32", meta = (Keywords = "Cast Convert Int64 signed int64 long int integer to Int32 signed int32 int int integer"))
	static FDolphinInt32 CastInt64ToInt32(const FDolphinInt64& Value)
	{
		return static_cast<int32>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Int64 to Float", meta = (Keywords = "Cast Convert Int64 signed int64 long int integer to Float float decimal single single-precision"))
	static FDolphinFloat CastInt64ToFloat(const FDolphinInt64& Value)
	{
		return static_cast<float>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Int64 to Double", meta = (Keywords = "Cast Convert Int64 signed int64 long int integer to Double double decimal double-precision float"))
	static FDolphinDouble CastInt64ToDouble(const FDolphinInt64& Value)
	{
		return static_cast<double>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Int64 to Unreal uint8", meta = (Keywords = "Cast Convert Int64 signed int64 long int integer to UInt8 unsigned uint8 char byte ubyte"))
	static uint8 CastInt64ToUnrealuint8(const FDolphinInt64& Value)
	{
		return static_cast<uint8>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Int64 to Unreal int32", meta = (Keywords = "Cast Convert Int64 signed int64 long int integer to Int32 signed int32 int int integer"))
	static int32 CastInt64ToUnrealint32(const FDolphinInt64& Value)
	{
		return static_cast<int32>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Int64 to Unreal int64", meta = (Keywords = "Cast Convert Int64 signed int64 long int integer to Int64 signed int64 long int integer"))
	static int64 CastInt64ToUnrealint64(const FDolphinInt64& Value)
	{
		return static_cast<int64>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Int64 to Unreal float", meta = (Keywords = "Cast Convert Int64 signed int64 long int integer to Float float decimal single single-precision"))
	static float CastInt64ToUnrealfloat(const FDolphinInt64& Value)
	{
		return static_cast<float>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Int64 Array to UInt8 Array", meta = (Keywords = "Cast Convert Array Int64 signed int64 long int integer to UInt8 unsigned uint8 char byte ubyte"))
	static TArray<FDolphinUInt8> CastInt64ArrayToUInt8Array(const TArray<FDolphinInt64>& Value)
	{
		TArray<FDolphinUInt8> Results;
		for (const FDolphinInt64& Next : Value)
		{
			Results.Add(CastInt64ToUInt8(Next));
		}
		return Results;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Int64 Array to UInt16 Array", meta = (Keywords = "Cast Convert Array Int64 signed int64 long int integer to UInt16 unsigned uint16 short ushort"))
	static TArray<FDolphinUInt16> CastInt64ArrayToUInt16Array(const TArray<FDolphinInt64>& Value)
	{
		TArray<FDolphinUInt16> Results;
		for (const FDolphinInt64& Next : Value)
		{
			Results.Add(CastInt64ToUInt16(Next));
		}
		return Results;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Int64 Array to UInt32 Array", meta = (Keywords = "Cast Convert Array Int64 signed int64 long int integer to UInt32 unsigned uint32 int uint integer"))
	static TArray<FDolphinUInt32> CastInt64ArrayToUInt32Array(const TArray<FDolphinInt64>& Value)
	{
		TArray<FDolphinUInt32> Results;
		for (const FDolphinInt64& Next : Value)
		{
			Results.Add(CastInt64ToUInt32(Next));
		}
		return Results;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Int64 Array to UInt64 Array", meta = (Keywords = "Cast Convert Array Int64 signed int64 long int integer to UInt64 unsigned uint64 long int ulong integer"))
	static TArray<FDolphinUInt64> CastInt64ArrayToUInt64Array(const TArray<FDolphinInt64>& Value)
	{
		TArray<FDolphinUInt64> Results;
		for (const FDolphinInt64& Next : Value)
		{
			Results.Add(CastInt64ToUInt64(Next));
		}
		return Results;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Int64 Array to Int8 Array", meta = (Keywords = "Cast Convert Array Int64 signed int64 long int integer to Int8 signed int8 char byte"))
	static TArray<FDolphinInt8> CastInt64ArrayToInt8Array(const TArray<FDolphinInt64>& Value)
	{
		TArray<FDolphinInt8> Results;
		for (const FDolphinInt64& Next : Value)
		{
			Results.Add(CastInt64ToInt8(Next));
		}
		return Results;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Int64 Array to Int16 Array", meta = (Keywords = "Cast Convert Array Int64 signed int64 long int integer to Int16 signed int16 short"))
	static TArray<FDolphinInt16> CastInt64ArrayToInt16Array(const TArray<FDolphinInt64>& Value)
	{
		TArray<FDolphinInt16> Results;
		for (const FDolphinInt64& Next : Value)
		{
			Results.Add(CastInt64ToInt16(Next));
		}
		return Results;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Int64 Array to Int32 Array", meta = (Keywords = "Cast Convert Array Int64 signed int64 long int integer to Int32 signed int32 int int integer"))
	static TArray<FDolphinInt32> CastInt64ArrayToInt32Array(const TArray<FDolphinInt64>& Value)
	{
		TArray<FDolphinInt32> Results;
		for (const FDolphinInt64& Next : Value)
		{
			Results.Add(CastInt64ToInt32(Next));
		}
		return Results;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Int64 Array to Float Array", meta = (Keywords = "Cast Convert Array Int64 signed int64 long int integer to Float float decimal single single-precision"))
	static TArray<FDolphinFloat> CastInt64ArrayToFloatArray(const TArray<FDolphinInt64>& Value)
	{
		TArray<FDolphinFloat> Results;
		for (const FDolphinInt64& Next : Value)
		{
			Results.Add(CastInt64ToFloat(Next));
		}
		return Results;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Int64 Array to Double Array", meta = (Keywords = "Cast Convert Array Int64 signed int64 long int integer to Double double decimal double-precision float"))
	static TArray<FDolphinDouble> CastInt64ArrayToDoubleArray(const TArray<FDolphinInt64>& Value)
	{
		TArray<FDolphinDouble> Results;
		for (const FDolphinInt64& Next : Value)
		{
			Results.Add(CastInt64ToDouble(Next));
		}
		return Results;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Int64 Array to Unreal uint8 Array", meta = (Keywords = "Cast Convert Int64 signed int64 long int integer Array to UInt8 unsigned uint8 char byte ubyte"))
	static TArray<uint8> CastInt64ArrayToUnrealUInt8Array(const TArray<FDolphinInt64>& Value)
	{
		TArray<uint8> Results;
		for (const FDolphinInt64& Next : Value)
		{
			Results.Add(static_cast<uint8>(Next));
		}
		return Results;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Int64 Array to Unreal int32 Array", meta = (Keywords = "Cast Convert Int64 signed int64 long int integer Array to Int32 signed int32 int int integer"))
	static TArray<int32> CastInt64ArrayToUnrealInt32Array(const TArray<FDolphinInt64>& Value)
	{
		TArray<int32> Results;
		for (const FDolphinInt64& Next : Value)
		{
			Results.Add(static_cast<int32>(Next));
		}
		return Results;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Int64 Array to Unreal int64 Array", meta = (Keywords = "Cast Convert Int64 signed int64 long int integer Array to Int64 signed int64 long int integer"))
	static TArray<int64> CastInt64ArrayToUnrealInt64Array(const TArray<FDolphinInt64>& Value)
	{
		TArray<int64> Results;
		for (const FDolphinInt64& Next : Value)
		{
			Results.Add(static_cast<int64>(Next));
		}
		return Results;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Int64 Array to Unreal float Array", meta = (Keywords = "Cast Convert Int64 signed int64 long int integer Array to Float float decimal single single-precision"))
	static TArray<float> CastInt64ArrayToUnrealFloatArray(const TArray<FDolphinInt64>& Value)
	{
		TArray<float> Results;
		for (const FDolphinInt64& Next : Value)
		{
			Results.Add(static_cast<float>(Next));
		}
		return Results;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Unreal uint8 Array to Int64 Array", meta = (Keywords = "Cast Convert Int64 signed int64 long int integer Array to UInt8 unsigned uint8 char byte ubyte"))
	static TArray<FDolphinInt64> CastUnrealUInt8ArrayToInt64Array(const TArray<uint8>& Value)
	{
		TArray<FDolphinInt64> Results;
		for (const uint8& Next : Value)
		{
			Results.Add(static_cast<int64>(Next));
		}
		return Results;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Unreal int32 Array to Int64 Array", meta = (Keywords = "Cast Convert Int64 signed int64 long int integer Array to Int32 signed int32 int int integer"))
	static TArray<FDolphinInt64> CastUnrealInt32ArrayToInt64Array(const TArray<int32>& Value)
	{
		TArray<FDolphinInt64> Results;
		for (const int32& Next : Value)
		{
			Results.Add(static_cast<int64>(Next));
		}
		return Results;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Unreal int64 Array to Int64 Array", meta = (Keywords = "Cast Convert Int64 signed int64 long int integer Array to Int64 signed int64 long int integer"))
	static TArray<FDolphinInt64> CastUnrealInt64ArrayToInt64Array(const TArray<int64>& Value)
	{
		TArray<FDolphinInt64> Results;
		for (const int64& Next : Value)
		{
			Results.Add(static_cast<int64>(Next));
		}
		return Results;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Unreal float Array to Int64 Array", meta = (Keywords = "Cast Convert Int64 signed int64 long int integer Array to Float float decimal single single-precision"))
	static TArray<FDolphinInt64> CastUnrealFloatArrayToInt64Array(const TArray<float>& Value)
	{
		TArray<FDolphinInt64> Results;
		for (const float& Next : Value)
		{
			Results.Add(static_cast<int64>(Next));
		}
		return Results;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Extract Int64 To Raw Bytes", meta = (Keywords = "Get Cast Convert Extract Int64 signed int64 long int integer to Raw Bytes"))
	static TArray<FDolphinInt8> ExtractInt64ToRawBytes(const FDolphinInt64& Value)
	{
		TArray<uint8> Bytes;
		Bytes.AddZeroed(sizeof(Value.Value));
		FMemory::Memcpy(Bytes.GetData(), &Value.Value, sizeof(Value.Value));
		return CastUnrealUInt8ArrayToInt8Array(Bytes);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Extract Int64 To Raw UBytes", meta = (Keywords = "Get Cast Convert Extract Int64 signed int64 long int integer to Raw UBytes"))
	static TArray<FDolphinUInt8> ExtractInt64ToRawUBytes(const FDolphinInt64& Value)
	{
		TArray<uint8> Bytes;
		Bytes.AddZeroed(sizeof(Value.Value));
		FMemory::Memcpy(Bytes.GetData(), &Value.Value, sizeof(Value.Value));
		return CastUnrealUInt8ArrayToUInt8Array(Bytes);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Float to UInt8", meta = (Keywords = "Cast Convert Float float decimal single single-precision to UInt8 unsigned uint8 char byte ubyte"))
	static FDolphinUInt8 CastFloatToUInt8(const FDolphinFloat& Value)
	{
		return static_cast<uint8>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Float to UInt16", meta = (Keywords = "Cast Convert Float float decimal single single-precision to UInt16 unsigned uint16 short ushort"))
	static FDolphinUInt16 CastFloatToUInt16(const FDolphinFloat& Value)
	{
		return static_cast<uint16>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Float to UInt32", meta = (Keywords = "Cast Convert Float float decimal single single-precision to UInt32 unsigned uint32 int uint integer"))
	static FDolphinUInt32 CastFloatToUInt32(const FDolphinFloat& Value)
	{
		return static_cast<uint32>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Float to UInt64", meta = (Keywords = "Cast Convert Float float decimal single single-precision to UInt64 unsigned uint64 long int ulong integer"))
	static FDolphinUInt64 CastFloatToUInt64(const FDolphinFloat& Value)
	{
		return static_cast<uint64>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Float to Int8", meta = (Keywords = "Cast Convert Float float decimal single single-precision to Int8 signed int8 char byte"))
	static FDolphinInt8 CastFloatToInt8(const FDolphinFloat& Value)
	{
		return static_cast<int8>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Float to Int16", meta = (Keywords = "Cast Convert Float float decimal single single-precision to Int16 signed int16 short"))
	static FDolphinInt16 CastFloatToInt16(const FDolphinFloat& Value)
	{
		return static_cast<int16>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Float to Int32", meta = (Keywords = "Cast Convert Float float decimal single single-precision to Int32 signed int32 int int integer"))
	static FDolphinInt32 CastFloatToInt32(const FDolphinFloat& Value)
	{
		return static_cast<int32>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Float to Int64", meta = (Keywords = "Cast Convert Float float decimal single single-precision to Int64 signed int64 long int integer"))
	static FDolphinInt64 CastFloatToInt64(const FDolphinFloat& Value)
	{
		return static_cast<int64>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Float to Double", meta = (Keywords = "Cast Convert Float float decimal single single-precision to Double double decimal double-precision float"))
	static FDolphinDouble CastFloatToDouble(const FDolphinFloat& Value)
	{
		return static_cast<double>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Float to Unreal uint8", meta = (Keywords = "Cast Convert Float float decimal single single-precision to UInt8 unsigned uint8 char byte ubyte"))
	static uint8 CastFloatToUnrealuint8(const FDolphinFloat& Value)
	{
		return static_cast<uint8>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Float to Unreal int32", meta = (Keywords = "Cast Convert Float float decimal single single-precision to Int32 signed int32 int int integer"))
	static int32 CastFloatToUnrealint32(const FDolphinFloat& Value)
	{
		return static_cast<int32>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Float to Unreal int64", meta = (Keywords = "Cast Convert Float float decimal single single-precision to Int64 signed int64 long int integer"))
	static int64 CastFloatToUnrealint64(const FDolphinFloat& Value)
	{
		return static_cast<int64>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Float to Unreal float", meta = (Keywords = "Cast Convert Float float decimal single single-precision to Float float decimal single single-precision"))
	static float CastFloatToUnrealfloat(const FDolphinFloat& Value)
	{
		return static_cast<float>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Float Array to UInt8 Array", meta = (Keywords = "Cast Convert Array Float float decimal single single-precision to UInt8 unsigned uint8 char byte ubyte"))
	static TArray<FDolphinUInt8> CastFloatArrayToUInt8Array(const TArray<FDolphinFloat>& Value)
	{
		TArray<FDolphinUInt8> Results;
		for (const FDolphinFloat& Next : Value)
		{
			Results.Add(CastFloatToUInt8(Next));
		}
		return Results;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Float Array to UInt16 Array", meta = (Keywords = "Cast Convert Array Float float decimal single single-precision to UInt16 unsigned uint16 short ushort"))
	static TArray<FDolphinUInt16> CastFloatArrayToUInt16Array(const TArray<FDolphinFloat>& Value)
	{
		TArray<FDolphinUInt16> Results;
		for (const FDolphinFloat& Next : Value)
		{
			Results.Add(CastFloatToUInt16(Next));
		}
		return Results;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Float Array to UInt32 Array", meta = (Keywords = "Cast Convert Array Float float decimal single single-precision to UInt32 unsigned uint32 int uint integer"))
	static TArray<FDolphinUInt32> CastFloatArrayToUInt32Array(const TArray<FDolphinFloat>& Value)
	{
		TArray<FDolphinUInt32> Results;
		for (const FDolphinFloat& Next : Value)
		{
			Results.Add(CastFloatToUInt32(Next));
		}
		return Results;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Float Array to UInt64 Array", meta = (Keywords = "Cast Convert Array Float float decimal single single-precision to UInt64 unsigned uint64 long int ulong integer"))
	static TArray<FDolphinUInt64> CastFloatArrayToUInt64Array(const TArray<FDolphinFloat>& Value)
	{
		TArray<FDolphinUInt64> Results;
		for (const FDolphinFloat& Next : Value)
		{
			Results.Add(CastFloatToUInt64(Next));
		}
		return Results;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Float Array to Int8 Array", meta = (Keywords = "Cast Convert Array Float float decimal single single-precision to Int8 signed int8 char byte"))
	static TArray<FDolphinInt8> CastFloatArrayToInt8Array(const TArray<FDolphinFloat>& Value)
	{
		TArray<FDolphinInt8> Results;
		for (const FDolphinFloat& Next : Value)
		{
			Results.Add(CastFloatToInt8(Next));
		}
		return Results;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Float Array to Int16 Array", meta = (Keywords = "Cast Convert Array Float float decimal single single-precision to Int16 signed int16 short"))
	static TArray<FDolphinInt16> CastFloatArrayToInt16Array(const TArray<FDolphinFloat>& Value)
	{
		TArray<FDolphinInt16> Results;
		for (const FDolphinFloat& Next : Value)
		{
			Results.Add(CastFloatToInt16(Next));
		}
		return Results;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Float Array to Int32 Array", meta = (Keywords = "Cast Convert Array Float float decimal single single-precision to Int32 signed int32 int int integer"))
	static TArray<FDolphinInt32> CastFloatArrayToInt32Array(const TArray<FDolphinFloat>& Value)
	{
		TArray<FDolphinInt32> Results;
		for (const FDolphinFloat& Next : Value)
		{
			Results.Add(CastFloatToInt32(Next));
		}
		return Results;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Float Array to Int64 Array", meta = (Keywords = "Cast Convert Array Float float decimal single single-precision to Int64 signed int64 long int integer"))
	static TArray<FDolphinInt64> CastFloatArrayToInt64Array(const TArray<FDolphinFloat>& Value)
	{
		TArray<FDolphinInt64> Results;
		for (const FDolphinFloat& Next : Value)
		{
			Results.Add(CastFloatToInt64(Next));
		}
		return Results;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Float Array to Double Array", meta = (Keywords = "Cast Convert Array Float float decimal single single-precision to Double double decimal double-precision float"))
	static TArray<FDolphinDouble> CastFloatArrayToDoubleArray(const TArray<FDolphinFloat>& Value)
	{
		TArray<FDolphinDouble> Results;
		for (const FDolphinFloat& Next : Value)
		{
			Results.Add(CastFloatToDouble(Next));
		}
		return Results;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Float Array to Unreal uint8 Array", meta = (Keywords = "Cast Convert Float float decimal single single-precision Array to UInt8 unsigned uint8 char byte ubyte"))
	static TArray<uint8> CastFloatArrayToUnrealUInt8Array(const TArray<FDolphinFloat>& Value)
	{
		TArray<uint8> Results;
		for (const FDolphinFloat& Next : Value)
		{
			Results.Add(static_cast<uint8>(Next));
		}
		return Results;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Float Array to Unreal int32 Array", meta = (Keywords = "Cast Convert Float float decimal single single-precision Array to Int32 signed int32 int int integer"))
	static TArray<int32> CastFloatArrayToUnrealInt32Array(const TArray<FDolphinFloat>& Value)
	{
		TArray<int32> Results;
		for (const FDolphinFloat& Next : Value)
		{
			Results.Add(static_cast<int32>(Next));
		}
		return Results;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Float Array to Unreal int64 Array", meta = (Keywords = "Cast Convert Float float decimal single single-precision Array to Int64 signed int64 long int integer"))
	static TArray<int64> CastFloatArrayToUnrealInt64Array(const TArray<FDolphinFloat>& Value)
	{
		TArray<int64> Results;
		for (const FDolphinFloat& Next : Value)
		{
			Results.Add(static_cast<int64>(Next));
		}
		return Results;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Float Array to Unreal float Array", meta = (Keywords = "Cast Convert Float float decimal single single-precision Array to Float float decimal single single-precision"))
	static TArray<float> CastFloatArrayToUnrealFloatArray(const TArray<FDolphinFloat>& Value)
	{
		TArray<float> Results;
		for (const FDolphinFloat& Next : Value)
		{
			Results.Add(static_cast<float>(Next));
		}
		return Results;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Unreal uint8 Array to Float Array", meta = (Keywords = "Cast Convert Float float decimal single single-precision Array to UInt8 unsigned uint8 char byte ubyte"))
	static TArray<FDolphinFloat> CastUnrealUInt8ArrayToFloatArray(const TArray<uint8>& Value)
	{
		TArray<FDolphinFloat> Results;
		for (const uint8& Next : Value)
		{
			Results.Add(static_cast<float>(Next));
		}
		return Results;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Unreal int32 Array to Float Array", meta = (Keywords = "Cast Convert Float float decimal single single-precision Array to Int32 signed int32 int int integer"))
	static TArray<FDolphinFloat> CastUnrealInt32ArrayToFloatArray(const TArray<int32>& Value)
	{
		TArray<FDolphinFloat> Results;
		for (const int32& Next : Value)
		{
			Results.Add(static_cast<float>(Next));
		}
		return Results;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Unreal int64 Array to Float Array", meta = (Keywords = "Cast Convert Float float decimal single single-precision Array to Int64 signed int64 long int integer"))
	static TArray<FDolphinFloat> CastUnrealInt64ArrayToFloatArray(const TArray<int64>& Value)
	{
		TArray<FDolphinFloat> Results;
		for (const int64& Next : Value)
		{
			Results.Add(static_cast<float>(Next));
		}
		return Results;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Unreal float Array to Float Array", meta = (Keywords = "Cast Convert Float float decimal single single-precision Array to Float float decimal single single-precision"))
	static TArray<FDolphinFloat> CastUnrealFloatArrayToFloatArray(const TArray<float>& Value)
	{
		TArray<FDolphinFloat> Results;
		for (const float& Next : Value)
		{
			Results.Add(static_cast<float>(Next));
		}
		return Results;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Extract Float To Raw Bytes", meta = (Keywords = "Get Cast Convert Extract Float float decimal single single-precision to Raw Bytes"))
	static TArray<FDolphinInt8> ExtractFloatToRawBytes(const FDolphinFloat& Value)
	{
		TArray<uint8> Bytes;
		Bytes.AddZeroed(sizeof(Value.Value));
		FMemory::Memcpy(Bytes.GetData(), &Value.Value, sizeof(Value.Value));
		return CastUnrealUInt8ArrayToInt8Array(Bytes);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Extract Float To Raw UBytes", meta = (Keywords = "Get Cast Convert Extract Float float decimal single single-precision to Raw UBytes"))
	static TArray<FDolphinUInt8> ExtractFloatToRawUBytes(const FDolphinFloat& Value)
	{
		TArray<uint8> Bytes;
		Bytes.AddZeroed(sizeof(Value.Value));
		FMemory::Memcpy(Bytes.GetData(), &Value.Value, sizeof(Value.Value));
		return CastUnrealUInt8ArrayToUInt8Array(Bytes);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Double to UInt8", meta = (Keywords = "Cast Convert Double double decimal double-precision float to UInt8 unsigned uint8 char byte ubyte"))
	static FDolphinUInt8 CastDoubleToUInt8(const FDolphinDouble& Value)
	{
		return static_cast<uint8>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Double to UInt16", meta = (Keywords = "Cast Convert Double double decimal double-precision float to UInt16 unsigned uint16 short ushort"))
	static FDolphinUInt16 CastDoubleToUInt16(const FDolphinDouble& Value)
	{
		return static_cast<uint16>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Double to UInt32", meta = (Keywords = "Cast Convert Double double decimal double-precision float to UInt32 unsigned uint32 int uint integer"))
	static FDolphinUInt32 CastDoubleToUInt32(const FDolphinDouble& Value)
	{
		return static_cast<uint32>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Double to UInt64", meta = (Keywords = "Cast Convert Double double decimal double-precision float to UInt64 unsigned uint64 long int ulong integer"))
	static FDolphinUInt64 CastDoubleToUInt64(const FDolphinDouble& Value)
	{
		return static_cast<uint64>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Double to Int8", meta = (Keywords = "Cast Convert Double double decimal double-precision float to Int8 signed int8 char byte"))
	static FDolphinInt8 CastDoubleToInt8(const FDolphinDouble& Value)
	{
		return static_cast<int8>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Double to Int16", meta = (Keywords = "Cast Convert Double double decimal double-precision float to Int16 signed int16 short"))
	static FDolphinInt16 CastDoubleToInt16(const FDolphinDouble& Value)
	{
		return static_cast<int16>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Double to Int32", meta = (Keywords = "Cast Convert Double double decimal double-precision float to Int32 signed int32 int int integer"))
	static FDolphinInt32 CastDoubleToInt32(const FDolphinDouble& Value)
	{
		return static_cast<int32>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Double to Int64", meta = (Keywords = "Cast Convert Double double decimal double-precision float to Int64 signed int64 long int integer"))
	static FDolphinInt64 CastDoubleToInt64(const FDolphinDouble& Value)
	{
		return static_cast<int64>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Double to Float", meta = (Keywords = "Cast Convert Double double decimal double-precision float to Float float decimal single single-precision"))
	static FDolphinFloat CastDoubleToFloat(const FDolphinDouble& Value)
	{
		return static_cast<float>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Double to Unreal uint8", meta = (Keywords = "Cast Convert Double double decimal double-precision float to UInt8 unsigned uint8 char byte ubyte"))
	static uint8 CastDoubleToUnrealuint8(const FDolphinDouble& Value)
	{
		return static_cast<uint8>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Double to Unreal int32", meta = (Keywords = "Cast Convert Double double decimal double-precision float to Int32 signed int32 int int integer"))
	static int32 CastDoubleToUnrealint32(const FDolphinDouble& Value)
	{
		return static_cast<int32>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Double to Unreal int64", meta = (Keywords = "Cast Convert Double double decimal double-precision float to Int64 signed int64 long int integer"))
	static int64 CastDoubleToUnrealint64(const FDolphinDouble& Value)
	{
		return static_cast<int64>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Double to Unreal float", meta = (Keywords = "Cast Convert Double double decimal double-precision float to Float float decimal single single-precision"))
	static float CastDoubleToUnrealfloat(const FDolphinDouble& Value)
	{
		return static_cast<float>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Double Array to UInt8 Array", meta = (Keywords = "Cast Convert Array Double double decimal double-precision float to UInt8 unsigned uint8 char byte ubyte"))
	static TArray<FDolphinUInt8> CastDoubleArrayToUInt8Array(const TArray<FDolphinDouble>& Value)
	{
		TArray<FDolphinUInt8> Results;
		for (const FDolphinDouble& Next : Value)
		{
			Results.Add(CastDoubleToUInt8(Next));
		}
		return Results;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Double Array to UInt16 Array", meta = (Keywords = "Cast Convert Array Double double decimal double-precision float to UInt16 unsigned uint16 short ushort"))
	static TArray<FDolphinUInt16> CastDoubleArrayToUInt16Array(const TArray<FDolphinDouble>& Value)
	{
		TArray<FDolphinUInt16> Results;
		for (const FDolphinDouble& Next : Value)
		{
			Results.Add(CastDoubleToUInt16(Next));
		}
		return Results;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Double Array to UInt32 Array", meta = (Keywords = "Cast Convert Array Double double decimal double-precision float to UInt32 unsigned uint32 int uint integer"))
	static TArray<FDolphinUInt32> CastDoubleArrayToUInt32Array(const TArray<FDolphinDouble>& Value)
	{
		TArray<FDolphinUInt32> Results;
		for (const FDolphinDouble& Next : Value)
		{
			Results.Add(CastDoubleToUInt32(Next));
		}
		return Results;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Double Array to UInt64 Array", meta = (Keywords = "Cast Convert Array Double double decimal double-precision float to UInt64 unsigned uint64 long int ulong integer"))
	static TArray<FDolphinUInt64> CastDoubleArrayToUInt64Array(const TArray<FDolphinDouble>& Value)
	{
		TArray<FDolphinUInt64> Results;
		for (const FDolphinDouble& Next : Value)
		{
			Results.Add(CastDoubleToUInt64(Next));
		}
		return Results;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Double Array to Int8 Array", meta = (Keywords = "Cast Convert Array Double double decimal double-precision float to Int8 signed int8 char byte"))
	static TArray<FDolphinInt8> CastDoubleArrayToInt8Array(const TArray<FDolphinDouble>& Value)
	{
		TArray<FDolphinInt8> Results;
		for (const FDolphinDouble& Next : Value)
		{
			Results.Add(CastDoubleToInt8(Next));
		}
		return Results;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Double Array to Int16 Array", meta = (Keywords = "Cast Convert Array Double double decimal double-precision float to Int16 signed int16 short"))
	static TArray<FDolphinInt16> CastDoubleArrayToInt16Array(const TArray<FDolphinDouble>& Value)
	{
		TArray<FDolphinInt16> Results;
		for (const FDolphinDouble& Next : Value)
		{
			Results.Add(CastDoubleToInt16(Next));
		}
		return Results;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Double Array to Int32 Array", meta = (Keywords = "Cast Convert Array Double double decimal double-precision float to Int32 signed int32 int int integer"))
	static TArray<FDolphinInt32> CastDoubleArrayToInt32Array(const TArray<FDolphinDouble>& Value)
	{
		TArray<FDolphinInt32> Results;
		for (const FDolphinDouble& Next : Value)
		{
			Results.Add(CastDoubleToInt32(Next));
		}
		return Results;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Double Array to Int64 Array", meta = (Keywords = "Cast Convert Array Double double decimal double-precision float to Int64 signed int64 long int integer"))
	static TArray<FDolphinInt64> CastDoubleArrayToInt64Array(const TArray<FDolphinDouble>& Value)
	{
		TArray<FDolphinInt64> Results;
		for (const FDolphinDouble& Next : Value)
		{
			Results.Add(CastDoubleToInt64(Next));
		}
		return Results;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Double Array to Float Array", meta = (Keywords = "Cast Convert Array Double double decimal double-precision float to Float float decimal single single-precision"))
	static TArray<FDolphinFloat> CastDoubleArrayToFloatArray(const TArray<FDolphinDouble>& Value)
	{
		TArray<FDolphinFloat> Results;
		for (const FDolphinDouble& Next : Value)
		{
			Results.Add(CastDoubleToFloat(Next));
		}
		return Results;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Double Array to Unreal uint8 Array", meta = (Keywords = "Cast Convert Double double decimal double-precision float Array to UInt8 unsigned uint8 char byte ubyte"))
	static TArray<uint8> CastDoubleArrayToUnrealUInt8Array(const TArray<FDolphinDouble>& Value)
	{
		TArray<uint8> Results;
		for (const FDolphinDouble& Next : Value)
		{
			Results.Add(static_cast<uint8>(Next));
		}
		return Results;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Double Array to Unreal int32 Array", meta = (Keywords = "Cast Convert Double double decimal double-precision float Array to Int32 signed int32 int int integer"))
	static TArray<int32> CastDoubleArrayToUnrealInt32Array(const TArray<FDolphinDouble>& Value)
	{
		TArray<int32> Results;
		for (const FDolphinDouble& Next : Value)
		{
			Results.Add(static_cast<int32>(Next));
		}
		return Results;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Double Array to Unreal int64 Array", meta = (Keywords = "Cast Convert Double double decimal double-precision float Array to Int64 signed int64 long int integer"))
	static TArray<int64> CastDoubleArrayToUnrealInt64Array(const TArray<FDolphinDouble>& Value)
	{
		TArray<int64> Results;
		for (const FDolphinDouble& Next : Value)
		{
			Results.Add(static_cast<int64>(Next));
		}
		return Results;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Double Array to Unreal float Array", meta = (Keywords = "Cast Convert Double double decimal double-precision float Array to Float float decimal single single-precision"))
	static TArray<float> CastDoubleArrayToUnrealFloatArray(const TArray<FDolphinDouble>& Value)
	{
		TArray<float> Results;
		for (const FDolphinDouble& Next : Value)
		{
			Results.Add(static_cast<float>(Next));
		}
		return Results;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Unreal uint8 Array to Double Array", meta = (Keywords = "Cast Convert Double double decimal double-precision float Array to UInt8 unsigned uint8 char byte ubyte"))
	static TArray<FDolphinDouble> CastUnrealUInt8ArrayToDoubleArray(const TArray<uint8>& Value)
	{
		TArray<FDolphinDouble> Results;
		for (const uint8& Next : Value)
		{
			Results.Add(static_cast<double>(Next));
		}
		return Results;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Unreal int32 Array to Double Array", meta = (Keywords = "Cast Convert Double double decimal double-precision float Array to Int32 signed int32 int int integer"))
	static TArray<FDolphinDouble> CastUnrealInt32ArrayToDoubleArray(const TArray<int32>& Value)
	{
		TArray<FDolphinDouble> Results;
		for (const int32& Next : Value)
		{
			Results.Add(static_cast<double>(Next));
		}
		return Results;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Unreal int64 Array to Double Array", meta = (Keywords = "Cast Convert Double double decimal double-precision float Array to Int64 signed int64 long int integer"))
	static TArray<FDolphinDouble> CastUnrealInt64ArrayToDoubleArray(const TArray<int64>& Value)
	{
		TArray<FDolphinDouble> Results;
		for (const int64& Next : Value)
		{
			Results.Add(static_cast<double>(Next));
		}
		return Results;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Unreal float Array to Double Array", meta = (Keywords = "Cast Convert Double double decimal double-precision float Array to Float float decimal single single-precision"))
	static TArray<FDolphinDouble> CastUnrealFloatArrayToDoubleArray(const TArray<float>& Value)
	{
		TArray<FDolphinDouble> Results;
		for (const float& Next : Value)
		{
			Results.Add(static_cast<double>(Next));
		}
		return Results;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Extract Double To Raw Bytes", meta = (Keywords = "Get Cast Convert Extract Double double decimal double-precision float to Raw Bytes"))
	static TArray<FDolphinInt8> ExtractDoubleToRawBytes(const FDolphinDouble& Value)
	{
		TArray<uint8> Bytes;
		Bytes.AddZeroed(sizeof(Value.Value));
		FMemory::Memcpy(Bytes.GetData(), &Value.Value, sizeof(Value.Value));
		return CastUnrealUInt8ArrayToInt8Array(Bytes);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Extract Double To Raw UBytes", meta = (Keywords = "Get Cast Convert Extract Double double decimal double-precision float to Raw UBytes"))
	static TArray<FDolphinUInt8> ExtractDoubleToRawUBytes(const FDolphinDouble& Value)
	{
		TArray<uint8> Bytes;
		Bytes.AddZeroed(sizeof(Value.Value));
		FMemory::Memcpy(Bytes.GetData(), &Value.Value, sizeof(Value.Value));
		return CastUnrealUInt8ArrayToUInt8Array(Bytes);
	}


	//////////////////////////////////////////////////////////////////////////////////
    //                                   OPERATORS                                  //
    //////////////////////////////////////////////////////////////////////////////////

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Subtract UInt8 - UInt8", meta = (Keywords = "- Minus Subtract"))
	static FDolphinUInt8 Dolphin_UInt8SubtractUInt8(const FDolphinUInt8& Value1, const FDolphinUInt8& Value2)
	{
		return Value1.Value - Value2.Value;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Add UInt8 + UInt8", meta = (Keywords = "+ Add Addition"))
	static FDolphinUInt8 Dolphin_UInt8AddUInt8(const FDolphinUInt8& Value1, const FDolphinUInt8& Value2)
	{
		return Value1.Value + Value2.Value;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Multiply UInt8 * UInt8", meta = (Keywords = "* Multiply Times"))
	static FDolphinUInt8 Dolphin_UInt8MultiplyUInt8(const FDolphinUInt8& Value1, const FDolphinUInt8& Value2)
	{
		return Value1.Value * Value2.Value;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Divide UInt8 / UInt8", meta = (Keywords = "/ Divide By Division"))
	static FDolphinUInt8 Dolphin_UInt8DivideUInt8(const FDolphinUInt8& Value1, const FDolphinUInt8& Value2)
	{
		return Value1.Value / Value2.Value;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "EqualTo UInt8 == UInt8", meta = (Keywords = "== Equal To Equals"))
	static bool Dolphin_UInt8EqualToUInt8(const FDolphinUInt8& Value1, const FDolphinUInt8& Value2)
	{
		return Value1.Value == Value2.Value;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "NotEqualTo UInt8 != UInt8", meta = (Keywords = "!= Not Equal To Equals"))
	static bool Dolphin_UInt8NotEqualToUInt8(const FDolphinUInt8& Value1, const FDolphinUInt8& Value2)
	{
		return Value1.Value != Value2.Value;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "LessThan UInt8 < UInt8", meta = (Keywords = "< Less Than"))
	static bool Dolphin_UInt8LessThanUInt8(const FDolphinUInt8& Value1, const FDolphinUInt8& Value2)
	{
		return Value1.Value < Value2.Value;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "LessThanOrEqualTo UInt8 <= UInt8", meta = (Keywords = "<= Less Than or Equal To Equals"))
	static bool Dolphin_UInt8LessThanOrEqualToUInt8(const FDolphinUInt8& Value1, const FDolphinUInt8& Value2)
	{
		return Value1.Value <= Value2.Value;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "GreaterThan UInt8 > UInt8", meta = (Keywords = "> Greater Than"))
	static bool Dolphin_UInt8GreaterThanUInt8(const FDolphinUInt8& Value1, const FDolphinUInt8& Value2)
	{
		return Value1.Value > Value2.Value;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "GreaterThanOrEqualTo UInt8 >= UInt8", meta = (Keywords = ">= Greater Than or Equal To Equals"))
	static bool Dolphin_UInt8GreaterThanOrEqualToUInt8(const FDolphinUInt8& Value1, const FDolphinUInt8& Value2)
	{
		return Value1.Value >= Value2.Value;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Subtract UInt16 - UInt16", meta = (Keywords = "- Minus Subtract"))
	static FDolphinUInt16 Dolphin_UInt16SubtractUInt16(const FDolphinUInt16& Value1, const FDolphinUInt16& Value2)
	{
		return Value1.Value - Value2.Value;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Add UInt16 + UInt16", meta = (Keywords = "+ Add Addition"))
	static FDolphinUInt16 Dolphin_UInt16AddUInt16(const FDolphinUInt16& Value1, const FDolphinUInt16& Value2)
	{
		return Value1.Value + Value2.Value;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Multiply UInt16 * UInt16", meta = (Keywords = "* Multiply Times"))
	static FDolphinUInt16 Dolphin_UInt16MultiplyUInt16(const FDolphinUInt16& Value1, const FDolphinUInt16& Value2)
	{
		return Value1.Value * Value2.Value;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Divide UInt16 / UInt16", meta = (Keywords = "/ Divide By Division"))
	static FDolphinUInt16 Dolphin_UInt16DivideUInt16(const FDolphinUInt16& Value1, const FDolphinUInt16& Value2)
	{
		return Value1.Value / Value2.Value;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "EqualTo UInt16 == UInt16", meta = (Keywords = "== Equal To Equals"))
	static bool Dolphin_UInt16EqualToUInt16(const FDolphinUInt16& Value1, const FDolphinUInt16& Value2)
	{
		return Value1.Value == Value2.Value;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "NotEqualTo UInt16 != UInt16", meta = (Keywords = "!= Not Equal To Equals"))
	static bool Dolphin_UInt16NotEqualToUInt16(const FDolphinUInt16& Value1, const FDolphinUInt16& Value2)
	{
		return Value1.Value != Value2.Value;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "LessThan UInt16 < UInt16", meta = (Keywords = "< Less Than"))
	static bool Dolphin_UInt16LessThanUInt16(const FDolphinUInt16& Value1, const FDolphinUInt16& Value2)
	{
		return Value1.Value < Value2.Value;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "LessThanOrEqualTo UInt16 <= UInt16", meta = (Keywords = "<= Less Than or Equal To Equals"))
	static bool Dolphin_UInt16LessThanOrEqualToUInt16(const FDolphinUInt16& Value1, const FDolphinUInt16& Value2)
	{
		return Value1.Value <= Value2.Value;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "GreaterThan UInt16 > UInt16", meta = (Keywords = "> Greater Than"))
	static bool Dolphin_UInt16GreaterThanUInt16(const FDolphinUInt16& Value1, const FDolphinUInt16& Value2)
	{
		return Value1.Value > Value2.Value;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "GreaterThanOrEqualTo UInt16 >= UInt16", meta = (Keywords = ">= Greater Than or Equal To Equals"))
	static bool Dolphin_UInt16GreaterThanOrEqualToUInt16(const FDolphinUInt16& Value1, const FDolphinUInt16& Value2)
	{
		return Value1.Value >= Value2.Value;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Subtract UInt32 - UInt32", meta = (Keywords = "- Minus Subtract"))
	static FDolphinUInt32 Dolphin_UInt32SubtractUInt32(const FDolphinUInt32& Value1, const FDolphinUInt32& Value2)
	{
		return Value1.Value - Value2.Value;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Add UInt32 + UInt32", meta = (Keywords = "+ Add Addition"))
	static FDolphinUInt32 Dolphin_UInt32AddUInt32(const FDolphinUInt32& Value1, const FDolphinUInt32& Value2)
	{
		return Value1.Value + Value2.Value;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Multiply UInt32 * UInt32", meta = (Keywords = "* Multiply Times"))
	static FDolphinUInt32 Dolphin_UInt32MultiplyUInt32(const FDolphinUInt32& Value1, const FDolphinUInt32& Value2)
	{
		return Value1.Value * Value2.Value;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Divide UInt32 / UInt32", meta = (Keywords = "/ Divide By Division"))
	static FDolphinUInt32 Dolphin_UInt32DivideUInt32(const FDolphinUInt32& Value1, const FDolphinUInt32& Value2)
	{
		return Value1.Value / Value2.Value;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "EqualTo UInt32 == UInt32", meta = (Keywords = "== Equal To Equals"))
	static bool Dolphin_UInt32EqualToUInt32(const FDolphinUInt32& Value1, const FDolphinUInt32& Value2)
	{
		return Value1.Value == Value2.Value;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "NotEqualTo UInt32 != UInt32", meta = (Keywords = "!= Not Equal To Equals"))
	static bool Dolphin_UInt32NotEqualToUInt32(const FDolphinUInt32& Value1, const FDolphinUInt32& Value2)
	{
		return Value1.Value != Value2.Value;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "LessThan UInt32 < UInt32", meta = (Keywords = "< Less Than"))
	static bool Dolphin_UInt32LessThanUInt32(const FDolphinUInt32& Value1, const FDolphinUInt32& Value2)
	{
		return Value1.Value < Value2.Value;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "LessThanOrEqualTo UInt32 <= UInt32", meta = (Keywords = "<= Less Than or Equal To Equals"))
	static bool Dolphin_UInt32LessThanOrEqualToUInt32(const FDolphinUInt32& Value1, const FDolphinUInt32& Value2)
	{
		return Value1.Value <= Value2.Value;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "GreaterThan UInt32 > UInt32", meta = (Keywords = "> Greater Than"))
	static bool Dolphin_UInt32GreaterThanUInt32(const FDolphinUInt32& Value1, const FDolphinUInt32& Value2)
	{
		return Value1.Value > Value2.Value;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "GreaterThanOrEqualTo UInt32 >= UInt32", meta = (Keywords = ">= Greater Than or Equal To Equals"))
	static bool Dolphin_UInt32GreaterThanOrEqualToUInt32(const FDolphinUInt32& Value1, const FDolphinUInt32& Value2)
	{
		return Value1.Value >= Value2.Value;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Subtract UInt64 - UInt64", meta = (Keywords = "- Minus Subtract"))
	static FDolphinUInt64 Dolphin_UInt64SubtractUInt64(const FDolphinUInt64& Value1, const FDolphinUInt64& Value2)
	{
		return Value1.Value - Value2.Value;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Add UInt64 + UInt64", meta = (Keywords = "+ Add Addition"))
	static FDolphinUInt64 Dolphin_UInt64AddUInt64(const FDolphinUInt64& Value1, const FDolphinUInt64& Value2)
	{
		return Value1.Value + Value2.Value;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Multiply UInt64 * UInt64", meta = (Keywords = "* Multiply Times"))
	static FDolphinUInt64 Dolphin_UInt64MultiplyUInt64(const FDolphinUInt64& Value1, const FDolphinUInt64& Value2)
	{
		return Value1.Value * Value2.Value;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Divide UInt64 / UInt64", meta = (Keywords = "/ Divide By Division"))
	static FDolphinUInt64 Dolphin_UInt64DivideUInt64(const FDolphinUInt64& Value1, const FDolphinUInt64& Value2)
	{
		return Value1.Value / Value2.Value;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "EqualTo UInt64 == UInt64", meta = (Keywords = "== Equal To Equals"))
	static bool Dolphin_UInt64EqualToUInt64(const FDolphinUInt64& Value1, const FDolphinUInt64& Value2)
	{
		return Value1.Value == Value2.Value;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "NotEqualTo UInt64 != UInt64", meta = (Keywords = "!= Not Equal To Equals"))
	static bool Dolphin_UInt64NotEqualToUInt64(const FDolphinUInt64& Value1, const FDolphinUInt64& Value2)
	{
		return Value1.Value != Value2.Value;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "LessThan UInt64 < UInt64", meta = (Keywords = "< Less Than"))
	static bool Dolphin_UInt64LessThanUInt64(const FDolphinUInt64& Value1, const FDolphinUInt64& Value2)
	{
		return Value1.Value < Value2.Value;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "LessThanOrEqualTo UInt64 <= UInt64", meta = (Keywords = "<= Less Than or Equal To Equals"))
	static bool Dolphin_UInt64LessThanOrEqualToUInt64(const FDolphinUInt64& Value1, const FDolphinUInt64& Value2)
	{
		return Value1.Value <= Value2.Value;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "GreaterThan UInt64 > UInt64", meta = (Keywords = "> Greater Than"))
	static bool Dolphin_UInt64GreaterThanUInt64(const FDolphinUInt64& Value1, const FDolphinUInt64& Value2)
	{
		return Value1.Value > Value2.Value;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "GreaterThanOrEqualTo UInt64 >= UInt64", meta = (Keywords = ">= Greater Than or Equal To Equals"))
	static bool Dolphin_UInt64GreaterThanOrEqualToUInt64(const FDolphinUInt64& Value1, const FDolphinUInt64& Value2)
	{
		return Value1.Value >= Value2.Value;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Subtract Int8 - Int8", meta = (Keywords = "- Minus Subtract"))
	static FDolphinInt8 Dolphin_Int8SubtractInt8(const FDolphinInt8& Value1, const FDolphinInt8& Value2)
	{
		return Value1.Value - Value2.Value;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Add Int8 + Int8", meta = (Keywords = "+ Add Addition"))
	static FDolphinInt8 Dolphin_Int8AddInt8(const FDolphinInt8& Value1, const FDolphinInt8& Value2)
	{
		return Value1.Value + Value2.Value;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Multiply Int8 * Int8", meta = (Keywords = "* Multiply Times"))
	static FDolphinInt8 Dolphin_Int8MultiplyInt8(const FDolphinInt8& Value1, const FDolphinInt8& Value2)
	{
		return Value1.Value * Value2.Value;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Divide Int8 / Int8", meta = (Keywords = "/ Divide By Division"))
	static FDolphinInt8 Dolphin_Int8DivideInt8(const FDolphinInt8& Value1, const FDolphinInt8& Value2)
	{
		return Value1.Value / Value2.Value;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "EqualTo Int8 == Int8", meta = (Keywords = "== Equal To Equals"))
	static bool Dolphin_Int8EqualToInt8(const FDolphinInt8& Value1, const FDolphinInt8& Value2)
	{
		return Value1.Value == Value2.Value;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "NotEqualTo Int8 != Int8", meta = (Keywords = "!= Not Equal To Equals"))
	static bool Dolphin_Int8NotEqualToInt8(const FDolphinInt8& Value1, const FDolphinInt8& Value2)
	{
		return Value1.Value != Value2.Value;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "LessThan Int8 < Int8", meta = (Keywords = "< Less Than"))
	static bool Dolphin_Int8LessThanInt8(const FDolphinInt8& Value1, const FDolphinInt8& Value2)
	{
		return Value1.Value < Value2.Value;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "LessThanOrEqualTo Int8 <= Int8", meta = (Keywords = "<= Less Than or Equal To Equals"))
	static bool Dolphin_Int8LessThanOrEqualToInt8(const FDolphinInt8& Value1, const FDolphinInt8& Value2)
	{
		return Value1.Value <= Value2.Value;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "GreaterThan Int8 > Int8", meta = (Keywords = "> Greater Than"))
	static bool Dolphin_Int8GreaterThanInt8(const FDolphinInt8& Value1, const FDolphinInt8& Value2)
	{
		return Value1.Value > Value2.Value;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "GreaterThanOrEqualTo Int8 >= Int8", meta = (Keywords = ">= Greater Than or Equal To Equals"))
	static bool Dolphin_Int8GreaterThanOrEqualToInt8(const FDolphinInt8& Value1, const FDolphinInt8& Value2)
	{
		return Value1.Value >= Value2.Value;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Subtract Int16 - Int16", meta = (Keywords = "- Minus Subtract"))
	static FDolphinInt16 Dolphin_Int16SubtractInt16(const FDolphinInt16& Value1, const FDolphinInt16& Value2)
	{
		return Value1.Value - Value2.Value;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Add Int16 + Int16", meta = (Keywords = "+ Add Addition"))
	static FDolphinInt16 Dolphin_Int16AddInt16(const FDolphinInt16& Value1, const FDolphinInt16& Value2)
	{
		return Value1.Value + Value2.Value;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Multiply Int16 * Int16", meta = (Keywords = "* Multiply Times"))
	static FDolphinInt16 Dolphin_Int16MultiplyInt16(const FDolphinInt16& Value1, const FDolphinInt16& Value2)
	{
		return Value1.Value * Value2.Value;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Divide Int16 / Int16", meta = (Keywords = "/ Divide By Division"))
	static FDolphinInt16 Dolphin_Int16DivideInt16(const FDolphinInt16& Value1, const FDolphinInt16& Value2)
	{
		return Value1.Value / Value2.Value;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "EqualTo Int16 == Int16", meta = (Keywords = "== Equal To Equals"))
	static bool Dolphin_Int16EqualToInt16(const FDolphinInt16& Value1, const FDolphinInt16& Value2)
	{
		return Value1.Value == Value2.Value;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "NotEqualTo Int16 != Int16", meta = (Keywords = "!= Not Equal To Equals"))
	static bool Dolphin_Int16NotEqualToInt16(const FDolphinInt16& Value1, const FDolphinInt16& Value2)
	{
		return Value1.Value != Value2.Value;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "LessThan Int16 < Int16", meta = (Keywords = "< Less Than"))
	static bool Dolphin_Int16LessThanInt16(const FDolphinInt16& Value1, const FDolphinInt16& Value2)
	{
		return Value1.Value < Value2.Value;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "LessThanOrEqualTo Int16 <= Int16", meta = (Keywords = "<= Less Than or Equal To Equals"))
	static bool Dolphin_Int16LessThanOrEqualToInt16(const FDolphinInt16& Value1, const FDolphinInt16& Value2)
	{
		return Value1.Value <= Value2.Value;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "GreaterThan Int16 > Int16", meta = (Keywords = "> Greater Than"))
	static bool Dolphin_Int16GreaterThanInt16(const FDolphinInt16& Value1, const FDolphinInt16& Value2)
	{
		return Value1.Value > Value2.Value;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "GreaterThanOrEqualTo Int16 >= Int16", meta = (Keywords = ">= Greater Than or Equal To Equals"))
	static bool Dolphin_Int16GreaterThanOrEqualToInt16(const FDolphinInt16& Value1, const FDolphinInt16& Value2)
	{
		return Value1.Value >= Value2.Value;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Subtract Int32 - Int32", meta = (Keywords = "- Minus Subtract"))
	static FDolphinInt32 Dolphin_Int32SubtractInt32(const FDolphinInt32& Value1, const FDolphinInt32& Value2)
	{
		return Value1.Value - Value2.Value;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Add Int32 + Int32", meta = (Keywords = "+ Add Addition"))
	static FDolphinInt32 Dolphin_Int32AddInt32(const FDolphinInt32& Value1, const FDolphinInt32& Value2)
	{
		return Value1.Value + Value2.Value;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Multiply Int32 * Int32", meta = (Keywords = "* Multiply Times"))
	static FDolphinInt32 Dolphin_Int32MultiplyInt32(const FDolphinInt32& Value1, const FDolphinInt32& Value2)
	{
		return Value1.Value * Value2.Value;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Divide Int32 / Int32", meta = (Keywords = "/ Divide By Division"))
	static FDolphinInt32 Dolphin_Int32DivideInt32(const FDolphinInt32& Value1, const FDolphinInt32& Value2)
	{
		return Value1.Value / Value2.Value;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "EqualTo Int32 == Int32", meta = (Keywords = "== Equal To Equals"))
	static bool Dolphin_Int32EqualToInt32(const FDolphinInt32& Value1, const FDolphinInt32& Value2)
	{
		return Value1.Value == Value2.Value;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "NotEqualTo Int32 != Int32", meta = (Keywords = "!= Not Equal To Equals"))
	static bool Dolphin_Int32NotEqualToInt32(const FDolphinInt32& Value1, const FDolphinInt32& Value2)
	{
		return Value1.Value != Value2.Value;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "LessThan Int32 < Int32", meta = (Keywords = "< Less Than"))
	static bool Dolphin_Int32LessThanInt32(const FDolphinInt32& Value1, const FDolphinInt32& Value2)
	{
		return Value1.Value < Value2.Value;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "LessThanOrEqualTo Int32 <= Int32", meta = (Keywords = "<= Less Than or Equal To Equals"))
	static bool Dolphin_Int32LessThanOrEqualToInt32(const FDolphinInt32& Value1, const FDolphinInt32& Value2)
	{
		return Value1.Value <= Value2.Value;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "GreaterThan Int32 > Int32", meta = (Keywords = "> Greater Than"))
	static bool Dolphin_Int32GreaterThanInt32(const FDolphinInt32& Value1, const FDolphinInt32& Value2)
	{
		return Value1.Value > Value2.Value;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "GreaterThanOrEqualTo Int32 >= Int32", meta = (Keywords = ">= Greater Than or Equal To Equals"))
	static bool Dolphin_Int32GreaterThanOrEqualToInt32(const FDolphinInt32& Value1, const FDolphinInt32& Value2)
	{
		return Value1.Value >= Value2.Value;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Subtract Int64 - Int64", meta = (Keywords = "- Minus Subtract"))
	static FDolphinInt64 Dolphin_Int64SubtractInt64(const FDolphinInt64& Value1, const FDolphinInt64& Value2)
	{
		return Value1.Value - Value2.Value;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Add Int64 + Int64", meta = (Keywords = "+ Add Addition"))
	static FDolphinInt64 Dolphin_Int64AddInt64(const FDolphinInt64& Value1, const FDolphinInt64& Value2)
	{
		return Value1.Value + Value2.Value;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Multiply Int64 * Int64", meta = (Keywords = "* Multiply Times"))
	static FDolphinInt64 Dolphin_Int64MultiplyInt64(const FDolphinInt64& Value1, const FDolphinInt64& Value2)
	{
		return Value1.Value * Value2.Value;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Divide Int64 / Int64", meta = (Keywords = "/ Divide By Division"))
	static FDolphinInt64 Dolphin_Int64DivideInt64(const FDolphinInt64& Value1, const FDolphinInt64& Value2)
	{
		return Value1.Value / Value2.Value;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "EqualTo Int64 == Int64", meta = (Keywords = "== Equal To Equals"))
	static bool Dolphin_Int64EqualToInt64(const FDolphinInt64& Value1, const FDolphinInt64& Value2)
	{
		return Value1.Value == Value2.Value;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "NotEqualTo Int64 != Int64", meta = (Keywords = "!= Not Equal To Equals"))
	static bool Dolphin_Int64NotEqualToInt64(const FDolphinInt64& Value1, const FDolphinInt64& Value2)
	{
		return Value1.Value != Value2.Value;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "LessThan Int64 < Int64", meta = (Keywords = "< Less Than"))
	static bool Dolphin_Int64LessThanInt64(const FDolphinInt64& Value1, const FDolphinInt64& Value2)
	{
		return Value1.Value < Value2.Value;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "LessThanOrEqualTo Int64 <= Int64", meta = (Keywords = "<= Less Than or Equal To Equals"))
	static bool Dolphin_Int64LessThanOrEqualToInt64(const FDolphinInt64& Value1, const FDolphinInt64& Value2)
	{
		return Value1.Value <= Value2.Value;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "GreaterThan Int64 > Int64", meta = (Keywords = "> Greater Than"))
	static bool Dolphin_Int64GreaterThanInt64(const FDolphinInt64& Value1, const FDolphinInt64& Value2)
	{
		return Value1.Value > Value2.Value;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "GreaterThanOrEqualTo Int64 >= Int64", meta = (Keywords = ">= Greater Than or Equal To Equals"))
	static bool Dolphin_Int64GreaterThanOrEqualToInt64(const FDolphinInt64& Value1, const FDolphinInt64& Value2)
	{
		return Value1.Value >= Value2.Value;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Subtract Float - Float", meta = (Keywords = "- Minus Subtract"))
	static FDolphinFloat Dolphin_FloatSubtractFloat(const FDolphinFloat& Value1, const FDolphinFloat& Value2)
	{
		return Value1.Value - Value2.Value;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Add Float + Float", meta = (Keywords = "+ Add Addition"))
	static FDolphinFloat Dolphin_FloatAddFloat(const FDolphinFloat& Value1, const FDolphinFloat& Value2)
	{
		return Value1.Value + Value2.Value;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Multiply Float * Float", meta = (Keywords = "* Multiply Times"))
	static FDolphinFloat Dolphin_FloatMultiplyFloat(const FDolphinFloat& Value1, const FDolphinFloat& Value2)
	{
		return Value1.Value * Value2.Value;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Divide Float / Float", meta = (Keywords = "/ Divide By Division"))
	static FDolphinFloat Dolphin_FloatDivideFloat(const FDolphinFloat& Value1, const FDolphinFloat& Value2)
	{
		return Value1.Value / Value2.Value;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "EqualTo Float == Float", meta = (Keywords = "== Equal To Equals"))
	static bool Dolphin_FloatEqualToFloat(const FDolphinFloat& Value1, const FDolphinFloat& Value2)
	{
		return Value1.Value == Value2.Value;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "NotEqualTo Float != Float", meta = (Keywords = "!= Not Equal To Equals"))
	static bool Dolphin_FloatNotEqualToFloat(const FDolphinFloat& Value1, const FDolphinFloat& Value2)
	{
		return Value1.Value != Value2.Value;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "LessThan Float < Float", meta = (Keywords = "< Less Than"))
	static bool Dolphin_FloatLessThanFloat(const FDolphinFloat& Value1, const FDolphinFloat& Value2)
	{
		return Value1.Value < Value2.Value;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "LessThanOrEqualTo Float <= Float", meta = (Keywords = "<= Less Than or Equal To Equals"))
	static bool Dolphin_FloatLessThanOrEqualToFloat(const FDolphinFloat& Value1, const FDolphinFloat& Value2)
	{
		return Value1.Value <= Value2.Value;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "GreaterThan Float > Float", meta = (Keywords = "> Greater Than"))
	static bool Dolphin_FloatGreaterThanFloat(const FDolphinFloat& Value1, const FDolphinFloat& Value2)
	{
		return Value1.Value > Value2.Value;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "GreaterThanOrEqualTo Float >= Float", meta = (Keywords = ">= Greater Than or Equal To Equals"))
	static bool Dolphin_FloatGreaterThanOrEqualToFloat(const FDolphinFloat& Value1, const FDolphinFloat& Value2)
	{
		return Value1.Value >= Value2.Value;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Subtract Double - Double", meta = (Keywords = "- Minus Subtract"))
	static FDolphinDouble Dolphin_DoubleSubtractDouble(const FDolphinDouble& Value1, const FDolphinDouble& Value2)
	{
		return Value1.Value - Value2.Value;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Add Double + Double", meta = (Keywords = "+ Add Addition"))
	static FDolphinDouble Dolphin_DoubleAddDouble(const FDolphinDouble& Value1, const FDolphinDouble& Value2)
	{
		return Value1.Value + Value2.Value;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Multiply Double * Double", meta = (Keywords = "* Multiply Times"))
	static FDolphinDouble Dolphin_DoubleMultiplyDouble(const FDolphinDouble& Value1, const FDolphinDouble& Value2)
	{
		return Value1.Value * Value2.Value;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Divide Double / Double", meta = (Keywords = "/ Divide By Division"))
	static FDolphinDouble Dolphin_DoubleDivideDouble(const FDolphinDouble& Value1, const FDolphinDouble& Value2)
	{
		return Value1.Value / Value2.Value;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "EqualTo Double == Double", meta = (Keywords = "== Equal To Equals"))
	static bool Dolphin_DoubleEqualToDouble(const FDolphinDouble& Value1, const FDolphinDouble& Value2)
	{
		return Value1.Value == Value2.Value;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "NotEqualTo Double != Double", meta = (Keywords = "!= Not Equal To Equals"))
	static bool Dolphin_DoubleNotEqualToDouble(const FDolphinDouble& Value1, const FDolphinDouble& Value2)
	{
		return Value1.Value != Value2.Value;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "LessThan Double < Double", meta = (Keywords = "< Less Than"))
	static bool Dolphin_DoubleLessThanDouble(const FDolphinDouble& Value1, const FDolphinDouble& Value2)
	{
		return Value1.Value < Value2.Value;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "LessThanOrEqualTo Double <= Double", meta = (Keywords = "<= Less Than or Equal To Equals"))
	static bool Dolphin_DoubleLessThanOrEqualToDouble(const FDolphinDouble& Value1, const FDolphinDouble& Value2)
	{
		return Value1.Value <= Value2.Value;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "GreaterThan Double > Double", meta = (Keywords = "> Greater Than"))
	static bool Dolphin_DoubleGreaterThanDouble(const FDolphinDouble& Value1, const FDolphinDouble& Value2)
	{
		return Value1.Value > Value2.Value;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "GreaterThanOrEqualTo Double >= Double", meta = (Keywords = ">= Greater Than or Equal To Equals"))
	static bool Dolphin_DoubleGreaterThanOrEqualToDouble(const FDolphinDouble& Value1, const FDolphinDouble& Value2)
	{
		return Value1.Value >= Value2.Value;
	}



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

		return Bytes;
	}

	static FString CleanHexString(FString HexString, int32 ByteCount)
	{
		HexString = HexString.TrimStartAndEnd().Replace(TEXT(" "), TEXT(""));

		if (HexString.StartsWith("0x") || HexString.StartsWith("0X"))
		{
			HexString.RightChopInline(2);
		}

		while (HexString.Len() < ByteCount * 2)
		{
			HexString = "0" + HexString;
		}

		if (HexString.Len() > ByteCount * 2)
		{
			HexString.LeftChopInline(HexString.Len() - ByteCount * 2);
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


