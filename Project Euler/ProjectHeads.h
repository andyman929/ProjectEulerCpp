#pragma once

class ProjectsObj
{
public:
	void Project1Calc();
	void Project2Calc(int upperLimit);
	void Project3CalcRecMethod(int num);
	void Project3Calc(long long num);
	void Project4Calc();

private:
	bool Project3CheckPrime(int p);
	int Project3Recurse(int num);

};

