#include "gtest/gtest.h"
#include "roman.h"

TEST(SubtractingInput, WrongOrder) {
	EXPECT_EQ(roman_to_int("VX"), -1);
	EXPECT_EQ(roman_to_int("VM"), -1);
	EXPECT_EQ(roman_to_int("VV"), -1);
	
	EXPECT_EQ(roman_to_int("XVX"), -1);
	EXPECT_EQ(roman_to_int("DM"), -1);
}

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
