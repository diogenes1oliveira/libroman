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

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
