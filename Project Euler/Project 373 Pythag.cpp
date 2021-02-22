/*
Every triangle has a circumscribed circle that goes through the three vertices. Consider all integer sided triangles for which the radius of the circumscribed circle is integral as well.

Let S(n) be the sum of the radii of the circumscribed circles of all such triangles for which the radius does not exceed n.

S(100)=4950 and S(1200)=1653605.

Find S(10^7).
*/


#include <iostream>
#include "ProjectHeads.h"

#define Round2Int(x) (int)(x > 0 ? (x + 0.5) : (x - 0.5))

using namespace std;

struct triple {
    long x;
    long y;
    long z;
};

int gcd(long a, long b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

void ProjectsObj::Project373Pyth(const int max)
{
    const int N = max + 1;
    vector<vector<triple>> PrimitiveTriples(N);

    // Generate a set of all primitive pythag triples with largest value less than the max radius
    for (long u = 1; u * u <= max; u++)
    {
        for (long v = 1; v < u && u * u + v * v <= max; v++)
        {
            if (gcd(u, v) == 1 && (u - v) % 2 != 0)
            {
                long a = u * u - v * v;
                long b = 2 * u * v;
                long c = u * u + v * v;
                // Include twice to allow for pairs to be paired up
                triple trip = { a, b, c };
                PrimitiveTriples[c].push_back(trip);
                PrimitiveTriples[c].push_back(trip);
            }
        }
    }

    // Set up radius counter
    long radiusTotal = 0;

    for (int d = 1; d <= max; d++)
    {
        vector<triple> TripleSet;
        // Select sets of triple into single vector for easy looping. Only those needed in the current comparison for gcd == d
        for (int i = 1; i * d <= max; i++)
        {
            for (triple x : PrimitiveTriples[i * d])
            {
                TripleSet.push_back(x);
            }
        }

        // Loop through all possible pairs (will do some checks to make sure you haven't flipped a pair later
        for (triple t1 : TripleSet)
        {
            for (triple t2 : TripleSet)
            {
                // Preview of calculation of radius. If the raidus*gcd is too large it isn't useful. It will keep getting larger so just break
                if (t1.z * t2.z > d * max)
                    break;

                // Check that gcd of the current pair matches the loop we are in
                long gcm = gcd(t1.z, t2.z);
                if (gcm != d)
                    continue;

                // Generate side lengths for the triple pair generated triangle.
                long x = t1.x * t2.z;
                long y = t1.z * t2.x;
                long z = t1.x * t2.y + t1.y * t2.x;

                // Check that the triangle sort of works and that it isn't a flipped version of an earlier triangle
                if (x <= y && y <= z)
                {
                    // Calculate diameter
                    long diam = t1.z * t2.z;

                    // Maybe somewhat coincidental, but using diam or radius is irrelevant, I think due to the scaling step. So just don't bother converting

                    // Convert to integral radius
                    long radius = diam;// / 2;

                    // GCD of the sides and diameter gives us a scaling factor to reduce the triangle to its smallest size
                    long gcm = gcd(x, gcd(y, gcd(z, radius)));

                    // Divide through by factor
                    x /= gcm;
                    y /= gcm;
                    x /= gcm;
                    radius /= gcm;

                    // Find the (whole) number of times the radius/triangle can be multiplied up and still fit within the maximum
                    long mult = max / radius;
                    
                    // Radius added to total, using the fact (1 + 2 + ... + mult)*radius = mult*(1+mult)/2*radius
                    radiusTotal += (mult * (1 + mult) / 2) * radius;
                }
            }
        }
    }

    cout << "The sum of all circumscribed radii less than " << max << " is: " << radiusTotal << "\n";
}