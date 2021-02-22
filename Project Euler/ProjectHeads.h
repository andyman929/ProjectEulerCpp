#pragma once

#include <string>
#include <vector>
#include <set>

typedef struct {
	int x, y;
} coordinate;

class ProjectsObj
{
public:
	void Project58Calc(int thresholdPC);

	void Project60Calc();
	void Project60CalcNoMap();
	void Project60Calc4p();

	void Project219Calc(int chain);
	void Project219Calc2(int chain);

	void Ld219Calc(double chain);

	void Project373Calc(__int64 n);
	void Project373TriangleCaller(__int64 n);
	void Project373CalcMultiThread(__int64 n);
	void Project373Pyth(const int max);
	void Project373Gauss(const int max);
	void Project373Heron(const int max);



private:
	void Project58AddLayer(int *last, int layer, std::vector<int>* corn);
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


	__int64 Project219Cost(int cost, std::vector<int> distribution);
	int Project219NodeCount(std::vector<int> distribution);

	long double Ld219Cost(double cost, std::vector<double> distribution);
	double Ld219NodeCount(std::vector<double> distribution);

	long double Project373SinX(__int64 x, __int64 y, __int64 z);
	bool Project373IsSquare(__int64 inp);
	bool Project373IsIntegral(coordinate n, coordinate m);

	int Project373CalcSimpleThread(int n);
	__int64 Project373TriangleThread(__int64 n, __int64 a);
};



