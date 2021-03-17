/*
Consecutive prime sum
*/

#include "pch.h"

namespace ns50 {

}

void Obj::Project50Calc(const int limit)
{
    std::vector<bool> isprime = Proj49Sieve(limit);
    std::vector<int> primes;
    for (int i = 2; i <= limit; i++)
        if (isprime[i])
            primes.push_back(i);

    // all primes under limit
    // loop through sums of each length, if you find a prime < limit then you win
    // Find upper bound using a loop
    // sqrt(limit) would also work but this gives a tighter bound for large limit
    int maxLength;
    int sumtest = 0;
    for (maxLength = 0; maxLength < primes.size(); maxLength++)
    {
        sumtest += primes[maxLength];
        if (sumtest > limit)
            break;
    }
    maxLength--;
    int maxChain = 0;
    int m;
    for (m = maxLength; m > 0; m--)
    {
        for (int start = 0; start + m < primes.size(); start++)
        {
            int chain = 0;
            for (int pos = start; pos - start < m; pos++)
            {
                chain += primes[pos];
                // These chains are increasing, so as soon as one is too big we can skip the rest
                if (chain > limit)
                    break;
            }
            if (chain > limit)
                break;
            if (isprime[chain])
            {
                maxChain = chain;
                goto out;
            }
        }
    }
    out:
    std::cout << "Longest prime sum chain is length " << m << ", adding up to " << maxChain << std::endl;
}