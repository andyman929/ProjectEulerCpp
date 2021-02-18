#pragma once

#include <string>
#include <vector>
#include <set>

class ProjectsObj
{
public:
	void Project1Calc();
	void Project2Calc(int upperLimit);
	void Project3CalcRecMethod(int num);
	void Project3Calc(long long num);
	void Project4Calc();
	bool Project4CheckPalindrome(int num);
	void Project5Calc(int lim);
	void Project6Calc(int lim);
	void Project7Calc(int pNumber);
	void Project8Calc(int digits, std::string input);
	void Project9Calc(int sumrequired);
	void Project10Calc(int lim);
	void Project11Calc(int line);
	void Project12Calc(int divs);
	void Project12CalcOld(int divs);
	void Project13Calc();
	void Project14Calc(int lim);
	void Project14CalcBM(int lim);
	void Project14CalcBF(int lim);
	void Project14PrintCollatz(int lim);
	void Project15Calc(int gridSize);
	void Project16Calc(int exp);




	void Project60Calc();
	void Project60CalcNoMap();
	void Project60Calc4p();

	void Project219Calc(int chain);

private:
	bool Project3CheckPrime(int p);
	int Project3Recurse(int num);
	int Project5GetGCD(int aIn,int bIn);
	int Project14CountCollatz(int lim);
	int Project14CountCollatzBM(int inp, int lim);
	std::vector<int> Proj14chainLengths;
	std::vector<bool> Proj14chainNeeded;
	int Project14Cursed(int lim, __int64 val);

	void Proj60ExtendSieve();
	std::vector<bool> Proj60Sieved;
	std::vector<int> Proj60PrimesStart;
	std::vector<int> Proj60Primes;
	bool Proj60IsPrime(int p);
	bool Proj60CheckPrimes2(int p1, int p2);
	std::set<int> Proj60BuildPairs(int p);
	std::set<int> Proj60Intersect(std::set<int> s1, std::set<int> s2);
	std::set<int> Proj60PairsSubset(int p, std::set<int> set1);
	int Proj60Limit;
};




