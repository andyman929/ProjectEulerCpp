/*
Every triangle has a circumscribed circle that goes through the three vertices. Consider all integer sided triangles for which the radius of the circumscribed circle is integral as well.

Let S(n) be the sum of the radii of the circumscribed circles of all such triangles for which the radius does not exceed n.

S(100)=4950 and S(1200)=1653605.

Find S(10^7).


https://hsm.stackexchange.com/questions/10997/what-is-the-modern-context-of-gausss-work-on-triangles-with-integer-sides-and-c
*/


#include <iostream>
#include "ProjectHeads.h"

#define Round2Int(x) (int)(x > 0 ? (x + 0.5) : (x - 0.5))

using namespace std;

void ProjectsObj::Project373Gauss(const int max)
{
    long fgmax = sqrt(max)/2;
    long abmax = sqrt(sqrt(max));
    long radiusTotal = 0;
    for (long a = 0; a <= abmax; a++)
    {
        for (long b = 0; b <= abmax; b++)
        {
            for (long f = 0; f <= fgmax; f++)
            {
                for (long g = 0; g <= fgmax; g++)
                {
                    long rad = (a * a + b * b) * (a * a * f * f + b * b * g * g);
                    if (rad == 0)
                        continue;
                    if (rad > max)
                        break;
                    radiusTotal += rad;
                }
            }
        }
    }
    cout << "The sum of all circumscribed radii less than " << max << " is: " << radiusTotal << "\n";
}