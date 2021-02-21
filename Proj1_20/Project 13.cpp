/*
Work out the first ten digits of the sum of the following one-hundred 50-digit numbers.
*/

#include <fstream>
#include <string>
#include "pch.h"

#define Round2Int64(x) (__int64)(x > 0 ? (x + 0.5) : (x - 0.5))

using namespace std;

void ProjectsObj::Project13Calc()
{
    string line;
    long double lineVal;
    long double sum = 0;
    __int64 intsum = 0;
    ifstream inputData("Data\\Project 13.txt");
    if (!inputData.is_open())
    {
        cout << "Unable to open file";
        return;
    }
    while (getline(inputData, line))
    {
        lineVal = stold(line);
        sum += lineVal;
    }
    inputData.close();

    cout << "Sum of all lines: " << sum << "\n";
    while (sum > 10000000000)
    {
        sum /= 10;
    }
    intsum = Round2Int64(sum);

    cout << "First 10 digits: " << intsum << "\n";
}