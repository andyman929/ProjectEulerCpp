#include "pch.h"
#include "UNBitIntTests.h"
#include "NBitIntTests.h"

int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}