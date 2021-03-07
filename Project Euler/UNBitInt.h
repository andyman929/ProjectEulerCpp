#pragma once

#include <bitset>
#include <vector>

// Unsigned integer of N bits
template <int N>
class UNBitInt
{
private:
	std::bitset<N> num;
	std::bitset<N> Int2Bits(int i);
	static std::bitset<N> AddImpl(std::bitset<N> aBits, std::bitset<N> bBits);
	std::bitset<N> SubImpl(std::bitset<N> aBits, std::bitset<N> bBits);
	std::bitset<N> MultImpl(std::bitset<N> aBits, std::bitset<N> bBits);
	std::bitset<N> DivImpl(std::bitset<N> aBits, std::bitset<N> bBits);
	std::bitset<N> ModImpl(std::bitset<N> aBits, std::bitset<N> bBits);
	int LastBit();

public:
	UNBitInt() {
		num.reset();
	};
	UNBitInt(int i);
	UNBitInt(std::bitset<N> i);
	~UNBitInt() {};
	__int64 GetInt();
	double GetDouble();
	std::bitset<N> GetBitset() {
		return num;
	};
	UNBitInt<N>& operator=(int i);

	UNBitInt pow(int p);

	std::vector<int> OutputVector();

	// Basic operators
	friend UNBitInt operator+ (UNBitInt& a, int& b) {
		std::bitset<N> outBits = AddImpl(a.GetBitset(), a.Int2Bits(b));
		return UNBitInt<N>(outBits);
	};
	friend UNBitInt operator+ (int& a, UNBitInt& b) {
		std::bitset<N> outBits = AddImpl(b.GetBitset(), b.Int2Bits(a));
		return UNBitInt<N>(outBits);
	};
	friend UNBitInt operator+ (UNBitInt a, UNBitInt b) {
		std::bitset<N> outBits = AddImpl(a.GetBitset(), b.GetBitset());
		return UNBitInt<N>(outBits);
	};

	friend UNBitInt operator- (UNBitInt a, int b) {
		std::bitset<N> outBits = a.SubImpl(a.GetBitset(), a.Int2Bits(b));
		return UNBitInt<N>(outBits);
	};
	friend UNBitInt operator- (int a, UNBitInt b) {
		std::bitset<N> outBits = b.SubImpl(b.Int2Bits(a), b.GetBitset());
		return UNBitInt<N>(outBits);
	};
	friend UNBitInt operator- (UNBitInt a, UNBitInt b) {
		std::bitset<N> outBits = a.SubImpl(a.GetBitset(), b.GetBitset());
		return UNBitInt<N>(outBits);
	};

	friend UNBitInt operator* (UNBitInt a, int b) {
		std::bitset<N> outBits = a.MultImpl(a.GetBitset(), a.Int2Bits(b));
		return UNBitInt<N>(outBits);
	};
	friend UNBitInt operator* (int a, UNBitInt b) {
		std::bitset<N> outBits = b.MultImpl(b.Int2Bits(a), b.GetBitset());
		return UNBitInt<N>(outBits);
	};
	friend UNBitInt operator* (UNBitInt a, UNBitInt b) {
		std::bitset<N> outBits = a.MultImpl(a.GetBitset(), b.GetBitset());
		return UNBitInt<N>(outBits);
	};

	friend UNBitInt operator/ (UNBitInt a, int b) {
		std::bitset<N> bits = a.DivImpl(a.GetBitset(), a.Int2Bits(b));
		return UNBitInt<N>(bits);
	};
	friend UNBitInt operator/ (int a, UNBitInt b) {
		std::bitset<N> bits = b.DivImpl(b.Int2Bits(a), b.GetBitset());
		return UNBitInt<N>(bits);
	};
	friend UNBitInt operator/ (UNBitInt a, UNBitInt b) {
		std::bitset<N> bits = a.DivImpl(a.GetBitset(), b.GetBitset());
		return UNBitInt<N>(bits);
	};

	friend UNBitInt operator% (UNBitInt a, int b) {
		std::bitset<N> aBits = a.GetBitset();
		std::bitset<N> bBits = a.Int2Bits(b);
		std::bitset<N> out = a.ModImpl(aBits, bBits);
		return UNBitInt<N>(out);
	};
	friend UNBitInt operator% (int a, UNBitInt b) {
		std::bitset<N> aBits = b.Int2Bits(a);
		std::bitset<N> bBits = b.GetBitset();
		std::bitset<N> out = b.ModImpl(aBits, bBits);
		return UNBitInt<N>(out);
	};
	friend UNBitInt operator% (UNBitInt a, UNBitInt b) {
		std::bitset<N> aBits = a.GetBitset();
		std::bitset<N> bBits = b.GetBitset();
		std::bitset<N> out = a.ModImpl(aBits, bBits);
		return UNBitInt<N>(out);
	};

	// Compound operators
	UNBitInt operator+= (int a) {
		num = AddImpl(num, Int2Bits(a));
		return *this;
	};
	UNBitInt operator+= (UNBitInt a) {
		num = AddImpl(num, a.GetBitset());
		return *this;
	};

	UNBitInt operator-= (int a) {
		num = SubImpl(num, Int2Bits(a));
		return *this;
	};
	UNBitInt operator-= (UNBitInt a) {
		num = SubImpl(num, a.GetBitset());
		return *this;
	};

	UNBitInt operator*= (int a) {
		num = MultImpl(num, Int2Bits(a));
		return *this;
	};
	UNBitInt operator*= (UNBitInt a) {
		num = MultImpl(num, a.GetBitset());
		return *this;
	};

	UNBitInt operator/= (int a) {
		num = DivImpl(num, Int2Bits(a));
		return *this;
	};
	UNBitInt operator/= (UNBitInt a) {
		num = DivImpl(num, a.GetBitset());
		return *this;
	};

	// Additional operators could be added eventually
};

template <int N>
int LastActivatedBit(std::bitset<N> Bits);

#include "UNBitInt.ipp"