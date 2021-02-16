/*
The prime factors of 13195 are 5, 7, 13 and 29.

What is the largest prime factor of the number 600851475143 ?
*/

#include <iostream>
#include "ProjectHeads.h"

void ProjectsObj::Project3Calc(long long num)
{
    long long largest = 0;
    largest = Project3CalcLoop(num);
    std::cout << "Largest prime factor: " << largest << "\n";
}

// Trying to unfurl the recursive method below into a for loop to simplify
int ProjectsObj::Project3CalcLoop(long long num)
{
    long long currentMax;
    long long reducedNum;
    long long testFactor = 2;

    reducedNum = num;

    while (true)
    {
        if (reducedNum % testFactor == 0)
        {
            currentMax = testFactor;
            reducedNum /= currentMax;
            if (reducedNum == 1)
                return currentMax;
            testFactor = 1;
        }
        testFactor++;
    }
}









// I wrote something to check for primes, but the below recursion should reach primes first as a default
void ProjectsObj::Project3CalcRecMethod(int num)
{
    int largestFactor;
    
    largestFactor = Project3Recurse(num);

    std::cout << "Largest prime factor: " << largestFactor << "\n";
}

int ProjectsObj::Project3Recurse(int num)
{
    int reducedNum;
    int i = 2;

    while (true)
    {
        if (num % i == 0)
        {
            reducedNum = num / i;
            if (reducedNum == 1)
                return i;
            return Project3Recurse(reducedNum);
        }
        i++;
    }
}



bool ProjectsObj::Project3CheckPrime(int p)
{
    int check = 2;
    while (check < p)
    {
        if (p % check == 0)
            return false;
    }
    return true;
}