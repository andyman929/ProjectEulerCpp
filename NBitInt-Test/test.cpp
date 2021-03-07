#include "pch.h"
#include "NBitInt.h"

TEST(InitialisationTests, EmptyInitialize) {
	const int size = 64;
	NBitInt<size> foo;
	std::bitset<size> fooBits = foo.GetBitset();
	__int64 fooInt = foo.GetInt();
	double fooDouble = foo.GetDouble();

	EXPECT_EQ(fooBits.size(), 64) << "Size one bitset does not match initialized size";
	EXPECT_EQ(fooInt, 0) << "Integer output does not match expected empty initialized value of 0";
	EXPECT_EQ(fooDouble, 0.0) << "Double output does not match";
}

TEST(InitialisationTests, SimpleIntInitialize) {
	const int size = 64;

	for (int i = 0; i < 10; i++)
	{
		int init = pow(3, 10);
		NBitInt<size> foo(init);
		std::bitset<size> fooBits = foo.GetBitset();
		__int64 fooInt = foo.GetInt();
		double fooDouble = foo.GetDouble();


		EXPECT_EQ(fooBits.size(), 64);
		EXPECT_EQ(fooInt, init);
		EXPECT_EQ(fooDouble, (double)init) << "Double output does not match";
	}
}

TEST(InitialisationTests, VarySizeAndInput) {
	const int size = 5;
	int init = size;
	NBitInt<size>* foo = new NBitInt<size>(init);
	std::bitset<size> fooBits = foo->GetBitset();		EXPECT_EQ(fooBits.size(), size);
	__int64 fooInt = foo->GetInt();						EXPECT_EQ(fooInt, init);
	double fooDouble = foo->GetDouble();				EXPECT_EQ(fooDouble, (double)init) << "Double output does not match";
	delete foo;

	const int size2 = 6;
	init += size2;
	NBitInt<size2>* foo2 = new NBitInt<size2>(init);
	std::bitset<size2> fooBits2 = foo2->GetBitset();	EXPECT_EQ(fooBits2.size(), size2);
	fooInt = foo2->GetInt();							EXPECT_EQ(fooInt, init);
	fooDouble = foo2->GetDouble();						EXPECT_EQ(fooDouble, (double)init) << "Double output does not match";
	delete foo2;

	const int size3 = 7;
	init += size3;
	NBitInt<size3>* foo3 = new NBitInt<size3>(init);
	std::bitset<size3> fooBits3 = foo3->GetBitset();	EXPECT_EQ(fooBits3.size(), size3);
	fooInt = foo3->GetInt();							EXPECT_EQ(fooInt, init);
	fooDouble = foo3->GetDouble();						EXPECT_EQ(fooDouble, (double)init) << "Double output does not match";
	delete foo3;

	const int size4 = 8;
	init += size4;
	NBitInt<size4>* foo4 = new NBitInt<size4>(init);
	std::bitset<size4> fooBits4 = foo4->GetBitset();	EXPECT_EQ(fooBits4.size(), size4);
	fooInt = foo4->GetInt();							EXPECT_EQ(fooInt, init);
	fooDouble = foo4->GetDouble();						EXPECT_EQ(fooDouble, (double)init) << "Double output does not match";
	delete foo4;

	const int size5 = 14;
	init += size5;
	NBitInt<size5>* foo5 = new NBitInt<size5>(init);
	std::bitset<size5> fooBits5 = foo5->GetBitset();		EXPECT_EQ(fooBits5.size(), size5);
	fooInt = foo5->GetInt();							EXPECT_EQ(fooInt, init);
	fooDouble = foo5->GetDouble();						EXPECT_EQ(fooDouble, (double)init);
	delete foo5;

	const int size6 = 23;
	init += size6;
	NBitInt<size6>* foo6 = new NBitInt<size6>(init);
	std::bitset<size6> fooBits6 = foo6->GetBitset();	EXPECT_EQ(fooBits6.size(), size6);
	fooInt = foo6->GetInt();							EXPECT_EQ(fooInt, init);
	fooDouble = foo6->GetDouble();						EXPECT_EQ(fooDouble, (double)init);
	delete foo6;

	const int size7 = 42;
	init += size7;
	NBitInt<size7>* foo7 = new NBitInt<size7>(init);
	std::bitset<size7> fooBits7 = foo7->GetBitset();		EXPECT_EQ(fooBits7.size(), size7);
	fooInt = foo7->GetInt();							EXPECT_EQ(fooInt, init);
	fooDouble = foo7->GetDouble();						EXPECT_EQ(fooDouble, (double)init);
	delete foo7;

	const int size8 = 56;
	init += size8;
	NBitInt<size8>* foo8 = new NBitInt<size8>(init);
	std::bitset<size8> fooBits8 = foo8->GetBitset();	EXPECT_EQ(fooBits8.size(), size8);
	fooInt = foo8->GetInt();							EXPECT_EQ(fooInt, init);
	fooDouble = foo8->GetDouble();						EXPECT_EQ(fooDouble, (double)init);
	delete foo8;

	const int size9 = 62;
	init += size9;
	NBitInt<size9>* foo9 = new NBitInt<size9>(init);
	std::bitset<size9> fooBits9 = foo9->GetBitset();	EXPECT_EQ(fooBits9.size(), size9);
	fooInt = foo9->GetInt();							EXPECT_EQ(fooInt, init);
	fooDouble = foo9->GetDouble();						EXPECT_EQ(fooDouble, (double)init);
	delete foo9;

	const int size10 = 71;
	init += size10;
	NBitInt<size10>* foo10 = new NBitInt<size10>(init);
	std::bitset<size10> fooBits10 = foo10->GetBitset();	EXPECT_EQ(fooBits10.size(), size10);
	fooInt = foo10->GetInt();							EXPECT_EQ(fooInt, init);
	fooDouble = foo10->GetDouble();						EXPECT_EQ(fooDouble, (double)init);
	delete foo10;

	const int size11 = 72;
	init += size11;
	NBitInt<size11>* foo11 = new NBitInt<size11>(init);
	std::bitset<size11> fooBits11 = foo11->GetBitset();	EXPECT_EQ(fooBits11.size(), size11);
	fooInt = foo11->GetInt();							EXPECT_EQ(fooInt, init);
	fooDouble = foo11->GetDouble();						EXPECT_EQ(fooDouble, (double)init);
	delete foo11;

	const int size12 = 167;
	init += size12;
	NBitInt<size12>* foo12 = new NBitInt<size12>(init);
	std::bitset<size12> fooBits12 = foo12->GetBitset();	EXPECT_EQ(fooBits12.size(), size12);
	fooInt = foo12->GetInt();							EXPECT_EQ(fooInt, init);
	fooDouble = foo12->GetDouble();						EXPECT_EQ(fooDouble, (double)init);
	delete foo12;

	const int size13 = 234;
	init += size13;
	NBitInt<size13>* foo13 = new NBitInt<size13>(init);
	std::bitset<size13> fooBits13 = foo13->GetBitset();	EXPECT_EQ(fooBits13.size(), size13);
	fooInt = foo13->GetInt();							EXPECT_EQ(fooInt, init);
	fooDouble = foo13->GetDouble();						EXPECT_EQ(fooDouble, (double)init);
	delete foo13;

	const int size14 = 534;
	init += size14;
	NBitInt<size14>* foo14 = new NBitInt<size14>(init);
	std::bitset<size14> fooBits14 = foo14->GetBitset();	EXPECT_EQ(fooBits14.size(), size14);
	fooInt = foo14->GetInt();							EXPECT_EQ(fooInt, init);
	fooDouble = foo14->GetDouble();						EXPECT_EQ(fooDouble, (double)init);
	delete foo14;

	const int size15 = 541;
	init += size15;
	NBitInt<size15>* foo15 = new NBitInt<size15>(init);
	std::bitset<size15> fooBits15 = foo15->GetBitset();	EXPECT_EQ(fooBits15.size(), size15);
	fooInt = foo15->GetInt();							EXPECT_EQ(fooInt, init);
	fooDouble = foo15->GetDouble();						EXPECT_EQ(fooDouble, (double)init);
	delete foo15;
}

TEST(AssigmentOperator, IntAssignemnt) {
	int t1 = 52; int t2 = 2674; int t3 = 1324; int t4 = 2341;
	NBitInt<32> s;
	s = t1;			EXPECT_EQ(s.GetInt(), t1);
	s = t2;			EXPECT_EQ(s.GetInt(), t2);
	s = t3;			EXPECT_EQ(s.GetInt(), t3);
	s = t4;			EXPECT_EQ(s.GetInt(), t4);
}

TEST(AdditionTest, Tests1) {
	const int width = 32;
	int m1 = 12; int m2 = 3780; int m3 = 71;
	NBitInt<width> data;						EXPECT_EQ(data.GetInt(), 0) << "Basic initialisation failing";
	data = data + m1;							EXPECT_EQ(data.GetInt(), m1) << "NBit + int failing";
	data = m2 + data;							EXPECT_EQ(data.GetInt(), m1 + m2) << "int + NBit failing, bitset: " << data.GetBitset();
	NBitInt<width> data2(m3);					EXPECT_EQ(data2.GetInt(), m3) << "int initialization failing";
	data = data + data2;						EXPECT_EQ(data.GetInt(), m1 + m2 + m3) << "NBit + NBit failing";
}

TEST(AdditionTest, Tests2) {
	const int width = 57;
	int m1 = 67534; int m2 = 6590986; int m3 = 475488;
	NBitInt<width> data;						EXPECT_EQ(data.GetInt(), 0) << "Basic initialisation failing";
	data = data + m1;							EXPECT_EQ(data.GetInt(), m1) << "NBit + int failing";
	data = m2 + data;							EXPECT_EQ(data.GetInt(), m1 + m2) << "int + NBit failing";
	NBitInt<width> data2(m3);					EXPECT_EQ(data2.GetInt(), m3) << "int initialization failing";
	data = data + data2;						EXPECT_EQ(data.GetInt(), m1 + m2 + m3) << "NBit + NBit failing";
}

TEST(SubtractionTest, Tests1) {
	const int width = 35;
	int m0 = 672341; int m1 = 23452; int m2 = 203874523; int m3 = 71;
	NBitInt<width> data(m0);					ASSERT_EQ(data.GetInt(), (__int64)m0) << "Basic initialisation failing, bitset: " << data.GetBitset();
	data = data - m1;							EXPECT_EQ(data.GetInt(), (__int64)m0 - (__int64)m1) << "NBit + int failing, bitset: " << data.GetBitset();
	data = m2 - data;							EXPECT_EQ(data.GetInt(), (__int64)m2 - (__int64)m0 + (__int64)m1) << "int + NBit failing, bitset: " << data.GetBitset();
	NBitInt<width> data2(m3);					EXPECT_EQ(data2.GetInt(), (__int64)m3) << "int initialization failing";
	data = data - data2;						EXPECT_EQ(data.GetInt(), (__int64)m2 - (__int64)m0 + (__int64)m1 - (__int64)m3) << "NBit + NBit failing";
}

TEST(SubtractionTest, Tests2) {
	const int width = 715;
	int m0 = 203874523; int m1 = 672341; int m2 = 253874523; int m3 = 71;
	NBitInt<width> data(m0);					ASSERT_EQ(data.GetDouble(), (double)m0) << "Basic initialisation failing, bitset: " << data.GetBitset();
	data = data - m1;							EXPECT_EQ(data.GetDouble(), (double)m0 - (double)m1) << "NBit + int failing, bitset: " << data.GetBitset();
	data = m2 - data;							EXPECT_EQ(data.GetDouble(), (double)m2 - (double)m0 + (__int64)m1) << "int + NBit failing, bitset: " << data.GetBitset();
	NBitInt<width> data2(m3);					EXPECT_EQ(data2.GetDouble(), (double)m3) << "int initialization failing";
	data = data - data2;						EXPECT_EQ(data.GetDouble(), (double)m2 - (double)m0 + (double)m1 - (double)m3) << "NBit + NBit failing";
}

TEST(MultiplicationTest, ZeroMultiplication) {
	const int width = 10;
	int m0 = 4;
	NBitInt<width> data;						ASSERT_EQ(data.GetInt(), 0) << "Basic initialisation failing";
	data = data * m0;							EXPECT_EQ(data.GetInt(), 0) << "Multiplication by zero failing when for NBit * int";
	data = data * data;							EXPECT_EQ(data.GetInt(), 0) << "Multiplication by zero failing when for NBit * NBit";
	data = m0 * data;							EXPECT_EQ(data.GetInt(), 0) << "Multiplication by zero failing when for int * NBit";
}

TEST(MultiplicationTest, Tests1) {
	const int width = 10;
	int m0 = 7; int m1 = 84; int m2 = 23; int m3 = 71;
	NBitInt<width> data(m0);					ASSERT_EQ(data.GetInt(), m0) << "Basic initialisation failing";
	data = data * m1;							EXPECT_EQ(data.GetInt(), m1 * m0) << "Multiplication failing for NBit * int";
	data = m2;
	data = data * data;							EXPECT_EQ(data.GetInt(), m2 * m2) << "Multiplication failing for NBit * NBit";
	data = m3;
	data = m0 * data;							EXPECT_EQ(data.GetInt(), m0 * m3) << "Multiplication failing for int * NBit";
}

TEST(MultiplicationTest, Tests2) {
	const int width = 64;
	int m0 = 2147483646; int m1 = m0 - 1; int m2 = m1 - 1; int m3 = m2 - 1;
	NBitInt<width> data(m0);					ASSERT_EQ(data.GetDouble(), (double)m0) << "Basic initialisation failing";
	data = data * m1;							EXPECT_EQ(data.GetDouble(), (double)m1 * (double)m0) << "Multiplication failing for NBit * int";
	data = m2;
	data = data * data;							EXPECT_EQ(data.GetDouble(), (double)m2 * (double)m2) << "Multiplication failing for NBit * NBit";
	data = m3;
	data = m0 * data;							EXPECT_EQ(data.GetDouble(), (double)m0 * (double)m3) << "Multiplication failing for int * NBit";
}

TEST(DivisionTest, ZeroDivision) {
	const char* expError = "Can't divide by zero even in made up data types";
	const int width = 10;
	NBitInt<width> data(1);
	NBitInt<width> zero;
	NBitInt<width> out;
	try {
		out = data / zero;
		FAIL() << "Failure expected for NBit / NBit=0";
	}
	catch (std::exception& ex) {
		EXPECT_STREQ(ex.what(), expError) << "Incorrect error for NBit / NBit=0: " << ex.what();
	}
	catch (...) {
		FAIL() << "std::exception expected for NBit / NBit=0";
	}
	try {
		out = data / 0;
		FAIL() << "Failure expected for NBit / int=0";
	}
	catch (std::exception& ex) {
		EXPECT_STREQ(ex.what(), expError) << "Incorrect error for NBit / int=0";
	}
	catch (...) {
		FAIL() << "std::exception expected for NBit / int=0";
	}
	try {
		out = 1 / zero;
		FAIL() << "Failure expected for int / NBit=0";
	}
	catch (std::exception& ex) {
		EXPECT_STREQ(ex.what(), expError) << "Incorrect error for int / NBit=0";
	}
	catch (...) {
		FAIL() << "std::exception expected for int / NBit=0";
	}
}

TEST(DivisionTest, SpecialCases) {
	// Should test if the special cases work, won't see if it actually takes that route though
	NBitInt<9> zero;
	NBitInt<9> data(123);
	NBitInt<9> one(1);
	NBitInt<9> testoutput;
	testoutput = zero / 123;
	EXPECT_EQ(testoutput.GetBitset(), zero.GetBitset()) << "Division of zero should always give zero";
	testoutput = data / 123;
	EXPECT_EQ(testoutput.GetBitset(), one.GetBitset()) << "Division by the same number should return 1";
	testoutput = 123 / one;
	EXPECT_EQ(testoutput.GetBitset(), data.GetBitset()) << "Division by one should return the numerator";
	testoutput = one / data;
	EXPECT_EQ(testoutput.GetBitset(), zero.GetBitset()) << "Division by a number greater than the numerator should return zero";
}

TEST(DivisionTest, EvenFactors) {
	const int width = 10;
	int m0 = 54; int m1 = 6; int m2 = 81; int m3 = 3;
	NBitInt<width> data(m0);
	data = data / m1;							EXPECT_EQ(data.GetInt(), m0 / m1) << "Division failing for NBit / int";
	data = m2 / data;							EXPECT_EQ(data.GetInt(), m2 / (m0 / m1)) << "Division failing for int / NBit";
	NBitInt<width> data2(m3);
	data = data / data2;						EXPECT_EQ(data.GetInt(), (m2 / (m0 / m1)) / m3) << "Division failing for int / NBit";
}

TEST(DivisionTest, UnevenFactors) {
	const int width = 123;
	int m0 = 13523452; int m1 = 23511; int m2 = 2457232; int m3 = 3;
	NBitInt<width> data(m0);
	data = data / m1;							EXPECT_EQ(data.GetInt(), m0 / m1) << "Uneven division failing for NBit / int";
	data = m2 / data;							EXPECT_EQ(data.GetInt(), m2 / (m0 / m1)) << "Uneven division failing for int / NBit";
	NBitInt<width> data2(m3);
	data = data / data2;						EXPECT_EQ(data.GetInt(), (m2 / (m0 / m1)) / m3) << "Uneven division failing for int / NBit";
}

TEST(ModuloTest, ZeroDivision) {
	const char* expError = "Can't divide by zero even in made up data types";
	const int width = 10;
	NBitInt<width> data(1);
	NBitInt<width> zero;
	NBitInt<width> out;
	try {
		out = data % zero;
		FAIL() << "Failure expected for NBit % NBit=0";
	}
	catch (std::exception& ex) {
		EXPECT_STREQ(ex.what(), expError) << "Incorrect error for NBit % NBit=0: " << ex.what();
	}
	catch (...) {
		FAIL() << "std::exception expected for NBit % NBit=0";
	}
	try {
		out = data % 0;
		FAIL() << "Failure expected for NBit % int=0";
	}
	catch (std::exception& ex) {
		EXPECT_STREQ(ex.what(), expError) << "Incorrect error for NBit % int=0";
	}
	catch (...) {
		FAIL() << "std::exception expected for NBit % int=0";
	}
	try {
		out = 1 % zero;
		FAIL() << "Failure expected for int % NBit=0";
	}
	catch (std::exception& ex) {
		EXPECT_STREQ(ex.what(), expError) << "Incorrect error for int % NBit=0";
	}
	catch (...) {
		FAIL() << "std::exception expected for int % NBit=0";
	}
}

TEST(ModuloTest, LHSSmaller) {
	const int width = 32;
	int m0 = 124; int m1 = 351; int m2 = 3451; int m3 = 123625;
	NBitInt<width> data(m0);
	NBitInt<width> data2(m3);
	NBitInt<width> out;
	out = data % m1;							EXPECT_EQ(out.GetInt(), m0 % m1) << "Modulo failing for NBit % int where LHS larger";
	out = m2 % data2;							EXPECT_EQ(out.GetInt(), m2 % m3) << "Modulo failing for int % NBit where LHS larger";
	out = data % data2;							EXPECT_EQ(out.GetInt(), m0 % m3) << "Modulo failing for NBit % NBit where LHS larger";
}

TEST(ModuloTest, RHSSmaller) {
	const int width = 32;
	int m0 = 65874; int m1 = 351; int m2 = 1233451; int m3 = 5467;
	NBitInt<width> data(m0);
	NBitInt<width> data2(m3);
	NBitInt<width> out;
	out = data % m1;							EXPECT_EQ(out.GetInt(), m0 % m1) << "Modulo failing for NBit % int where LHS larger";
	out = m2 % data2;							EXPECT_EQ(out.GetInt(), m2 % m3) << "Modulo failing for int % NBit where LHS larger";
	out = data % data2;							EXPECT_EQ(out.GetInt(), m0 % m3) << "Modulo failing for NBit % NBit where LHS larger";
}

TEST(ModuloTest, EvenMultiples) {
	const int width = 47;
	int m0 = 574035; int m1 = 2343; int m2 = 82005; int m3 = 5467;
	NBitInt<width> data(m0);
	NBitInt<width> data2(m3);
	NBitInt<width> out;
	out = data % m1;							EXPECT_EQ(out.GetInt(), 0) << "Modulo failing for NBit % int where LHS larger";
	out = m2 % data2;							EXPECT_EQ(out.GetInt(), 0) << "Modulo failing for int % NBit where LHS larger";
	out = data % data2;							EXPECT_EQ(out.GetInt(), 0) << "Modulo failing for NBit % NBit where LHS larger";
}

// I don't anticipate these compound operators showing any issues not present in the normal operators
// These tests are just checks that the operators themselves are working
TEST(CompoundOperators, Addition) {
	const int width = 32;
	int m1 = 12; int m3 = 3780;
	NBitInt<width> data;					EXPECT_EQ(data.GetInt(), 0) << "Basic initialisation failing";
	data += m1;								EXPECT_EQ(data.GetInt(), m1) << "NBit += int failing";
	NBitInt<width> data2(m3);				EXPECT_EQ(data2.GetInt(), m3) << "int initialization failing";
	data += data2;							EXPECT_EQ(data.GetInt(), m1 + m3) << "NBit += NBit failing";
}

TEST(CompoundOperators, Subtraction) {
	const int width = 32;
	int m0 = 87964; int m1 = 12; int m3 = 3780;
	NBitInt<width> data(m0);				EXPECT_EQ(data.GetInt(), m0) << "Basic initialisation failing";
	data -= m1;								EXPECT_EQ(data.GetInt(), m0 - m1) << "NBit -= int failing";
	NBitInt<width> data2(m3);				EXPECT_EQ(data2.GetInt(), m3) << "int initialization failing";
	data -= data2;							EXPECT_EQ(data.GetInt(), m0 - m1 - m3) << "NBit -= NBit failing";
}

TEST(CompoundOperators, Multiplication) {
	const int width = 41;
	int m0 = 5; int m1 = 12; int m3 = 3780;
	NBitInt<width> data(m0);				EXPECT_EQ(data.GetInt(), m0) << "Basic initialisation failing";
	data *= m1;								EXPECT_EQ(data.GetInt(), m0 * m1) << "NBit *= int failing";
	NBitInt<width> data2(m3);				EXPECT_EQ(data2.GetInt(), m3) << "int initialization failing";
	data *= data2;							EXPECT_EQ(data.GetInt(), m0 * m1 * m3) << "NBit *= NBit failing";
}

TEST(CompoundOperators, Division) {
	const int width = 41;
	int m0 = 3255; int m1 = 5; int m3 = 17;
	NBitInt<width> data(m0);				EXPECT_EQ(data.GetInt(), m0) << "Basic initialisation failing";
	data /= m1;								EXPECT_EQ(data.GetInt(), m0 / m1) << "NBit *= int failing";
	NBitInt<width> data2(m3);				EXPECT_EQ(data2.GetInt(), m3) << "int initialization failing";
	data /= data2;							EXPECT_EQ(data.GetInt(), (m0 / m1) / m3) << "NBit *= NBit failing";
}

int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}