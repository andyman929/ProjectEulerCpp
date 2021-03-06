#include "pch.h"
#include "NBitInt.h"

TEST(NBitBasicTests, EmptyInitialize) {
	const int size = 64;
	NBitInt<size> foo;
	std::bitset<size> fooBits = foo.GetBitset();
	__int64 fooInt = foo.GetInt();
	double fooDouble = foo.GetDouble();

	EXPECT_EQ(fooBits.size(), 64) << "Size one bitset does not match initialized size";
	EXPECT_EQ(fooInt, 0) << "Integer output does not match expected empty initialized value of 0";
	EXPECT_EQ(fooDouble, 0.0) << "Double output does not match";
}

TEST(NBitBasicTests, SimpleIntInitialize) {
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

TEST(NBitBasicTests, VarySizeAndInput) {
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

TEST(NBitBasicTests, IntAssignemnt) {
	int t1 = 52; int t2 = 2674; int t3 = 1324; int t4 = 2341;
	NBitInt<32> s;
	s.operator=(t1);
	s = t1;			EXPECT_EQ(s.GetInt(), t1);
	s = t2;			EXPECT_EQ(s.GetInt(), t2);
	s = t3;			EXPECT_EQ(s.GetInt(), t3);
	s = t4;			EXPECT_EQ(s.GetInt(), t4);
}
/*
TEST(NBitBasicTests, AdditionTests32) {
	const int width = 32;
	int m1 = 12; int m2 = 3780; int m3 = 71;
	NBitInt<width> data;						EXPECT_EQ(data.GetInt(), 0);
	data = data + m1;							EXPECT_EQ(data.GetInt(), m1);
	data = m2 + data;							EXPECT_EQ(data.GetInt(), m1 + m2);
	NBitInt<width> data2(m3);					EXPECT_EQ(data2.GetInt(), m3);
	data = data + data2;						EXPECT_EQ(data.GetInt(), m1 + m2 + m3);
}

TEST(NBitBasicTests, AdditionTests57) {
	const int width = 57;
	int m1 = 67534; int m2 = 6590986; int m3 = 475488;
	NBitInt<width> data;						EXPECT_EQ(data.GetInt(), 0);
	data = data + m1;							EXPECT_EQ(data.GetInt(), m1);
	data = m2 + data;							EXPECT_EQ(data.GetInt(), m1 + m2);
	NBitInt<width> data2(m3);					EXPECT_EQ(data2.GetInt(), m3);
	data = data + data2;						EXPECT_EQ(data.GetInt(), m1 + m2 + m3);
}
*/
int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}