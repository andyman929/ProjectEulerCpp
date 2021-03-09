/*
Euler discovered the remarkable quadratic formula...
*/

#include "pch.h"

// This looks for the larget fully reptend prime (will have p-1 digits repeating)
void ProjectsObjDll::Project27Calc(int limits)
{
    // Limit is based on assumption that n < 100 always. Could be adapted but not by me right now
    int pLimit = 100 * 100 + 100 * limits + limits;
    std::vector<bool> prime = Proj27Sieve(pLimit);
    int a; int b; int aMax; int bMax;
    int result = 0;
    for (a = -limits; a <= limits; a++)
    {
        // needs to work for n = 0, so b > 1 always
        // needs to work for n = 1, so 1+a+b > 1, so a+b>0, so bmin = max(2,-a)
        for (b = max(2, -a); b <= limits; b++)
        {
            int n;
            for (n = 0; n < 101; n++)
            {
                int p = n * n + a * n + b;
                if (p < 2 || p > pLimit)
                    break;
                if (!prime[p])
                    break;
            }
            if (n > result)
            {
                result = n - 1;
                aMax = a;
                bMax = b;
            }
        }
    }
    std::cout << "With |a|,|b| < " << limits << ". Largest prime sequence given for n^2 + " << aMax << "n + " << bMax << " resulting in primes from 0 to " << result << "\n";
    std::cout << "The product of these coefficients is " << aMax * bMax;
}

std::vector<bool> ProjectsObjDll::Proj27Sieve(int limit)
{
    std::vector<bool> prime(limit + 1);

    fill(prime.begin(), prime.end(), true);
    prime.at(1) = false;

    int pos;

    for (int loop = 1; loop <= sqrt(limit); loop++)
    {
        if (prime.at(loop))
        {
            pos = loop * loop;
            while (pos <= limit)
            {
                prime.at(pos) = false;
                pos += loop;
            }

        }
    }

    return prime;
}

int ProjectsObjDll::GCM27(int a, int b)
{
    if (b == 0)
        return a;
    return GCM27(b, a % b);
}