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
	void Project25Calc(int digits);




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
};

extern "C" __declspec(dllexport) IProjectsObj2 * __cdecl Create_ProjectsObj()
{
	return new ProjectsObjDll();
}
