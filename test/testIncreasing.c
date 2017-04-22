#include "gtest/gtest.h"
#include "roman.h"

TEST(ComplexInput, MultipleSingleCharacters) {
	EXPECT_EQ(roman_to_int("II"), 2);
	EXPECT_EQ(roman_to_int("XXX"), 30);
	EXPECT_EQ(roman_to_int("L"), 50);
	EXPECT_EQ(roman_to_int("CC"), 200);
	EXPECT_EQ(roman_to_int("CCC"), 300);
	EXPECT_EQ(roman_to_int("MM"), 2000);
}

TEST(ComplexInput, IncreasingCharacters) {
	EXPECT_EQ(roman_to_int("XI"), 11);
	EXPECT_EQ(roman_to_int("XII"), 12);
	EXPECT_EQ(roman_to_int("VI"), 6);
	EXPECT_EQ(roman_to_int("LX"), 60);
	EXPECT_EQ(roman_to_int("MDXX"), 1520);
}

TEST(ComplexInput, NonRepeatableCharacters) {
	EXPECT_EQ(roman_to_int("VV"), -1);
	EXPECT_EQ(roman_to_int("DDD"), -1);
	EXPECT_EQ(roman_to_int("LL"), -1);
	EXPECT_EQ(roman_to_int("MDDX"), -1);
}

TEST(ComplexInput, TooManyRepetitions) {
	EXPECT_EQ(roman_to_int("XXXXX"), -1);
	EXPECT_EQ(roman_to_int("MMMM"), -1);
	EXPECT_EQ(roman_to_int("IIIIIIII"), -1);
	
	EXPECT_EQ(roman_to_int("MIIII"), -1);
	EXPECT_EQ(roman_to_int("DXXXX"), -1);
	EXPECT_EQ(roman_to_int("LXXXXX"), -1);
	EXPECT_EQ(roman_to_int("MMMMMDXII"), -1);
}

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
