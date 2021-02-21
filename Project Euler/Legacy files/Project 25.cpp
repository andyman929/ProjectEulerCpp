/*
The Fibonacci sequence is defined by the recurrence relation:

Fn = Fn-1 + Fn-2, where F1 = 1 and F2 = 1.
Hence the first 12 terms will be:

F1 = 1
F2 = 1
F3 = 2
F4 = 3
F5 = 5
F6 = 8
F7 = 13
F8 = 21
F9 = 34
F10 = 55
F11 = 89
F12 = 144
The 12th term, F12, is the first term to contain three digits.

What is the index of the first term in the Fibonacci sequence to contain 1000 digits?
*/



#include <iostream>
#include <vector>
#include "ProjectHeads.h"

using namespace std;

void ProjectsObj::Project25Calc(int digits)
{
    vector<int> factn;
    factn.push_back(1);
    vector<int> factn_1;
    factn_1.push_back(1);
    vector<int> factn_2;
    int n = 2;

    while (factn.size() < digits)
    {
        n++;
        factn_2 = factn_1;
        factn_1 = factn;
        int n1Size = factn_1.size();
        int n2Size = factn_2.size();
        factn.clear();
        factn.push_back(factn_1[0] + factn_2[0]);
        for (int i = 1; i < n1Size; i++)
        {
            if (i >= n2Size)
            {
                // Accounting for chance larger has more digits
                factn.push_back(factn_1[i] + (factn[i - 1] / 10));
            }
            else
            {
                factn.push_back(factn_1[i] + factn_2[i] + (factn[i - 1] / 10));
            }
        }
        while (factn.back() >= 10)
        {
            factn.push_back(factn.back() / 10);
        }
        for (int i = 0; i < factn.size(); i++)
        {
            factn[i] = factn[i] % 10;
        }
    }
    /*
    for (int i = factn.size() - 1; i >= 0; i--)
    {
        cout << factn[i];
    }
    */
    cout << "\n";
    std::cout << "First Fibonacci term with more than " << digits << " digits is: " << n << "\n";
}
