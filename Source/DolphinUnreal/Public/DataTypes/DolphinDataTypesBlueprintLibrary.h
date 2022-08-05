#pragma once

#include "DataTypes/DolphinDataTypes.h"
#include "DolphinDataTypesBlueprintLibrary.generated.h"

#define KCPPPWPLog(Level, Text) UE_LOG(LogDolphinDataTypesBlueprintLibraryPlugin, Level, TEXT(Text))
#define KCPPPWPLogF(Level, Format, ...) UE_LOG(LogDolphinDataTypesBlueprintLibraryPlugin, Level, TEXT(Format), __VA_ARGS__)

#define OPERATOR_HEADER(DataType, OperationName, Operation) UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = #DataType" "#Operation" "#DataType) \

#define OPERATOR(DataType, OperationName, Operation) \
	OPERATOR_HEADER(DataType, OperationName, Operation) \
	static FDolphin ## DataType Dolphin_ ## DataType ## OperationName ## DataType(const FDolphin ## DataType& Value1, const FDolphin ## DataType& Value2) \
	{ \
		return Value1.Value ## Operation Value2.Value; \
	}
#define OPERATOR_BOOL(DataType, OperationName, Operation) \
	OPERATOR_HEADER(DataType, OperationName, Operation) \
	static bool Dolphin_ ## DataType ## OperationName ## DataType(const FDolphin ## DataType& Value1, const FDolphin ## DataType& Value2) \
	{ \
		return Value1.Value ## Operation Value2.Value; \
	}

#define OPERATOR_PLUS(DataType)		OPERATOR(DataType, Plus, +)
#define OPERATOR_MINUS(DataType)	OPERATOR(DataType, Minus, -)
#define OPERATOR_TIMES(DataType)	OPERATOR(DataType, Times, *)
#define OPERATOR_DIVIDE(DataType)	OPERATOR(DataType, Divide, /)
#define OPERATOR_E(DataType)	OPERATOR_BOOL(DataType, EqualTo, ==)
#define OPERATOR_NE(DataType)	OPERATOR_BOOL(DataType, NotEqualTo, !=)
#define OPERATOR_L(DataType)	OPERATOR_BOOL(DataType, LessThan, <)
#define OPERATOR_LE(DataType)	OPERATOR_BOOL(DataType, LessThanOrEqualTo, <=)
#define OPERATOR_G(DataType)	OPERATOR_BOOL(DataType, GreaterThan, >)
#define OPERATOR_GE(DataType)	OPERATOR_BOOL(DataType, GreaterThanEqualTo, >=)

#define OPERATORS(DataType) \
	OPERATOR_PLUS(DataType) \
	OPERATOR_MINUS(DataType) \
	OPERATOR_TIMES(DataType) \
	OPERATOR_DIVIDE(DataType) \
	OPERATOR_E(DataType) \
	OPERATOR_NE(DataType) \
	OPERATOR_L(DataType) \
	OPERATOR_LE(DataType) \
	OPERATOR_G(DataType) \
	OPERATOR_GE(DataType)

UCLASS(ClassGroup = "Dolphin|CPP UE4FundamentalType Wrapper", BlueprintType)
class UDolphinDataTypesBlueprintLibrary : public UObject
{
	GENERATED_BODY()

public:
	UDolphinDataTypesBlueprintLibrary(const class FObjectInitializer& ObjectInitializer);

	/************/
	/* Creators */
	/************/

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Create Dolphin Double")
	static FDolphinDouble CreateDouble(float Value)
	{
		return { static_cast<double>(Value) };
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Create Dolphin Float")
		static FDolphinFloat CreateFloat(float Value)
	{
		return { static_cast<float>(Value) };
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Create Dolphin Int 64")
	static FDolphinInt64 CreateInt64(int32 Value)
	{
		return { static_cast<int64>(Value) };
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Create Dolphin UInt 64")
	static FDolphinUInt64 CreateUInt64(int32 Value)
	{
		return { static_cast<uint64>(Value) };
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Create Dolphin Int 32")
	static FDolphinInt32 CreateInt32(int32 Value)
	{
		return { static_cast<int32>(Value) };
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Create Dolphin UInt 32")
	static FDolphinUInt32 CreateUInt32(int32 Value)
	{
		return { static_cast<uint32>(Value) };
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Create Dolphin Int 16")
	static FDolphinInt16 CreateInt16(int32 Value)
	{
		return { static_cast<int16>(Value) };
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Create Dolphin UInt 16")
	static FDolphinUInt16 CreateUInt16(int32 Value)
	{
		return { static_cast<uint16>(Value) };
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Create Dolphin Int 8")
	static FDolphinInt8 CreateInt8(int32 Value)
	{
		return { static_cast<int8>(Value) };
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Create Dolphin UInt 8")
	static FDolphinUInt8 CreateUInt8(int32 Value)
	{
		return { static_cast<uint8>(Value) };
	}

	/*************/
	/* Extractors */
	/*************/

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "double #")
	static void ExtractDouble(const FDolphinDouble& D, float& F)
	{
		F = static_cast<float>(D.Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "float #")
		static void ExtractFloat(const FDolphinFloat& D, float& F)
	{
		F = static_cast<float>(D.Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "int64 #")
	static void ExtractInt64(const FDolphinInt64& I64, int32& I32)
	{
		I32 = static_cast<int32>(I64.Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "uint64 #")
	static void ExtractUInt64(const FDolphinUInt64& UI64, int32& I32)
	{
		I32 = static_cast<int32>(UI64.Value & 0x7FFFFFFF);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "uint32 #")
	static void ExtractUInt32(const FDolphinUInt32& UI32, int32& I32)
	{
		I32 = static_cast<int32>(UI32.Value & 0x7FFFFFFF);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "uint32 #")
	static void ExtractUInt32Full(const FDolphinUInt32& UI32, int32& I32, uint8& HighBit)
	{
		I32 = static_cast<int32>(UI32.Value & 0x7FFFFFFF);
		HighBit = UI32.Value >> 31;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "int16 #")
	static void ExtractInt16(const FDolphinInt16& I16, int32& I32)
	{
		I32 = static_cast<int32>(I16.Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "uint16 #")
	static void ExtractUInt16(const FDolphinUInt16& UI16, int32& I32)
	{
		I32 = static_cast<int32>(UI16.Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "int8 #")
	static void ExtractInt8(const FDolphinInt8& I8, int32& I32)
	{
		I32 = static_cast<int32>(I8.Value);
	}

	/*********/
	/* Casts */
	/*********/

	/* Double */
	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "double -> float")
	static FDolphinFloat CastDoubleToFloat(const FDolphinDouble& D)
	{
		return static_cast<float>(D.Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "float -> double")
	static FDolphinDouble CastFloatToDouble(const FDolphinFloat& F)
	{
		return static_cast<double>(F);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "double -> int64")
	static FDolphinInt64 CastDoubleToInt64(const FDolphinDouble& D)
	{
		return static_cast<int64>(D.Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "int64 -> double")
	static FDolphinDouble CastInt64ToDouble(const FDolphinInt64& I64)
	{
		return static_cast<double>(I64.Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "double -> uint64")
	static FDolphinUInt64 CastDoubleToUInt64(const FDolphinDouble& D)
	{
		return static_cast<uint64>(D.Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "uint64 -> double")
	static FDolphinDouble CastUInt64ToDouble(const FDolphinUInt64& UI64)
	{
		return static_cast<double>(UI64.Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "double -> int32")
	static int32 CastDoubleToInt32(const FDolphinDouble& D)
	{
		return static_cast<int32>(D.Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "int32 -> double")
	static FDolphinDouble CastInt32ToDouble(int32 I32)
	{
		return static_cast<double>(I32);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "double -> uint32")
	static FDolphinUInt32 CastDoubleToUInt32(const FDolphinDouble& D)
	{
		return static_cast<uint32>(D.Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "uint32 -> double")
	static FDolphinDouble CastUInt32ToDouble(const FDolphinUInt32& UI32)
	{
		return static_cast<double>(UI32.Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "double -> int16")
	static FDolphinInt16 CastDoubleToInt16(const FDolphinDouble& D)
	{
		return static_cast<int16>(D.Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "int16 -> double")
	static FDolphinDouble CastInt16ToDouble(const FDolphinInt16& I16)
	{
		return static_cast<double>(I16.Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "double -> uint16")
	static FDolphinUInt16 CastDoubleToUInt16(const FDolphinDouble& D)
	{
		return static_cast<uint16>(D.Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "uint16 -> double")
	static FDolphinDouble CastUInt16ToDouble(const FDolphinUInt16& UI16)
	{
		return static_cast<double>(UI16.Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "double -> int8")
	static FDolphinInt8 CastDoubleToInt8(const FDolphinDouble& D)
	{
		return static_cast<int8>(D.Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "int8 -> double")
	static FDolphinDouble CastInt8ToDouble(const FDolphinInt8& I8)
	{
		return static_cast<double>(I8.Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "double -> uint8")
	static uint8 CastDoubleToUInt8(const FDolphinDouble& D)
	{
		return static_cast<uint8>(D.Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "uint8 -> double")
	static FDolphinDouble CastUInt8ToDouble(uint8 UI8)
	{
		return static_cast<double>(UI8);
	}

	/* Float */
	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "float -> int64")
	static FDolphinInt64 CastFloatToInt64(float F)
	{
		return static_cast<int64>(F);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "int64 -> float")
	static float CastInt64ToFloat(const FDolphinInt64& I64)
	{
		return static_cast<float>(I64.Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "float -> uint64")
	static FDolphinUInt64 CastFloatToUInt64(float F)
	{
		return static_cast<uint64>(F);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "uint64 -> float")
	static float CastUInt64ToFloat(const FDolphinUInt64& UI64)
	{
		return static_cast<float>(UI64.Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "float -> int32")
	static int32 CastFloatToInt32(float F)
	{
		return static_cast<int32>(F);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "int32 -> float")
	static float CastInt32ToFloat(int32 I32)
	{
		return static_cast<float>(I32);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "float -> uint32")
	static FDolphinUInt32 CastFloatToUInt32(float F)
	{
		return static_cast<uint32>(F);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "uint32 -> float")
	static float CastUInt32ToFloat(const FDolphinUInt32& UI32)
	{
		return static_cast<float>(UI32.Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "float -> int16")
	static FDolphinInt16 CastFloatToInt16(float F)
	{
		return static_cast<int16>(F);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "int16 -> float")
	static float CastInt16ToFloat(const FDolphinInt16& I16)
	{
		return static_cast<float>(I16.Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "float -> uint16")
	static FDolphinUInt16 CastFloatToUInt16(float F)
	{
		return static_cast<uint16>(F);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "uint16 -> float")
	static float CastUInt16ToFloat(const FDolphinUInt16& UI16)
	{
		return static_cast<float>(UI16.Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "float -> int8")
	static FDolphinInt8 CastFloatToInt8(float F)
	{
		return static_cast<int8>(F);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "int8 -> float")
	static float CastInt8ToFloat(const FDolphinInt8& I8)
	{
		return static_cast<float>(I8.Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "float -> uint8")
	static uint8 CastFloatToUInt8(float F)
	{
		return static_cast<uint8>(F);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "uint8 -> float")
	static float CastUInt8ToFloat(uint8 UI8)
	{
		return static_cast<float>(UI8);
	}

	/* Int 64 */
	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "int64 -> uint64")
	static FDolphinUInt64 CastInt64ToUInt64(const FDolphinInt64& I64)
	{
		return static_cast<uint64>(I64.Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "uint64 -> int64")
	static FDolphinInt64 CastUInt64ToInt64(const FDolphinUInt64& UI64)
	{
		return static_cast<int64>(UI64.Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "int64 -> int32")
	static int32 CastInt64ToInt32(const FDolphinInt64& I64)
	{
		return static_cast<int32>(I64.Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "int32 -> int64")
	static FDolphinInt64 CastInt32ToInt64(int32 I32)
	{
		return static_cast<int64>(I32);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "int64 -> uint32")
	static FDolphinUInt32 CastInt64ToUInt32(const FDolphinInt64& I64)
	{
		return static_cast<uint32>(I64.Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "uint32 -> int64")
	static FDolphinInt64 CastUInt32ToInt64(const FDolphinUInt32& UI32)
	{
		return static_cast<int64>(UI32.Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "int64 -> int16")
	static FDolphinInt16 CastInt64ToInt16(const FDolphinInt64& I64)
	{
		return static_cast<int16>(I64.Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "int16 -> int64")
	static FDolphinInt64 CastInt16ToInt64(const FDolphinInt16& I16)
	{
		return static_cast<int64>(I16.Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "int64 -> uint16")
	static FDolphinUInt16 CastInt64ToUInt16(const FDolphinInt64& I64)
	{
		return static_cast<uint16>(I64.Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "uint16 -> int64")
	static FDolphinInt64 CastUInt16ToInt64(const FDolphinUInt16& UI16)
	{
		return static_cast<int64>(UI16.Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "int64 -> int8")
	static FDolphinInt8 CastInt64ToInt8(const FDolphinInt64& I64)
	{
		return static_cast<int8>(I64.Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "int8 -> int64")
	static FDolphinInt64 CastInt8ToInt64(const FDolphinInt8& I8)
	{
		return static_cast<int64>(I8.Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "int64 -> uint8")
	static uint8 CastInt64ToUInt8(const FDolphinInt64& I64)
	{
		return static_cast<uint8>(I64.Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "uint8 -> int64")
	static FDolphinInt64 CastUInt8ToInt64(uint8 UI8)
	{
		return static_cast<int64>(UI8);
	}

	/* UInt 64 */
	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "uint64 -> int32")
	static int32 CastUInt64ToInt32(const FDolphinUInt64& UI64)
	{
		return static_cast<int32>(UI64.Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "int32 -> uint64")
	static FDolphinUInt64 CastInt32ToUInt64(int32 I32)
	{
		return static_cast<uint64>(I32);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "uint64 -> uint32")
	static FDolphinUInt32 CastUInt64ToUInt32(const FDolphinUInt64& UI64)
	{
		return static_cast<uint32>(UI64.Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "uint32 -> uint64")
	static FDolphinUInt64 CastUInt32ToUInt64(const FDolphinUInt32& UI32)
	{
		return static_cast<uint64>(UI32.Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "uint64 -> int16")
	static FDolphinInt16 CastUInt64ToInt16(const FDolphinUInt64& UI64)
	{
		return static_cast<int16>(UI64.Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "int16 -> uint64")
	static FDolphinUInt64 CastInt16ToUInt64(const FDolphinInt16& I16)
	{
		return static_cast<uint64>(I16.Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "uint64 -> uint16")
	static FDolphinUInt16 CastUInt64ToUInt16(const FDolphinUInt64& UI64)
	{
		return static_cast<uint16>(UI64.Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "uint16 -> uint64")
	static FDolphinUInt64 CastUInt16ToUInt64(const FDolphinUInt16& UI16)
	{
		return static_cast<uint64>(UI16.Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "uint64 -> int8")
	static FDolphinInt8 CastUInt64ToInt8(const FDolphinUInt64& UI64)
	{
		return static_cast<int8>(UI64.Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "int8 -> uint64")
	static FDolphinUInt64 CastInt8ToUInt64(const FDolphinInt8& I8)
	{
		return static_cast<uint64>(I8.Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "uint64 -> uint8")
	static uint8 CastUInt64ToUInt8(const FDolphinUInt64& UI64)
	{
		return static_cast<uint8>(UI64.Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "uint8 -> uint64")
	static FDolphinUInt64 CastUInt8ToUInt64(uint8 UI8)
	{
		return static_cast<uint64>(UI8);
	}

	/* Int 32 */
	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "int32 -> uint32")
	static FDolphinUInt32 CastInt32ToUInt32(int32 I32)
	{
		return static_cast<uint32>(I32);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "uint32 -> int32")
	static int32 CastUInt32ToInt32(const FDolphinUInt32& UI32)
	{
		return static_cast<int32>(UI32.Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "int32 -> int16")
	static FDolphinInt16 CastInt32ToInt16(int32 I32)
	{
		return static_cast<int16>(I32);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "int16 -> int32")
	static int32 CastInt16ToInt32(const FDolphinInt16& I16)
	{
		return static_cast<int32>(I16.Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "int32 -> uint16")
	static FDolphinUInt16 CastInt32ToUInt16(int32 I32)
	{
		return static_cast<uint16>(I32);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "uint16 -> int32")
	static int32 CastUInt16ToInt32(const FDolphinUInt16& UI16)
	{
		return static_cast<int32>(UI16.Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "int32 -> int8")
	static FDolphinInt8 CastInt32ToInt8(int32 I32)
	{
		return static_cast<int8>(I32);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "int8 -> int32")
	static int32 CastInt8ToInt32(const FDolphinInt8& I8)
	{
		return static_cast<int32>(I8.Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "int32 -> uint8")
	static uint8 CastInt32ToUInt8(int32 I32)
	{
		return static_cast<uint8>(I32);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "uint8 -> int32")
	static int32 CastUInt8ToInt32(uint8 UI8)
	{
		return static_cast<int32>(UI8);
	}

	/* UInt 32 */
	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "uint32 -> int16")
	static FDolphinInt16 CastUInt32ToInt16(const FDolphinUInt32& UI32)
	{
		return static_cast<int16>(UI32.Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "int16 -> uint32")
	static FDolphinUInt32 CastInt16ToUInt32(const FDolphinInt16& I16)
	{
		return static_cast<uint32>(I16.Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "uint32 -> uint16")
	static FDolphinUInt16 CastUInt32ToUInt16(const FDolphinUInt32& UI32)
	{
		return static_cast<uint16>(UI32.Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "uint16 -> uint32")
	static FDolphinUInt32 CastUInt16ToUInt32(const FDolphinUInt16& UI16)
	{
		return static_cast<uint32>(UI16.Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "uint32 -> int8")
	static FDolphinInt8 CastUInt32ToInt8(const FDolphinUInt32& UI32)
	{
		return static_cast<int8>(UI32.Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "int8 -> uint32")
	static FDolphinUInt32 CastInt8ToUInt32(const FDolphinInt8& I8)
	{
		return static_cast<uint32>(I8.Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "uint32 -> uint8")
	static uint8 CastUInt32ToUInt8(const FDolphinUInt32& UI32)
	{
		return static_cast<uint8>(UI32.Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "uint8 -> uint32")
	static FDolphinUInt32 CastUInt8ToUInt32(uint8 UI8)
	{
		return static_cast<uint32>(UI8);
	}

	/* Int 16 */
	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "int16 -> uint16")
	static FDolphinUInt16 CastInt16ToUInt16(const FDolphinInt16& I16)
	{
		return static_cast<uint16>(I16.Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "uint16 -> int16")
	static FDolphinInt16 CastUInt16ToInt16(const FDolphinUInt16& UI16)
	{
		return static_cast<int16>(UI16.Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "int16 -> int8")
	static FDolphinInt8 CastInt16ToInt8(const FDolphinInt16& I16)
	{
		return static_cast<int8>(I16.Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "int8 -> int16")
	static FDolphinInt16 CastInt8ToInt16(const FDolphinInt8& I8)
	{
		return static_cast<int16>(I8.Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "int16 -> uint8")
	static uint8 CastInt16ToUInt8(const FDolphinInt16& I16)
	{
		return static_cast<uint8>(I16.Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "uint8 -> int16")
	static FDolphinInt16 CastUInt8ToInt16(uint8 UI8)
	{
		return static_cast<int16>(UI8);
	}

	/* UInt 16 */
	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "uint16 -> int8")
	static FDolphinInt8 CastUInt16ToInt8(const FDolphinUInt16& UI16)
	{
		return static_cast<int8>(UI16.Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "int8 -> uint16")
	static FDolphinUInt16 CastInt8ToUInt16(const FDolphinInt8& I8)
	{
		return static_cast<uint16>(I8.Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "uint16 -> uint8")
	static uint8 CastUInt16ToUInt8(const FDolphinUInt16& UI16)
	{
		return static_cast<uint8>(UI16.Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "uint8 -> uint16")
	static FDolphinUInt16 CastUInt8ToUInt16(uint8 UI8)
	{
		return static_cast<uint16>(UI8);
	}

	/* Int 8 */
	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "int8 -> uint8")
	static uint8 CastInt8ToUInt8(const FDolphinInt8& I8)
	{
		return static_cast<uint8>(I8.Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "uint8 -> int8")
	static FDolphinInt8 CastUInt8ToInt8(uint8 UI8)
	{
		return static_cast<int8>(UI8);
	}

	OPERATORS(Int8)
	OPERATORS(UInt8)
	OPERATORS(Int16)
	OPERATORS(UInt16)
	OPERATORS(Int32)
	OPERATORS(UInt32)
	OPERATORS(Int64)
	OPERATORS(UInt64)
	OPERATORS(Float)
	OPERATORS(Double)
};
