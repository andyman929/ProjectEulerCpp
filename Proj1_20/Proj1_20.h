#pragma once

#include <string>
#include <vector>
#include <set>
#include "Interfaces.h"

class ProjectsObjDLL1 : public IProjectsObj
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
	void Project17Calc(int minN, int maxN);


	// 0 = small proj 13, 1 = large proj 18, 2 = proj 67
	void Project18Calc(int data);

	void Project19Calc();
	void Project20Calc(int fact);

private:
	bool Project3CheckPrime(int p);
	int Project3Recurse(int num);
	int Project5GetGCD(int aIn, int bIn);
	int Project14CountCollatz(int lim);
	int Project14CountCollatzBM(int inp, int lim);
	std::vector<int> Proj14chainLengths;
	std::vector<bool> Proj14chainNeeded;
	int Project14Cursed(int lim, __int64 val);
	std::string Project17ReturnHundreds(int n, bool thou);
	std::string Project17DigitString(int n);
	std::string Project17DoubleDigitString(int n);
	std::string Project17TensString(int n);
	std::string Project17Teens(int n);

	// 0 = small proj 13, 1 = large proj 18, 2 = proj 67
	std::vector<std::vector<int>> Project18GetData(int data);

	int Project19DaysInMonth(int month, int year);
};

extern "C" __declspec(dllexport) IProjectsObj* __cdecl Create_ProjectsObj()
{
	return new ProjectsObjDLL1();
}