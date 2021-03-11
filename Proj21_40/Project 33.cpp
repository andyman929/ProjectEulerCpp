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
    RationalNumber output(1);
    for (int i = 1; i < 10; i++)
    {
        for (int j = 1; j < 10; j++)
        {
            int numer = 10*i + j;
            for (int k = 1; k < 10; k++)
            {
                RationalNumber testi(j, k);
                if (testi < 1)
                {
                    RationalNumber a(numer, 10 * k + i);
                    if (testi == a)
                    {
                        std::cout << numer << "/" << 10 * k + i << std::endl;
                        output = output * a;
                    }
                    RationalNumber b(numer, 10 * i + k);
                    if (testi == b)
                    {
                        std::cout << numer << "/" << 10 * i + k << std::endl;
                        output = output * b;
                    }
                }
                if (i != j)
                {
                    RationalNumber testj(i, k);
                    if (testj < 1)
                    {
                        RationalNumber x(numer, 10 * k + j);
                        if (testj == x)
                        {
                            std::cout << numer << "/" << 10 * k + j << std::endl;
                            output = output * x;
                        }
                        RationalNumber y(numer, 10 * j + k);
                        if (testj == y)
                        {
                            std::cout << numer << "/" << 10 * j + k << std::endl;
                            output = output * y;
                        }
                    }
                }
            }
        }
    }
    std::cout << "Product of weird fractions is " << output.print() << std::endl;
}