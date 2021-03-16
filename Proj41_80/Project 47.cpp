/*
Distinct Prime factors
*/

#include "pch.h"

void Obj::Project47Calc(const int size)
{
    std::vector<int> pFactorCount;
    Proj47Sieve(pFactorCount);

    int i;
    for (i = 1; i < INT_MAX; i++)
    {
        if (i + size > pFactorCount.size())
            Proj47Sieve(pFactorCount);
        bool found = true;
        for (int n = 0; n < size; n++)
        {
            if (pFactorCount[i + n] != size)
            {
                found = false;
                break;
            }
        }
        if (found)
            break;
    }
    std::cout << "First " << size << " consecutive values with " << size << " distinct factors is " << i;
    for (int j = 1; j < size; j++)
        std::cout << ", " << i + j;
    std::cout << std::endl;
}

void Obj::Proj47Sieve(std::vector<int>& pfactors)
{
    constexpr int increment = 1000;
    int restart = pfactors.size();
    int limit = increment + restart;

    pfactors.resize(limit + 1);

    std::fill(pfactors.begin() + restart, pfactors.end(), 0);

    for (int loop = 2; loop <= limit / 2; loop += 1)
    {
        if (pfactors.at(loop) == 0)
        {
            int pos = 2 * loop;
            // little optimisation
            if (pos < restart)
            {
                pos += (1 + (restart - pos) / loop) * loop; // reposition to just after restart. might not even move in some cases but for some it's a huge difference
            }
            while (pos <= limit)
            {
                pfactors.at(pos) += 1;
                pos += loop;
            }
        }
    }
}