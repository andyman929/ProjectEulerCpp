#pragma once

#include <string>
#include <vector>
#include <set>

class IProjectsObj2
{
public:
	virtual void Project21Calc(int count) = 0;
	virtual void Project22Calc(bool qs) = 0;
	virtual void Project23Calc() = 0;
	virtual void Project24Calc(int objects, int req) = 0;
	virtual void Project25Calc(int digits) = 0;
	virtual void Project26Calc(int digits) = 0;
	virtual void Project27Calc(int limits) = 0;
	virtual void Project28Calc(int sides) = 0;
};
