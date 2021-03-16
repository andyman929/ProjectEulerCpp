/*
Self powers
*/

#include "pch.h"

void Obj::Project48Calc(const int lim)
{
    using ull = unsigned long long;
    ull sum = 0;
    constexpr ull mod = 10000000000;

    for (ull i = 1; i <= lim; i++)
    {
        ull reduce = i;
        ull innersum = 1;
        ull k = i;
        
        /*
        while (reduce > 0)
        {
            if (reduce % 2 == 1)
                innersum = (innersum * k) % mod;
            reduce /= 2;
            k = (k * k) % mod;
        }
        */
        
        ull altsum = 1;
        for (int k = 1; k <= i; k++)
        {
            altsum = (altsum * i) % mod;
        }
        /*
        if (innersum != altsum)
        {
            std::cout << "Sp of " << i << " is " << innersum << std::endl;
            std::cout << "Alt sp of " << i << " is " << altsum << std::endl;
        }
        */
        sum = (sum + altsum) % mod;
        //std::cout << "Running Sp sum to " << i << " is " << sum << std::endl;
    }

    std::cout << "Last 10 digits of sum of self powers up to " << lim << " is " << sum << std::endl;
}