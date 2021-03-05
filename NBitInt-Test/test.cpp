#include "pch.h"

TEST(NBitBasicTests, EmptyInitialize) {
	const int size = 64;
	NBitInt<size> foo;
	std::bitset<size> fooBits = foo.GetBitset();
	__int64 fooInt = foo.GetInt();
	double fooDouble = foo.GetDouble();

	EXPECT_EQ(fooBits.size(), 64);
	EXPECT_EQ(fooInt, 0);
	EXPECT_EQ(fooDouble, 0.0) << "Double output does not match";
}

int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}