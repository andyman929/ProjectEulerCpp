#pragma once

#include <bitset>
#include <vector>

// Unsigned integer of N bits
template <int N>
class NBitInt
{
	// Can only output positive integers in vector form
	// TODO: implement a simple function to return the sign
private:
	std::bitset<N> num;
	std::bitset<N> Int2Bits(int i);
	static std::bitset<N> AddImpl(std::bitset<N> aBits, std::bitset<N> bBits);
	std::bitset<N> SubImpl(std::bitset<N> aBits, std::bitset<N> bBits);
	std::bitset<N> MultImpl(std::bitset<N> aBits, std::bitset<N> bBits);
	std::bitset<N> DivImpl(std::bitset<N> aBits, std::bitset<N> bBits);
	std::bitset<N> ModImpl(std::bitset<N> aBits, std::bitset<N> bBits);
	int LastBit();
	int Bits2Digit(std::bitset<N> Bits);

public:
	NBitInt() {
		num.reset();
	};
	NBitInt(int i);
	NBitInt(std::bitset<N> i);
	~NBitInt() {};
	__int64 GetInt();
	double GetDouble();
	std::bitset<N> GetBitset() {
		return num;
	};
	NBitInt<N>& operator=(int i);

	NBitInt pow(int p);

	std::vector<int> OutputVector();

	// Basic operators
	friend NBitInt operator+ (NBitInt& a, int& b) {
		std::bitset<N> outBits = AddImpl(a.GetBitset(), a.Int2Bits(b));
		return NBitInt<N>(outBits);
	};
	friend NBitInt operator+ (int& a, NBitInt& b) {
		std::bitset<N> outBits = AddImpl(b.GetBitset(), b.Int2Bits(a));
		return NBitInt<N>(outBits);
	};
	friend NBitInt operator+ (NBitInt a, NBitInt b) {
		std::bitset<N> outBits = AddImpl(a.GetBitset(), b.GetBitset());
		return NBitInt<N>(outBits);
	};

	friend NBitInt operator- (NBitInt a, int b) {
		std::bitset<N> outBits = a.SubImpl(a.GetBitset(), a.Int2Bits(b));
		return NBitInt<N>(outBits);
	};
	friend NBitInt operator- (int a, NBitInt b) {
		std::bitset<N> outBits = b.SubImpl(b.Int2Bits(a), b.GetBitset());
		return NBitInt<N>(outBits);
	};
	friend NBitInt operator- (NBitInt a, NBitInt b) {
		std::bitset<N> outBits = a.SubImpl(a.GetBitset(), b.GetBitset());
		return NBitInt<N>(outBits);
	};

	friend NBitInt operator* (NBitInt a, int b) {
		std::bitset<N> outBits = a.MultImpl(a.GetBitset(), a.Int2Bits(b));
		return NBitInt<N>(outBits);
	};
	friend NBitInt operator* (int a, NBitInt b) {
		std::bitset<N> outBits = b.MultImpl(b.Int2Bits(a), b.GetBitset());
		return NBitInt<N>(outBits);
	};
	friend NBitInt operator* (NBitInt a, NBitInt b) {
		std::bitset<N> outBits = a.MultImpl(a.GetBitset(), b.GetBitset());
		return NBitInt<N>(outBits);
	};

	friend NBitInt operator/ (NBitInt a, int b) {
		std::bitset<N> bits = a.DivImpl(a.GetBitset(), a.Int2Bits(b));
		return NBitInt<N>(bits);
	};
	friend NBitInt operator/ (int a, NBitInt b) {
		std::bitset<N> bits = b.DivImpl(b.Int2Bits(a), b.GetBitset());
		return NBitInt<N>(bits);
	};
	friend NBitInt operator/ (NBitInt a, NBitInt b) {
		std::bitset<N> bits = a.DivImpl(a.GetBitset(), b.GetBitset());
		return NBitInt<N>(bits);
	};

	friend NBitInt operator% (NBitInt a, int b) {
		std::bitset<N> aBits = a.GetBitset();
		std::bitset<N> bBits = a.Int2Bits(b);
		std::bitset<N> out = a.ModImpl(aBits, bBits);
		return NBitInt<N>(out);
	};
	friend NBitInt operator% (int a, NBitInt b) {
		std::bitset<N> aBits = b.Int2Bits(a);
		std::bitset<N> bBits = b.GetBitset();
		std::bitset<N> out = b.ModImpl(aBits, bBits);
		return NBitInt<N>(out);
	};
	friend NBitInt operator% (NBitInt a, NBitInt b) {
		std::bitset<N> aBits = a.GetBitset();
		std::bitset<N> bBits = b.GetBitset();
		std::bitset<N> out = a.ModImpl(aBits, bBits);
		return NBitInt<N>(out);
	};

	// Compound operators
	NBitInt operator+= (int a) {
		num = AddImpl(num, Int2Bits(a));
		return *this;
	};
	NBitInt operator+= (NBitInt a) {
		num = AddImpl(num, a.GetBitset());
		return *this;
	};

	NBitInt operator-= (int a) {
		num = SubImpl(num, Int2Bits(a));
		return *this;
	};
	NBitInt operator-= (NBitInt a) {
		num = SubImpl(num, a.GetBitset());
		return *this;
	};

	NBitInt operator*= (int a) {
		num = MultImpl(num, Int2Bits(a));
		return *this;
	};
	NBitInt operator*= (NBitInt a) {
		num = MultImpl(num, a.GetBitset());
		return *this;
	};

	NBitInt operator/= (int a) {
		num = DivImpl(num, Int2Bits(a));
		return *this;
	};
	NBitInt operator/= (NBitInt a) {
		num = DivImpl(num, a.GetBitset());
		return *this;
	};

	// Additional operators could be added eventually
};

template <int N>
int LastActivatedSBit(std::bitset<N> Bits);

#include "NBitInt.ipp"