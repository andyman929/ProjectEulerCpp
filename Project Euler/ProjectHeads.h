#pragma once

#include <string>

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



private:
	bool Project3CheckPrime(int p);
	int Project3Recurse(int num);
	int Project5GetGCD(int aIn,int bIn);

};

