/*
Goldbach other
*/

#include "pch.h"

void Obj::Project46Calc()
{
    constexpr int increment = 100;
    int limit = increment;
    std::vector<bool> primeFilter;
    std::vector<long long> primeList;
    // This list actually contains double the squares
    std::vector<long long> squareList;

    Proj46Sieves(primeFilter, primeList, squareList, limit);
    long long i;
    for (i = 9; i < UINT_MAX; i += 2)
    {
        if (i > limit)
        {
            limit += increment;
            Proj46Sieves(primeFilter, primeList, squareList, limit);
        }
        bool foundCurrent = false;
        if (primeFilter[i])
            continue;
        for (auto s : squareList)
        {
            if (s > i)
                break;
            for (auto p : primeList)
            {
                if (i == s + p)
                {
                    foundCurrent = true;
                    goto doublebreak;
                }
                if (p > i)
                    break;
            }
        }
    doublebreak:
        if (!foundCurrent)
            break;
    }
    std::cout << "First value that disproves this conjecture is " << i << std::endl;
}

void Obj::Proj46Sieves(std::vector<bool>& pFilter, std::vector<long long>& primes, std::vector<long long>& squares, int limit)
{
    if (squares.size() == 0)
        squares.push_back(0);
    for (long long i = squares.size(); 2 * i * i <= limit; i++)
    {
        squares.push_back(2 * i * i);
    }

    int restart = pFilter.size();
    pFilter.resize(limit + 1);
    std::fill(pFilter.begin() + restart, pFilter.end(), true);
    pFilter[1] = false;
    for (int loop = 1; loop <= sqrt(limit); loop += 2)
    {
        if (pFilter.at(loop))
        {
            int pos = loop * loop;
            // little optimisation
            if (pos < restart)
            {
                pos += ((restart - pos) / loop) * loop; // reposition to just before restart. might not even move in some cases but for some it's a huge difference
            }
            while (pos <= limit)
            {
                pFilter.at(pos) = false;
                pos += loop;
            }
        }
    }
    if (restart == 0)
    {
        primes.push_back(2);
    }
    if (restart % 2 == 0)
        restart++;
    for (int j = restart; j < pFilter.size(); j += 2)
    {
        if (pFilter[j])
            primes.push_back(j);
    }
}