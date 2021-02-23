/*
A permutation is an ordered arrangement of objects. For example, 3124 is one possible permutation of the digits 1, 2, 3 and 4. 
If all of the permutations are listed numerically or alphabetically, we call it lexicographic order. 
The lexicographic permutations of 0, 1 and 2 are:

012   021   102   120   201   210

What is the millionth lexicographic permutation of the digits 0, 1, 2, 3, 4, 5, 6, 7, 8 and 9?
*/

#include "pch.h"

#define Round2Int(x) (int)(x > 0 ? (x + 0.5) : (x - 0.5))

using namespace std;

/*
Scan through one digit at a time. This should get the answer.

Required structure:
Find a start digit 1-n. To do this, there are (n-1)! arrangements for each start, find maximum k such that k(n-1)! < req
Repeat with all other objects than the start digit. Looking for req = req-kth outcome
*/

int factorial(int a)
{
    if (a == 1)
        return 1;
    return a * factorial(a - 1);
}

void ProjectsObjDll::Project24Calc(int objects, int req)
{
    vector<int> order(objects);
    // Subtract 1 from vec as this looks for the nth position, but the vector is zero indexed
    Project24Recurse(&order, req-1, objects);
    // This will return a list that says use nth object, but list reduces, so need to account for that. Easy enough to do
    vector<int> digits;
    for (int i = 0; i < order.size(); i++)
        digits.push_back(i);
    for (int i = 0; i < order.size(); i++)
    {
        int pos = order[i];
        order[i] = digits[pos];
        digits.erase(digits.begin() + pos);
    }


    cout << "Where n = " << req << ", the nth lexicograthic order of " << objects << " digits is: ";
    for (int i = 0; i < order.size(); i++)
    {
        cout << order[i];
    }
    cout << "\n";
}
void ProjectsObjDll::Project24Recurse(vector<int>* order, int req, int objects)
{
    if (objects == 1)
    {
        order->at(order->size() - objects) = req;
        return;
    }

    int perStart = factorial(objects - 1);
    int k = req / perStart;
    // n objects to go => n from the end of objects
    order->at(order->size() - objects) = k;
    int newreq = req % perStart;
    objects--;
    Project24Recurse(order, newreq, objects);
}