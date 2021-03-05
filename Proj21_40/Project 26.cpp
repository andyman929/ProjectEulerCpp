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
#include "NBitInt.h"

using namespace std;

// This looks for the larget fully reptend prime (will have p-1 digits repeating)
void ProjectsObjDll::Project26Calc(int digits)
{


    std::cout << "First Fibonacci term with more than " << 1 << " digits is: " << 1 << "\n";
}

bool ProjectsObjDll::Project26Cyclic(int inp)
{


}

// Checks the prime mod 40. If true it is still possible for inp to be fully reptend 
bool ProjectsObjDll::Project26Reptend40Check(int inp)
{
    switch (inp % 40)
    {
    case 1:
    case 3:
    case 9:
    case 13:
    case 27:
    case 31:
    case 37:
    case 39:
        return false;
    default:
        return true;
    }
}

