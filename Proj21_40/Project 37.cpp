/*
Truncatable Primes
*/

#include "pch.h"

void ProjectsObjDll::Project37Calc(const int limit)
{
    int sum = 0;
    std::vector<bool> sieve;
    std::vector<int> primes = Proj35Sieve(limit, &sieve);

    for (int i = 4; i < primes.size(); i++)
    {
        std::string numstr = std::to_string(primes[i]);
        if (numstr[0] != '2' && numstr[0] != '3' && numstr[0] != '5' && numstr[0] != '7')
            continue;
        if (Proj37LeftCheck(numstr, sieve))
            if (Proj37RightCheck(numstr, sieve))
            {
                std::cout << numstr << "\tis a valid num\n";
                sum += std::stoi(numstr);
            }
             
    }

    std::cout << "The sum of all truncatable primes under " << limit << " is " << sum << "\n";
}

bool ProjectsObjDll::Proj37LeftCheck(std::string number, const std::vector<bool>& sieve)
{
    int tst;
    do {
        number.erase(number.begin());
        tst = std::stoi(number);
        if (!sieve[tst])
            return false;
    } while (number.size() != 1);
    return true;
}

bool ProjectsObjDll::Proj37RightCheck(std::string number, const std::vector<bool>& sieve)
{
    int tst;
    do {
        number.erase(number.end() - 1);
        tst = std::stoi(number);
        if (!sieve[tst])
            return false;
    } while (number.size() != 1);
    return true;
}