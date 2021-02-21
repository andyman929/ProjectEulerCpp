/*
n! means n x (n - 1) x ... x 3 x 2 x 1

For example, 10! = 10 x 9 x ... x 3 x 2 x 1 = 3628800,
and the sum of the digits in the number 10! is 3 + 6 + 2 + 8 + 8 + 0 + 0 = 27.

Find the sum of the digits in the number 100!
*/

#include "pch.h"
#include <numeric>

#define Round2Int(x) (int)(x > 0 ? (x + 0.5) : (x - 0.5))

using namespace std;

// Possibly a repeat of project 16 in many ways
// Made more complex as the carry over of values can be more than one digit
void ProjectsObj::Project20Calc(int fact)
{
    int digitSum = 0;
    vector<int> factorial;
    factorial.push_back(1);

    for (int i = 2; i <= fact; i++)
    {
        factorial.at(0) *= i;
        // multiply by current factor and then carry up the excess from all lower index (rounding sorts this out)
        for (int pLoop = 1; pLoop < factorial.size(); pLoop++)
        {
            factorial.at(pLoop) = i * factorial.at(pLoop) + factorial.at(pLoop - 1) / 10;
        }
        // loop around the last digit and move up if needed
        while (factorial.at(factorial.size() - 1) >= 10)
        {
            factorial.push_back(factorial.at(factorial.size() - 1) / 10);
        }
        // go through and remove the values that were carried up in the first loop step
        for (int pLoop = 0; pLoop < factorial.size(); pLoop++)
        {
            factorial.at(pLoop) = factorial.at(pLoop) % 10;
        }
    }

    digitSum = accumulate(factorial.begin(), factorial.end(), 0);

    cout << "For " << fact << "!, the sum of the digits is: " << digitSum << "\n";
}