/*
By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.

What is the 10 001st prime number?
*/

#include <vector>
#include "pch.h"

using namespace std;

void ProjectsObj::Project7Calc(int pNumber)
{
    int p = 0;
    vector<int> primes;
    int finder = 2;

    bool isPrime;

    while (primes.size() < pNumber)
    {
        isPrime = true;
        for (int i = 0; i < primes.size(); i++)
        {
            if (finder % primes[i] == 0)
                isPrime = false;
        }
        if (isPrime)
        {
            primes.push_back(finder);
        }
        finder++;
    }
    p = primes[pNumber - 1];

    cout << "nth Prime Number: " << p << "\n";
}