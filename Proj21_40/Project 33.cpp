/*
Digit cancelling fractions
*/

#include "pch.h"

void ProjectsObjDll::Project33Calc()
{
    // Can ignore 0 since there is no way for that to work under those conditions
    std::vector<int> digits{ 1,2,3,4,5,6,7,8,9 };
    int numerProd = 1;
    int denomProd = 1;
    for (int i = 1; i < 10; i++)
    {
        for (int j = 1; j < 10; j++)
        {
            int numer = 10*i + j;
            for (int k = 1; k < 10; k++)
            {
                double iFrac = i / (double)k;
                double jFrac = j / (double)k;
                int d1 = 10 * k + i;
                if (numer / (double)d1 == iFrac)
                {
                    std::cout << "Valid fraction " << numer << "/" << d1 << std::endl;
                }
                d1 = 10 * i + k;
                if (numer / (double)d1 == iFrac)
                {
                    std::cout << "Valid fraction " << numer << "/" << d1 << std::endl;
                }
                if (i != j)
                {
                    double jFrac = j / (double)k;
                    int d1 = 10 * k + j;
                    if (numer / (double)d1 == jFrac)
                    {
                        std::cout << "Valid fraction " << numer << "/" << d1 << std::endl;
                    } 
                    d1 = 10 * j + k;
                    if (numer / (double)d1 == jFrac)
                    {
                        std::cout << "Valid fraction " << numer << "/" << d1 << std::endl;
                    }
                }
            }
        }
    }
    std::cout << "Sum of all products where a*b = product is 9-pandigital is " << 1 << std::endl;
}