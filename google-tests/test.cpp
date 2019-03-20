#include "pch.h"
#include "flowerpot.h"

// int onesMaskOfWidthLength(int width);
TEST(maskGeneration, maskTest0) {
  EXPECT_EQ(0, onesMaskOfWidthLength(0));
}

TEST(maskGeneration, maskTest1) {
	EXPECT_EQ(1, onesMaskOfWidthLength(1));
}

TEST(maskGeneration, maskTest2) {
	EXPECT_EQ(3, onesMaskOfWidthLength(2));
}

TEST(maskGeneration, maskTest3) {
	EXPECT_EQ(7, onesMaskOfWidthLength(3));
}

// int horizontalFlow(int whereIsWater, int lowerRow, int width);
TEST(horizontalFlow, horizontalFlowTestWidth3v1) {
	EXPECT_EQ(0b101, horizontalFlow(0b101, 0b101, 3));
}

TEST(horizontalFlow, horizontalFlowTestWidth3v2) {
	EXPECT_EQ(0b100, horizontalFlow(0b100, 0b101, 3));
}

TEST(horizontalFlow, horizontalFlowTestWidth3v3) {
	EXPECT_EQ(0b111, horizontalFlow(0b100, 0b111, 3));
}

TEST(horizontalFlow, horizontalFlowTestWidth3v4) {
	EXPECT_EQ(0b111, horizontalFlow(0b001, 0b111, 3));
}

TEST(horizontalFlow, horizontalFlowTestWidth3v5) {
	EXPECT_EQ(0b111, horizontalFlow(0b010, 0b111, 3));
}

TEST(horizontalFlow, horizontalFlowTestWidth3v6) {
	EXPECT_EQ(0b000, horizontalFlow(0b000, 0b101, 3));
}

TEST(horizontalFlow, horizontalFlowTestWidth3v7) {
	EXPECT_EQ(0b110, horizontalFlow(0b100, 0b110, 3));
}

TEST(horizontalFlow, horizontalFlowTestWidth4v1) {
	EXPECT_EQ(0b1111, horizontalFlow(0b1001, 0b1111, 3));
}

TEST(horizontalFlow, horizontalFlowTestWidth4v2) {
	EXPECT_EQ(0b1111, horizontalFlow(0b0100, 0b1111, 3)); 
}

TEST(horizontalFlow, horizontalFlowTestWidth4v3) {
	EXPECT_EQ(0b0010, horizontalFlow(0b0010, 0b0010, 3));
}


// test as whole
TEST(FinalOutput, test3x3v1) {
	constexpr int width = 3;
	constexpr int depth = 3;
	int flowerpot = 0b111'111'111;
	EXPECT_EQ(1, canWaterFlow(flowerpot, width, depth));
}

TEST(FinalOutput, test3x3v2) {
	constexpr int width = 3;
	constexpr int depth = 3;
	int flowerpot = 0b101'101'101;
	EXPECT_EQ(1, canWaterFlow(flowerpot, width, depth));
}
TEST(FinalOutput, test3x3v3) {
	constexpr int width = 3;
	constexpr int depth = 3;
	int flowerpot = 0b101'000'101;
	EXPECT_EQ(0, canWaterFlow(flowerpot, width, depth));
}
TEST(FinalOutput, test3x3v4) {
	constexpr int width = 3;
	constexpr int depth = 3;
	int flowerpot = 0b100'111'001;
	EXPECT_EQ(1, canWaterFlow(flowerpot, width, depth));
}

TEST(FinalOutput, test3x3v5) {
	constexpr int width = 3;
	constexpr int depth = 3;
	int flowerpot = 0b000'111'001;
	EXPECT_EQ(0, canWaterFlow(flowerpot, width, depth));
}
TEST(FinalOutput, test3x4v1) {
	constexpr int width = 3;
	constexpr int depth = 4;
	int flowerpot = 0b000'100'111'001;
	EXPECT_EQ(0, canWaterFlow(flowerpot, width, depth));
}

TEST(FinalOutput, test3x4v2) {
	constexpr int width = 3;
	constexpr int depth = 4;
	int flowerpot = 0b100'100'111'001;
	EXPECT_EQ(1, canWaterFlow(flowerpot, width, depth));
}

TEST(FinalOutput, test3x4v3) {
	constexpr int width = 3;
	constexpr int depth = 4;
	int flowerpot = 0b001'001'111'001;
	EXPECT_EQ(1, canWaterFlow(flowerpot, width, depth));
}

TEST(FinalOutput, test4x4v1) {
	const int width = 4;
	const int depth = 4;
	int flowerpot = 0b0100'0100'0111'001;
	EXPECT_EQ(1, canWaterFlow(flowerpot, width, depth));
}

TEST(FinalOutput, test4x4v2) {
	const int width = 4;
	const int depth = 4;
	int flowerpot = 0b1001'0101'1001'0101;
	EXPECT_EQ(1, canWaterFlow(flowerpot, width, depth));
}

TEST(FinalOutput, test5x4v1) {
	const int width = 5;
	const int depth = 4;
	int flowerpot = 0b01100'00110'00011'00001;
	EXPECT_EQ(1, canWaterFlow(flowerpot, width, depth));
}

TEST(FinalOutput, test5x4v2) {
	const int width = 5;
	const int depth = 4;
	int flowerpot = 0b11000'00110'00011'00001;
	EXPECT_EQ(0, canWaterFlow(flowerpot, width, depth));
}

TEST(FinalOutput, test5x4v3) {
	const int width = 5;
	const int depth = 4;
	int flowerpot = 0b01100'00110'11000'00001;
	EXPECT_EQ(0, canWaterFlow(flowerpot, width, depth));
}