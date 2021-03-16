/*
Triangular, pentagonal, and hexagonal

Sneaky trick, every hexagonal number is a triangular number, so skip the check for triangular

P(s,n) = (s-2)Tn-1 + n      ->          Hn = T2n-1

So, pentagonal gives P(5,n)=3Tn-1 + n = 2Tn-1 + Tn
*/

#include "pch.h"

void Obj::Project45Calc()
{
    // Start from nHex = 144 so we skip the unnecessary values
    long long Hex;
    for (long long nHex = 144; nHex < INT_MAX; nHex++)
    {
        Hex = nHex * (2 * nHex - 1);
        // Find n s.t. Hex = 3Tn-1 + n. If it exists then Hex is pentagonal
        for (long long nPent = nHex + 1; nPent < 2 * nHex; nPent++)
        {
            long long Pent = nPent * (3 * nPent - 1) / 2;
            if (Hex == Pent)
                goto end;
            if (Hex < Pent)
                break;
        }
    }
    end:
    std::cout << "Next Hexagonal, Pentagonal and Triagonal number is " << Hex << std::endl;
}

bool Obj::IsPentagonal(int val)
{
    int r = 0;
    if (PerfectSquare(1 + 24 * val, r))
        if (r % 6 == 5)
            return true;
    
    return false;
}

bool Obj::IsTriangle(int val)
{
    int r = 0;
    if (PerfectSquare(1 + 8 * val, r))
        if (r % 2 == 1)
            return true;
    return false;
}