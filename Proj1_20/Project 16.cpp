/*
2^15 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.

What is the sum of the digits of the number 2^1000?
*/

#include "pch.h"
#include <numeric>

#define Round2Int(x) (int)(x > 0 ? (x + 0.5) : (x - 0.5))

using namespace std;

// Presumably a very big number so not an option to go at this just calculating and going from there.
// Calculating every digit individually in vector<int>. Should be able to track through like doing it in your head/on paper.
void ProjectsObj::Project16Calc(int exp)
{
    int digitSum = 0;
    vector<int> power;
    power.push_back(2);

    for (int i = 1; i < exp; i++)
    {
        power.at(0) *= 2;
        // multiply by 2 and then carry up the excess from the lower index (rounding sorts this out)
        for (int pLoop = 1; pLoop < power.size(); pLoop++)
        {
            power.at(pLoop) = 2 * power.at(pLoop) + power.at(pLoop - 1) / 10;
        }
        // if the final digit is greater then ten then extend the vector to add the new highest digit
        if (power.at(power.size() - 1) >= 10)
        {
            power.push_back(power.at(power.size() - 1) / 10);
        }
        // go through and remove the value (10s) that were carried up in the first loop step
        for (int pLoop = 0; pLoop < power.size(); pLoop++)
        {
            power.at(pLoop) = power.at(pLoop) % 10;
        }
    }

    digitSum = accumulate(power.begin(), power.end(), 0);

    cout << "For 2^" << exp << ", the sum of the digits is: " << digitSum << "\n";
}