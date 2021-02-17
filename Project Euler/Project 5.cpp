/*
2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.

What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?
*/



#include <iostream>
#include "ProjectHeads.h"

#define ROUND_INT(x) ((int)(x >= 0.0 ? (x + 0.5) : (x - 0.5)))

void ProjectsObj::Project5Calc(int lim)
{
    int lcm = 1;
    int gcd;

    for (int looper = lim; looper > 1; looper--)
    {
        // If it's already ok, skip
        if (lcm % looper != 0)
        {
            gcd = Project5GetGCD(lcm, looper);
            lcm *= looper / gcd;
        }
    }

    std::cout << "Lowest common multiple of digits 1 to n(20): " << lcm << "\n";
}

int ProjectsObj::Project5GetGCD(int aIn, int bIn)
{
    int a = aIn;
    int b = bIn;

    while (true)
    {
        // Easier if a>=b always
        if (b > a)
        {
            int c = b;
            b = a;
            a = c;
        }

        if (a % b == 0)
            return b;

        // Set a to be the remainder and repeat
        a = a % b;
    }
}