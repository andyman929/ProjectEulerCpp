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
    int zerocnt = maxDigits - 2;
    int runningtotal = 0;
    int counter = 0;
    while (true)
    {
        counter++;
        int sum = 0;
        for (int i = 0; i < digits.size() - zerocnt; i++)
        {
            sum += arr[digits[i]];
        }
        std::vector<int> tmp;
        tmp.insert(tmp.end(), digits.begin(), digits.end() - zerocnt);
        for (int zloop = 0; zloop <= zerocnt; zloop++)
        {
            int innersum = sum + zloop;
            std::vector<int> sumdigits = Proj30GetDigits(innersum);
            if (sumdigits.size() != tmp.size())
            {
                tmp.push_back(0);
                continue;
            }
            if (std::is_permutation(sumdigits.begin(), sumdigits.end(), tmp.begin(), tmp.end()))
            {
                runningtotal += sum;
                std::cout << sum << std::endl;
            }
            tmp.push_back(0);
        }

        Proj34Advance(&digits, &zerocnt);
        if (digits[digits.size() - 1] == BASE)
            break;
    }

    std::cout << "Total of all digits that are the sum of the " << 1 << "th power of their digits is: " << runningtotal << "\n";
    std::cout << "Required " << counter << " checks\n";
}

void ProjectsObjDll::Proj34Advance(std::vector<int>* dig, int* zeros)
{
    int lastReset = -1;
    int carry = 0;
    for (int j = 0; j < dig->size() - 1; j++)
    {
        if (j == 0 || carry == 1)
        {
            if (dig->at(j) == BASE - 1)
            {
                dig->at(j) = dig->at(j + 1) + 1;
                carry = 1;
                lastReset = j;
            }
            else
            {
                dig->at(j) += 1;
                carry = 0;
            }
        }
    }
    if (carry == 1)
    {
        dig->at(dig->size() - 1) += 1;
    }

    for (int i = 0; i < lastReset; i++)
    {
        dig->at(i) = dig->at(lastReset);
    }
    
    int lastActive;
    for (lastActive = dig->size() - 1; lastActive >= 0; lastActive--)
        if (dig->at(lastActive) != 0)
            break;
    *zeros = dig->size() - lastActive - 1;
}

std::vector<int> ProjectsObjDll::Proj34GetDigits(int val)
{
    std::vector<int> digitlist;
    int reduce = val;
    while (reduce > 0)
    {
        digitlist.push_back(reduce % 10);
        reduce /= 10;
    }
    return digitlist;
}