/*
The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.

Find the sum of all the primes below two million
*/

#include <vector>
#include <numeric>
#include "pch.h"

using namespace std;

// Sieve of Eratosthenes
void ProjectsObjDLL1::Project10Calc(int lim)
{
    __int64 primeSum = 0;

    vector<bool> isPrime(lim);
    int pos;

    fill(isPrime.begin(), isPrime.end(), true);
    isPrime.at(1) = false;

    for (int loop = 1; loop < lim; loop++)
    {
        if (isPrime.at(loop))
        {
            primeSum += loop;
            if (loop <= sqrt(lim))
            {
                pos = loop * loop;
                while (pos < lim)
                {
                    isPrime.at(pos) = false;
                    pos += loop;
                }
            }
        }
    }

    cout << "Sum of all primes less than " << lim << " is: " << primeSum;
}