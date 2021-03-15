/*
Pandigital primes - find the largest
*/

#include "pch.h"

using namespace std;

void Obj::Project41Calc()
{
    constexpr int maxPrime = 987654321;
    // Only need to find the primes below sqrt(maxPrime) in order to check primality of the bigger primes
    std::vector<int> plist = Proj41Sieve(sqrt(maxPrime));
    int out = 0;

    std::string digstring = "123456789";
    int maxpanprime = 0;
    while (digstring.size() > 0)
    {
        std::set<int> panprimes = GeneratePans(digstring, plist);
        if (panprimes.size() == 0)
        {
            digstring.erase(digstring.end() - 1);
            continue;
        }
        maxpanprime = *(panprimes.rbegin());
        break;
    }

    cout << "The largest pan-digital prime is " << maxpanprime << std::endl;
}

std::set<int> Obj::GeneratePans(std::string digits, const std::vector<int>& primes)
{
    std::set<int> panprimes;
    do
    {
        int value = std::stoi(digits);
        bool isPrime = true;
        for (auto p : primes)
        {
            if (p * p > value)
                break;
            if (value % p == 0)
            {
                isPrime = false;
                break;
            }
        }
        if (isPrime)
            panprimes.insert(value);
    } while (std::next_permutation(digits.begin(), digits.end()));
    return panprimes;
}

bool Obj::IsPandigital(const int val)
{
    int reduce = val;
    std::set<int> digits;
    int maxy = 0;
    while (reduce > 0)
    {
        int tmp = reduce % 10;
        if (tmp == 0)
            return false;
        if (digits.insert(tmp).second == false)
            return false;
        if (tmp > maxy)
            maxy = tmp;
        reduce /= 10;
    }
    // The full set of digits should be such that the size equals the maximum (as entries are unique)
    return digits.size() == maxy;
}

std::vector<int> Obj::Proj41Sieve(const int limit)
{
    std::vector<bool> prime;
    prime.resize(limit + 1);
    std::fill(prime.begin(), prime.end(), true);
    prime.at(1) = false;

    int pos;

    for (int loop = 3; loop <= sqrt(limit); loop += 2)
    {
        if (prime.at(loop))
        {
            pos = loop * loop;
            int dl = 2 * loop;
            while (pos <= limit)
            {
                prime.at(pos) = false;
                pos += dl;
            }
        }
    }

    std::vector<int> pList;
    pList.push_back(2);
    for (int i = 3; i < prime.size(); i += 2)
    {
        if (prime.at(i))
            pList.push_back(i);
    }
    return pList;
}