#include "gtest/gtest.h"
#include "roman.h"

#define LINE_MAX_SIZE 50

//! [TestingList, TestingUntil3000]
TEST(TestingList, TestingUntil3000) {
	FILE *fp = fopen("test/data/romans-until-3000.dat", "r");
	ASSERT_TRUE(fp != NULL);
	char buffer[LINE_MAX_SIZE];
	
	while(fgets(buffer, LINE_MAX_SIZE, fp)) {
		int value;
		char roman[LINE_MAX_SIZE];
		
		if(sscanf(buffer, "%d %49s ", &value, roman) != 2)
			continue;
		
		EXPECT_EQ(roman_to_int(roman), value);
	}
	
	fclose(fp);
}
//! [TestingList, TestingUntil3000]

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
