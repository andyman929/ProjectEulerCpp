#pragma once

#include "Interface21_40.h"
#include <string>
#include <vector>
#include <set>

class ProjectsObjDll : public IProjectsObj2
{
public:
	void Project21Calc(int count);

	void Project25Calc(int digits);




private:
	std::vector<bool> amic;
	int amic_d = 0;
	bool Project21Amicable(int inp, int parent, int max);
	int Project21FactorsSum(int inp);
};

extern "C" __declspec(dllexport) IProjectsObj2 * __cdecl Create_ProjectsObj()
{
	return new ProjectsObjDll();
}
