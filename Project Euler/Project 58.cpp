/*
Starting with 1 and spiralling anticlockwise in the following way, a square spiral with side length 7 is formed.

37 36 35 34 33 32 31
38 17 16 15 14 13 30
39 18  5  4  3 12 29
40 19  6  1  2 11 28
41 20  7  8  9 10 27
42 21 22 23 24 25 26
43 44 45 46 47 48 49

It is interesting to note that the odd squares lie along the bottom right diagonal, but what is more interesting is that 8 out of the 13 numbers
lying along both diagonals are prime; that is, a ratio of 8/13 ~ 62%.

If one complete new layer is wrapped around the spiral above, a square spiral with side length 9 will be formed. If this process is continued, 
what is the side length of the square spiral for which the ratio of primes along both diagonals first falls below 10%?
*/

#include <iostream>
#include <vector>
#include "ProjectHeads.h"

#define Round2Int(x) (int)(x > 0 ? (x + 0.5) : (x - 0.5))

using namespace std;

// Only track the corners
void ProjectsObj::Project58Calc(int thresholdPC)
{
    double threshold = thresholdPC / (double)100.0;
    double ratio = 1;
    vector<int> corners;
    vector<int> primes;
    corners.push_back(1);
    int lastN = 1;
    int layer = 0;
    int pSize = 0;

    while (ratio > threshold)
    {
        layer++;
        Project58AddLayer(&lastN, layer, &corners);
        primes.insert(primes.end(), corners.end() - 4, corners.end());
        Project58EraseConjugates(&primes, pSize);
        pSize = primes.size();
        ratio = (double)pSize / (double)corners.size();
    }

    int sideLength = 1 + layer * 2;

    cout << "The first layer where less than " << thresholdPC << "% of values on the diagonals are has sidelength: " << sideLength << "\n";
}

void ProjectsObj::Project58AddLayer(int *last, int layer, vector<int> *corn)
{
    for (int i = 0; i < 4; i++)
    {
        *last += layer * 2;
        corn->push_back(*last);
    }
}

void ProjectsObj::Project58EraseConjugates(vector<int> *list, int oldSize)
{
    for (int i = oldSize; i < list->size(); )
    {
        bool prime = true;
        int p = list->at(i);
        if (p % 2 == 0)
        {
            prime = false;
        }
        else if (p == 1)
        {
            prime = false;
        }
        else
        {
            for (int j = 3; j <= sqrt(p); j += 2)
            {
                if (p % j == 0)
                {
                    prime = false;
                    break;
                }
            }
        }

        if (!prime)
            list->erase(list->begin() + i);
        else
            i++;
    }
}