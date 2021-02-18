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