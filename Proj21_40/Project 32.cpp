/*
Pandigital products
*/

#include "pch.h"

void ProjectsObjDll::Project32Calc(const int n)
{
    std::vector<int> digits{ 1,2,3,4,5,6,7,8,9 };
    // If the product was 5 digits or longer then the product would be too small to get a result
    // If it were 3 digits then then the product would have to be too large
    // So the product must be 4 digits long

    // Take a permutation of the digits set, take the last 4 as the product and then 
    // Take [0]*[1][2][3][4] and [0][1]*[2][3][4], check if the product matches
    // Make a set of all [5][6][7][8] sets that worked to prevent rechecking
    std::set<int> found;
    int sum = 0;
    do {
        int val = Proj32SetInt(digits, 5, 8);
        if (std::find(found.begin(), found.end(), val) != found.end())
            continue;
        int m1 = digits[0];
        int m2 = Proj32SetInt(digits, 1, 4);
        int n1 = Proj32SetInt(digits, 0, 1);
        int n2 = Proj32SetInt(digits, 2, 4);
        if (m1 * m2 == val || n1 * n2 == val)
        {
            sum += val;
            found.insert(val);
        }
    } while (std::next_permutation(digits.begin(), digits.end()));
    std::cout << "Sum of all products where a*b = product is 9-pandigital is " << sum << std::endl;
}

int ProjectsObjDll::Proj32SetInt(const std::vector<int>& s, int start, int end)
{
    int val = 0;
    int inc = 1;
    for (int i = start; i <= end; i++)
    {
        val += s[i] * inc;
        inc *= 10;
    }
    return val;
}