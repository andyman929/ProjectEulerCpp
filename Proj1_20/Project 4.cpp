/*
A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.

Find the largest palindrome made from the product of two 3-digit numbers.
*/

#include <string>
#include "pch.h"

using namespace std;

void ProjectsObj::Project4Calc()
{
    int currentMax = 0;
    int aLowerBound = 100;
    int bLowerBound = 100;
    int upperBound = 999;

    int currentVal;

    int a;
    int b;
    a = upperBound;
    b = upperBound;

    while (a > aLowerBound)
    {
        while (b > bLowerBound)
        {
            currentVal = a * b;
            // Not sure if it's standard that the second condition will be skipped if first is false. It'd be helpful here.
            // It doesn't, moved to nested condition
            if (currentVal > currentMax)
            {
                if (Project4CheckPalindrome(currentVal))
                {
                    currentMax = currentVal;
                    break;
                }
            }
            --b;
        }
        --a;
        // Start tightening the bounds but only if we have an answer already
        if (currentMax > 0)
            bLowerBound = b + 1;
        b = a;
    }
    cout << "Largest palindrome: " << currentMax;
}

bool ProjectsObj::Project4CheckPalindrome(int num)
{
    string number;
    number = to_string(num);
    
    int lower = 0;
    int upper = number.length() - 1;

    while (lower < upper)
    {
        if (number[lower] != number[upper])
            return false;
        ++lower;
        --upper;
    }
    return true;
}