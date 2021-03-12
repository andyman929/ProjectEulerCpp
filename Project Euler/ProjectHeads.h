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



