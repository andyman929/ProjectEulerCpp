/*
Integer right triangles
*/

#include "pch.h"

void ProjectsObjDll::Project39Calc(const int limit)
{
    // Use coprime pairs of m,n, m<n in order to generate primitive pythagorean triples
    // Add these into a vector full of the SUM of these triples
    // If all 3 sides are even you need to divide through to get the output
    // For each p value up to limit, scan this vector for even factors. Then for each even factor there is a 
    // valid right angled triangle with integer sides
    // May be more efficient to scan the list once and apply the triple to each limit

    // a = m^2 - n^2; b = 2mn; c = m^2 + n^2
    // a + b + c = 2m^2 + 2mn < limit
    // 

    std::vector<int> triplecount(limit + 1);

    // This loop can probably be further restricted
    for (int m = 1; m < limit / 2; m++)
    {
        for (int n = 1; n < m; n++)
        {
            if (GCM27(m, n) != 1)
                continue;
            int abc = 2 * m * m + 2 * m * n;
            if (m % 2 == 0 && n % 2 == 0)
                abc /= 2;

            int i = 1;
            while (i * abc < limit)
            {
                triplecount.at(i * abc) += 1;
                i++;
            }
        }
    }

    int maxy = 0;
    int pMax = 0;
    for (int i = 2; i < triplecount.size(); i++)
    {
        if (triplecount.at(i) > maxy)
        {
            maxy = triplecount.at(i);
            pMax = i;
        }
    }

    std::cout << "Maximum combination of pandigital numbers is " << maxy << " at p = " << pMax << "\n";
}