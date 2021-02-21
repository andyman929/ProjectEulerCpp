/*
The sum of the squares of the first ten natural numbers is,
$$1^2 + 2^2 + ... + 10^2 = 385$$
The square of the sum of the first ten natural numbers is,
$$(1 + 2 + ... + 10)^2 = 55^2 = 3025$$
Hence the difference between the sum of the squares of the first ten natural numbers and the square of the sum is $3025 - 385 = 2640$.
Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.
*/



#include <iostream>
#include "ProjectHeads.h"

void ProjectsObj::Project6Calc(int lim)
{
    int sumOfInts = 0;
    int squareOfSum = 0;
    int sumOfSquares = 0;
    int difference = 0;

    sumOfInts = lim * (lim + 1) / 2;
    squareOfSum = sumOfInts*sumOfInts;
    sumOfSquares = lim * (lim + 1) * (2*lim + 1) / 6;

    difference = squareOfSum - sumOfSquares;

    std::cout << "Difference between sum of squares and square of sum of digits 1 to n(100): " << difference << "\n";
}