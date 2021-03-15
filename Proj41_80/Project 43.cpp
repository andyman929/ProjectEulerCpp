/*
Sub-string divisibility
*/

#include "pch.h"

void Obj::Project43Calc()
{
    std::vector<int> digits { 0,1,2,3,4,5,6,7,8,9 };
    __int64 sum = 0;
    do
    {
        int check;
        // Check if 0-9 pandigital
        if (digits[0] == 0)
            continue;
        // Check if d2d3d4 is divisible by 2
        // Digits are offset by 1 as digits are in a vector
        if (digits[3] % 2 != 0)
            continue;
        // Check if d3d4d5 is divisible by 3
        if ((digits[2] + digits[3] + digits[4]) % 3 != 0)
            continue;
        // Check if d4d5d6 is divisible by 5
        if (digits[5] % 5 != 0)
            continue;
        // Check if d5d6d7 is divisible by 7
        check = 100 * digits[4] + 10 * digits[5] + digits[6];
        if (check % 7 != 0)
            continue;
        // Check if d6d7d8 is divisible by 11
        check = 100 * digits[5] + 10 * digits[6] + digits[7];
        if (check % 11 != 0)
            continue;
        // Check if d7d8d9 is divisible by 13
        check = 100 * digits[6] + 10 * digits[7] + digits[8];
        if (check % 13 != 0)
            continue;
        // Check if d8d9d10 is divisible by 17
        check = 100 * digits[7] + 10 * digits[8] + digits[9];
        if (check % 17 != 0)
            continue;
        // If I get to here the value is valid
        long long value = VectorToInt(digits);
        sum += value;
        std::cout << "Valid value:\t" << value << std::endl;
    } while (std::next_permutation(digits.begin(), digits.end()));

    std::cout << "The sum of all valid integers is " << sum << std::endl;
}

long long Obj::VectorToInt(const std::vector<int>& digits)
{
    long long sum = 0;
    long long inc = 1;
    for (int i = digits.size() - 1; i >= 0; i--)
    {
        sum += inc * digits[i];
        inc *= 10;
    }
    return sum;
}