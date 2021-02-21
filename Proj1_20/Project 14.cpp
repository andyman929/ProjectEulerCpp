/*
The following iterative sequence is defined for the set of positive integers:

n -> n/2 (n is even)
n -> 3n + 1 (n is odd)

Using the rule above and starting with 13, we generate the following sequence:

13 -> 40 -> 20 -> 10 -> 5 -> 16 -> 8 -> 4 -> 2 -> 1
It can be seen that this sequence (starting at 13 and finishing at 1) contains 10 terms. Although it has not been proved yet (Collatz Problem), it is thought that all starting numbers finish at 1.

Which starting number, under one million, produces the longest chain?

NOTE: Once the chain starts the terms are allowed to go above one million.
*/

#include <vector>
#include "pch.h"

using namespace std;

// Creating a third method that, instead of storing the values from each chain I'll flag the later values as not needed and not calculate the chain.
// Not sure if it'll be more efficient but might be nicer to look at
void ProjectsObj::Project14CalcBM(int lim)
{
	Proj14chainNeeded.resize(lim + 1); // +1 so that I can index with the actual numbers, just being lazy

	fill(Proj14chainNeeded.begin(), Proj14chainNeeded.end(), true);
	Proj14chainNeeded[1] = false;

	int terms = 0;
	int maxTerms = 0;
	int maxIndex = 0;

	for (int i = lim; i > 1; i--)
	{
		if (!Proj14chainNeeded[i])
			continue;
		terms = Project14CountCollatz(i);
		if (terms > maxTerms)
		{
			maxTerms = terms;
			maxIndex = i;
		}
	}
	cout << "Number under " << lim << " with the longest chain: " << maxIndex << ", " << maxTerms << "steps\n";
}
int ProjectsObj::Project14CountCollatzBM(int inp, int lim)
{
	__int64 val = inp;
	int count = 0;
	while (val > 1)
	{
		count++;
		if (val % 2 == 0)
		{
			val /= 2;
		}
		else
		{
			val = 3 * val + 1;
		}
		if (val <= lim)
		{
			Proj14chainNeeded[val] = false;
		}

	}
	return count;
}

// Method that involves storing the values for the chains as they are calculated, removes recalculation of every chain.
// Final step is removing the calculation of an unwanted chain.
void ProjectsObj::Project14Calc(int lim)
{
	int chain;
	int maxChain = 0;
	int maxIndex = 0;

	Proj14chainLengths.resize(lim + 1); // +1 so that I can index with the actual numbers, just being lazy

	fill(Proj14chainLengths.begin(), Proj14chainLengths.end(), -1);
	Proj14chainLengths[1] = 0;
	for (__int64 i = lim; i > 1; i--)
	{
		chain = Project14Cursed(lim, i);
		if (chain > maxChain)
		{
			maxChain = chain;
			maxIndex = i;
		}
	}
	cout << "Number under " << lim << " with the longest chain: " << maxIndex << ", " << maxChain << " steps\n";
	Proj14chainLengths.clear();
}

// Recursive function to implement the above
int ProjectsObj::Project14Cursed(int lim, __int64 val)
{
	if (val <= lim)
		if (Proj14chainLengths[val] != -1)
			return Proj14chainLengths[val];
	__int64 innerVal = val;
	int chainLength;
	if (val % 2 == 0)
		innerVal /= 2;
	else
		innerVal = 3 * innerVal + 1;
	chainLength = Project14Cursed(lim, innerVal) + 1;
	if (val <= lim)
		Proj14chainLengths[val] = chainLength;
	return chainLength;
}

// Brute force method
void ProjectsObj::Project14CalcBF(int lim)
{
	int terms = 0;
	int maxTerms = 0;
	int maxIndex = 0;

	for (int i = 1; i <= lim; i++)
	{
		terms = Project14CountCollatz(i);
		if (terms > maxTerms)
		{
			maxTerms = terms;
			maxIndex = i;
		}
	}
	cout << "Number under " << lim << " with the longest chain: " << maxIndex << ", " << maxTerms << "steps\n";
}

int ProjectsObj::Project14CountCollatz(int lim)
{
	__int64 val = lim;
	int count = 0;
	while (val > 1)
	{
		count++;
		if (val % 2 == 0)
		{
			val /= 2;
		}
		else
		{
			val = 3 * val + 1;
		}
	}
	//cout << count;
	return count;
}

void ProjectsObj::Project14PrintCollatz(int lim)
{
	__int64 val = lim;
	while (val > 1)
	{
		cout << val << " -> ";
		if (val % 2 == 0)
		{
			val /= 2;
		}
		else
		{
			val = 3 * val + 1;
		}
	}
	cout << val << "\n";
}