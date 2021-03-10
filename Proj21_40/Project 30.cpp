/*
Digit fifth powers
Output the sum of all numbers that can be written as the sum of their fifth powers
*/

#include "pch.h"

#define BASE 10     // There are 10 possible digits in this base

void ProjectsObjDll::Project30Calc(const int power)
{
    int arr[BASE];
    for (int i = 0; i < BASE; i++)
        arr[i] = pow(i, power);
    int maxDigits = 1;
    int findr = 10;
    while ((maxDigits) * arr[9] > findr)
    {
        findr *= 10;
        maxDigits++;
    }

    std::vector<int> digits(maxDigits, 0);

    digits[0] = 1;
    digits[1] = 1;
    int runningtotal = 0;
    int counter = 0;
    while (true)
    {
        counter++;
        int sum = 0;
        for (int i = 0; i < digits.size(); i++)
        {
            sum += arr[digits[i]];
        }
        std::vector<int> sumdigits = Proj30GetDigits(sum);
        while (sumdigits.size() < digits.size())
        {
            sumdigits.push_back(0);
        }
        if (std::is_permutation(sumdigits.begin(), sumdigits.end(), digits.begin(), digits.end()))
        {
            runningtotal += sum;
            std::cout << sum << std::endl;
        }

        Proj30Advance(&digits);
        if (digits[digits.size() - 1] == BASE)
            break;
    }

    std::cout << "Total of all digits that are the sum of the " << power << "th power of their digits is: " << runningtotal << "\n";
    std::cout << "Required " << counter << " checks\n";
}

void ProjectsObjDll::Proj30Advance(std::vector<int>* dig)
{
    for (int lastActive = dig->size() - 1; lastActive >= 0; lastActive--)
        if (dig->at(lastActive) != 0)
            break;

    int lastReset = -1;
    int carry = 0;
    for (int j = 0; j < dig->size() - 1; j++)
    {
        if (j == 0 || carry == 1)
        {
            if (dig->at(j) == BASE-1)
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
}

std::vector<int> ProjectsObjDll::Proj30GetDigits(int val)
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