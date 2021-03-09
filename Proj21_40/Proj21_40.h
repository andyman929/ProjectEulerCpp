#pragma once

#include "Interface21_40.h"
#include <string>
#include <vector>
#include <set>

class ProjectsObjDll : public IProjectsObj2
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
};

extern "C" __declspec(dllexport) IProjectsObj2 * __cdecl Create_ProjectsObj()
{
	return new ProjectsObjDll();
}
