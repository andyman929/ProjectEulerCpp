/*
The square root of 2 can be written as an infinite continued fraction.

The infinite continued fraction can be written, ,  indicates that 2 repeats ad infinitum. In a similar way, .

It turns out that the sequence of partial values of continued fractions for square roots provide the best rational approximations. Let us consider the convergents for .

Hence the sequence of the first ten convergents for  are:

What is most surprising is that the important mathematical constant,
.
The first ten terms in the sequence of convergents for e are:

The sum of digits in the numerator of the 10th convergent is .

Find the sum of digits in the numerator of the 100th convergent of the continued fraction for .
*/

#include <iostream>
#include "RationalNumber.h"
#include "ProjectHeads.h"

#define Round2Int(x) (int)(x > 0 ? (x + 0.5) : (x - 0.5))

using namespace std;

// This setup using a rational numbers class currently overflows. Not sure on how I want to fix that.
void ProjectsObj::Project65Calc(int count)
{
    vector<int> contin;
    contin.push_back(2);
    contin.push_back(1);
    int j = 1;
    for (int i = 2; i < count; i++)
    {
        contin.push_back(2*j);
        contin.push_back(1);
        contin.push_back(1);
        j++;
    }
    while (contin.size() > count)
    {
        contin.erase(contin.end() - 1);
    }
    RationalNumber fract(0);
    for (int i = contin.size() - 1; i >= 0; i--)
    {
        if (i < contin.size() - 1)
            fract = 1 / fract;
        fract = contin[i] + fract;
    }

    cout << "The nth (n = " << count << ") convergent of e is " << fract.print() << "\n";
    int sum = 0;
    int num = fract.Numerator();
    while (num > 0)
    {
        sum += num % 10;
        num /= 10;
    }

    cout << "The sum of the digits of the numerator are " << sum << "\n";
}