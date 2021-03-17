/*
Special subset sums
*/

#include "pch_euler.h"

void ProjectsObj::Project103Calc(int vectSize)
{
    int minElement = 1;
    int maxElement = 10;
    if (vectSize >= 5)
    {
        maxElement = vectSize * vectSize;
        minElement = maxElement / 4;
    }

    sequence seq;
    sols solutions;

    SetSearch(seq, minElement, maxElement, vectSize, solutions);
    auto solIter = solutions.begin()->second;
    std::cout << "Solution is " << solIter[0];
    for (int i = 1; i < solIter.size(); i++)
        std::cout << ", " << solIter[i];
    std::cout << std::endl;
}

void ProjectsObj::SetCheck(sequence& s, sols& s2, bool findMin)
{
    int fullsum = 0;
    for (int x : s)
        fullsum += x;
    if (s2.size() > 0 && findMin)
    {
        if (s2.begin()->first <= fullsum)
            return;
    }

    std::vector<bool> sums(fullsum + 1, false);

    std::vector<int> maxSum(s.size() + 1, 0);
    std::vector<int> minSum(s.size() + 1, fullsum + 1);

    int fullmask = (1 << s.size()) - 1;

    for (int mask = 1; mask <= fullmask; mask++)
    {
        int sum = 0;
        int size = 0;
        for (int ele = 0; ele < s.size(); ele++)
        {
            int bit = 1 << ele;
            if ((mask & bit) == 0)
                continue;
            sum += s[ele];
            size++;
        }

        if (sums[sum])
            return;
        sums[sum] = true;

        if (minSum[size] > sum)
            minSum[size] = sum;
        if (maxSum[size] < sum)
            maxSum[size] = sum;
    }

    for (int i = 1; i < s.size(); i++)
        if (maxSum[i] > minSum[i + 1])
            return;

    s2[fullsum] = s;
}

void ProjectsObj::SetSearch(sequence& s, const int miny, const int maxy, const int size, sols& s2)
{
    if (s.size() == size)
    {
        SetCheck(s, s2, true);
        return;
    }

    auto last = s.empty() ? miny - 1 : s.back();
    for (int i = last + 1; i <= maxy; i++)
    {
        s.push_back(i);
        SetSearch(s, miny, maxy, size, s2);
        s.pop_back();
    }
}