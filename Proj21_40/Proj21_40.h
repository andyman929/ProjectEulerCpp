#pragma once

#include "Interfaces.h"
#include "NBitInt.h"
#include <string>
#include <vector>
#include <set>

#define WIDTH_36 32

class ProjectsObjDll : public IProjectsObj
{
public:
	void Project21Calc(int count);
	void Project22Calc(bool qs);
	void Project23Calc();
	void Project24Calc(int objects, int req);
	void Project25Calc(int digits);
	void Project26Calc(int digits);
	void Project27Calc(int limits);
	void Project28Calc(int sides);
	void Project29Calc(const int limit);
	void Project30Calc(const int power);
	void Project31Calc(const int pounds);
	void Project32Calc();
	void Project33Calc();
	void Project34Calc();
	void Project35Calc(const int limit);
	void Project36Calc(const int limit);
	


private:
	std::vector<bool> amic;
	int amic_d = 0;
	bool Project21Amicable(int inp, int parent, int max);
	int Project21FactorsSum(int inp);
	void Project22Trim(std::string *inp, char ch);
	bool Project22IsBefore(std::string str1, std::string str2);
	int Project22NameScore(std::string str);
	void Project22Quicksort(std::vector<std::string>* strs, int low, int high);
	int Project22Partition(std::vector<std::string>* strs, int low, int high);
	void Project23FindPerfection(std::vector<bool> *factors);
	void Project24Recurse(std::vector<int>* order, int req, int objects);
	bool Project26ReptendCheck(const int p);
	std::vector<bool> Proj27Sieve(int limit);
	int GCM27(int a, int b);
	std::vector<int> Proj30GetDigits(int val);
	void Proj30Advance(std::vector<int>* dig);
	int Proj32SetInt(const std::vector<int>& s, int start, int end);
	int Proj34GetFactSum(int val, const int values[]);
	void Proj35CycleVector(std::vector<int>* digits);
	int Proj35GetInt(const std::vector<int>& digits);
	std::vector<int> Proj35GetVector(const int val);
	std::vector<int> Proj35Sieve(int limit, std::vector<bool>* prime);
	bool Proj36CheckPalindrome(NBitInt<WIDTH_36> num);
};

extern "C" __declspec(dllexport) IProjectsObj * __cdecl Create_ProjectsObj()
{
	return new ProjectsObjDll();
}
