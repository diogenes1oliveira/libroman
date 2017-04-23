#include <stdio.h>
#include <stdlib.h>

#include "gtest/gtest.h"
#include "roman.h"

//! [TestingBin, ExitsGracefully]
TEST(TestingBin, ExitsGracefully) {
	EXPECT_NE(system("./bin/roman-to-int"), 0);
	EXPECT_NE(system("./bin/roman-to-int VI 38 --system"), 0);
	
	EXPECT_EQ(system("./bin/roman-to-int VI"), 0);
	EXPECT_EQ(system("./bin/roman-to-int mIiI"), 0);
	
	EXPECT_NE(system("./bin/roman-to-int IM"), 0);
	EXPECT_NE(system("./bin/roman-to-int XDI"), 0);
}
//! [TestingBin, ExitsGracefully]

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
