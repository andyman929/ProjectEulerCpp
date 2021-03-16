/*
The primes 3, 7, 109, and 673, are quite remarkable. By taking any two primes and concatenating them in any order the result will always be prime. For example, taking 7 and 109, both 7109 and 1097 are prime. The sum of these four primes, 792, represents the lowest sum for a set of four primes with this property.

Find the lowest sum for a set of five primes for which any two primes concatenate to produce another prime.
*/

#include "pch.h"

// Making a potentially massive assumption that the below is enough to find the result. If not then we're in trouble
#define LIMIT 25000
#define LIMIT4 1000

using namespace std; 

// Version cut down to 4 primes to check the case provided
void Obj::Project60Calc4p()
{
    // Initialise sieve and prime list up to 1000
    Proj60Limit = LIMIT4;
    Proj60ExtendSieve();
    map<int, set<int>> pairsList;
    set<int> pairs1, pairs2, pairs3;
    int result = INT_MAX;

    for (int p1 : Proj60PrimesStart)
    {
        // unfortunate case I need to account for
        if (p1 == 0)
            continue;
        if (p1 * 4 >= result)
            continue;
        if (pairsList.count(p1) == 0)
            pairsList[p1] = Proj60BuildPairs(p1);
        pairs1 = pairsList[p1];

        for (int p2 : pairs1)
        {
            if (p1 + p2 * 3 >= result)
                break;
            if (pairsList.count(p2) == 0)
                pairsList[p2] = Proj60BuildPairs(p2);
            pairs2 = pairsList[p2];

            pairs2 = Proj60Intersect(pairs1, pairs2);

            for (int p3 : pairs2)
            {
                if (p1 + p2 + p3 * 2 >= result)
                    break;
                if (pairsList.count(p3) == 0)
                    pairsList[p3] = Proj60BuildPairs(p3);
                pairs3 = pairsList[p3];

                pairs3 = Proj60Intersect(pairs3, pairs2);
                
                if (pairs3.size() == 0)
                    continue;

                int p4 = *pairs3.begin();
                if (result > p1 + p2 + p3 + p4)
                {
                    result = p1 + p2 + p3 + p4;
                    std::cout << p1 << " + " << p2 << " + " << p3 << " + " << p4 << " = " << result << "\n";
                }
            }
        }
    }

    std::cout << "Smallest sum of 4 special primes is: " << result << "\n";
}

// Main calculation, around 90 seconds to run
void Obj::Project60Calc()
{
    // Initialise sieve and prime list up to 25000
    Proj60Limit = LIMIT;
    Proj60ExtendSieve();
    map<int, set<int>> pairsList;
    set<int> pairs1, pairs2, pairs3, pairs4;
    int result = INT_MAX;

    for (int p1 : Proj60PrimesStart)
    {
        // unfortunate case I need to account for
        if (p1 == 0)
            continue;
        if (p1 * 5 >= result)
            continue;
        if (pairsList.count(p1) == 0)
            pairsList[p1] = Proj60BuildPairs(p1);
        pairs1 = pairsList[p1];


        //for (int i2 = 1; i2 < Proj60Primes.size(); i2++)
        for (int p2 : pairs1)
        {
            if (p1 + p2 * 4 >= result)
                break;
            if (pairsList.count(p2) == 0)
                pairsList[p2] = Proj60BuildPairs(p2);
            pairs2 = pairsList[p2];

            pairs2 = Proj60Intersect(pairs1, pairs2);

            for (int p3 : pairs2)
            {
                if (p1 + p2 + p3 * 3 >= result)
                    break;
                if (pairsList.count(p3) == 0)
                    pairsList[p3] = Proj60BuildPairs(p3);
                pairs3 = pairsList[p3];

                pairs3 = Proj60Intersect(pairs3, pairs2);
                for (int p4 : pairs3)
                {
                    // prioritise looking for reasons to skip this prime to save time
                    if (p1 + p2 + p3 + p4 * 2 >= result)
                        break;

                    if (pairsList.count(p4) == 0)
                        pairsList[p4] = Proj60BuildPairs(p4);
                    pairs4 = pairsList[p4];

                    pairs4 = Proj60Intersect(pairs3, pairs4);

                    if (pairs4.size() == 0)
                        continue;

                    int p5 = *pairs4.begin();
                    if (result > p1 + p2 + p3 + p4 + p5)
                    {
                        result = p1 + p2 + p3 + p4 + p5;
                        cout << p1 << " + " << p2 << " + " << p3 << " + " << p4 << " + " << p5 << " = " << result << "\n";
                    }
                }
            }
        }
    }

    cout << "Smallest sum of 5 special primes is: " << result << "\n";
}


// Main calc with Map removed. Stores only the intersection subset through the loop. 68 seconds :)
void Obj::Project60CalcNoMap()
{
    // Initialise sieve and prime list up to 25000
    Proj60Limit = LIMIT;
    Proj60ExtendSieve();
    set<int> pairs1, pairs2, pairs3, pairs4;
    int result = INT_MAX;

    for (int p1 : Proj60PrimesStart)
    {
        // unfortunate case I need to account for
        if (p1 == 0)
            continue;
        if (p1 * 5 >= result)
            continue;

        pairs1 = Proj60BuildPairs(p1);

        //for (int i2 = 1; i2 < Proj60Primes.size(); i2++)
        for (int p2 : pairs1)
        {
            if (p1 + p2 * 4 >= result)
                break;

            pairs2 = Proj60PairsSubset(p2, pairs1);

            for (int p3 : pairs2)
            {
                if (p1 + p2 + p3 * 3 >= result)
                    break;

                pairs3 = Proj60PairsSubset(p3, pairs2);
                for (int p4 : pairs3)
                {
                    // prioritise looking for reasons to skip this prime to save time
                    if (p1 + p2 + p3 + p4 * 2 >= result)
                        break;

                    pairs4 = Proj60PairsSubset(p4, pairs3);

                    if (pairs4.size() == 0)
                        continue;

                    int p5 = *pairs4.begin();
                    if (result > p1 + p2 + p3 + p4 + p5)
                    {
                        result = p1 + p2 + p3 + p4 + p5;
                        cout << p1 << " + " << p2 << " + " << p3 << " + " << p4 << " + " << p5 << " = " << result << "\n";
                    }
                }
            }
        }
    }

    cout << "Smallest sum of 5 special primes is: " << result << "\n";
}

// Fill a vector with isprime true/false (reusing the Sieve of Eratosthenes from project 10)
// On the first run through it builds a list of the primes to be used in the scanning step above
// Other runs produce a new list every time so that it can be used to check primality(?) of later numbers
void Obj::Proj60ExtendSieve()
{
    int pos;
    int start;
    int restart;
    int end;
    bool build = true;

    if (Proj60Sieved.size() == 0)
    {
        start = 0;
        end = Proj60Limit;
        restart = 0;
    }
    else 
    {
        build = false;
        start = Proj60Sieved.size();
        restart = Proj60Sieved.size();
        end = 2 * restart;
    }

    Proj60Sieved.resize(end + 1);
    fill(Proj60Sieved.begin() + start, Proj60Sieved.end(), true);
    Proj60Sieved.at(1) = false;

    for (int loop = 1; loop <= sqrt(end); loop++)
    {
        if (Proj60Sieved.at(loop))
        {
            pos = loop * loop;
            // little optimisation
            if (pos < restart)
            {
                pos += ((restart - pos) / loop) * loop; // reposition to just before restart. might not even move in some cases but for some it's a huge difference
            }
            while (pos <= end)
            {
                Proj60Sieved.at(pos) = false;
                pos += loop;
            }
            
        }
    }

    int j = 1;
    int pEnd;
    pEnd = end + 1;

    Proj60Primes.clear();
    // loop through each un-added prime and add it to the list
    for (int j = 1; j < pEnd; j++)
    {

        if (Proj60Sieved[j])
        {
            Proj60Primes.push_back(j);
        }
    }

    if (build)
        Proj60PrimesStart = Proj60Primes;
}

// Simple function to check for prime and resize array if necessary
// New idea. There shouldn't be any need to check values beyond sqrt(p). This should massively reduce the need
// to extend the sieve. Should save time and a lot of memory.
bool Obj::Proj60IsPrime(int p)
{
    bool bigEnough = false;

    while (!bigEnough)
    {
        if (Proj60Primes.back() < sqrt(p))
        {
            Proj60ExtendSieve();
        }
        else
        {
            bigEnough = true;
        }
    }
    for (int primo : Proj60Primes)
    {
        if (p % primo == 0)
        {
            if (p == primo)
                return true;
            return false;
        }
    }
    return true;
}

// Concatenates pairs of numbers and checks if they are prime
bool Obj::Proj60CheckPrimes2(int p1, int p2)
{
    string testStr;
    __int64 testVal;

    testStr = to_string(p1) + to_string(p2);
    testVal = stoll(testStr);
    if (!Proj60IsPrime(testVal))
        return false;

    testStr = to_string(p2) + to_string(p1);
    testVal = stoll(testStr);
    if (!Proj60IsPrime(testVal))
        return false;

    return true;
}

// Return a list of all primes bigger than p that can be paired successfully. A faster implementation might involve
// only checking the subset, but this prevents the use of the map to store everything.
set<int> Obj::Proj60BuildPairs(int p)
{
    set<int> pairs;
    int index;
    auto it = find(Proj60Primes.begin(), Proj60Primes.end(), p);
    // If element was found
    if (it != Proj60Primes.end())
    {
        // calculating the index of prime
        index = it - Proj60Primes.begin();
    }
    else {
        index = 0;
        cout << "err - prime not found" << endl;
    }
    for (int i = index; i < Proj60Primes.size(); i++)
    {
        if (Proj60CheckPrimes2(p, Proj60Primes[i]))
        {
            pairs.insert(Proj60Primes[i]);
        }
    }
    return pairs;
}

// Finds the intersection of two sets
set<int> Obj::Proj60Intersect(set<int> s1, set<int> s2)
{
    int size = max(s1.size(), s2.size());

    vector<int> v1(s1.begin(), s1.end()), v2(s2.begin(), s2.end());
    vector<int> it(size);
    
    auto iter = set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), it.begin());

    it.resize(iter - it.begin());

    set<int> out(it.begin(), it.end());

    return out;
}

// Quicker? method of finding the intersection. Skips scanning, skips storing.
set<int> Obj::Proj60PairsSubset(int p, set<int> set1)
{
    set<int> intersect;
    for (int p2 : set1)
    {
        if (p2 > p)
        {
            if (Proj60CheckPrimes2(p, p2))
            {
                intersect.insert(p2);
            }
        }
    }
    return intersect;
}