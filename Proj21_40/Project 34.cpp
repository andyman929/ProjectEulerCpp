/*
Digit factorials

Adapting project 30. Main difference is that the number of 0s used is now significant.
Hard to include 0s properly as leading zeros need to be removed.
*/

#include "pch.h"

#define BASE 10     // There are 10 possible digits in this base

void ProjectsObjDll::Project34Calc()
{
    int arr[BASE];
    arr[0] = 1;
    for (int i = 1; i < BASE; i++)
        arr[i] = arr[i - 1] * i;
    int maxDigits = 1;
    int findr = 10;
    while ((maxDigits)*arr[9] > findr)
    {
        findr *= 10;
        maxDigits++;
    }

    std::vector<int> digits(maxDigits, 0);

    digits[0] = 1;
    digits[1] = 1;

    int lim = std::pow(10, maxDigits);

    int sum;
    int running = 0;
    for (int i = 11; i < lim; i++)
    {
        sum = Proj34GetFactSum(i, arr);
        if (i == sum)
        {
            std::cout << sum << "\tis valid\n";
            running += sum;
        }
    }

    std::cout << "Total of all numbers that are equal to the sum of the factorials of their digits is: " << running << "\n";
}

int ProjectsObjDll::Proj34GetFactSum(int val, const int values[])
{
    int sum = 0;
    int i = 0;
    int reduce = val;
    while (reduce > 0)
    {
        int tmp = reduce % BASE;
        sum += values[tmp];
        reduce /= 10;
        i++;
    }
    return sum;
}