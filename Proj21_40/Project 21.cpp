/*
Let d(n) be defined as the sum of proper divisors of n (numbers less than n which divide evenly into n).
If d(a) = b and d(b) = a, where a != b, then a and b are an amicable pair and each of a and b are called amicable numbers.

For example, the proper divisors of 220 are 1, 2, 4, 5, 10, 11, 20, 22, 44, 55 and 110; therefore d(220) = 284. The proper divisors of 284 are 1, 2, 4, 71 and 142; so d(284) = 220.

Evaluate the sum of all the amicable numbers under 10000.
*/

#include "pch.h"

#define Round2Int(x) (int)(x > 0 ? (x + 0.5) : (x - 0.5))

using namespace std;


void ProjectsObjDll::Project21Calc(int count)
{
    amic.resize(count);
    fill(amic.begin(), amic.end(), false);
    amic_d = 0;

    for (int i = 1; i < count; i++)
    {
        Project21Amicable(i, -1, count);
    }


    cout << "The sum of all amicable numbers less than " << count << " is: " << amic_d << "\n";
}
// Outline: checks if the value is worth checking. If it is then the value is sent
// the d(n) value is calculated. If this is equal to itself then reject and go no further.
// If not, check if it is equal to the parent d(m). If it is then inp and parent inp are amicable, so add inp
// and return true so parent inp can be added in
// If neither of the above, use the currently calculated d(n) to check if n and d(n) are amicable (this is also base case for recursion)
// Need to behave a little differently if we don't want to count inp in the sum or track its state(its too large)
bool ProjectsObjDll::Project21Amicable(int inp, int parent, int max)
{
    bool aboveMax = inp >= max;
    // No point sending back anything reasonable if already checked
    if (!aboveMax)
    {
        if (amic[inp])
        {
            return false;
        }
        // Immediately set to true this is now being checked
        amic[inp] = true;
    }
    int d_inp;
    d_inp = Project21FactorsSum(inp);
    if (d_inp == inp)
    {
        // result is a definite no if the value is equal to itself, also means no need to return something useful
        return false;
    }
    if (d_inp == parent)
    {
        if (!aboveMax)
            amic_d += inp;
        cout << inp << " and ";
        return true;
    }
    
    // Don't bother checking further down the rabbit hole if the inp value is too large
    if (aboveMax)
        return false;
    
    bool amicable;
    amicable = Project21Amicable(d_inp, inp, max);
    if (amicable)
    {
        amic_d += inp;
        cout << inp << " are amicable\n";
    }

    return false;
}
int ProjectsObjDll::Project21FactorsSum(int inp)
{
    int sum = 0;

    for (int i = 1; i < inp; i++)
    {
        if (inp % i == 0)
            sum += i;
    }

    return sum;
}