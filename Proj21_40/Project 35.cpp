/*
Circular primes
*/

#include "pch.h"

void ProjectsObjDll::Project35Calc(const int limit)
{
    std::vector<bool> sieve;
    std::vector<int> primes = Proj35Sieve(limit, &sieve);
    int count = 0;
    for (int i = 0; i < primes.size(); i++)
    {
        bool isCyclic = true;
        int p = primes[i];
        std::vector<int> pv = Proj35GetVector(p);
        int cycles = pv.size() - 1;
        for (int i = 0; i < cycles; i++)
        {
            Proj35CycleVector(&pv);
            int current = Proj35GetInt(pv);
            if (!sieve[current])
            {
                isCyclic = false;
                break;
            }
        }
        if (isCyclic)
        {
            std::cout << p << "\t\tis cyclic\n";
            count++;
        }
    }

    std::cout << "There are " << count << " cyclic primes below " << limit << "\n";
}

void ProjectsObjDll::Proj35CycleVector(std::vector<int>* digits)
{
    int hold = digits->at(0);

    for (int i = 0; i < digits->size() - 1; i++)
    {
        digits->at(i) = digits->at(i + 1);
    }

    digits->at(digits->size() - 1) = hold;
}

int ProjectsObjDll::Proj35GetInt(const std::vector<int>& digits)
{
    int sum = 0;
    int inc = 1;
    for (int u = 0; u < digits.size(); u++)
    {
        sum += digits[u] * inc;
        inc *= 10;
    }
    return sum;
}

std::vector<int> ProjectsObjDll::Proj35GetVector(const int val)
{
    // Don't allow for <= 0
    int reduce = val;
    std::vector<int> tst;
    while (reduce > 0)
    {
        tst.push_back(reduce % 10);
        reduce /= 10;
    }
    return tst;
}

std::vector<int> ProjectsObjDll::Proj35Sieve(int limit, std::vector<bool>* prime)
{
    prime->resize(limit + 1);
    std::fill(prime->begin(), prime->end(), true);
    prime->at(1) = false;

    int pos;

    for (int loop = 1; loop <= sqrt(limit); loop++)
    {
        if (prime->at(loop))
        {
            pos = loop * loop;
            while (pos <= limit)
            {
                prime->at(pos) = false;
                pos += loop;
            }
        }
    }

    std::vector<int> pList;
    for (int i = 2; i < prime->size(); i++)
    {
        if (prime->at(i))
            pList.push_back(i);
    }
    return pList;
}