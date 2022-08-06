//////////////////////////////////////////////////////////////////////////////////
// THIS C++ FILE IS GENERATED DO NOT EDIT. RUN CodeGen.py TO GENERATE THIS FILE //
//////////////////////////////////////////////////////////////////////////////////

#pragma once

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
	
	//////////////////////////////////////////////////////////////////////////////////
    //                                    CREATE                                    //
    //////////////////////////////////////////////////////////////////////////////////

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Create Dolphin UInt8")
	static FDolphinUInt8 CreateUInt8(int32 Value)
	{
		return static_cast<uint8>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Create Dolphin UInt16")
	static FDolphinUInt16 CreateUInt16(int32 Value)
	{
		return static_cast<uint16>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Create Dolphin UInt32")
	static FDolphinUInt32 CreateUInt32(int32 Value)
	{
		return static_cast<uint32>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Create Dolphin UInt64")
	static FDolphinUInt64 CreateUInt64(int64 Value)
	{
		return static_cast<uint64>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Create Dolphin Int8")
	static FDolphinInt8 CreateInt8(int32 Value)
	{
		return static_cast<int8>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Create Dolphin Int16")
	static FDolphinInt16 CreateInt16(int32 Value)
	{
		return static_cast<int16>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Create Dolphin Int32")
	static FDolphinInt32 CreateInt32(int32 Value)
	{
		return static_cast<int32>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Create Dolphin Int64")
	static FDolphinInt64 CreateInt64(int64 Value)
	{
		return static_cast<int64>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Create Dolphin Float")
	static FDolphinFloat CreateFloat(float Value)
	{
		return static_cast<float>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Create Dolphin Double")
	static FDolphinDouble CreateDouble(float Value)
	{
		return static_cast<double>(Value);
	}


	//////////////////////////////////////////////////////////////////////////////////
    //                                     CAST                                     //
    //////////////////////////////////////////////////////////////////////////////////

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast UInt8 to UInt16", meta = (Keywords = "Cast UInt8 unsigned uint8 char byte ubyte to UInt16 unsigned uint16 short ushort"))
	static FDolphinUInt16 CastUInt8ToUInt16(const FDolphinUInt8& Value)
	{
		return static_cast<uint16>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast UInt8 to UInt32", meta = (Keywords = "Cast UInt8 unsigned uint8 char byte ubyte to UInt32 unsigned uint32 int uint integer"))
	static FDolphinUInt32 CastUInt8ToUInt32(const FDolphinUInt8& Value)
	{
		return static_cast<uint32>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast UInt8 to UInt64", meta = (Keywords = "Cast UInt8 unsigned uint8 char byte ubyte to UInt64 unsigned uint64 long int ulong integer"))
	static FDolphinUInt64 CastUInt8ToUInt64(const FDolphinUInt8& Value)
	{
		return static_cast<uint64>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast UInt8 to Int8", meta = (Keywords = "Cast UInt8 unsigned uint8 char byte ubyte to Int8 signed int8 char byte"))
	static FDolphinInt8 CastUInt8ToInt8(const FDolphinUInt8& Value)
	{
		return static_cast<int8>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast UInt8 to Int16", meta = (Keywords = "Cast UInt8 unsigned uint8 char byte ubyte to Int16 signed int16 short"))
	static FDolphinInt16 CastUInt8ToInt16(const FDolphinUInt8& Value)
	{
		return static_cast<int16>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast UInt8 to Int32", meta = (Keywords = "Cast UInt8 unsigned uint8 char byte ubyte to Int32 signed int32 int int integer"))
	static FDolphinInt32 CastUInt8ToInt32(const FDolphinUInt8& Value)
	{
		return static_cast<int32>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast UInt8 to Int64", meta = (Keywords = "Cast UInt8 unsigned uint8 char byte ubyte to Int64 signed int64 long int integer"))
	static FDolphinInt64 CastUInt8ToInt64(const FDolphinUInt8& Value)
	{
		return static_cast<int64>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast UInt8 to Float", meta = (Keywords = "Cast UInt8 unsigned uint8 char byte ubyte to Float float decimal single single-precision"))
	static FDolphinFloat CastUInt8ToFloat(const FDolphinUInt8& Value)
	{
		return static_cast<float>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast UInt8 to Double", meta = (Keywords = "Cast UInt8 unsigned uint8 char byte ubyte to Double double decimal double-precision float"))
	static FDolphinDouble CastUInt8ToDouble(const FDolphinUInt8& Value)
	{
		return static_cast<double>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast UInt8 to Unreal uint8", meta = (Keywords = "Cast UInt8 unsigned uint8 char byte ubyte to UInt8 unsigned uint8 char byte ubyte"))
	static uint8 CastUInt8ToUnrealuint8(const FDolphinUInt8& Value)
	{
		return static_cast<uint8>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast UInt8 to Unreal int32", meta = (Keywords = "Cast UInt8 unsigned uint8 char byte ubyte to Int32 signed int32 int int integer"))
	static int32 CastUInt8ToUnrealint32(const FDolphinUInt8& Value)
	{
		return static_cast<int32>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast UInt8 to Unreal int64", meta = (Keywords = "Cast UInt8 unsigned uint8 char byte ubyte to Int64 signed int64 long int integer"))
	static int64 CastUInt8ToUnrealint64(const FDolphinUInt8& Value)
	{
		return static_cast<int64>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast UInt8 to Unreal float", meta = (Keywords = "Cast UInt8 unsigned uint8 char byte ubyte to Float float decimal single single-precision"))
	static float CastUInt8ToUnrealfloat(const FDolphinUInt8& Value)
	{
		return static_cast<float>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast UInt16 to UInt8", meta = (Keywords = "Cast UInt16 unsigned uint16 short ushort to UInt8 unsigned uint8 char byte ubyte"))
	static FDolphinUInt8 CastUInt16ToUInt8(const FDolphinUInt16& Value)
	{
		return static_cast<uint8>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast UInt16 to UInt32", meta = (Keywords = "Cast UInt16 unsigned uint16 short ushort to UInt32 unsigned uint32 int uint integer"))
	static FDolphinUInt32 CastUInt16ToUInt32(const FDolphinUInt16& Value)
	{
		return static_cast<uint32>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast UInt16 to UInt64", meta = (Keywords = "Cast UInt16 unsigned uint16 short ushort to UInt64 unsigned uint64 long int ulong integer"))
	static FDolphinUInt64 CastUInt16ToUInt64(const FDolphinUInt16& Value)
	{
		return static_cast<uint64>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast UInt16 to Int8", meta = (Keywords = "Cast UInt16 unsigned uint16 short ushort to Int8 signed int8 char byte"))
	static FDolphinInt8 CastUInt16ToInt8(const FDolphinUInt16& Value)
	{
		return static_cast<int8>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast UInt16 to Int16", meta = (Keywords = "Cast UInt16 unsigned uint16 short ushort to Int16 signed int16 short"))
	static FDolphinInt16 CastUInt16ToInt16(const FDolphinUInt16& Value)
	{
		return static_cast<int16>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast UInt16 to Int32", meta = (Keywords = "Cast UInt16 unsigned uint16 short ushort to Int32 signed int32 int int integer"))
	static FDolphinInt32 CastUInt16ToInt32(const FDolphinUInt16& Value)
	{
		return static_cast<int32>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast UInt16 to Int64", meta = (Keywords = "Cast UInt16 unsigned uint16 short ushort to Int64 signed int64 long int integer"))
	static FDolphinInt64 CastUInt16ToInt64(const FDolphinUInt16& Value)
	{
		return static_cast<int64>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast UInt16 to Float", meta = (Keywords = "Cast UInt16 unsigned uint16 short ushort to Float float decimal single single-precision"))
	static FDolphinFloat CastUInt16ToFloat(const FDolphinUInt16& Value)
	{
		return static_cast<float>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast UInt16 to Double", meta = (Keywords = "Cast UInt16 unsigned uint16 short ushort to Double double decimal double-precision float"))
	static FDolphinDouble CastUInt16ToDouble(const FDolphinUInt16& Value)
	{
		return static_cast<double>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast UInt16 to Unreal uint8", meta = (Keywords = "Cast UInt16 unsigned uint16 short ushort to UInt8 unsigned uint8 char byte ubyte"))
	static uint8 CastUInt16ToUnrealuint8(const FDolphinUInt16& Value)
	{
		return static_cast<uint8>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast UInt16 to Unreal int32", meta = (Keywords = "Cast UInt16 unsigned uint16 short ushort to Int32 signed int32 int int integer"))
	static int32 CastUInt16ToUnrealint32(const FDolphinUInt16& Value)
	{
		return static_cast<int32>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast UInt16 to Unreal int64", meta = (Keywords = "Cast UInt16 unsigned uint16 short ushort to Int64 signed int64 long int integer"))
	static int64 CastUInt16ToUnrealint64(const FDolphinUInt16& Value)
	{
		return static_cast<int64>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast UInt16 to Unreal float", meta = (Keywords = "Cast UInt16 unsigned uint16 short ushort to Float float decimal single single-precision"))
	static float CastUInt16ToUnrealfloat(const FDolphinUInt16& Value)
	{
		return static_cast<float>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast UInt32 to UInt8", meta = (Keywords = "Cast UInt32 unsigned uint32 int uint integer to UInt8 unsigned uint8 char byte ubyte"))
	static FDolphinUInt8 CastUInt32ToUInt8(const FDolphinUInt32& Value)
	{
		return static_cast<uint8>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast UInt32 to UInt16", meta = (Keywords = "Cast UInt32 unsigned uint32 int uint integer to UInt16 unsigned uint16 short ushort"))
	static FDolphinUInt16 CastUInt32ToUInt16(const FDolphinUInt32& Value)
	{
		return static_cast<uint16>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast UInt32 to UInt64", meta = (Keywords = "Cast UInt32 unsigned uint32 int uint integer to UInt64 unsigned uint64 long int ulong integer"))
	static FDolphinUInt64 CastUInt32ToUInt64(const FDolphinUInt32& Value)
	{
		return static_cast<uint64>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast UInt32 to Int8", meta = (Keywords = "Cast UInt32 unsigned uint32 int uint integer to Int8 signed int8 char byte"))
	static FDolphinInt8 CastUInt32ToInt8(const FDolphinUInt32& Value)
	{
		return static_cast<int8>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast UInt32 to Int16", meta = (Keywords = "Cast UInt32 unsigned uint32 int uint integer to Int16 signed int16 short"))
	static FDolphinInt16 CastUInt32ToInt16(const FDolphinUInt32& Value)
	{
		return static_cast<int16>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast UInt32 to Int32", meta = (Keywords = "Cast UInt32 unsigned uint32 int uint integer to Int32 signed int32 int int integer"))
	static FDolphinInt32 CastUInt32ToInt32(const FDolphinUInt32& Value)
	{
		return static_cast<int32>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast UInt32 to Int64", meta = (Keywords = "Cast UInt32 unsigned uint32 int uint integer to Int64 signed int64 long int integer"))
	static FDolphinInt64 CastUInt32ToInt64(const FDolphinUInt32& Value)
	{
		return static_cast<int64>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast UInt32 to Float", meta = (Keywords = "Cast UInt32 unsigned uint32 int uint integer to Float float decimal single single-precision"))
	static FDolphinFloat CastUInt32ToFloat(const FDolphinUInt32& Value)
	{
		return static_cast<float>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast UInt32 to Double", meta = (Keywords = "Cast UInt32 unsigned uint32 int uint integer to Double double decimal double-precision float"))
	static FDolphinDouble CastUInt32ToDouble(const FDolphinUInt32& Value)
	{
		return static_cast<double>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast UInt32 to Unreal uint8", meta = (Keywords = "Cast UInt32 unsigned uint32 int uint integer to UInt8 unsigned uint8 char byte ubyte"))
	static uint8 CastUInt32ToUnrealuint8(const FDolphinUInt32& Value)
	{
		return static_cast<uint8>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast UInt32 to Unreal int32", meta = (Keywords = "Cast UInt32 unsigned uint32 int uint integer to Int32 signed int32 int int integer"))
	static int32 CastUInt32ToUnrealint32(const FDolphinUInt32& Value)
	{
		return static_cast<int32>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast UInt32 to Unreal int64", meta = (Keywords = "Cast UInt32 unsigned uint32 int uint integer to Int64 signed int64 long int integer"))
	static int64 CastUInt32ToUnrealint64(const FDolphinUInt32& Value)
	{
		return static_cast<int64>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast UInt32 to Unreal float", meta = (Keywords = "Cast UInt32 unsigned uint32 int uint integer to Float float decimal single single-precision"))
	static float CastUInt32ToUnrealfloat(const FDolphinUInt32& Value)
	{
		return static_cast<float>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast UInt64 to UInt8", meta = (Keywords = "Cast UInt64 unsigned uint64 long int ulong integer to UInt8 unsigned uint8 char byte ubyte"))
	static FDolphinUInt8 CastUInt64ToUInt8(const FDolphinUInt64& Value)
	{
		return static_cast<uint8>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast UInt64 to UInt16", meta = (Keywords = "Cast UInt64 unsigned uint64 long int ulong integer to UInt16 unsigned uint16 short ushort"))
	static FDolphinUInt16 CastUInt64ToUInt16(const FDolphinUInt64& Value)
	{
		return static_cast<uint16>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast UInt64 to UInt32", meta = (Keywords = "Cast UInt64 unsigned uint64 long int ulong integer to UInt32 unsigned uint32 int uint integer"))
	static FDolphinUInt32 CastUInt64ToUInt32(const FDolphinUInt64& Value)
	{
		return static_cast<uint32>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast UInt64 to Int8", meta = (Keywords = "Cast UInt64 unsigned uint64 long int ulong integer to Int8 signed int8 char byte"))
	static FDolphinInt8 CastUInt64ToInt8(const FDolphinUInt64& Value)
	{
		return static_cast<int8>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast UInt64 to Int16", meta = (Keywords = "Cast UInt64 unsigned uint64 long int ulong integer to Int16 signed int16 short"))
	static FDolphinInt16 CastUInt64ToInt16(const FDolphinUInt64& Value)
	{
		return static_cast<int16>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast UInt64 to Int32", meta = (Keywords = "Cast UInt64 unsigned uint64 long int ulong integer to Int32 signed int32 int int integer"))
	static FDolphinInt32 CastUInt64ToInt32(const FDolphinUInt64& Value)
	{
		return static_cast<int32>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast UInt64 to Int64", meta = (Keywords = "Cast UInt64 unsigned uint64 long int ulong integer to Int64 signed int64 long int integer"))
	static FDolphinInt64 CastUInt64ToInt64(const FDolphinUInt64& Value)
	{
		return static_cast<int64>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast UInt64 to Float", meta = (Keywords = "Cast UInt64 unsigned uint64 long int ulong integer to Float float decimal single single-precision"))
	static FDolphinFloat CastUInt64ToFloat(const FDolphinUInt64& Value)
	{
		return static_cast<float>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast UInt64 to Double", meta = (Keywords = "Cast UInt64 unsigned uint64 long int ulong integer to Double double decimal double-precision float"))
	static FDolphinDouble CastUInt64ToDouble(const FDolphinUInt64& Value)
	{
		return static_cast<double>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast UInt64 to Unreal uint8", meta = (Keywords = "Cast UInt64 unsigned uint64 long int ulong integer to UInt8 unsigned uint8 char byte ubyte"))
	static uint8 CastUInt64ToUnrealuint8(const FDolphinUInt64& Value)
	{
		return static_cast<uint8>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast UInt64 to Unreal int32", meta = (Keywords = "Cast UInt64 unsigned uint64 long int ulong integer to Int32 signed int32 int int integer"))
	static int32 CastUInt64ToUnrealint32(const FDolphinUInt64& Value)
	{
		return static_cast<int32>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast UInt64 to Unreal int64", meta = (Keywords = "Cast UInt64 unsigned uint64 long int ulong integer to Int64 signed int64 long int integer"))
	static int64 CastUInt64ToUnrealint64(const FDolphinUInt64& Value)
	{
		return static_cast<int64>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast UInt64 to Unreal float", meta = (Keywords = "Cast UInt64 unsigned uint64 long int ulong integer to Float float decimal single single-precision"))
	static float CastUInt64ToUnrealfloat(const FDolphinUInt64& Value)
	{
		return static_cast<float>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Int8 to UInt8", meta = (Keywords = "Cast Int8 signed int8 char byte to UInt8 unsigned uint8 char byte ubyte"))
	static FDolphinUInt8 CastInt8ToUInt8(const FDolphinInt8& Value)
	{
		return static_cast<uint8>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Int8 to UInt16", meta = (Keywords = "Cast Int8 signed int8 char byte to UInt16 unsigned uint16 short ushort"))
	static FDolphinUInt16 CastInt8ToUInt16(const FDolphinInt8& Value)
	{
		return static_cast<uint16>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Int8 to UInt32", meta = (Keywords = "Cast Int8 signed int8 char byte to UInt32 unsigned uint32 int uint integer"))
	static FDolphinUInt32 CastInt8ToUInt32(const FDolphinInt8& Value)
	{
		return static_cast<uint32>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Int8 to UInt64", meta = (Keywords = "Cast Int8 signed int8 char byte to UInt64 unsigned uint64 long int ulong integer"))
	static FDolphinUInt64 CastInt8ToUInt64(const FDolphinInt8& Value)
	{
		return static_cast<uint64>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Int8 to Int16", meta = (Keywords = "Cast Int8 signed int8 char byte to Int16 signed int16 short"))
	static FDolphinInt16 CastInt8ToInt16(const FDolphinInt8& Value)
	{
		return static_cast<int16>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Int8 to Int32", meta = (Keywords = "Cast Int8 signed int8 char byte to Int32 signed int32 int int integer"))
	static FDolphinInt32 CastInt8ToInt32(const FDolphinInt8& Value)
	{
		return static_cast<int32>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Int8 to Int64", meta = (Keywords = "Cast Int8 signed int8 char byte to Int64 signed int64 long int integer"))
	static FDolphinInt64 CastInt8ToInt64(const FDolphinInt8& Value)
	{
		return static_cast<int64>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Int8 to Float", meta = (Keywords = "Cast Int8 signed int8 char byte to Float float decimal single single-precision"))
	static FDolphinFloat CastInt8ToFloat(const FDolphinInt8& Value)
	{
		return static_cast<float>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Int8 to Double", meta = (Keywords = "Cast Int8 signed int8 char byte to Double double decimal double-precision float"))
	static FDolphinDouble CastInt8ToDouble(const FDolphinInt8& Value)
	{
		return static_cast<double>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Int8 to Unreal uint8", meta = (Keywords = "Cast Int8 signed int8 char byte to UInt8 unsigned uint8 char byte ubyte"))
	static uint8 CastInt8ToUnrealuint8(const FDolphinInt8& Value)
	{
		return static_cast<uint8>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Int8 to Unreal int32", meta = (Keywords = "Cast Int8 signed int8 char byte to Int32 signed int32 int int integer"))
	static int32 CastInt8ToUnrealint32(const FDolphinInt8& Value)
	{
		return static_cast<int32>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Int8 to Unreal int64", meta = (Keywords = "Cast Int8 signed int8 char byte to Int64 signed int64 long int integer"))
	static int64 CastInt8ToUnrealint64(const FDolphinInt8& Value)
	{
		return static_cast<int64>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Int8 to Unreal float", meta = (Keywords = "Cast Int8 signed int8 char byte to Float float decimal single single-precision"))
	static float CastInt8ToUnrealfloat(const FDolphinInt8& Value)
	{
		return static_cast<float>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Int16 to UInt8", meta = (Keywords = "Cast Int16 signed int16 short to UInt8 unsigned uint8 char byte ubyte"))
	static FDolphinUInt8 CastInt16ToUInt8(const FDolphinInt16& Value)
	{
		return static_cast<uint8>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Int16 to UInt16", meta = (Keywords = "Cast Int16 signed int16 short to UInt16 unsigned uint16 short ushort"))
	static FDolphinUInt16 CastInt16ToUInt16(const FDolphinInt16& Value)
	{
		return static_cast<uint16>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Int16 to UInt32", meta = (Keywords = "Cast Int16 signed int16 short to UInt32 unsigned uint32 int uint integer"))
	static FDolphinUInt32 CastInt16ToUInt32(const FDolphinInt16& Value)
	{
		return static_cast<uint32>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Int16 to UInt64", meta = (Keywords = "Cast Int16 signed int16 short to UInt64 unsigned uint64 long int ulong integer"))
	static FDolphinUInt64 CastInt16ToUInt64(const FDolphinInt16& Value)
	{
		return static_cast<uint64>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Int16 to Int8", meta = (Keywords = "Cast Int16 signed int16 short to Int8 signed int8 char byte"))
	static FDolphinInt8 CastInt16ToInt8(const FDolphinInt16& Value)
	{
		return static_cast<int8>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Int16 to Int32", meta = (Keywords = "Cast Int16 signed int16 short to Int32 signed int32 int int integer"))
	static FDolphinInt32 CastInt16ToInt32(const FDolphinInt16& Value)
	{
		return static_cast<int32>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Int16 to Int64", meta = (Keywords = "Cast Int16 signed int16 short to Int64 signed int64 long int integer"))
	static FDolphinInt64 CastInt16ToInt64(const FDolphinInt16& Value)
	{
		return static_cast<int64>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Int16 to Float", meta = (Keywords = "Cast Int16 signed int16 short to Float float decimal single single-precision"))
	static FDolphinFloat CastInt16ToFloat(const FDolphinInt16& Value)
	{
		return static_cast<float>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Int16 to Double", meta = (Keywords = "Cast Int16 signed int16 short to Double double decimal double-precision float"))
	static FDolphinDouble CastInt16ToDouble(const FDolphinInt16& Value)
	{
		return static_cast<double>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Int16 to Unreal uint8", meta = (Keywords = "Cast Int16 signed int16 short to UInt8 unsigned uint8 char byte ubyte"))
	static uint8 CastInt16ToUnrealuint8(const FDolphinInt16& Value)
	{
		return static_cast<uint8>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Int16 to Unreal int32", meta = (Keywords = "Cast Int16 signed int16 short to Int32 signed int32 int int integer"))
	static int32 CastInt16ToUnrealint32(const FDolphinInt16& Value)
	{
		return static_cast<int32>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Int16 to Unreal int64", meta = (Keywords = "Cast Int16 signed int16 short to Int64 signed int64 long int integer"))
	static int64 CastInt16ToUnrealint64(const FDolphinInt16& Value)
	{
		return static_cast<int64>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Int16 to Unreal float", meta = (Keywords = "Cast Int16 signed int16 short to Float float decimal single single-precision"))
	static float CastInt16ToUnrealfloat(const FDolphinInt16& Value)
	{
		return static_cast<float>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Int32 to UInt8", meta = (Keywords = "Cast Int32 signed int32 int int integer to UInt8 unsigned uint8 char byte ubyte"))
	static FDolphinUInt8 CastInt32ToUInt8(const FDolphinInt32& Value)
	{
		return static_cast<uint8>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Int32 to UInt16", meta = (Keywords = "Cast Int32 signed int32 int int integer to UInt16 unsigned uint16 short ushort"))
	static FDolphinUInt16 CastInt32ToUInt16(const FDolphinInt32& Value)
	{
		return static_cast<uint16>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Int32 to UInt32", meta = (Keywords = "Cast Int32 signed int32 int int integer to UInt32 unsigned uint32 int uint integer"))
	static FDolphinUInt32 CastInt32ToUInt32(const FDolphinInt32& Value)
	{
		return static_cast<uint32>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Int32 to UInt64", meta = (Keywords = "Cast Int32 signed int32 int int integer to UInt64 unsigned uint64 long int ulong integer"))
	static FDolphinUInt64 CastInt32ToUInt64(const FDolphinInt32& Value)
	{
		return static_cast<uint64>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Int32 to Int8", meta = (Keywords = "Cast Int32 signed int32 int int integer to Int8 signed int8 char byte"))
	static FDolphinInt8 CastInt32ToInt8(const FDolphinInt32& Value)
	{
		return static_cast<int8>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Int32 to Int16", meta = (Keywords = "Cast Int32 signed int32 int int integer to Int16 signed int16 short"))
	static FDolphinInt16 CastInt32ToInt16(const FDolphinInt32& Value)
	{
		return static_cast<int16>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Int32 to Int64", meta = (Keywords = "Cast Int32 signed int32 int int integer to Int64 signed int64 long int integer"))
	static FDolphinInt64 CastInt32ToInt64(const FDolphinInt32& Value)
	{
		return static_cast<int64>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Int32 to Float", meta = (Keywords = "Cast Int32 signed int32 int int integer to Float float decimal single single-precision"))
	static FDolphinFloat CastInt32ToFloat(const FDolphinInt32& Value)
	{
		return static_cast<float>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Int32 to Double", meta = (Keywords = "Cast Int32 signed int32 int int integer to Double double decimal double-precision float"))
	static FDolphinDouble CastInt32ToDouble(const FDolphinInt32& Value)
	{
		return static_cast<double>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Int32 to Unreal uint8", meta = (Keywords = "Cast Int32 signed int32 int int integer to UInt8 unsigned uint8 char byte ubyte"))
	static uint8 CastInt32ToUnrealuint8(const FDolphinInt32& Value)
	{
		return static_cast<uint8>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Int32 to Unreal int32", meta = (Keywords = "Cast Int32 signed int32 int int integer to Int32 signed int32 int int integer"))
	static int32 CastInt32ToUnrealint32(const FDolphinInt32& Value)
	{
		return static_cast<int32>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Int32 to Unreal int64", meta = (Keywords = "Cast Int32 signed int32 int int integer to Int64 signed int64 long int integer"))
	static int64 CastInt32ToUnrealint64(const FDolphinInt32& Value)
	{
		return static_cast<int64>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Int32 to Unreal float", meta = (Keywords = "Cast Int32 signed int32 int int integer to Float float decimal single single-precision"))
	static float CastInt32ToUnrealfloat(const FDolphinInt32& Value)
	{
		return static_cast<float>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Int64 to UInt8", meta = (Keywords = "Cast Int64 signed int64 long int integer to UInt8 unsigned uint8 char byte ubyte"))
	static FDolphinUInt8 CastInt64ToUInt8(const FDolphinInt64& Value)
	{
		return static_cast<uint8>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Int64 to UInt16", meta = (Keywords = "Cast Int64 signed int64 long int integer to UInt16 unsigned uint16 short ushort"))
	static FDolphinUInt16 CastInt64ToUInt16(const FDolphinInt64& Value)
	{
		return static_cast<uint16>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Int64 to UInt32", meta = (Keywords = "Cast Int64 signed int64 long int integer to UInt32 unsigned uint32 int uint integer"))
	static FDolphinUInt32 CastInt64ToUInt32(const FDolphinInt64& Value)
	{
		return static_cast<uint32>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Int64 to UInt64", meta = (Keywords = "Cast Int64 signed int64 long int integer to UInt64 unsigned uint64 long int ulong integer"))
	static FDolphinUInt64 CastInt64ToUInt64(const FDolphinInt64& Value)
	{
		return static_cast<uint64>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Int64 to Int8", meta = (Keywords = "Cast Int64 signed int64 long int integer to Int8 signed int8 char byte"))
	static FDolphinInt8 CastInt64ToInt8(const FDolphinInt64& Value)
	{
		return static_cast<int8>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Int64 to Int16", meta = (Keywords = "Cast Int64 signed int64 long int integer to Int16 signed int16 short"))
	static FDolphinInt16 CastInt64ToInt16(const FDolphinInt64& Value)
	{
		return static_cast<int16>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Int64 to Int32", meta = (Keywords = "Cast Int64 signed int64 long int integer to Int32 signed int32 int int integer"))
	static FDolphinInt32 CastInt64ToInt32(const FDolphinInt64& Value)
	{
		return static_cast<int32>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Int64 to Float", meta = (Keywords = "Cast Int64 signed int64 long int integer to Float float decimal single single-precision"))
	static FDolphinFloat CastInt64ToFloat(const FDolphinInt64& Value)
	{
		return static_cast<float>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Int64 to Double", meta = (Keywords = "Cast Int64 signed int64 long int integer to Double double decimal double-precision float"))
	static FDolphinDouble CastInt64ToDouble(const FDolphinInt64& Value)
	{
		return static_cast<double>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Int64 to Unreal uint8", meta = (Keywords = "Cast Int64 signed int64 long int integer to UInt8 unsigned uint8 char byte ubyte"))
	static uint8 CastInt64ToUnrealuint8(const FDolphinInt64& Value)
	{
		return static_cast<uint8>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Int64 to Unreal int32", meta = (Keywords = "Cast Int64 signed int64 long int integer to Int32 signed int32 int int integer"))
	static int32 CastInt64ToUnrealint32(const FDolphinInt64& Value)
	{
		return static_cast<int32>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Int64 to Unreal int64", meta = (Keywords = "Cast Int64 signed int64 long int integer to Int64 signed int64 long int integer"))
	static int64 CastInt64ToUnrealint64(const FDolphinInt64& Value)
	{
		return static_cast<int64>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Int64 to Unreal float", meta = (Keywords = "Cast Int64 signed int64 long int integer to Float float decimal single single-precision"))
	static float CastInt64ToUnrealfloat(const FDolphinInt64& Value)
	{
		return static_cast<float>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Float to UInt8", meta = (Keywords = "Cast Float float decimal single single-precision to UInt8 unsigned uint8 char byte ubyte"))
	static FDolphinUInt8 CastFloatToUInt8(const FDolphinFloat& Value)
	{
		return static_cast<uint8>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Float to UInt16", meta = (Keywords = "Cast Float float decimal single single-precision to UInt16 unsigned uint16 short ushort"))
	static FDolphinUInt16 CastFloatToUInt16(const FDolphinFloat& Value)
	{
		return static_cast<uint16>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Float to UInt32", meta = (Keywords = "Cast Float float decimal single single-precision to UInt32 unsigned uint32 int uint integer"))
	static FDolphinUInt32 CastFloatToUInt32(const FDolphinFloat& Value)
	{
		return static_cast<uint32>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Float to UInt64", meta = (Keywords = "Cast Float float decimal single single-precision to UInt64 unsigned uint64 long int ulong integer"))
	static FDolphinUInt64 CastFloatToUInt64(const FDolphinFloat& Value)
	{
		return static_cast<uint64>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Float to Int8", meta = (Keywords = "Cast Float float decimal single single-precision to Int8 signed int8 char byte"))
	static FDolphinInt8 CastFloatToInt8(const FDolphinFloat& Value)
	{
		return static_cast<int8>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Float to Int16", meta = (Keywords = "Cast Float float decimal single single-precision to Int16 signed int16 short"))
	static FDolphinInt16 CastFloatToInt16(const FDolphinFloat& Value)
	{
		return static_cast<int16>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Float to Int32", meta = (Keywords = "Cast Float float decimal single single-precision to Int32 signed int32 int int integer"))
	static FDolphinInt32 CastFloatToInt32(const FDolphinFloat& Value)
	{
		return static_cast<int32>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Float to Int64", meta = (Keywords = "Cast Float float decimal single single-precision to Int64 signed int64 long int integer"))
	static FDolphinInt64 CastFloatToInt64(const FDolphinFloat& Value)
	{
		return static_cast<int64>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Float to Double", meta = (Keywords = "Cast Float float decimal single single-precision to Double double decimal double-precision float"))
	static FDolphinDouble CastFloatToDouble(const FDolphinFloat& Value)
	{
		return static_cast<double>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Float to Unreal uint8", meta = (Keywords = "Cast Float float decimal single single-precision to UInt8 unsigned uint8 char byte ubyte"))
	static uint8 CastFloatToUnrealuint8(const FDolphinFloat& Value)
	{
		return static_cast<uint8>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Float to Unreal int32", meta = (Keywords = "Cast Float float decimal single single-precision to Int32 signed int32 int int integer"))
	static int32 CastFloatToUnrealint32(const FDolphinFloat& Value)
	{
		return static_cast<int32>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Float to Unreal int64", meta = (Keywords = "Cast Float float decimal single single-precision to Int64 signed int64 long int integer"))
	static int64 CastFloatToUnrealint64(const FDolphinFloat& Value)
	{
		return static_cast<int64>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Float to Unreal float", meta = (Keywords = "Cast Float float decimal single single-precision to Float float decimal single single-precision"))
	static float CastFloatToUnrealfloat(const FDolphinFloat& Value)
	{
		return static_cast<float>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Double to UInt8", meta = (Keywords = "Cast Double double decimal double-precision float to UInt8 unsigned uint8 char byte ubyte"))
	static FDolphinUInt8 CastDoubleToUInt8(const FDolphinDouble& Value)
	{
		return static_cast<uint8>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Double to UInt16", meta = (Keywords = "Cast Double double decimal double-precision float to UInt16 unsigned uint16 short ushort"))
	static FDolphinUInt16 CastDoubleToUInt16(const FDolphinDouble& Value)
	{
		return static_cast<uint16>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Double to UInt32", meta = (Keywords = "Cast Double double decimal double-precision float to UInt32 unsigned uint32 int uint integer"))
	static FDolphinUInt32 CastDoubleToUInt32(const FDolphinDouble& Value)
	{
		return static_cast<uint32>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Double to UInt64", meta = (Keywords = "Cast Double double decimal double-precision float to UInt64 unsigned uint64 long int ulong integer"))
	static FDolphinUInt64 CastDoubleToUInt64(const FDolphinDouble& Value)
	{
		return static_cast<uint64>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Double to Int8", meta = (Keywords = "Cast Double double decimal double-precision float to Int8 signed int8 char byte"))
	static FDolphinInt8 CastDoubleToInt8(const FDolphinDouble& Value)
	{
		return static_cast<int8>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Double to Int16", meta = (Keywords = "Cast Double double decimal double-precision float to Int16 signed int16 short"))
	static FDolphinInt16 CastDoubleToInt16(const FDolphinDouble& Value)
	{
		return static_cast<int16>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Double to Int32", meta = (Keywords = "Cast Double double decimal double-precision float to Int32 signed int32 int int integer"))
	static FDolphinInt32 CastDoubleToInt32(const FDolphinDouble& Value)
	{
		return static_cast<int32>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Double to Int64", meta = (Keywords = "Cast Double double decimal double-precision float to Int64 signed int64 long int integer"))
	static FDolphinInt64 CastDoubleToInt64(const FDolphinDouble& Value)
	{
		return static_cast<int64>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Double to Float", meta = (Keywords = "Cast Double double decimal double-precision float to Float float decimal single single-precision"))
	static FDolphinFloat CastDoubleToFloat(const FDolphinDouble& Value)
	{
		return static_cast<float>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Double to Unreal uint8", meta = (Keywords = "Cast Double double decimal double-precision float to UInt8 unsigned uint8 char byte ubyte"))
	static uint8 CastDoubleToUnrealuint8(const FDolphinDouble& Value)
	{
		return static_cast<uint8>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Double to Unreal int32", meta = (Keywords = "Cast Double double decimal double-precision float to Int32 signed int32 int int integer"))
	static int32 CastDoubleToUnrealint32(const FDolphinDouble& Value)
	{
		return static_cast<int32>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Double to Unreal int64", meta = (Keywords = "Cast Double double decimal double-precision float to Int64 signed int64 long int integer"))
	static int64 CastDoubleToUnrealint64(const FDolphinDouble& Value)
	{
		return static_cast<int64>(Value);
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast Double to Unreal float", meta = (Keywords = "Cast Double double decimal double-precision float to Float float decimal single single-precision"))
	static float CastDoubleToUnrealfloat(const FDolphinDouble& Value)
	{
		return static_cast<float>(Value);
	}


	//////////////////////////////////////////////////////////////////////////////////
    //                                   OPERATORS                                  //
    //////////////////////////////////////////////////////////////////////////////////

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "UInt8 - UInt8", meta = (Keywords = "- Minus Subtract"))
	static FDolphinUInt8 Dolphin_UInt8SubtractUInt8(const FDolphinUInt8& Value1, const FDolphinUInt8& Value2)
	{
		return Value1.Value - Value2.Value;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "UInt8 + UInt8", meta = (Keywords = "+ Add Addition"))
	static FDolphinUInt8 Dolphin_UInt8AddUInt8(const FDolphinUInt8& Value1, const FDolphinUInt8& Value2)
	{
		return Value1.Value + Value2.Value;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "UInt8 * UInt8", meta = (Keywords = "* Multiply Times"))
	static FDolphinUInt8 Dolphin_UInt8MultiplyUInt8(const FDolphinUInt8& Value1, const FDolphinUInt8& Value2)
	{
		return Value1.Value * Value2.Value;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "UInt8 / UInt8", meta = (Keywords = "/ Divide By Division"))
	static FDolphinUInt8 Dolphin_UInt8DivideUInt8(const FDolphinUInt8& Value1, const FDolphinUInt8& Value2)
	{
		return Value1.Value / Value2.Value;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "UInt8 == UInt8", meta = (Keywords = "== Equal To Equals"))
	static bool Dolphin_UInt8EqualToUInt8(const FDolphinUInt8& Value1, const FDolphinUInt8& Value2)
	{
		return Value1.Value == Value2.Value;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "UInt8 != UInt8", meta = (Keywords = "!= Not Equal To Equals"))
	static bool Dolphin_UInt8NotEqualToUInt8(const FDolphinUInt8& Value1, const FDolphinUInt8& Value2)
	{
		return Value1.Value != Value2.Value;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "UInt8 < UInt8", meta = (Keywords = "< Less Than"))
	static bool Dolphin_UInt8LessThanUInt8(const FDolphinUInt8& Value1, const FDolphinUInt8& Value2)
	{
		return Value1.Value < Value2.Value;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "UInt8 <= UInt8", meta = (Keywords = "<= Less Than or Equal To Equals"))
	static bool Dolphin_UInt8LessThanOrEqualToUInt8(const FDolphinUInt8& Value1, const FDolphinUInt8& Value2)
	{
		return Value1.Value <= Value2.Value;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "UInt8 > UInt8", meta = (Keywords = "> Greater Than"))
	static bool Dolphin_UInt8GreaterThanUInt8(const FDolphinUInt8& Value1, const FDolphinUInt8& Value2)
	{
		return Value1.Value > Value2.Value;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "UInt8 >= UInt8", meta = (Keywords = ">= Greater Than or Equal To Equals"))
	static bool Dolphin_UInt8GreaterThanOrEqualToUInt8(const FDolphinUInt8& Value1, const FDolphinUInt8& Value2)
	{
		return Value1.Value >= Value2.Value;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "UInt16 - UInt16", meta = (Keywords = "- Minus Subtract"))
	static FDolphinUInt16 Dolphin_UInt16SubtractUInt16(const FDolphinUInt16& Value1, const FDolphinUInt16& Value2)
	{
		return Value1.Value - Value2.Value;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "UInt16 + UInt16", meta = (Keywords = "+ Add Addition"))
	static FDolphinUInt16 Dolphin_UInt16AddUInt16(const FDolphinUInt16& Value1, const FDolphinUInt16& Value2)
	{
		return Value1.Value + Value2.Value;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "UInt16 * UInt16", meta = (Keywords = "* Multiply Times"))
	static FDolphinUInt16 Dolphin_UInt16MultiplyUInt16(const FDolphinUInt16& Value1, const FDolphinUInt16& Value2)
	{
		return Value1.Value * Value2.Value;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "UInt16 / UInt16", meta = (Keywords = "/ Divide By Division"))
	static FDolphinUInt16 Dolphin_UInt16DivideUInt16(const FDolphinUInt16& Value1, const FDolphinUInt16& Value2)
	{
		return Value1.Value / Value2.Value;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "UInt16 == UInt16", meta = (Keywords = "== Equal To Equals"))
	static bool Dolphin_UInt16EqualToUInt16(const FDolphinUInt16& Value1, const FDolphinUInt16& Value2)
	{
		return Value1.Value == Value2.Value;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "UInt16 != UInt16", meta = (Keywords = "!= Not Equal To Equals"))
	static bool Dolphin_UInt16NotEqualToUInt16(const FDolphinUInt16& Value1, const FDolphinUInt16& Value2)
	{
		return Value1.Value != Value2.Value;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "UInt16 < UInt16", meta = (Keywords = "< Less Than"))
	static bool Dolphin_UInt16LessThanUInt16(const FDolphinUInt16& Value1, const FDolphinUInt16& Value2)
	{
		return Value1.Value < Value2.Value;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "UInt16 <= UInt16", meta = (Keywords = "<= Less Than or Equal To Equals"))
	static bool Dolphin_UInt16LessThanOrEqualToUInt16(const FDolphinUInt16& Value1, const FDolphinUInt16& Value2)
	{
		return Value1.Value <= Value2.Value;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "UInt16 > UInt16", meta = (Keywords = "> Greater Than"))
	static bool Dolphin_UInt16GreaterThanUInt16(const FDolphinUInt16& Value1, const FDolphinUInt16& Value2)
	{
		return Value1.Value > Value2.Value;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "UInt16 >= UInt16", meta = (Keywords = ">= Greater Than or Equal To Equals"))
	static bool Dolphin_UInt16GreaterThanOrEqualToUInt16(const FDolphinUInt16& Value1, const FDolphinUInt16& Value2)
	{
		return Value1.Value >= Value2.Value;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "UInt32 - UInt32", meta = (Keywords = "- Minus Subtract"))
	static FDolphinUInt32 Dolphin_UInt32SubtractUInt32(const FDolphinUInt32& Value1, const FDolphinUInt32& Value2)
	{
		return Value1.Value - Value2.Value;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "UInt32 + UInt32", meta = (Keywords = "+ Add Addition"))
	static FDolphinUInt32 Dolphin_UInt32AddUInt32(const FDolphinUInt32& Value1, const FDolphinUInt32& Value2)
	{
		return Value1.Value + Value2.Value;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "UInt32 * UInt32", meta = (Keywords = "* Multiply Times"))
	static FDolphinUInt32 Dolphin_UInt32MultiplyUInt32(const FDolphinUInt32& Value1, const FDolphinUInt32& Value2)
	{
		return Value1.Value * Value2.Value;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "UInt32 / UInt32", meta = (Keywords = "/ Divide By Division"))
	static FDolphinUInt32 Dolphin_UInt32DivideUInt32(const FDolphinUInt32& Value1, const FDolphinUInt32& Value2)
	{
		return Value1.Value / Value2.Value;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "UInt32 == UInt32", meta = (Keywords = "== Equal To Equals"))
	static bool Dolphin_UInt32EqualToUInt32(const FDolphinUInt32& Value1, const FDolphinUInt32& Value2)
	{
		return Value1.Value == Value2.Value;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "UInt32 != UInt32", meta = (Keywords = "!= Not Equal To Equals"))
	static bool Dolphin_UInt32NotEqualToUInt32(const FDolphinUInt32& Value1, const FDolphinUInt32& Value2)
	{
		return Value1.Value != Value2.Value;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "UInt32 < UInt32", meta = (Keywords = "< Less Than"))
	static bool Dolphin_UInt32LessThanUInt32(const FDolphinUInt32& Value1, const FDolphinUInt32& Value2)
	{
		return Value1.Value < Value2.Value;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "UInt32 <= UInt32", meta = (Keywords = "<= Less Than or Equal To Equals"))
	static bool Dolphin_UInt32LessThanOrEqualToUInt32(const FDolphinUInt32& Value1, const FDolphinUInt32& Value2)
	{
		return Value1.Value <= Value2.Value;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "UInt32 > UInt32", meta = (Keywords = "> Greater Than"))
	static bool Dolphin_UInt32GreaterThanUInt32(const FDolphinUInt32& Value1, const FDolphinUInt32& Value2)
	{
		return Value1.Value > Value2.Value;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "UInt32 >= UInt32", meta = (Keywords = ">= Greater Than or Equal To Equals"))
	static bool Dolphin_UInt32GreaterThanOrEqualToUInt32(const FDolphinUInt32& Value1, const FDolphinUInt32& Value2)
	{
		return Value1.Value >= Value2.Value;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "UInt64 - UInt64", meta = (Keywords = "- Minus Subtract"))
	static FDolphinUInt64 Dolphin_UInt64SubtractUInt64(const FDolphinUInt64& Value1, const FDolphinUInt64& Value2)
	{
		return Value1.Value - Value2.Value;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "UInt64 + UInt64", meta = (Keywords = "+ Add Addition"))
	static FDolphinUInt64 Dolphin_UInt64AddUInt64(const FDolphinUInt64& Value1, const FDolphinUInt64& Value2)
	{
		return Value1.Value + Value2.Value;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "UInt64 * UInt64", meta = (Keywords = "* Multiply Times"))
	static FDolphinUInt64 Dolphin_UInt64MultiplyUInt64(const FDolphinUInt64& Value1, const FDolphinUInt64& Value2)
	{
		return Value1.Value * Value2.Value;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "UInt64 / UInt64", meta = (Keywords = "/ Divide By Division"))
	static FDolphinUInt64 Dolphin_UInt64DivideUInt64(const FDolphinUInt64& Value1, const FDolphinUInt64& Value2)
	{
		return Value1.Value / Value2.Value;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "UInt64 == UInt64", meta = (Keywords = "== Equal To Equals"))
	static bool Dolphin_UInt64EqualToUInt64(const FDolphinUInt64& Value1, const FDolphinUInt64& Value2)
	{
		return Value1.Value == Value2.Value;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "UInt64 != UInt64", meta = (Keywords = "!= Not Equal To Equals"))
	static bool Dolphin_UInt64NotEqualToUInt64(const FDolphinUInt64& Value1, const FDolphinUInt64& Value2)
	{
		return Value1.Value != Value2.Value;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "UInt64 < UInt64", meta = (Keywords = "< Less Than"))
	static bool Dolphin_UInt64LessThanUInt64(const FDolphinUInt64& Value1, const FDolphinUInt64& Value2)
	{
		return Value1.Value < Value2.Value;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "UInt64 <= UInt64", meta = (Keywords = "<= Less Than or Equal To Equals"))
	static bool Dolphin_UInt64LessThanOrEqualToUInt64(const FDolphinUInt64& Value1, const FDolphinUInt64& Value2)
	{
		return Value1.Value <= Value2.Value;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "UInt64 > UInt64", meta = (Keywords = "> Greater Than"))
	static bool Dolphin_UInt64GreaterThanUInt64(const FDolphinUInt64& Value1, const FDolphinUInt64& Value2)
	{
		return Value1.Value > Value2.Value;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "UInt64 >= UInt64", meta = (Keywords = ">= Greater Than or Equal To Equals"))
	static bool Dolphin_UInt64GreaterThanOrEqualToUInt64(const FDolphinUInt64& Value1, const FDolphinUInt64& Value2)
	{
		return Value1.Value >= Value2.Value;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Int8 - Int8", meta = (Keywords = "- Minus Subtract"))
	static FDolphinInt8 Dolphin_Int8SubtractInt8(const FDolphinInt8& Value1, const FDolphinInt8& Value2)
	{
		return Value1.Value - Value2.Value;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Int8 + Int8", meta = (Keywords = "+ Add Addition"))
	static FDolphinInt8 Dolphin_Int8AddInt8(const FDolphinInt8& Value1, const FDolphinInt8& Value2)
	{
		return Value1.Value + Value2.Value;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Int8 * Int8", meta = (Keywords = "* Multiply Times"))
	static FDolphinInt8 Dolphin_Int8MultiplyInt8(const FDolphinInt8& Value1, const FDolphinInt8& Value2)
	{
		return Value1.Value * Value2.Value;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Int8 / Int8", meta = (Keywords = "/ Divide By Division"))
	static FDolphinInt8 Dolphin_Int8DivideInt8(const FDolphinInt8& Value1, const FDolphinInt8& Value2)
	{
		return Value1.Value / Value2.Value;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Int8 == Int8", meta = (Keywords = "== Equal To Equals"))
	static bool Dolphin_Int8EqualToInt8(const FDolphinInt8& Value1, const FDolphinInt8& Value2)
	{
		return Value1.Value == Value2.Value;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Int8 != Int8", meta = (Keywords = "!= Not Equal To Equals"))
	static bool Dolphin_Int8NotEqualToInt8(const FDolphinInt8& Value1, const FDolphinInt8& Value2)
	{
		return Value1.Value != Value2.Value;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Int8 < Int8", meta = (Keywords = "< Less Than"))
	static bool Dolphin_Int8LessThanInt8(const FDolphinInt8& Value1, const FDolphinInt8& Value2)
	{
		return Value1.Value < Value2.Value;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Int8 <= Int8", meta = (Keywords = "<= Less Than or Equal To Equals"))
	static bool Dolphin_Int8LessThanOrEqualToInt8(const FDolphinInt8& Value1, const FDolphinInt8& Value2)
	{
		return Value1.Value <= Value2.Value;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Int8 > Int8", meta = (Keywords = "> Greater Than"))
	static bool Dolphin_Int8GreaterThanInt8(const FDolphinInt8& Value1, const FDolphinInt8& Value2)
	{
		return Value1.Value > Value2.Value;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Int8 >= Int8", meta = (Keywords = ">= Greater Than or Equal To Equals"))
	static bool Dolphin_Int8GreaterThanOrEqualToInt8(const FDolphinInt8& Value1, const FDolphinInt8& Value2)
	{
		return Value1.Value >= Value2.Value;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Int16 - Int16", meta = (Keywords = "- Minus Subtract"))
	static FDolphinInt16 Dolphin_Int16SubtractInt16(const FDolphinInt16& Value1, const FDolphinInt16& Value2)
	{
		return Value1.Value - Value2.Value;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Int16 + Int16", meta = (Keywords = "+ Add Addition"))
	static FDolphinInt16 Dolphin_Int16AddInt16(const FDolphinInt16& Value1, const FDolphinInt16& Value2)
	{
		return Value1.Value + Value2.Value;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Int16 * Int16", meta = (Keywords = "* Multiply Times"))
	static FDolphinInt16 Dolphin_Int16MultiplyInt16(const FDolphinInt16& Value1, const FDolphinInt16& Value2)
	{
		return Value1.Value * Value2.Value;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Int16 / Int16", meta = (Keywords = "/ Divide By Division"))
	static FDolphinInt16 Dolphin_Int16DivideInt16(const FDolphinInt16& Value1, const FDolphinInt16& Value2)
	{
		return Value1.Value / Value2.Value;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Int16 == Int16", meta = (Keywords = "== Equal To Equals"))
	static bool Dolphin_Int16EqualToInt16(const FDolphinInt16& Value1, const FDolphinInt16& Value2)
	{
		return Value1.Value == Value2.Value;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Int16 != Int16", meta = (Keywords = "!= Not Equal To Equals"))
	static bool Dolphin_Int16NotEqualToInt16(const FDolphinInt16& Value1, const FDolphinInt16& Value2)
	{
		return Value1.Value != Value2.Value;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Int16 < Int16", meta = (Keywords = "< Less Than"))
	static bool Dolphin_Int16LessThanInt16(const FDolphinInt16& Value1, const FDolphinInt16& Value2)
	{
		return Value1.Value < Value2.Value;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Int16 <= Int16", meta = (Keywords = "<= Less Than or Equal To Equals"))
	static bool Dolphin_Int16LessThanOrEqualToInt16(const FDolphinInt16& Value1, const FDolphinInt16& Value2)
	{
		return Value1.Value <= Value2.Value;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Int16 > Int16", meta = (Keywords = "> Greater Than"))
	static bool Dolphin_Int16GreaterThanInt16(const FDolphinInt16& Value1, const FDolphinInt16& Value2)
	{
		return Value1.Value > Value2.Value;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Int16 >= Int16", meta = (Keywords = ">= Greater Than or Equal To Equals"))
	static bool Dolphin_Int16GreaterThanOrEqualToInt16(const FDolphinInt16& Value1, const FDolphinInt16& Value2)
	{
		return Value1.Value >= Value2.Value;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Int32 - Int32", meta = (Keywords = "- Minus Subtract"))
	static FDolphinInt32 Dolphin_Int32SubtractInt32(const FDolphinInt32& Value1, const FDolphinInt32& Value2)
	{
		return Value1.Value - Value2.Value;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Int32 + Int32", meta = (Keywords = "+ Add Addition"))
	static FDolphinInt32 Dolphin_Int32AddInt32(const FDolphinInt32& Value1, const FDolphinInt32& Value2)
	{
		return Value1.Value + Value2.Value;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Int32 * Int32", meta = (Keywords = "* Multiply Times"))
	static FDolphinInt32 Dolphin_Int32MultiplyInt32(const FDolphinInt32& Value1, const FDolphinInt32& Value2)
	{
		return Value1.Value * Value2.Value;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Int32 / Int32", meta = (Keywords = "/ Divide By Division"))
	static FDolphinInt32 Dolphin_Int32DivideInt32(const FDolphinInt32& Value1, const FDolphinInt32& Value2)
	{
		return Value1.Value / Value2.Value;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Int32 == Int32", meta = (Keywords = "== Equal To Equals"))
	static bool Dolphin_Int32EqualToInt32(const FDolphinInt32& Value1, const FDolphinInt32& Value2)
	{
		return Value1.Value == Value2.Value;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Int32 != Int32", meta = (Keywords = "!= Not Equal To Equals"))
	static bool Dolphin_Int32NotEqualToInt32(const FDolphinInt32& Value1, const FDolphinInt32& Value2)
	{
		return Value1.Value != Value2.Value;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Int32 < Int32", meta = (Keywords = "< Less Than"))
	static bool Dolphin_Int32LessThanInt32(const FDolphinInt32& Value1, const FDolphinInt32& Value2)
	{
		return Value1.Value < Value2.Value;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Int32 <= Int32", meta = (Keywords = "<= Less Than or Equal To Equals"))
	static bool Dolphin_Int32LessThanOrEqualToInt32(const FDolphinInt32& Value1, const FDolphinInt32& Value2)
	{
		return Value1.Value <= Value2.Value;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Int32 > Int32", meta = (Keywords = "> Greater Than"))
	static bool Dolphin_Int32GreaterThanInt32(const FDolphinInt32& Value1, const FDolphinInt32& Value2)
	{
		return Value1.Value > Value2.Value;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Int32 >= Int32", meta = (Keywords = ">= Greater Than or Equal To Equals"))
	static bool Dolphin_Int32GreaterThanOrEqualToInt32(const FDolphinInt32& Value1, const FDolphinInt32& Value2)
	{
		return Value1.Value >= Value2.Value;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Int64 - Int64", meta = (Keywords = "- Minus Subtract"))
	static FDolphinInt64 Dolphin_Int64SubtractInt64(const FDolphinInt64& Value1, const FDolphinInt64& Value2)
	{
		return Value1.Value - Value2.Value;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Int64 + Int64", meta = (Keywords = "+ Add Addition"))
	static FDolphinInt64 Dolphin_Int64AddInt64(const FDolphinInt64& Value1, const FDolphinInt64& Value2)
	{
		return Value1.Value + Value2.Value;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Int64 * Int64", meta = (Keywords = "* Multiply Times"))
	static FDolphinInt64 Dolphin_Int64MultiplyInt64(const FDolphinInt64& Value1, const FDolphinInt64& Value2)
	{
		return Value1.Value * Value2.Value;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Int64 / Int64", meta = (Keywords = "/ Divide By Division"))
	static FDolphinInt64 Dolphin_Int64DivideInt64(const FDolphinInt64& Value1, const FDolphinInt64& Value2)
	{
		return Value1.Value / Value2.Value;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Int64 == Int64", meta = (Keywords = "== Equal To Equals"))
	static bool Dolphin_Int64EqualToInt64(const FDolphinInt64& Value1, const FDolphinInt64& Value2)
	{
		return Value1.Value == Value2.Value;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Int64 != Int64", meta = (Keywords = "!= Not Equal To Equals"))
	static bool Dolphin_Int64NotEqualToInt64(const FDolphinInt64& Value1, const FDolphinInt64& Value2)
	{
		return Value1.Value != Value2.Value;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Int64 < Int64", meta = (Keywords = "< Less Than"))
	static bool Dolphin_Int64LessThanInt64(const FDolphinInt64& Value1, const FDolphinInt64& Value2)
	{
		return Value1.Value < Value2.Value;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Int64 <= Int64", meta = (Keywords = "<= Less Than or Equal To Equals"))
	static bool Dolphin_Int64LessThanOrEqualToInt64(const FDolphinInt64& Value1, const FDolphinInt64& Value2)
	{
		return Value1.Value <= Value2.Value;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Int64 > Int64", meta = (Keywords = "> Greater Than"))
	static bool Dolphin_Int64GreaterThanInt64(const FDolphinInt64& Value1, const FDolphinInt64& Value2)
	{
		return Value1.Value > Value2.Value;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Int64 >= Int64", meta = (Keywords = ">= Greater Than or Equal To Equals"))
	static bool Dolphin_Int64GreaterThanOrEqualToInt64(const FDolphinInt64& Value1, const FDolphinInt64& Value2)
	{
		return Value1.Value >= Value2.Value;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Float - Float", meta = (Keywords = "- Minus Subtract"))
	static FDolphinFloat Dolphin_FloatSubtractFloat(const FDolphinFloat& Value1, const FDolphinFloat& Value2)
	{
		return Value1.Value - Value2.Value;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Float + Float", meta = (Keywords = "+ Add Addition"))
	static FDolphinFloat Dolphin_FloatAddFloat(const FDolphinFloat& Value1, const FDolphinFloat& Value2)
	{
		return Value1.Value + Value2.Value;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Float * Float", meta = (Keywords = "* Multiply Times"))
	static FDolphinFloat Dolphin_FloatMultiplyFloat(const FDolphinFloat& Value1, const FDolphinFloat& Value2)
	{
		return Value1.Value * Value2.Value;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Float / Float", meta = (Keywords = "/ Divide By Division"))
	static FDolphinFloat Dolphin_FloatDivideFloat(const FDolphinFloat& Value1, const FDolphinFloat& Value2)
	{
		return Value1.Value / Value2.Value;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Float == Float", meta = (Keywords = "== Equal To Equals"))
	static bool Dolphin_FloatEqualToFloat(const FDolphinFloat& Value1, const FDolphinFloat& Value2)
	{
		return Value1.Value == Value2.Value;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Float != Float", meta = (Keywords = "!= Not Equal To Equals"))
	static bool Dolphin_FloatNotEqualToFloat(const FDolphinFloat& Value1, const FDolphinFloat& Value2)
	{
		return Value1.Value != Value2.Value;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Float < Float", meta = (Keywords = "< Less Than"))
	static bool Dolphin_FloatLessThanFloat(const FDolphinFloat& Value1, const FDolphinFloat& Value2)
	{
		return Value1.Value < Value2.Value;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Float <= Float", meta = (Keywords = "<= Less Than or Equal To Equals"))
	static bool Dolphin_FloatLessThanOrEqualToFloat(const FDolphinFloat& Value1, const FDolphinFloat& Value2)
	{
		return Value1.Value <= Value2.Value;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Float > Float", meta = (Keywords = "> Greater Than"))
	static bool Dolphin_FloatGreaterThanFloat(const FDolphinFloat& Value1, const FDolphinFloat& Value2)
	{
		return Value1.Value > Value2.Value;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Float >= Float", meta = (Keywords = ">= Greater Than or Equal To Equals"))
	static bool Dolphin_FloatGreaterThanOrEqualToFloat(const FDolphinFloat& Value1, const FDolphinFloat& Value2)
	{
		return Value1.Value >= Value2.Value;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Double - Double", meta = (Keywords = "- Minus Subtract"))
	static FDolphinDouble Dolphin_DoubleSubtractDouble(const FDolphinDouble& Value1, const FDolphinDouble& Value2)
	{
		return Value1.Value - Value2.Value;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Double + Double", meta = (Keywords = "+ Add Addition"))
	static FDolphinDouble Dolphin_DoubleAddDouble(const FDolphinDouble& Value1, const FDolphinDouble& Value2)
	{
		return Value1.Value + Value2.Value;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Double * Double", meta = (Keywords = "* Multiply Times"))
	static FDolphinDouble Dolphin_DoubleMultiplyDouble(const FDolphinDouble& Value1, const FDolphinDouble& Value2)
	{
		return Value1.Value * Value2.Value;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Double / Double", meta = (Keywords = "/ Divide By Division"))
	static FDolphinDouble Dolphin_DoubleDivideDouble(const FDolphinDouble& Value1, const FDolphinDouble& Value2)
	{
		return Value1.Value / Value2.Value;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Double == Double", meta = (Keywords = "== Equal To Equals"))
	static bool Dolphin_DoubleEqualToDouble(const FDolphinDouble& Value1, const FDolphinDouble& Value2)
	{
		return Value1.Value == Value2.Value;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Double != Double", meta = (Keywords = "!= Not Equal To Equals"))
	static bool Dolphin_DoubleNotEqualToDouble(const FDolphinDouble& Value1, const FDolphinDouble& Value2)
	{
		return Value1.Value != Value2.Value;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Double < Double", meta = (Keywords = "< Less Than"))
	static bool Dolphin_DoubleLessThanDouble(const FDolphinDouble& Value1, const FDolphinDouble& Value2)
	{
		return Value1.Value < Value2.Value;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Double <= Double", meta = (Keywords = "<= Less Than or Equal To Equals"))
	static bool Dolphin_DoubleLessThanOrEqualToDouble(const FDolphinDouble& Value1, const FDolphinDouble& Value2)
	{
		return Value1.Value <= Value2.Value;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Double > Double", meta = (Keywords = "> Greater Than"))
	static bool Dolphin_DoubleGreaterThanDouble(const FDolphinDouble& Value1, const FDolphinDouble& Value2)
	{
		return Value1.Value > Value2.Value;
	}

	UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Double >= Double", meta = (Keywords = ">= Greater Than or Equal To Equals"))
	static bool Dolphin_DoubleGreaterThanOrEqualToDouble(const FDolphinDouble& Value1, const FDolphinDouble& Value2)
	{
		return Value1.Value >= Value2.Value;
	}


};


