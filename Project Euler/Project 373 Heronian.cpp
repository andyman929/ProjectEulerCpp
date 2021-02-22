/*
Every triangle has a circumscribed circle that goes through the three vertices. Consider all integer sided triangles for which the radius of the circumscribed circle is integral as well.

Let S(n) be the sum of the radii of the circumscribed circles of all such triangles for which the radius does not exceed n.

S(100)=4950 and S(1200)=1653605.

Find S(10^7).

Every heronian triangle has rational circumradius, so the wiki claims
https://hsm.stackexchange.com/questions/10997/what-is-the-modern-context-of-gausss-work-on-triangles-with-integer-sides-and-c
*/


#include <iostream>
#include "ProjectHeads.h"

#define Round2Int(x) (int)(x > 0 ? (x + 0.5) : (x - 0.5))

using namespace std;

int gcd2(long a, long b)
{
    if (b == 0)
        return a;
    return gcd2(b, a % b);
}
int gcd(long a, long b, long c)
{
    if (b < c)
    {
        long temp = c;
        c = b;
        b = temp;
    }
    if (a < c)
    {
        long temp = a;
        a = c;
        c = temp;
    }
    if (a < b)
    {
        long temp = a;
        a = b;
        b = temp;
    }
    return gcd2(a, gcd2(b, c));
}

void ProjectsObj::Project373Heron(const int max)
{
    long lmax = sqrt(max);
    long radiusTotal = 0;
    for (long m = 1; m <= lmax; m++)
    {
        for (long n = 1; n <= m; n++)
        {
            long kstart = (m * m * n / (2 * m + n)) < 1 ? 1 : (m * m * n / (2 * m + n));
            for (long k = kstart; k*k < m * n; k++)
            {
                if (gcd(m, n, k) != 1)
                    continue;
                long s = m * n * (m + n);
                long area = k * m * n * (m + n) * (m * n - k * k);
                long a = n * (m * m + k * k);
                long b = m * (n * n + k * k);
                long c = (m + n) * (m * n - k * k);
                long numer = a * b * c;
                long denom = 4 * area;
                if (numer % denom != 0)
                    continue;
                long rad = numer / denom;

                long m = max / rad;
                radiusTotal += m*(m+1)*rad;
            }
        }
    }
    cout << "The sum of all circumscribed radii less than " << max << " is: " << radiusTotal << "\n";
}