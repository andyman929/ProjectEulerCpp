/*
Pandigital multiples
*/

#include "pch.h"

void ProjectsObjDll::Project38Calc()
{
    /*
    The actual problem, need to find max concatenation.
    We know 9,5 works, so we should only look for things starting with 9
    90s won't work as there is no suitable n a number in the 90s could pair with
    Also know that 900s wont work, as 9XX + 9XX*2 is too short and 9XX + 9XX*2 +9XX*3 is too long
    9XXXX is too long, pretty trivially, same for anything larger also.
    That leaves only the 9000s. From here it makes most sense to scan downwards, the first suitable value is the maximum also.
    This ignores 9, so we scan down in the 9000s, find an example (maybe) and then compare to the 9 example

    Worth noting that n = 2 for a 9000s number
    Can increase lower limit to 9122 to remove all zeros and duplicated values
    Can decrease upper limit to 9876 for the same reason

    Can shift limits with further analysis (e.g. 9XXX*2 = 19XXX if the x bit is too large, so i < 9500 and i > 91XX)
    */
    
    int maxFound = 0;
    for (int i = 9487; i > 9212; i--)
    {
        // Check multiple conditions as follows
        // Divisible by 5 => i or 2*i ends in 0.
        // i % 100 < 10 => there is a 0 digit in the tens position, not allowed
        // i % 10 == 9 => the last digit is 9 which would be a repeated digit
        if (i % 5 == 0 || i % 100 < 10 || i % 10 == 9)
            continue;
        int i2 = i * 2;
        int tst = i*100000 + i2;    // This is an appropriately non-generic way of concatenating the values
        if (Proj38IsPandigital(tst))
        {
            std::cout << i << "\t" << i2 << "\t is a valid combo\n";
            maxFound = tst;
            break;
        }
    }

    int nine = 9;
    int ninesval = 0;
    int hundred = 100;
    int i = 0;
    while (ninesval < pow(10, 8))
    {
        i++;
        ninesval = ninesval * hundred + nine * i;
    }

    if (ninesval > maxFound)
    {
        maxFound = ninesval;
    }

    std::cout << "Maximum combination of pandigital numbers is " << maxFound << "\n";
}

bool ProjectsObjDll::Proj38IsPandigital(const int val)
{
    int reduce = val;
    std::set<int> digits;
    while (reduce > 0)
    {
        int tmp = reduce % 10;
        if (tmp == 0)
            return false;
        if (digits.insert(tmp).second == false)
            break;
        reduce /= 10;
    }
    return digits.size() == 9;
}