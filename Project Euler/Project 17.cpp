/*
If the numbers 1 to 5 are written out in words: one, two, three, four, five, then there are 3 + 3 + 5 + 4 + 4 = 19 letters used in total.

If all the numbers from 1 to 1000 (one thousand) inclusive were written out in words, how many letters would be used?


NOTE: Do not count spaces or hyphens. For example, 342 (three hundred and forty-two) contains 23 letters and 115 (one hundred and fifteen) contains 20 letters. The use of "and" when writing out numbers is in compliance with British usage.
*/



#include <iostream>
#include "ProjectHeads.h"

using namespace std;

void ProjectsObj::Project17Calc(int minN, int maxN)
{
    string number;
    bool thousandsplus;
    int num;
    int sum = 0;
    for (int i = maxN; i >= minN; i--)
    {
        number = "";
        thousandsplus = false;
        num = i;
        if (num >= 1000)
        {
            number += Project17ReturnHundreds(num / 1000, false) + "thousand";
            thousandsplus = true;
            num -= 1000;
        }
        number += Project17ReturnHundreds(num, thousandsplus);
        cout << number << "\n";
        sum += number.length();
    }
    // cout << "Sum of the length of numbers from " << minN << " to " << maxN << " is: " << sum << "\n";
}

string ProjectsObj::Project17ReturnHundreds(int n, bool thou)
{
    string out = "";
    int digit;
    int doubledig = n;
    if (n >= 100)
    {
        digit = n / 100;
        out += Project17DigitString(digit) + "hundred";
        doubledig = n - 100 * digit;
        if (doubledig != 0)
            out += "and";
    }
    else
    {
        if (thou && n != 0)
            out += "and";
    }

    out += Project17DoubleDigitString(doubledig);

    return out;
}

// Return a string name for a number from 1-9
string ProjectsObj::Project17DigitString(int n)
{
    string out;
    switch (n)
    {
    case 1:
        out = "one";
        break;
    case 2:
        out = "two";
        break;
    case 3:
        out = "three";
        break;
    case 4:
        out = "four";
        break;
    case 5:
        out = "five";
        break;
    case 6:
        out = "six";
        break;
    case 7:
        out = "seven";
        break;
    case 8:
        out = "eight";
        break;
    case 9:
        out = "nine";
        break;
    default:
        break;
    }
    return out;
}

std::string ProjectsObj::Project17DoubleDigitString(int n)
{
    string out = "";
    int digit;
    if (n >= 20)
    {
        out += Project17TensString(n);
        digit = n / 10;
        digit = n - 10 * digit;
        out += Project17DigitString(digit);
    }
    else if (n >= 10)
    {
        out += Project17Teens(n);
    }
    else if (n > 0)
    {
        out += Project17DigitString(n);
    }

    return out;
}

std::string ProjectsObj::Project17TensString(int n)
{
    string out = "";
    if (n < 30)
        out = "twenty";
    else if (n < 40)
        out = "thirty";
    else if (n < 50)
        out = "forty";
    else if (n < 60)
        out = "fifty";
    else if (n < 70)
        out = "sixty";
    else if (n < 80)
        out = "seventy";
    else if (n < 90)
        out = "eighty";
    else
        out = "ninety";

    return out;
}

std::string ProjectsObj::Project17Teens(int n)
{
    string out = "";
    switch (n)
    {
    case 10:
        out = "ten";
        break;
    case 11:
        out = "eleven";
        break;
    case 12:
        out = "twelve";
        break;
    case 13:
        out = "thirteen";
        break;
    case 14:
        out = "fourteen";
        break;
    case 15:
        out = "fifteen";
        break;
    case 16:
        out = "sixteen";
        break;
    case 17:
        out = "seventeen";
        break;
    case 18:
        out = "eighteen";
        break;
    default:
        out = "nineteen";
        break;
    }

    return out;
}
