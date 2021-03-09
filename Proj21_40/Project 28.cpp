/*
Number spiral diagonals
*/

#include "pch.h"

// This looks for the larget fully reptend prime (will have p-1 digits repeating)
void ProjectsObjDll::Project28Calc(int sides)
{
    int spirals = (sides - 1) / 2;
    int sum = 1;
    int lastC = 1;
    int l1;
    for (int i = 1; i <= spirals; i++)
    {
        int length = 2 * i;
        sum += 4 * lastC + 10 * length;
        lastC += 4*length;
    }
    std::cout << "Sum of corners for " << sides << " by " << sides << " number spiral is: " << sum << "\n";
}