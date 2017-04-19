#include "gtest/gtest.h"
#include "roman.h"

/*
 * This test checks if simple invalid strings are correctly handled.
 */
TEST(SimpleInput, InvalidInput) {
	EXPECT_EQ(roman_to_int(NULL), -1);
	EXPECT_EQ(roman_to_int(""), -1);
}

/*
 * This test intends to find whether the conversion for single character input
 * is working as intended. As we know, we have the following equivalences:
 * I -> 1
 * V -> 5
 * X -> 10
 * L -> 50
 * C -> 100
 * D -> 500
 * M -> 1000
 */
TEST(SimpleInput, SingleCharacter) {
	EXPECT_EQ(roman_to_int("I"), 1);
	EXPECT_EQ(roman_to_int("V"), 5);
	EXPECT_EQ(roman_to_int("X"), 10);
	EXPECT_EQ(roman_to_int("L"), 50);
	EXPECT_EQ(roman_to_int("C"), 100);
	EXPECT_EQ(roman_to_int("D"), 500);
	EXPECT_EQ(roman_to_int("M"), 1000);
}

TEST(SimpleInput, InvalidCharacter) {
	EXPECT_EQ(roman_to_int("A"), -1);
	EXPECT_EQ(roman_to_int("XXe"), -1);
	EXPECT_EQ(roman_to_int("xx"), -1);
	EXPECT_EQ(roman_to_int("AMMMI"), -1);
	EXPECT_EQ(roman_to_int("C "), -1);
	EXPECT_EQ(roman_to_int("D  I"), -1);
	EXPECT_EQ(roman_to_int("MM_1"), -1);
}

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
