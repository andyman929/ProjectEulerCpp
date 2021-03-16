/*
Prime permutations
*/

#include "pch.h"

void Obj::Project49Calc()
{
    constexpr int limit = 10000;
    std::vector<bool> prime = Proj49Sieve(limit);
    bool found = false;
    int i;
    int j;
    // Start loop from 1489 to avoid already found solution
    // Increment in both cases to avoid even numbers
    for (i = 1489; i < limit; i += 2)
    {
        if (!prime[i])
            continue;
        int shiftlimit = (limit - i) / 2;
        for (j = 2; j < shiftlimit; j += 2)
        {
            // Prime checks are really quick so do these first
            if (!prime[i + j])
                continue;
            if (!prime[i + j + j])
                continue;
            // Now do permutation checks
            if (!CheckPerm(i, i + j))
                continue;
            if (!CheckPerm(i, i + j + j))
                continue;
            found = true;
            break;
        }
        if (found)
            break;
    }
    std::cout << "First prime permutation is " << i << ", " << i + j << ", " << i + j + j << std::endl;
}

bool Obj::CheckPerm(int a, int b)
{
    std::string aStr = std::to_string(a);
    std::string bStr = std::to_string(b);
    return std::is_permutation(aStr.begin(), aStr.end(), bStr.begin(), bStr.end());
}

std::vector<bool> Obj::Proj49Sieve(const int limit)
{
    std::vector<bool> prime;
    prime.resize(limit + 1);
    std::fill(prime.begin(), prime.end(), true);
    prime.at(1) = false;

    int pos;

    for (int loop = 2; loop <= sqrt(limit); loop++)
    {
        if (prime.at(loop))
        {
            pos = loop * loop;
            int dl = 2 * loop;
            while (pos <= limit)
            {
                prime.at(pos) = false;
                pos += dl;
            }
        }
    }
    return prime;
}