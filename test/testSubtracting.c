#include "gtest/gtest.h"
#include "roman.h"

TEST(SubtractingInput, WrongOrder) {
	EXPECT_EQ(roman_to_int("ICCV"), -1);
	EXPECT_EQ(roman_to_int("IM"), -1);
	EXPECT_EQ(roman_to_int("IDX"), -1);
	
	EXPECT_EQ(roman_to_int("XVX"), -1);
	EXPECT_EQ(roman_to_int("DM"), -1);
	
	EXPECT_EQ(roman_to_int("LM"), -1);
	EXPECT_EQ(roman_to_int("LCIX"), -1);
}


TEST(SubtractingInput, SingleSubtractingChar) {
	EXPECT_EQ(roman_to_int("IX"), 9);
	EXPECT_EQ(roman_to_int("XCII"), 92);
	EXPECT_EQ(roman_to_int("CMLXX"), 970);
}

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
