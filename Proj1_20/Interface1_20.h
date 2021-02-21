#pragma once

#include <string>
#include <vector>
#include <set>

// Interface for ProjectsObj
class IProjectsObj
{
public:
	virtual void Project1Calc() = 0;
	virtual void Project2Calc(int upperLimit) = 0;
	virtual void Project3CalcRecMethod(int num) = 0;
	virtual void Project3Calc(long long num) = 0;
	virtual void Project4Calc() = 0;
	virtual bool Project4CheckPalindrome(int num) = 0;
	virtual void Project5Calc(int lim) = 0;
	virtual void Project6Calc(int lim) = 0;
	virtual void Project7Calc(int pNumber) = 0;
	virtual void Project8Calc(int digits, std::string input) = 0;
	virtual void Project9Calc(int sumrequired) = 0;
	virtual void Project10Calc(int lim) = 0;
	virtual void Project11Calc(int line) = 0;
	virtual void Project12Calc(int divs) = 0;
	virtual void Project12CalcOld(int divs) = 0;
	virtual void Project13Calc() = 0;
	virtual void Project14Calc(int lim) = 0;
	virtual void Project14CalcBM(int lim) = 0;
	virtual void Project14CalcBF(int lim) = 0;
	virtual void Project14PrintCollatz(int lim) = 0;
	virtual void Project15Calc(int gridSize) = 0;
	virtual void Project16Calc(int exp) = 0;
	virtual void Project17Calc(int minN, int maxN) = 0;
	virtual void Project18Calc(int data) = 0;
	virtual void Project19Calc() = 0;
	virtual void Project20Calc(int fact) = 0;

};