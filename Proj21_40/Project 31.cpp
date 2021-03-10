/*
How many ways to make n pounds

Realistically, I think the best way is to have nested loops, start with outermost and then go inwards
Might look neater to do this with recursive calls and maybe even memoisation but not gonna do that
*/

#include "pch.h"

void ProjectsObjDll::Project31Calc(const int pounds)
{
    constexpr int twopound = 200;
    constexpr int onepound = 100;
    constexpr int fiftyp = 50;
    constexpr int twentyp = 20;
    constexpr int tenp = 10;
    constexpr int fivep = 5;
    constexpr int twop = 2;

    const int pence = pounds * 100;

    int combinations = 0;
    for (int tpndcount = 0; tpndcount <= pence / twopound; tpndcount++)
    {
        int tpndsum = twopound * tpndcount;
        for (int opndcount = 0; opndcount <= (pence - tpndsum) / onepound; opndcount++)
        {
            int opndsum = tpndsum + onepound * opndcount;
            for (int fifpcount = 0; fifpcount <= (pence - opndsum) / fiftyp; fifpcount++)
            {
                int fifpsum = opndsum + fiftyp * fifpcount;
                for (int twepcount = 0; twepcount <= (pence - fifpsum) / twentyp; twepcount++)
                {
                    int twepsum = fifpsum + twentyp * twepcount;
                    for (int tenpcount = 0; tenpcount <= (pence - twepsum) / tenp; tenpcount++)
                    {
                        int tenpsum = twepsum + tenp * tenpcount;
                        for (int fivpcount = 0; fivpcount <= (pence - tenpsum) / fivep; fivpcount++)
                        {
                            int fivpsum = tenpsum + fivep * fivpcount;

                            // Don't need to loop the last two, from here the number of combinations
                            // just depends on the number of 2ps you can fit into the remainder
                            int currentCombos = 1 + ((pence - fivpsum) / twop);
                            /*
                            std::cout << tpndcount << "*" << twopound << " + " << opndcount << "*" << onepound << " + ";
                            std::cout << fifpcount << "*" << fiftyp << " + " << twepcount << "*" << twentyp << " + ";
                            std::cout << tenpcount << "*" << tenp << " + " << fivpcount << "*" << fivep;
                            std::cout << " \tGives " << currentCombos << "  combinations\t";
                            std::cout << "Sum of coins up to 5p: " << fivpsum << std::endl;
                            */
                            combinations += currentCombos;
                        }
                    }

                }
            }
        }
    }

    std::cout << "£ " << pounds << " pounds can be generated " << combinations << " ways using GBP\n";
}