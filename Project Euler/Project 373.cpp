/*
Every triangle has a circumscribed circle that goes through the three vertices. Consider all integer sided triangles for which the radius of the circumscribed circle is integral as well.

Let S(n) be the sum of the radii of the circumscribed circles of all such triangles for which the radius does not exceed n.

S(100)=4950 and S(1200)=1653605.

Find S(10^7).
*/

/*
Grid based thing. Let's start with a centre point of the grid as the first vertex

Start with vertical point to (0,k).
Insert a third point (a,b). It is important then that this gives integral side lengths sqrt(a^2 + b^2) and sqrt(a^2 + (b-k)^2)

It's fair to assume that the line (0,0) -> (a,b) is shorter than (0,0) -> (0,k). We can also assume a > 0.

Then, (a,b) -> (0,k) < 2k.

So we can check create loop through ks, getting bigger as needed
Then loop through (a,b), with a>0, sqrt(a^2+b^2) <= k. So fix an a then loop through b by setting b = (int)sqrt(k^2-a^2), repeat to minus that
Then, check the length of (0,k)->(a,b). Should be easy enough (simple loop function to do this)

Once the three lengths are known we can guess on the rest


ROUND2:
The below is messy and doesn't work but should eventually get the right answers, doesn't yet.
^^^ Won't get the right answer, no real reason to think that an integer length edge will end at an integer valued coordinate

Other thing though is that I may be able to get to this much more easily using Niven's theorm and some other stuff maybe.


Third method. I think between two theorems this becomes simple. Firstly, the radius of the circumscribed circle is
given by a/2sin(A), for side length a and it's opposite angle A. This means that, given a must be an integer, the value of
sin(A) must be rational.

Therefore, A = 30, 90, 150 by Niven's Theorem

Given the a/2sin(A) relationship is true for all sides, this means each angle is one of 30,90,150
Therefore, we have A = 90, B = 30, C = 30
*/

#include <iostream>
#include "ProjectHeads.h"

#define Round2Int(x) (int)(x > 0 ? (x + 0.5) : (x - 0.5))

using namespace std;

/* 
Second method:
for side lengths a,b,c
R = abc/(
*/
void ProjectsObj::Project373Calc(int radius)
{
    int circumRadius;
    int intRadiusCount = 0;
    int cYLimit;
    int cX, cY;
    coordinate a, b, c;
    a.x = 0;
    a.y = 0;
    b.x = 0;

    int lengthAB, lengthAC, lengthBC;
    int semiPerim, denom, numer;

    int kLimit = 2 * radius; // This is a bit of a guess, but I think it makes sense
    for (int k = 1; k <= kLimit; k++)
    {
        b.y = k;
        lengthAB = k;
        for (cX = 1; cX <= k; cX++)
        {
            c.x = cX;
            cYLimit = Round2Int(sqrt(k * k - cX * cX));
            for (cY = cYLimit; cY >= -cYLimit; cY--)
            {
                c.y = cY;
                if (!Project373IsIntegral(a, c))
                    continue;
                if (!Project373IsIntegral(b, c))
                    continue;
                lengthAC = Round2Int((c.x - a.x) * (c.x - a.x) + (c.y - a.y) * (c.y - a.y));
                lengthBC = Round2Int((c.x - b.x) * (c.x - b.x) + (c.y - b.y) * (c.y - b.y));

                semiPerim = (lengthAB + lengthAC + lengthBC) / 2;
                denom = semiPerim * (semiPerim - lengthAB) * (semiPerim - lengthAC) * (semiPerim - lengthBC);
                if (!Project373IsSquare(denom))
                    continue;
                denom = 2 * Round2Int(sqrt(denom));
                numer = lengthAB * lengthAC * lengthBC;
                if (numer % denom != 0)
                    continue;
                circumRadius = numer / denom;
                if (circumRadius < radius)
                    intRadiusCount += 1;
            }
        }
    }
    cout << "Circles: " << intRadiusCount << "\n";
}


// Original method to try and loop through lots of cases
/*
void ProjectsObj::Project373Calc(int radius)
{
    int circumRadius;
    int intRadiusCount = 0;
    int cYLimit;
    int cX, cY;
    coordinate a, b, c;
    a.x = 0;
    a.y = 0;
    b.x = 0;

    int lengthAB, lengthAC, lengthBC;
    int semiPerim, denom, numer;

    int kLimit = 2 * radius; // This is a bit of a guess, but I think it makes sense
    for (int k = 1; k <= kLimit; k++)
    {
        b.y = k;
        lengthAB = k;
        for (cX = 1; cX <= k; cX++)
        {
            c.x = cX;
            cYLimit = Round2Int(sqrt(k * k - cX * cX));
            for (cY = cYLimit; cY >= -cYLimit; cY--)
            {
                c.y = cY;
                if (!Project373IsIntegral(a, c))
                    continue;
                if (!Project373IsIntegral(b, c))
                    continue;
                lengthAC = Round2Int((c.x - a.x) * (c.x - a.x) + (c.y - a.y) * (c.y - a.y));
                lengthBC = Round2Int((c.x - b.x) * (c.x - b.x) + (c.y - b.y) * (c.y - b.y));

                semiPerim = (lengthAB + lengthAC + lengthBC) / 2;
                denom = semiPerim * (semiPerim - lengthAB) * (semiPerim - lengthAC) * (semiPerim - lengthBC);
                if (!Project373IsSquare(denom))
                    continue;
                denom = 2 * Round2Int(sqrt(denom));
                numer = lengthAB * lengthAC * lengthBC;
                if (numer % denom != 0)
                    continue;
                circumRadius = numer / denom;
                if (circumRadius < radius)
                    intRadiusCount += 1;
            }
        }
    }
    cout << "Circles: " << intRadiusCount << "\n";
}
*/


// Simple function to check if two points are 
bool ProjectsObj::Project373IsIntegral(coordinate n, coordinate m)
{
    int dist;
    dist = (n.x - m.x) * (n.x - m.x) + (n.y - m.y) * (n.y - m.y);
    return Project373IsSquare(dist);
}

// Simple loop to check if a number is square
bool ProjectsObj::Project373IsSquare(int inp)
{
    for (int i = 1; i < sqrt(inp) + 1; i++)
    {
        if (i * i == inp)
            return true;
    }
    return false;
}