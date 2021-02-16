/*
A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,

a2 + b2 = c2
For example, 32 + 42 = 9 + 16 = 25 = 52.

There exists exactly one Pythagorean triplet for which a + b + c = 1000.
Find the product abc.
*/

#include <iostream>
#include <string>
#include "ProjectHeads.h"

using namespace std;

void ProjectsObj::Project9Calc(int sumrequired)
{
    int a = 0;
    int b;
    int c;
    int testVal;
    bool found = false;

    while (!found && a < sumrequired)
    {
        ++a;
        b = a;
        while (a + b < sumrequired)
        {
            ++b;

            c = sumrequired - a - b;
            testVal = c * c - a*a - b * b;

            found = (testVal == 0);
            if (found)
                break;
        }
    }
    if (found)
    {
        cout << "Pythagorean triple summing to " << sumrequired << " found: " << a << ", " << b << ", " << c << "\n";
        cout << "Product of abc: " << a * b * c << "\n";
    }
    else
        cout << "Failed to find any triples";
}