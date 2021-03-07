#include "NBitInt.h"
template <int N>
NBitInt<N>::NBitInt(std::bitset<N> i)
{
	num = i;
}

template <int N>
NBitInt<N>::NBitInt(int i)
{
	num = Int2Bits(i);
}

template <int N>
inline NBitInt<N>& NBitInt<N>::operator=(int i)
{
	this->num = Int2Bits(i);
	return *this;
}

template <int N>
std::bitset<N> NBitInt<N>::Int2Bits(int inp)
{
	std::bitset<N> out;
	int currNum = inp;
	int remainder = 0;
	int i = 0;
	while (currNum != 0)
	{
		if (i == N)
			i = 0;
		remainder = currNum % 2;
		currNum = currNum / 2;
		if (remainder == 1)
			out.set(i);
		i++;
	}
	return out;
}

template <int N>
__int64 NBitInt<N>::GetInt()
{
	__int64 out = 0;
	__int64 twos = 1;
	for (int i = 0; i < N; i++)
	{
		out += num[i] * twos;
		twos *= 2;
	}
	return out;
}

template <int N>
double NBitInt<N>::GetDouble()
{
	double out = 0.0;
	double twos = 1.0;
	for (int i = 0; i < N; i++)
	{
		out += num[i] * twos;
		twos *= 2.0;
	}
	return out;
}

template <int N>
std::vector<int> NBitInt<N>::OutputVector()
{
	std::vector<int> digits;
	NBitInt<N> holder = this;
	NBitInt<N> temp;
	if (holder.GetInt() == 0)
	{
		digits.push_back(0);
		return digits;
	}
	while (holder.GetInt() != 0)
	{
		temp = holder % 10;
		digits.push_back(temp.GetInt());
		holder = holder / 10;
	}
	return digits;
}

template<int N>
std::bitset<N> NBitInt<N>::AddImpl(std::bitset<N> aBits, std::bitset<N> bBits)
{
	std::bitset<N> cBits;
	cBits.reset();
	int carry = 0;
	int sum;

	for (int i = 0; i < N; i++)
	{
		sum = aBits[i] + bBits[i] + carry;
		switch (sum)
		{
		case 0:
			carry = 0;
			break;
		case 1:
			cBits.set(i);
			carry = 0;
			break;
		case 2:
			carry = 1;
			break;
		default:
			cBits.set(i);
			carry = 1;
		}
	}

	return cBits;
}

template <int N>
std::bitset<N> NBitInt<N>::SubImpl(std::bitset<N> aBits, std::bitset<N> bBits)
{
	std::bitset<N> cBits;
	cBits.reset();
	int sum;
	int borrow = 0;
	for (int i = 0; i < N; i++)
	{
		sum = aBits[i] - bBits[i] - borrow;
		switch (sum)
		{
		case 1:
			cBits.set(i);
		case 0:
			borrow = 0;
			break;
		case -1:
			cBits.set(i);
		case -2:
			borrow = 1;
			break;
		default:
			break;
		}
	}
	return cBits;
}

template <int N>
std::bitset<N> NBitInt<N>::MultImpl(std::bitset<N> aBits, std::bitset<N> bBits)
{
	std::bitset<N> cBits;
	cBits.reset();
	for (int shift = 0; shift < N; shift++)
	{
		if (bBits[shift] == 1)
		{
			cBits = AddImpl(cBits, aBits);
		}
		aBits <<= 1;
	}
	return cBits;
}

template<int N>
std::bitset<N> NBitInt<N>::DivImpl(std::bitset<N> aBits, std::bitset<N> bBits)
{
	int lastABit = LastActivatedBit<N>(aBits);
	int lastBBit = LastActivatedBit<N>(bBits);
	std::bitset<N> tBits;
	tBits.reset();
	// Cover a bunch of special cases
	if (lastABit == -1 || lastABit < lastBBit)
		return tBits;
	if (lastBBit == -1)
		throw std::exception("Can't divide by zero even in made up data types");
	if (lastBBit == 0)
		return aBits;
	if (aBits == bBits)
		return tBits.set(0);

	std::bitset<N> numer;
	std::bitset<N> denom;

	// When doing this operation, we need to check if a bitset represents a number less than zero after a subtraction has taken place
	// This is done by checking if the largest activated bit is on the unsubracted side, an overflow would result
	// in the opposite
	int bitDiff = lastABit - lastBBit;
	numer = aBits;
	denom = bBits << bitDiff;
	for (int i = bitDiff; i >= 0; i--)
	{
		int sigBit = LastActivatedBit(numer);
		std::bitset<N> temptBits = SubImpl(numer, denom);
		// As above, this checks if t>=0 in a rough way
		if (sigBit >= LastActivatedBit(temptBits))
		{
			numer = temptBits;
			tBits.set(0);

		}
		tBits <<= 1;
		denom >>= 1;
	}
	tBits >>= 1;

	return tBits;
}

template<int N>
int NBitInt<N>::LastBit()
{
	for (int i = N - 1; i >= 0; i--)
	{
		if (num[i] != 0)
			return i;
	}
	return -1;
}

template<int N>
inline int LastActivatedBit(std::bitset<N> Bits)
{
	for (int i = N - 1; i >= 0; i--)
	{
		if (Bits[i] != 0)
			return i;
	}
	return -1;
}

template <int N>
NBitInt<N> NBitInt<N>::pow(int p)
{
	NBitInt b(1);
	for (int q = 0; q < p; q++)
	{
		b = b * *this;
	}

	return b;
}

// This assume a,b are positive. If not something new will have to be added, but key for now is all
// of this class assumes these values are positive
template <int N>
std::bitset<N> NBitInt<N>::ModImpl(std::bitset<N> aBits, std::bitset<N> bBits)
{
	// Find floor value of the result of the division
	std::bitset<N> div = DivImpl(aBits, bBits);
	// Use this to find the largest multiple less than lhs
	std::bitset<N> mult = MultImpl(div, bBits);
	// From the largest factor, get the remainder from division
	std::bitset<N> sub = SubImpl(aBits, mult);
	return sub;
}