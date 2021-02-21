/*
The prime factors of 13195 are 5, 7, 13 and 29.

What is the largest prime factor of the number 600851475143 ?
*/

#include "pch.h"

// Originally did this with recursion, trying to unpack into a for loop to clean up
// Did a couple things to make it more efficient. Skip increment if a factor is found which means the loop doesn't need to reset
// Also added a proper condition so the whole thing looks cleaner
void ProjectsObj::Project3Calc(long long num)
{
    long long currentMax = 0;
    long long reducedNum;
    long long testFactor = 2;

    reducedNum = num;

    while (reducedNum > 1)
    {
        if (reducedNum % testFactor == 0)
        {
            currentMax = testFactor;
            reducedNum /= currentMax;
        }
        else
        {
            testFactor++;
        }
    }
    
    std::cout << "Largest prime factor: " << currentMax << "\n";
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