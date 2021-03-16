/*
Pentagon numbers
*/

#include "pch.h"

void Obj::Project44Calc()
{
    // Inititally include the first 100 pentagonal numbers
    int limit = 100;
    std::vector<int> pentagons;
    PentagonFilter(pentagons, limit);
    int D = INT_MAX;
    bool found = false;
    for (int i = 2; i < pentagons.size() && !found; i++)
    {
        int minDiff = 3 * i - 2;
        if (minDiff > D)
            break;
        int maxSum = 3 * i * i - 4 * i + 2;
        if (maxSum > pentagons.back())
        {
            limit *= 2;
            PentagonFilter(pentagons, limit);
        }
        // To find if a number is pentagonal we just need to check if sqrt(24*x+1)==5 mod 6, but only do this if not in vector
        for (int j = i - 1; j > 0; j--)
        {
            int checkSub = pentagons[i] - pentagons[j];
            if (checkSub > D)
                break;
            if (std::find(pentagons.begin(), pentagons.end(), checkSub) == pentagons.end())
                continue;

            int checkAdd = pentagons[i] + pentagons[j];
            if (checkAdd > pentagons.back())        // This shouldn't happen with the extension, but just in case
            {
                int sqroot = 0;
                if (PerfectSquare(checkAdd, sqroot))
                {
                    if (sqroot % 6 != 5)
                        continue;
                }
                else
                {
                    continue;
                }
            }
            else
            {
                if (std::find(pentagons.begin(), pentagons.end(), checkAdd) == pentagons.end())
                    continue;
            }
            // This means its a valid pair
            D = pentagons[i] - pentagons[j];
            std::cout << "This pair works:\t P(" << j << ") = " << pentagons[j] << "\tP(" << i << ") = " << pentagons[i] << std::endl;
            found = true;
            break;
        }
    }
    std::cout << "The minimum gap is " << D << std::endl;
}

// Return true/false if the value is/isn't a perfect square. Return the root via the input reference
bool Obj::PerfectSquare(const int input, int& root)
{
    for (root = 1; root <= sqrt(input) + 1; root++)
    {
        if (root * root == input)
        {
            return true;
        }
    }
    root = -1;
    return false;
}

inline void Obj::PentagonFilter(std::vector<int>& pent, const int maxim)
{
    int start = pent.size();
    pent.resize(maxim + 1);
    for (int i = start; i < maxim + 1; i++)
    {
        pent[i] = i * (3 * i - 1) / 2;
    }
}