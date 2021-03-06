#pragma once

#include <bitset>
#include <vector>

// Doesn't support negative numbers currently. I think the operations for that are the same (due to
// overflowing and such) so would only need to extend the basic output to include signing)
template <int N>
class NBitInt
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

	friend NBitInt operator- (NBitInt a, int b);
	friend NBitInt operator- (int a, NBitInt b);
	friend NBitInt operator- (NBitInt a, NBitInt b);

	friend NBitInt operator* (NBitInt a, int b);
	friend NBitInt operator* (int a, NBitInt b);
	friend NBitInt operator* (NBitInt a, NBitInt b);

	friend NBitInt operator/ (NBitInt a, int b);
	friend NBitInt operator/ (int a, NBitInt b);
	friend NBitInt operator/ (NBitInt a, NBitInt b);

	friend NBitInt operator% (NBitInt a, int b);
	friend NBitInt operator% (int a, NBitInt b);
	friend NBitInt operator% (NBitInt a, NBitInt b);
	// Additional operators could be added eventually
};

template <int N>
int LastActivatedBit(std::bitset<N> Bits);

#include "NBitInt.ipp"