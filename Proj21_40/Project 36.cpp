/*
Palindromes in base 2 and base 10
*/

#include "pch.h"

void ProjectsObjDll::Project36Calc(const int limit)
{
    int sum = 0;
    for (NBitInt<WIDTH_36> i = 1; i < limit; i += 1)
    {
        if (Proj36CheckPalindrome(i))
            if (i.BinaryPalindrome())
            {
                std::cout << i.GetInt() << "\tis valid\t" << i.GetBitset() << std::endl;
                sum += i.GetInt();
            }
    }
    std::cout << "The sum of all double base palindromes under " << limit << " is " << sum << "\n";
}

bool ProjectsObjDll::Proj36CheckPalindrome(NBitInt<WIDTH_36> num)
{
    int v = num.GetInt();
    std::string number;
    number = std::to_string(v);

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