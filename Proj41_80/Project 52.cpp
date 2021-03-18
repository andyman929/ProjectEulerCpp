/*
Prime permutations

I sort of guessed this one, the result is the cyclic number that is also the recurring component of 1/7
*/

#include "pch.h"

void Obj::Project52Calc()
{
    // We can bound the solution in such a way that we know each possible value must contain 6 distinct integers, as follows
    constexpr double bound0 = 1.0;
    const std::string r1 = "123456";
    constexpr double bound1 = 7.0 / 6.0;
    const std::string r2 = "123457";
    constexpr double bound2 = 6.0 / 5.0;
    const std::string r3 = "123467";
    constexpr double bound3 = 5.0 / 4.0;
    const std::string r4 = "123567";
    constexpr double bound4 = 4.0 / 3.0;
    const std::string r5 = "124568";
    constexpr double bound5 = 7.0 / 5.0;
    const std::string r6 = "124578";
    constexpr double bound6 = 3.0 / 2.0;
    const std::string r7 = "134679";
    constexpr double bound7 = 8.0 / 5.0;
    const std::string r8 = "134689";
    constexpr double bound8 = 5.0 / 3.0;

    const double bounds[9] = { bound0,bound1,bound2,bound3,bound4,bound5,bound6,bound7,bound8 };
    const std::string reqs[8] = { r1,r2,r3,r4,r5,r6,r7,r8 };

    int digitfactor = 100000;
    // Worth adding that there is a more fundamental bound of 123467 given the necessary digits
    int lBound = 123467;
    int uBound = 164983;
    bool notFound = true;
    int val;
    for (int i = 0; i < 8 && notFound; i++)
    {
        int lowerbound = bounds[i] * digitfactor;
        int upperbound = bounds[i + 1] * digitfactor;
        if (upperbound < lBound)
            continue;
        auto req = reqs[i];

        val = max(lowerbound, lBound);
        while (val < upperbound)
        {
            val++;
            std::string str = std::to_string(val);
            int n = 100;
            if (std::is_permutation(req.begin(), req.end(), str.begin(), str.end()))
            {
                for (n = 2; n <= 6; n++)
                {
                    int nval = n * val;
                    std::string nstr = std::to_string(nval);
                    if (!std::is_permutation(req.begin(), req.end(), nstr.begin(), nstr.end()))
                        n = 100;
                } 
            }
            // If n hasn't been set using this dumb trick then we've found a value
            if (n < 100)
            {
                notFound = false;
                break;
            }
        }
    }


    std::cout << "Lowest number with first 6 multiples as permutations is " << val << std::endl;
}