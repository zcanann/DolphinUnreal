// Copyright 2014-2015 Matthew Chapman, Inc. All Rights Reserved.

#pragma once

#include "UObject/UnrealType.h"

#include "DolphinDataTypes.generated.h"

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
