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
	if (inp == 0)
		return out;
	int currNum = inp;
	int remainder = 0;
	int i = 0;
	if (currNum < 0)
		currNum = -currNum;
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
	if (inp < 0)
	{
		std::bitset<N> temp;
		out = SubImpl(temp, out);
	}
	return out;
}

template <int N>
__int64 NBitInt<N>::GetInt()
{
	__int64 out = 0;
	__int64 twos = 1;
	for (int i = 0; i < N - 1; i++)
	{
		out += num[i] * twos;
		twos *= 2;
	}
	out -= num[N - 1] * twos;
	return out;
}

template <int N>
double NBitInt<N>::GetDouble()
{
	double out = 0.0;
	double twos = 1.0;
	for (int i = 0; i < N - 1; i++)
	{
		out += num[i] * twos;
		twos *= 2.0;
	}
	out -= num[N - 1] * twos;
	return out;
}

template <int N>
std::vector<int> NBitInt<N>::OutputVector()
{
	std::vector<int> digits;
	std::bitset<N> holder = num;
	std::bitset<N> temp;
	if (holder.none())
	{
		digits.push_back(0);
		return digits;
	}
	// Force the value held to positive so the vector can be output properly
	if (holder[N - 1] == 1)
	{
		holder = SubImpl(0, holder);
	}
	int a = 1;
	while (holder.any())
	{
		temp = ModImpl(holder, 10);
		digits.push_back(Bits2Digit(temp));
		holder = DivImpl(holder, 10);
	}
	return digits;
}

template <int N>
std::string NBitInt<N>::to_string()
{
	if (num.none())
	{
		return "0";
	}
	std::string digits;
	digits.reserve(N);
	std::bitset<N> holder = num;
	std::bitset<N> temp;
	// Force the value held to positive so the vector can be output properly
	if (holder[N - 1] == 1)
	{
		holder = SubImpl(0, holder);
	}
	int a = 1;
	while (holder.any())
	{
		temp = ModImpl(holder, 10);
		digits.insert(0, std::to_string(Bits2Digit(temp)));
		holder = DivImpl(holder, 10);
	}
	return digits;
}

template <int N>
int NBitInt<N>::Bits2Digit(std::bitset<N> Bits)
{
	int out = 0;
	int twos = 1;
	for (int i = 0; i < std::min(N - 1, 4); i++)
	{
		out += Bits[i] * twos;
		twos *= 2;
	}
	return out;
}

template<int N>
std::bitset<N> NBitInt<N>::AddImpl(std::bitset<N> aBits, std::bitset<N> bBits)
{
	if (bBits.none())
		return aBits;
	if (aBits.none())
		return bBits;
	std::bitset<N> cBits;
	int carry = 0;
	int sum;
	int lastB = LastActivatedSBit(bBits);

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
		if (i >= lastB)
		{
			i++;
			while (true)
			{
				if (carry == 0)
				{
					for (; i < N; i++)
					{
						cBits[i] = aBits[i];
					}
					break;
				}
				else if (i < N)
				{
					for (; i < N; i++)
					{
						if (aBits[i] == 0)
						{
							carry = 0;
							cBits[i] = 1;
							i++;
							break;
						}
					}
				}
				else break;
			}
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
	int lastB = LastActivatedSBit(bBits);
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
		if (i >= lastB)
		{
			if (borrow == 0)
			{
				i++;
				for (; i < N; i++)
				{
					cBits[i] = aBits[i];
				}
			}
		}
	}
	return cBits;
}

template <int N>
std::bitset<N> NBitInt<N>::MultImpl(std::bitset<N> aBits, std::bitset<N> bBits)
{
	bool aNeg = aBits[N - 1] == 1;
	if (aNeg) aBits = SubImpl(0, aBits);
	bool bNeg = bBits[N - 1] == 1;
	if (bNeg) bBits = SubImpl(0, bBits);
	bool cNeg = aNeg ^ bNeg;
	std::bitset<N> cBits;
	cBits.reset();
	int lastB = LastActivatedSBit(bBits);
	for (int shift = 0; shift <= lastB; shift++)
	{
		if (bBits[shift] == 1)
		{
			cBits = AddImpl(cBits, aBits);
		}
		aBits <<= 1;
	}
	if (cNeg)
		return SubImpl(0, cBits);
	return cBits;
}

template<int N>
std::bitset<N> NBitInt<N>::DivImpl(std::bitset<N> aBits, std::bitset<N> bBits)
{
	// Check if the inputs are negative, if they are then swap to positive, fix the result before output
	bool aNeg = aBits[N - 1] == 1;
	if (aNeg)
		aBits = SubImpl(0, aBits);
	bool bNeg = bBits[N - 1] == 1;
	if (bNeg)
		bBits = SubImpl(0, bBits);
	bool tNeg = aNeg ^ bNeg;
	int lastABit = LastActivatedSBit<N>(aBits);
	int lastBBit = LastActivatedSBit<N>(bBits);	
	std::bitset<N> tBits;
	tBits.reset();
	// Cover a bunch of special cases
	if (lastABit == -1 || lastABit < lastBBit)
		return tBits;
	if (lastBBit == -1)
		throw std::exception("Can't divide by zero even in made up data types");
	if (lastBBit == 0)
	{
		if (tNeg)
			return SubImpl(0, aBits);
		return aBits;
	}
	if (aBits == bBits)
	{
		tBits.set(0);
		if (tNeg)
			tBits = SubImpl(0, tBits);
		return tBits;
	}

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
		int sigBit = LastActivatedSBit(numer);
		std::bitset<N> temptBits = SubImpl(numer, denom);
		// As above, this checks if t>=0 in a rough way
		if (sigBit >= LastActivatedSBit(temptBits))
		{
			numer = temptBits;
			tBits.set(0);

		}
		tBits <<= 1;
		denom >>= 1;
	}
	tBits >>= 1;

	if (tNeg)
		return SubImpl(0, tBits);
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
inline int LastActivatedSBit(std::bitset<N> Bits)
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
	std::bitset<N> a = num;
	std::bitset<N> b(1);
	std::bitset<N> pbits = Int2Bits(p);
	int lastP = LastActivatedSBit(pbits);
	for (int i = 0; i <= lastP; i++)
	{
		if (pbits[i] == 1)
		{
			b = MultImpl(b, a);
		}
		a = MultImpl(a, a);
	}
	return b;
}

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

template <int N>
bool NBitInt<N>::BinaryPalindrome()
{
	int lBit = this->LastBit();
	if (lBit == -1)
		return true;

	int lower = 0;
	int upper = lBit;

	while (lower < upper)
	{
		if (num[lower] != num[upper])
			return false;
		++lower;
		--upper;
	}
	return true;
}