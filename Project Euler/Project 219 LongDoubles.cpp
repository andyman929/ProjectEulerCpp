/*
Let A and B be bit strings (sequences of 0's and 1's).
If A is equal to the leftmost length(A) bits of B, then A is said to be a prefix of B.
For example, 00110 is a prefix of 001101001, but not of 00111 or 100110.

A prefix-free code of size n is a collection of n distinct bit strings such that no string is a prefix of any other. For example, this is a prefix-free code of size 6:

0000, 0001, 001, 01, 10, 11

Now suppose that it costs one penny to transmit a '0' bit, but four pence to transmit a '1'.
Then the total cost of the prefix-free code shown above is 35 pence, which happens to be the cheapest possible for the skewed pricing scheme in question.
In short, we write Cost(6) = 35.

What is Cost(10^9) ?
*/


/*
Project 219 converted to use long doubles instead of integers
*/

#include <iostream>
#include "ProjectHeads.h"

using namespace std;

void ProjectsObj::Ld219Calc(double chain)
{
    vector<double> dist;
    double holder;
    long double cost = 0;
    double totalCost;

    dist.resize(4);
    // base node with a cost of 0
    dist[0] = 1;
    // cost of 0 for any other node
    dist[1] = 0;
    dist[2] = 0;
    dist[3] = 0;

    // Expansion step
    while (Ld219NodeCount(dist) < chain)
    {
        // Increment the cost as the vector shifts along
        cost++;
        // Cycle the vector around with the lowest price added in at cost and cost+3
        holder = dist[0];
        dist[0] += dist[1];
        dist[1] = dist[2];
        dist[2] = dist[3];
        dist[3] = holder;
    }
    // The is a good chance that the above give too many nodes, so we need to reduce
    // Add in an extra element to the vector to handle the extra cost now needed, shift elements and price too
    dist.resize(5);
    for (int i = 4; i > 0; i--)
    {
        dist[i] = dist[i - 1];
    }
    dist[0] = 0;
    cost--;

    // How many nodes too many?
    int excess = Ld219NodeCount(dist) - chain;

    // Largest nodes need to be unsplit and moved back to lower cost node. This means removing
    // from cost+1 and cost+4 and transferring back to cost
    dist[1] -= excess;
    dist[4] -= excess;
    dist[0] = excess;

    totalCost = Ld219Cost(cost, dist);

    cout << "Minimum cost for a pre-fix code of size " << chain << " is: " << totalCost << "\n";
}
long double ProjectsObj::Ld219Cost(double cost, vector<double> distribution)
{
    long double price = 0;
    for (int i = 0; i < distribution.size(); i++)
    {
        price += (long double)distribution[i] * (long double)(cost + i);
    }
    return price;
}
double ProjectsObj::Ld219NodeCount(vector<double> distribution)
{
    double sum = 0;
    for (double i = 0; i < distribution.size(); i++)
    {
        sum += distribution[i];
    }
    return sum;
}
