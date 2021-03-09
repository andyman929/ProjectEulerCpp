/*
Distinct powers
*/

#include "pch.h"

void ProjectsObjDll::Project29Calc(const int limit)
{
    // the exponent, b, is less than or equal to log2(limit), as 2^maxEXP>limit otherwise
    int maxExp = 8;// (int)(log2(limit) + 0.5);
    // In second section, we find things based on each having a parent x s.t. a = x^y
    // Then, a^b = x^(b*y). So for each b in [2, limit] we need to check if b*y will have already been reached with a 
    // lower value of y.
    // Use this loop to find the minimum value of b that will get to b*y. Store it in minExp
    std::vector<int> minExp((limit + 1) * maxExp);
    for (int b = 1; b <= maxExp; b++)
    {
        for (int y = 1; y <= limit; y++)
        {
            if (minExp[b * y] == 0)
                minExp[b * y] = b;
        }
    }

    // Starting point of all possible powers included, below acts to remove any that shouldn't be in there
    int sum = (limit - 1);
    sum *= sum;
    // Scan all values
    std::vector<int> expbase(limit + 1, 0);
    for (int a = 2; a <= limit; a++)
    {
        // If exp[a] == 0, then there is not x,y such that y>1 and x^y = a, so nothing is being repeated here
        int parent = expbase[a];
        if (parent == 0)
        {
            // Find anything in the set that is a power
            int kapow = a * a;
            while (kapow <= limit)
            {
                expbase[kapow] = a;
                kapow *= a;
            }
            continue;
        }

        // Find the exponent that gives a = parent^exponent
        int exponent = 0;
        int reduction = a;
        while (reduction > 1)
        {
            reduction /= parent;
            exponent++;
        }

        for (int b = 2; b <= limit; b++)
        {
            // If minExp is less than exponent for the combo b * exponent
            if (minExp[b * exponent] < exponent)
                sum -= 1;
        }
    }

    std::cout << "Total distinct powers for 2 <= a,b <= " << limit << " is: " << sum  << "\n";
}