/*
A perfect number is a number for which the sum of its proper divisors is exactly equal to the number. For example, the sum of the 
proper divisors of 28 would be 1 + 2 + 4 + 7 + 14 = 28, which means that 28 is a perfect number.

A number n is called deficient if the sum of its proper divisors is less than n and it is called abundant if this sum exceeds n.

As 12 is the smallest abundant number, 1 + 2 + 3 + 4 + 6 = 16, the smallest number that can be written as the sum of two abundant 
numbers is 24. By mathematical analysis, it can be shown that all integers greater than 28123 can be written as the sum of two 
abundant numbers. However, this upper limit cannot be reduced any further by analysis even though it is known that the greatest 
number that cannot be expressed as the sum of two abundant numbers is less than this limit.

Find the sum of all the positive integers which cannot be written as the sum of two abundant numbers.
*/

#include "pch.h"

#define Round2Int(x) (int)(x > 0 ? (x + 0.5) : (x - 0.5))

using namespace std;

constexpr int maxVal = 28123;

void ProjectsObjDll::Project23Calc()
{
    vector<bool> isAbundant(maxVal + 1);
    Project23FindPerfection(&isAbundant);
    vector<int> abundantNumbers;
    for (int i = 1; i < isAbundant.size(); i++)
        if (isAbundant[i])
            abundantNumbers.push_back(i);

    // Find all numbers that are the sum of a pair
    vector<bool> isPair(maxVal + 1);
    fill(isPair.begin(), isPair.end(), false);
    for (int i = 0; i < abundantNumbers.size(); i++)
    {
        // Start from j = i to avoid repitition. Can test how much this improves performance
        for (int j = i; j < abundantNumbers.size(); j++)
        {
            int sum = abundantNumbers[i] + abundantNumbers[j];
            if (sum > maxVal)
                break;
            isPair[sum] = true;
        }
    }

    // Find sum of all the non-pair sums
    int nonPairSum = 0;
    for (int i = 1; i < isPair.size(); i++)
    {
        if (!isPair[i])
            nonPairSum += i;
    }

    cout << "The sum of all numbers that are not the sum of two abundant numbers is: " << nonPairSum << "\n";
}
void ProjectsObjDll::Project23FindPerfection(vector<bool> *factors)
{
    for (int i = 1; i <= maxVal; i++)
    {
        int factorsum = 0;
        int inc = 2;            // if not divisible by 2 then can skip all even factors. Will test how much this helps
        if (i % 2 == 0)
        {
            inc = 1;
        }
        for (int j = 1; j < i; j += inc)
        {
            if (i % j == 0)
                factorsum += j;
        }
        factors->at(i) = (factorsum > i);
    }
}