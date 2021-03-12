/*
Champernowne's constant
*/

#include "pch.h"

void ProjectsObjDll::Project40Calc()
{
    constexpr int singledigs = 9;
    constexpr int firstdbl = singledigs + 1;

    constexpr int doubledigs = 100 - 10;
    constexpr int firsttpl = firstdbl + doubledigs * 2;

    constexpr int tripledigs = 1000 - 100;
    constexpr int firstquad = firsttpl + tripledigs * 3;

    constexpr int quaddigs = 10000 - 1000;
    constexpr int firstquint = firstquad + quaddigs * 4;

    constexpr int quintdigs = 100000 - 10000;
    constexpr int firstsext = firstquint + quintdigs * 5;

    constexpr int sextdigs = 1000000 - 100000;
    constexpr int firstsept = firstsext + sextdigs * 6;


    int find[7] = { 1,10,100,1000,10000,100000,1000000 };
    int found[7];

    for (int i = 0; i < 7; i++)
    {
        int targ = find[i];
        int digcount = 0;
        int start = 0;
        int base = 0;

        int pos = 0;
        int nthvalue = 0;
        int value = 0;
        std::string valstr = "";
        int digit = 0;
        if (find[i] < firstdbl)
        {
            found[i] = find[i];
            continue;
        }
        else if (find[i] < firsttpl)
        {
            digcount = 2;
            start = firstdbl;
            base = 10;
        }
        else if (find[i] < firstquad)
        {
            digcount = 3;
            start = firsttpl;
            base = 100;
        }
        else if (find[i] < firstquint)
        {
            digcount = 4;
            start = firstquad;
            base = 1000;
        }
        else if (find[i] < firstsext)
        {
            digcount = 5;
            start = firstquint;
            base = 10000;
        }
        else
        {
            digcount = 6;
            start = firstsext;
            base = 100000;
        }
        pos = find[i] - start;
        nthvalue = pos / digcount;
        digit = pos % digcount;
        value = base + nthvalue;
        valstr = std::to_string(value);
        found[i] = (int)(valstr[digit] - '0');
    }

    int output = 1;
    for (int j = 0; j < 7; j++)
    {
        output *= found[j];
    }

    std::cout << "The product of the required values is " << output << "\n";
}