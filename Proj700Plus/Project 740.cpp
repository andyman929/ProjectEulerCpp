/*
Secret santa*2
*/

#include "pch.h"
#include "Projects700.h"

int select_random(const std::multiset<int>& s) {
	int ind = rand() % s.size();
	auto it = s.begin();
	std::advance(it, ind);
	return *it;
};

int factorial(const int n)
{
	int l = n;
	int out = 1;
	while (l > 1)
	{
		out *= l;
		l--;
	}
	return out;
}

void Obj::Project740Calc(const int n)
{
	// More interesting set permutation method
	int wins = 0;
	int permutations = factorial(2*n);
	int validsetcount = 0;
	std::vector<int> hat;
	for (int k = 1; k <= n; k++)
	{
		hat.push_back(k);
		// adapted to use pairs of +-k to make it easier to search for independent permutations
		hat.push_back(-k);
	}
	do {
		bool validset = true;
		// Check if the cards in this permutation have been drawn correctly up to this point
		for (int i = 0; i < hat.size() - 2; i++)
		{
			if (hat[i] == (i / 2)+1 || hat[i] == (-i / 2) - 1)
			{
				validset = false;
				break;
			}
		}
		// Only include these valid sets in the calculation
		if (validset)
		{
			validsetcount++;
			if (hat[hat.size() - 2] != n && hat[hat.size() - 1] != n)
			{
				if (hat[hat.size() - 2] != -n && hat[hat.size() - 1] != -n)
					wins++;
			}
		}
	} while (std::next_permutation(hat.begin(), hat.end()));

	std::cout << std::setprecision(10);
	std::cout << "Fail count: " << (double)wins / (double)validsetcount << std::endl;

	/*		Dumb brute force
	int repeats = 100000000;//INT_MAX;
	int fails = 0;
	int cards = n * 2;
	std::multiset<int> basehat;
	std::multiset<int> hat;
	for (int k = 1; k <= n; k++)
	{
		basehat.insert(k);
		basehat.insert(k);
	}

	for (int k = 0; k < repeats; k++)
	{
		hat = basehat;
		for (int i = 1; i < n; i++)
		{
			int c1;
			do {
				c1 = select_random(hat);
			} while (c1 == i);

			hat.erase(hat.lower_bound(c1));

			int c2;
			do {
				c2 = select_random(hat);
			} while (c2 == i);
			hat.erase(hat.lower_bound(c2));
		}

		if (hat.find(n) != hat.end())
		{
			fails++;
		}
	}
	std::cout << std::setprecision(10);
	std::cout << "Fail count: " << (double)fails / (double)repeats << std::endl;
	*/
}