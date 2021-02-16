/*
The four adjacent digits in the 1000-digit number that have the greatest product are 9 × 9 × 8 × 9 = 5832. (input)
Find the thirteen adjacent digits in the 1000-digit number that have the greatest product. What is the value of this product?
*/



#include <iostream>
#include <string>
#include <vector>
#include "ProjectHeads.h"

#define CharToInt(x) x - '0'

using namespace std;

void ProjectsObj::Project8Calc(int digits, string input)
{
    __int64 product;
    __int64 maxProduct = 0;

    vector<int> int_array;
    for (int i = 0; i < input.size(); i++)
        int_array.push_back(CharToInt(input[i]));

    for (int i = 0; i < (input.size() - digits); i++)
    {
        product = 1;
        for (int pos = i; pos < i + digits; pos++)
        {
            if (int_array[pos] == 0)
            {
                //go next but skip until after this zero
                i = pos;
                product = 0;
                break;
            }
            product *= int_array[pos];
        }
        maxProduct = product > maxProduct ? product : maxProduct;

    }

    cout << "Largest product of " << digits << " consecutive digits: " << maxProduct << "\n";
}