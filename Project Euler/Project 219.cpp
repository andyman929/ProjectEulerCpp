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
Notes:
Problem has 0 bits much cheaper, so look to minimise those (as otherwise irrelevant). Can probably use a bit array or something to store all of this.
Looking for some code of size n.
Let the longest string be length k.

Thought about this while watching TV and I think the answer is to turn this into a (binary) tree problem. The branches being the 0/1 elements of the bit strings. If a string starts at
the base node and reaches some terminal node, then it cannot be the prefix of any other string, as this string would have to reach the terminal node and so would be identical.

This gives a good framing for the problem, the weighting of the branches still keeps some complexity. I think the simplest solution is to ignore the actual bit strings. We just need the cost of each node.
Then, we know from the binary tree that if we ever want to increase the number of terminal nodes we must take an existing terminal node and split into into two new ones, one of which will end in 0 and the other
in 1. This can be repeated any number of times and, crucially, the cost of this split and the creation of the two new nodes follows the same pattern on any part of the tree. This means we just need to track the
cost of getting to this node before we split it.
Also, we know that we will always want to split the cheapest node to reach, as this will produce the cheapest new nodes possible.

My proposed method of doing this is to use a multiset first populated with only 0 (base node) and then loop through splitting the cheapest node. Should be easy enough.
Multiset is useful as it orders itself and also allows duplicates (unlike set).
Once I have the required number of nodes in multiset I can just sum over the set and output the result
*/

#include <iostream>
#include "ProjectHeads.h"

using namespace std;

// For small numbers this worked fine, for the target number I gave up at around 3 hours.
// I think it was getting close but way too slow to be considered a success
void ProjectsObj::Project219Calc(int chain)
{
    int node;
    multiset<int> chainCosts;

    // Add base node
    chainCosts.insert(0);

    // Loop until required chain set length reached
    while (chainCosts.size() < chain)
    {
        // Get the cost of the cheapest node
        node = *chainCosts.begin();
        // Remove this node, it no longer exists after we add the connected nodes (at least not as a terminal node)
        chainCosts.erase(chainCosts.begin());
        // Add in the 0 branch terminal node
        chainCosts.insert(node + 1);
        // Add in the 1 branch terminal node
        chainCosts.insert(node + 4);
    }

    __int64 sum = 0;
    for (int i : chainCosts)
    {
        sum += i;
    }

    cout << "Lowest cost for a pre-fix code of size " << chain << " is: " << sum << "\n";
}

/*
The above process works in theory but in practice is incredibly slow. Must be a better way.
I think you can make a guess at the node costs, or at least get a range. I think every node should be within
5 of each other. i.e. if every cost was at 10, one would jump to 11 and another to 14. This splitting will
continue until all are 11/14, only then can thing max jump to 15, but now the gap is still only 4. This diverges from
zero not 10 but principle is the same.

Also, it makes sense that the minimum available would be 000...00000. The length of this chain is the final cost.
Scratch that, lowest or second lowest.
00000.....000001 (same as above but last bit swapped) will also be in and known as
lowest/second lowest + 3
There will also be a chain of 1s somewhere and a also this chain with last bit swapped. So interval of 5 that contains all node
values will also include a multiple of 4 and a value 3 less than this. (let's say true for n>=6)

This probably gives us enough to find the interval maybe if I can find a starting point

I think I need some understanding of the growth of the tree rather than growing the whole thing as I have been. Not
sure how to go about that though.

Question: Can I consider each node as a subtree?
    This would mean I can look for appropriate paths under each node recursively rather than searching the whole tree


Take this as a base structure, rather than the 0,1 structure. This provides output where I can continually add these
together rather than add up the much smaller nodes. Memory is still a major issue though.
As long as (chain-4)%3==0 this should work directly.
Also, given I would still have to add in all of these to the multiset I'm not convinced it would improve performance much/at all.

I think this subtree is ideal though, it keeps every node in a spot where can cycle through the node, then cycle through slightly
differently afterwards.     (subtree below is actually C(4))
                    X
                  /  \
                 4    1
                    /   \
                   5     2
                       /  \
                      6    3

Left -> right
{4,5,6,3}
after
{8,9,10,7,9,10,11,8,10,11,12,9,7,8,9,6}
sorted
{6,7,7,8,8,8,9,9,9,9,10,10,10,11,11,12}
This isn't really a cycle though, newset = {(set+3),(set+4),(set+5),(set+6)}
Our goal of making the elements fall within 4 of each other falls apart here though
6/16=3/8 of the resulting nodes are too low. Can split these individually though
Result
{7,10,8,11,8,11,9,12,9,12,9,12,9,9,9,9,10,10,10,11,11,12}
Sorted
{7,8,8,9,9,9,9,9,9,9,10,10,10,10,11,11,11,11,12,12,12,12}
3 more need sorting
{8,11,9,12,9,12,9,9,9,9,9,9,9,10,10,10,10,11,11,11,11,12,12,12,12}
nodes 4 -> 25
cost also increases, not sure I can actually manage this in the current way.

Not gonna work



Attempt 4.
I can try adding in something to partition the tree?
Set is made up of paths of cost n,n+1,n+2,n+3 at all points to maintain an option set for that collection of paths
i.e. each optimum set will be n-1,n,...,n+3, and this will be extended to n,...,n+3, which is optimal for however many
numbers there are in this set
say the count is (a,b,c,d)
up(set): n->n+1, (a,b,c,d) -> (b+a,c,d,a)

If this gets to large I have to partially split though, that might be more complicated, but only needing to track
4 integers growing is pretty huge as an improvement
Trying to write that out below
*/

// 9ms, so a ton faster than the other method
void ProjectsObj::Project219Calc2(int chain)
{
    vector<int> dist;
    int holder;
    int cost = 0;
    __int64 totalCost;

    dist.resize(4);
    // base node with a cost of 0
    dist[0] = 1;
    // cost of 0 for any other node
    dist[1] = 0;
    dist[2] = 0;
    dist[3] = 0;

    // Expansion step
    while (Project219NodeCount(dist) < chain)
    {
        // Increment the cost as the vector shifts along
        cost++;
        // Cycle the vector around with the lowest price added in at cost and cost+3
        holder = dist [0];
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
    int excess = Project219NodeCount(dist) - chain;

    // Largest nodes need to be unsplit and moved back to lower cost node. This means removing
    // from cost+1 and cost+4 and transferring back to cost
    dist[1] -= excess;
    dist[4] -= excess;
    dist[0] = excess;

    totalCost = Project219Cost(cost, dist);

    cout << "Minimum cost for a pre-fix code of size " << chain << " is: " << totalCost << "\n";
}
__int64 ProjectsObj::Project219Cost(int cost, vector<int> distribution)
{
    __int64 price = 0;
    for (int i = 0; i < distribution.size(); i++)
    {
        price += (__int64)distribution[i] * (__int64)(cost + i);
    }
    return price;
}
int ProjectsObj::Project219NodeCount(vector<int> distribution)
{
    int sum = 0;
    for (int i = 0; i < distribution.size(); i++)
    {
        sum += distribution[i];
    }
    return sum;
}
