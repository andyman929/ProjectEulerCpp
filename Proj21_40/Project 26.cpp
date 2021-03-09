/*
A unit fraction contains 1 in the numerator. The decimal representation of the unit fractions with denominators 2 to 10 are given:

1/2	= 	0.5
1/3	= 	0.(3)
1/4	= 	0.25
1/5	= 	0.2
1/6	= 	0.1(6)
1/7	= 	0.(142857)
1/8	= 	0.125
1/9	= 	0.(1)
1/10	= 	0.1
Where 0.1(6) means 0.166666..., and has a 1-digit recurring cycle. It can be seen that 1/7 has a 6-digit recurring cycle.

Find the value of d < 1000 for which 1/d contains the longest recurring cycle in its decimal fraction part.
*/

#include "pch.h"

using namespace std;

// This looks for the larget fully reptend prime (will have p-1 digits repeating)
void ProjectsObjDll::Project26Calc(int digits)
{
    __int64 primeSum = 0;

    vector<int> primes;
    vector<bool> isPrime(digits);
    int pos;

    fill(isPrime.begin(), isPrime.end(), true);
    isPrime.at(1) = false;

    for (int loop = 1; loop < digits; loop++)
    {
        if (isPrime.at(loop))
        {
            primes.push_back(loop);
            if (loop <= sqrt(digits))
            {
                pos = loop * loop;
                while (pos < digits)
                {
                    isPrime.at(pos) = false;
                    pos += loop;
                }
            }
        }
    }
    int out;
    for (int i = primes.size() - 1; i >= 0; i--)
    {
        if (Project26ReptendCheck(primes[i]))
        {
            out = primes[i];
            break;
        }
    }
    std::cout << "Value of d for the longest recurring cycle in 1/d where d <  " << digits << ": " << out << "\n";
}

// Full reptend prime iff 10^k == 1 mod p, where k = p-1
bool ProjectsObjDll::Project26ReptendCheck(int p)
{
    int k = p - 1;
    int out = 1;
    vector<bool> coprimes(p);
    fill(coprimes.begin(), coprimes.end(), false);
    for (int i = 0; i < k; i++)
    {
        out *= 10;
        out %= p;
        coprimes[out] = true;
    }
    if (out != 1)
        return false;

    for (int i = 1; i < p; i++)
    {
        if (!coprimes[i])
            return false;
    }

    return true;
}

