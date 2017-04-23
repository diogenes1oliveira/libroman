#include "gtest/gtest.h"
#include "roman.h"

//! [SubtractingInput, WrongOrder]
TEST(SubtractingInput, WrongOrder) {
	EXPECT_EQ(roman_to_int("ICCV"), -1);
	EXPECT_EQ(roman_to_int("IM"), -1);
	EXPECT_EQ(roman_to_int("IDX"), -1);
	
	EXPECT_EQ(roman_to_int("XVX"), -1);
	EXPECT_EQ(roman_to_int("DM"), -1);
	
	EXPECT_EQ(roman_to_int("LM"), -1);
	EXPECT_EQ(roman_to_int("LCIX"), -1);
}
//! [SubtractingInput, WrongOrder]

//! [SubtractingInput, SingleSubtractingChar]
TEST(SubtractingInput, SingleSubtractingChar) {
	EXPECT_EQ(roman_to_int("IV"), 4);
	EXPECT_EQ(roman_to_int("IX"), 9);
	EXPECT_EQ(roman_to_int("XCII"), 92);
	EXPECT_EQ(roman_to_int("CMLXX"), 970);
}
//! [SubtractingInput, SingleSubtractingChar]

//! [SubtractingInput, MultipleSubtractingChar]
TEST(SubtractingInput, MultipleSubtractingChar) {
	EXPECT_EQ(roman_to_int("IIX"), -1);
	EXPECT_EQ(roman_to_int("IIIV"), -1);
	EXPECT_EQ(roman_to_int("XXCVI"), -1);
	EXPECT_EQ(roman_to_int("XXCIV"), -1);
}
//! [SubtractingInput, MultipleSubtractingChar]

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
