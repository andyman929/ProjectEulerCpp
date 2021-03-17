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

void ProjectsObj::SetCheck(sequence& s, sols& s2)
{
    int fullsum = 0;
    for (int x : s)
        fullsum += x;
    if (s2.size() > 0)
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
        SetCheck(s, s2);
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

void ProjectsObj::Project103CalcOld()
{
    constexpr int size = 7;
    int S6[6] = { 11,18,19,20,22,25 };
    // S7base gives a suboptimal attempt at the set
    int S7base[7];
    std::fill_n(S7base, 7, S6[3]);
    int testsum = S6[3];
    for (int i = 1; i <= 6; i++)
    {
        S7base[i] += S6[i - 1];
        testsum += S7base[i];
    }
 
    // Make some pieces to adjust the suboptimal solution, assuming the actual answer is within 3 for each element
    constexpr int maxadjust = 25;
    constexpr int minadjust = -maxadjust;

    int adjust[size];
    std::fill_n(adjust, 7, minadjust);

    // This gives the lowest successful shift. Starts at 0 for S7base, should only check pairs if the permutation has lower shift
    int minshift = 0;
    // Store the minimum working set. 
    int* minshifted = new int[size];
    do
    {
        // If the shift is smaller than that already found, skip
        int shift = Sum(adjust, size);
        if (shift >= minshift)
            continue;
        // Get the adjusted set
        int* test = new int[size];
        Add(test, S7base, adjust, size);
        // Test against out test sets in order of how many checks there are to do
        if (!Proj103Test1Zero(test, size))
            continue;
        if (!Proj103Test2Zero(test, size))
            continue;
        if (!Proj103Test3Zero(test, size))
            continue;
        minshift = shift;
        minshifted = test;
    } while (Proj103NextAdjustment(adjust, size, minadjust, maxadjust));


    std::cout << "Lowest cost for a pre-fix code of size " << minshifted[0];
    for (int i = 1; i < size; i++)
    {
        std::cout << ", " << minshifted[i];
    }
    std::cout << std::endl;
}

inline int ProjectsObj::Sum(int* arr, int sz)
{
    int sum = 0;
    for (int i = 0; i < sz; i++)
    {
        sum += arr[i];
    }
    return sum;
}

inline void ProjectsObj::Add(int* out, int* arr1, int* arr2, int sz)
{
    for (int i = 0; i < sz; i++)
    {
        out[i] = arr1[i] + arr2[i];
    }
}

bool ProjectsObj::Proj103NextAdjustment(int* c, int sz, int minadj, int maxadj)
{
    bool carry = false;
    if (c[0] == maxadj)
    {
        c[0] == minadj;
        carry = true;
    }
    else
    {
        c[0]++;
    }
    for (int i = 1; i < sz; i++)
    {
        if (!carry)
            break;
        if (c[i] == maxadj)
        {
            c[i] == minadj;
            carry = true;
        }
        else
        {
            c[i]++;
            carry = false;
        }
    }
    return !carry;
}

bool ProjectsObj::Proj103Test1Zero(int* const arr, const int sz)
{
    std::vector<int> test = { 1,1,1,1,1,1,0 };
    for (int i = 6; i >= 0; i--)
    {
        int la = 0;
        int sm = 0;
        for (int j = 0; j < sz; j++)
        {
            if (test[j] == 1)
                la += arr[j];
            else
                sm += arr[j];
        }
        if (sm >= la)
            return false;

        if (i == 0)
            break;

        test[i] = 1;
        test[i - 1] = 0;
    }
    return true;
}

bool ProjectsObj::Proj103Test2Zero(int* const arr, const int sz)
{
    std::vector<int> test = { 1,1,1,1,1,0,0 };
    for (int i = 6; i >= 1; i--)
    {
        for (int k = i - 1; k >= 0; k--)
        {
            int la = 0;
            int sm = 0;
            for (int j = 0; j < sz; j++)
            {
                if (test[j] == 1)
                    la += arr[j];
                else
                    sm += arr[j];
            }
            if (sm >= la)
                return false;

            if (k == 0)
            {
                test[k] = 1;
                break;
            }
            test[k] = 1;
            test[k - 1] = 0;
        }

        if (i == 1)
            break;
        test[i] = 1;
        test[i - 1] = 0;
        test[i - 2] = 0;
    }
    return true;
}

bool ProjectsObj::Proj103Test3Zero(int* const arr, const int sz)
{
    std::vector<int> test = { 1,1,1,1,0,0,0 };
    for (int i = 6; i >= 2; i--)
    {
        for (int j = i - 1; j >= 1; j--)
        {
            for (int k = j - 1; k >= 0; k--)
            {
                int la = 0;
                int sm = 0;
                for (int M = 0; M < sz; M++)
                {
                    if (test[M] == 1)
                        la += arr[M];
                    else
                        sm += arr[M];
                }
                if (sm >= la)
                    return false;

                if (k == 0)
                    break;

                test[k] = 1;
                test[k - 1] = 0;
            }

            if (j == 1)
                break;

            test[j] = 1;
            test[j - 1] = 0;
            test[j - 2] = 0;
        }

        if (i == 2)
            break;

        test[i] = 1;
        test[i - 1] = 0;
        test[i - 2] = 0;
        test[i - 3] = 0;
    }
}