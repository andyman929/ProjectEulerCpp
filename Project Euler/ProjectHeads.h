#pragma once

class ProjectsObj
{
public:
	void Project1Calc();
	void Project2Calc(int upperLimit);
	void Project3CalcRecMethod(int num);
	void Project3Calc(long long num);

private:
	bool Project3CheckPrime(int p);
	int Project3Recurse(int num);
	int Project3CalcLoop(long long num);

};
