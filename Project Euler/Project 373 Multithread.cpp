#include <iostream>
#include <future>
#include <chrono>
#include <vector>
#include "ProjectHeads.h"

#define Round2Int(x) (int)(x > 0 ? (x + 0.5) : (x - 0.5))
#define Round2Int64(x) (__int64)(x > 0 ? (x + 0.5) : (x - 0.5))
#define TOLERANCE 0.000000000001

//using namespace std;
using namespace std::chrono_literals;

// From caller we need an output from this function. This will be a sum of the radii of circles with triangle of side length a
__int64 ProjectsObj::Project373TriangleThread(__int64 n, __int64 a)
{
    __int64 totalRadius = 0;

    for (__int64 b = 1; b <= a; b++)
    {
        // This bound should ensure every c allows abc to actually be a triangle (triangle rule and such)
        int cLower = std::max((int)(a - b + 1), 1);
        for (__int64 c = cLower; c <= b; c++)
        {
            // a >= b >= c to ensure all triangles in this loop are unique

            long double sinA = Project373SinX(a, b, c);
            long double radius = a / sinA;
            __int64 radiusRounded = Round2Int64(radius);
            // Try checking that if the integer cast to a double gives the same value, this would suggest the long double is then an integer
            //if (radius == (long double)radiusRounded)
            if (radius - radiusRounded > TOLERANCE || radiusRounded - radius > TOLERANCE)
                continue;
            if (radiusRounded > n)
                continue;
            totalRadius += radiusRounded;
        }
    }
    return totalRadius;
}

// Caller for triangle mapping. The i loop is equivalent to looping through side a in the original function
void ProjectsObj::Project373TriangleCaller(__int64 n)
{
    std::vector<std::future<__int64>> handles;

    __int64 totalRadius = 0;
    int i = 1;
    constexpr int maxThreads = 16;
    auto waitTime = std::chrono::time_point<std::chrono::high_resolution_clock>(100ms);
    while (true)
    {
        if (handles.size() < maxThreads && i <= n)
        {
            handles.push_back(std::async(std::launch::async, &ProjectsObj::Project373TriangleThread, this, n, i));
            i++;
            continue;
        }
        for (int j = 0; j < handles.size(); )
        {
            if (handles[j].wait_until(waitTime) == std::future_status::ready)
            {
                totalRadius += handles[j].get();
                handles.erase(handles.begin() + j);
                continue;
            }
            // only iterate if the element was not erased
            j++;
        }
        if (i > n && handles.size() == 0)
            break;
    }
    std::cout << "Calculated total radius: " << totalRadius << "\n";
}


// Trying out multithreading a simple function (with a wait time to make a point). Did an inital version launching a single thread, then as many as needed in one go, then just limited to 10
void ProjectsObj::Project373CalcMultiThread(__int64 n)
{
    std::vector<std::future<int>> handles;

    int i = 0;
    constexpr int maxThreads = 10;
    auto waitTime = std::chrono::time_point<std::chrono::high_resolution_clock>(100ms);
    while (true)
    {
        if (handles.size() < maxThreads && i <= n)
        {
            handles.push_back(std::async(std::launch::async, &ProjectsObj::Project373CalcSimpleThread, this, i));
            i++;
            continue;
        }
        for (int j = 0; j < handles.size(); )
        {
            if (handles[j].wait_until(waitTime) == std::future_status::ready)
            {
                std::cout << "Output value " << handles[j].get() << "\n";
                handles.erase(handles.begin() + j);
                continue;
            }
            // only iterate if the element was not erased
            j++;
        }
        if (i > n && handles.size() == 0)
            break;
    }
}

int ProjectsObj::Project373CalcSimpleThread(int n)
{
    int out = n;// *n;
    std::this_thread::sleep_for(1s);
    return out;
}