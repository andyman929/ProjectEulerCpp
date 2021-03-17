/*
Special subset sums: meta-testing
*/

#include "pch_euler.h"

// namespace to hide these functions from other classes just in case
namespace n106 {
	int f(int a)
	{
		int out = 1;
		while (a > 1)
			out *= a--;
		return out;

	}

	int AchooseB(int A, int B)
	{
		return f(A) / (f(B) * f(A - B));
	}
}

void ProjectsObj::Project106Calc(const int sz)
{
    // Count all non-empty subset pairs sizes
	int setCount = 0;
	// Look at smaller set first to remove repitition
	for (int i = 1; i <= sz - 1; i++)
	{
		// There are sz choose i ways to pick this first element
		for (int j = i + 1; j <= sz - i; j++)
		{
			setCount += n106::AchooseB(sz, i) * n106::AchooseB(sz - i, j);
		}
	}
	// also don't need to check pairs of subsets size 1
	setCount += (sz * (sz - 1)) / 2;

	// Include remaining sets
	// The checking of these amounts to finding all possible subsets
	// then check how many of these are Dyck words, i.e. X = {1,2}, Y = {3,4} => XXYY which is a Dyck word
	// X = {2,3}, Y = {1,4} => YXXY
	// This works basically because we can compare the elements in a pairwise way to confirm S(X) < S(Y)
	// Number of Dyck words of length 2i is the ith catalan number
	int setsToCheck = 0;
	for (int i = 2; i <= sz / 2; i++)
	{
		int iiPairs = (n106::AchooseB(sz, i) * n106::AchooseB(sz - i, i)) / 2;
		int iiCatalan = n106::AchooseB(2 * i, i) / (i + 1);
		setCount += iiPairs;
		setsToCheck += (iiPairs - iiCatalan * n106::AchooseB(sz, 2 * i));
	}


	std::cout << "Total special sets subset pairs is: " << setCount << std::endl;
	std::cout << "Total special sets subset pairs to check: " << setsToCheck << std::endl;
}