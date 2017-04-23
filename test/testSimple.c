#include "gtest/gtest.h"
#include "roman.h"

//! [SimpleInput, InvalidInput]
TEST(SimpleInput, InvalidInput) {
	EXPECT_EQ(roman_to_int(NULL), -1);
	EXPECT_EQ(roman_to_int(""), -1);
}
//! [SimpleInput, InvalidInput]

//! [SimpleInput, SingleCharacter]
TEST(SimpleInput, SingleCharacter) {
	EXPECT_EQ(roman_to_int("I"), 1);
	EXPECT_EQ(roman_to_int("V"), 5);
	EXPECT_EQ(roman_to_int("X"), 10);
	EXPECT_EQ(roman_to_int("L"), 50);
	EXPECT_EQ(roman_to_int("C"), 100);
	EXPECT_EQ(roman_to_int("D"), 500);
	EXPECT_EQ(roman_to_int("M"), 1000);
}
//! [SimpleInput, SingleCharacter]

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
