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
^^^Niven's doesn't apply here
*/

#include <iostream>
#include "ProjectHeads.h"

#define Round2Int(x) (int)(x > 0 ? (x + 0.5) : (x - 0.5))
#define Round2Int64(x) (__int64)(x > 0 ? (x + 0.5) : (x - 0.5))
#define TOLERANCE 0.000000000001

using namespace std;

/*
Second method:
for side lengths a,b,c
R = a*b*c/sqrt((a+b+c)*(-a+b+c)*(a-b+c)*(a+b-c))
Can create random triangles with abc provided they satisfy some conditions (not random but unplanned)
n is the max radius we want
This means we can assume all side lengths are less than or equal to n as they have to fit inside the circle
Set b <= a <= n. Obviously greater than or equal to 1 too
Need to satisfy a+b>c, a+c>b, b+c>a
So set c with max(|a-b|, 1) < c < min(a+b,n)
Removed looping stuff, so far it isn't working out


cosine could work instead. It turns out that cos(A) = (b*b + c*c - a*a)/(2*b*c)
then sin(A) = sqrt(1-cos(A)*cos(A)).
finally, radius = a/sin(A)
I can cheat here and use long doubles to maintain precision rather than ints, not sure on another way to do this for 10^7
*/
void ProjectsObj::Project373Calc(__int64 n)
{
    __int64 circleCount = 0;
    __int64 totalRadius = 0;

    for (__int64 a = 1; a <= n; a++)
    {
        for (__int64 b = 1; b <= a; b++)
        {
            for (__int64 c = 1; c <= b; c++)
            {
                // a >= b >= c to ensure all triangles in this loop are unique
                // check below to ensure that this can actually be a triangle (triangle rule). Skip if not.
                if (b + c <= a)
                    continue;

                long double sinA = Project373SinX(a, b, c);
                long double radius = a/sinA;
                __int64 radiusRounded = Round2Int64(radius);
                // Try checking that if the integer cast to a double gives the same value, this would suggest the long double is then an integer
                //if (radius == (long double)radiusRounded)
                if (radius - radiusRounded > TOLERANCE || radiusRounded - radius > TOLERANCE)
                    continue;
                if (radiusRounded > n)
                    continue;
                circleCount += 1;
                totalRadius += radiusRounded;
                //cout << "Valid triangle " << a << ", " << b << ", " << c << " found\n";
            }

        }

    }

    cout << "Circles: " << circleCount << "\n" << "Sum of radii: " << totalRadius << "\n";
}


// Simple loop to check if a number is square
long double ProjectsObj::Project373SinX(__int64 x, __int64 y, __int64 z)
{

    long double cosX = (long double)(y * y + z * z - x * x) / (long double)(2 * y * z);
    long double sinX = sqrt(1 - cosX * cosX);
    return sinX;
}


// Simple function to check if two points are
bool ProjectsObj::Project373IsIntegral(coordinate n, coordinate m)
{
    int dist;
    dist = (n.x - m.x) * (n.x - m.x) + (n.y - m.y) * (n.y - m.y);
    return Project373IsSquare(dist);
}

// Simple loop to check if a number is square
bool ProjectsObj::Project373IsSquare(__int64 inp)
{
    __int64 sqr;
    sqr = Round2Int64(sqrt(inp));
    sqr = sqr * sqr;
    if (sqr == inp)
        return true;
    return false;
}
