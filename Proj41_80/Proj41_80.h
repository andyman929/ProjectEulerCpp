#pragma once

#ifndef PROJ4180
#define PROJ4180

#include "Interfaces.h"
#include <set>

class Obj : public ProjInterface
{
public:
	void Project58Calc(int thresholdPC);

	void Project60Calc();
	void Project60CalcNoMap();
	void Project60Calc4p();

	void Project65Calc(int count);


private:
	void Project58AddLayer(int* last, int layer, std::vector<int>* corn);
	void Project58EraseConjugates(std::vector<int>* list, int oldSize);

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

extern "C" __declspec(dllexport) ProjInterface * __cdecl Create_ProjectsObj()
{
	return new Obj();
}

#endif