#pragma once

#include "Interfaces.h"

class Obj : public ProjInterface
{
	void Project740Calc(const int n);
	void Project741Calc(const int n);
};

extern "C" __declspec(dllexport) ProjInterface * __cdecl Create_ProjectsObj()
{
	return new Obj();
}
