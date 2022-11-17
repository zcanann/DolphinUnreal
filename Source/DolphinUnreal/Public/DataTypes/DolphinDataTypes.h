// Copyright 2014-2015 Matthew Chapman, Inc. All Rights Reserved.

#pragma once

#include "UObject/UnrealType.h"

#include "DolphinDataTypes.generated.h"

UENUM(BlueprintType)
enum class EMemoryCardSlot : uint8
{
	SlotA,
	SlotB,
};
ENUM_RANGE_BY_FIRST_AND_LAST(EMemoryCardSlot, EMemoryCardSlot::SlotA, EMemoryCardSlot::SlotB);

UENUM(BlueprintType)
enum class EMemoryCardSize : uint8
{
	GC_4_Mbit_59_Blocks UMETA(DisplayName = "4 Mbit (59 Blocks)"),
	GC_8_Mbit_123_Blocks UMETA(DisplayName = "8 Mbit (123 Blocks)"),
	GC_16_Mbit_251_Blocks UMETA(DisplayName = "16 Mbit (251 Blocks)"),
	GC_32_Mbit_507_Blocks UMETA(DisplayName = "32 Mbit (507 Blocks)"),
	GC_64_Mbit_1019_Blocks UMETA(DisplayName = "64 Mbit (1019 Blocks)"),
	GC_128_Mbit_2043_Blocks UMETA(DisplayName = "128 Mbit (2043 Blocks)"),
};
ENUM_RANGE_BY_FIRST_AND_LAST(EMemoryCardSize, EMemoryCardSize::GC_4_Mbit_59_Blocks, EMemoryCardSize::GC_128_Mbit_2043_Blocks);

UENUM(BlueprintType)
enum class EMemoryCardEncoding : uint8
{
	Western,
	Japanese,
};
ENUM_RANGE_BY_FIRST_AND_LAST(EMemoryCardEncoding, EMemoryCardEncoding::Western, EMemoryCardEncoding::Japanese);

#define PACKED
#pragma pack(push,1)

USTRUCT(BlueprintType)
struct FDolphinInt8
{
	GENERATED_BODY()

	int8 Value;

	operator int8() const { return Value; }

	FDolphinInt8() { this->Value = 0; }
	FDolphinInt8(const int8& Value) { this->Value = Value; }
};

#pragma pack(pop)
#undef PACKED

#define PACKED
#pragma pack(push,1)

USTRUCT(BlueprintType)
struct FDolphinInt8Array
{
	GENERATED_BODY()
		
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FDolphinInt8> Values;

	FDolphinInt8Array() { }
	FDolphinInt8Array(TArray<FDolphinInt8> InValues) : Values(InValues) { }
};

#pragma pack(pop)
#undef PACKED

#define PACKED
#pragma pack(push,1)

USTRUCT(BlueprintType)
struct FDolphinInt16
{
	GENERATED_BODY()

	int16 Value;

	operator int16() const { return Value; }

	FDolphinInt16() { this->Value = 0; }
	FDolphinInt16(const int16& Value) { this->Value = Value; }
};

#pragma pack(pop)
#undef PACKED

#define PACKED
#pragma pack(push,1)

USTRUCT(BlueprintType)
struct FDolphinInt32
{
	GENERATED_BODY()

	int32 Value;

	operator int32() const { return Value; }

	FDolphinInt32() { this->Value = 0; }
	FDolphinInt32(const int32& Value) { this->Value = Value; }
};

#pragma pack(pop)
#undef PACKED

#define PACKED
#pragma pack(push,1)

USTRUCT(BlueprintType)
struct FDolphinInt64
{
	GENERATED_BODY()

	int64 Value;

	operator int64() const { return Value; }

	FDolphinInt64() { this->Value = 0; }
	FDolphinInt64(const int64& Value) { this->Value = Value; }
};

#pragma pack(pop)
#undef PACKED

#define PACKED
#pragma pack(push,1)

USTRUCT(BlueprintType)
struct FDolphinUInt8
{
	GENERATED_BODY()

	uint8 Value;

	operator uint8() const { return Value; }

	FDolphinUInt8() { this->Value = 0; }
	FDolphinUInt8(const uint8& Value) { this->Value = Value; }
};

#pragma pack(pop)
#undef PACKED

#define PACKED
#pragma pack(push,1)

USTRUCT(BlueprintType)
struct FDolphinUInt8Array
{
	GENERATED_BODY()
		
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FDolphinUInt8> Values;

	FDolphinUInt8Array() { }
	FDolphinUInt8Array(TArray<FDolphinUInt8> InValues) : Values(InValues) { }
};

#pragma pack(pop)
#undef PACKED

#define PACKED
#pragma pack(push,1)

USTRUCT(BlueprintType)
struct FDolphinUInt16
{
	GENERATED_BODY()

	uint16 Value;

	operator uint16() const { return Value; }

	FDolphinUInt16() { this->Value = 0; }
	FDolphinUInt16(const uint16& Value) { this->Value = Value; }
};

#pragma pack(pop)
#undef PACKED

#define PACKED
#pragma pack(push,1)

USTRUCT(BlueprintType)
struct FDolphinUInt32
{
	GENERATED_BODY()

	uint32 Value;

	operator uint32() const { return Value; }

	FDolphinUInt32() { this->Value = 0; }
	FDolphinUInt32(const uint32& Value) { this->Value = Value; }
};

#pragma pack(pop)
#undef PACKED

#define PACKED
#pragma pack(push,1)

USTRUCT(BlueprintType)
struct FDolphinUInt64
{
	GENERATED_BODY()

	uint64 Value;

	operator uint64() const { return Value; }

	FDolphinUInt64() { this->Value = 0; }
	FDolphinUInt64(const uint64& Value) { this->Value = Value; }
};

#pragma pack(pop)
#undef PACKED

#define PACKED
#pragma pack(push,1)

USTRUCT(BlueprintType)
struct FDolphinFloat
{
	GENERATED_BODY()

	float Value;

	operator float() const { return Value; }

	FDolphinFloat() { this->Value = 0.0f; }
	FDolphinFloat(const float& Value) { this->Value = Value; }
};

#pragma pack(pop)
#undef PACKED

#define PACKED
#pragma pack(push,1)

USTRUCT(BlueprintType)
struct FDolphinDouble
{
	GENERATED_BODY()

	double Value;

	operator double() const { return Value; }

	FDolphinDouble() { this->Value = 0.0; }
	FDolphinDouble(const double& Value) { this->Value = Value; }
};

#pragma pack(pop)
#undef PACKED
