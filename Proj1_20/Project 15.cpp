/*
Work out the first ten digits of the sum of the following one-hundred 50-digit numbers.
*/

#include "pch.h"

#define Round2Int64(x) (__int64)(x > 0 ? (x + 0.5) : (x - 0.5))

using namespace std;

// This problem is pretty simple to resolve. The solution needed is just 2n choose n. Issue is doing this in a manageable way (no overflows)
// Got around this by just running as a double then casting to an integer when ouptutting the result
void ProjectsObjDLL1::Project15Calc(int gridSize)
{
    double product = 1;
    for (int i = gridSize * 2; i > 0; i--)
    {
        if (i > gridSize)
        {
            product *= i;
        }
        else
        {
            product /= i;
        }
    }
    cout << "Number of routes through a grid of size: " << gridSize << ": " << Round2Int64(product) << "\n";
}