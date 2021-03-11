#pragma once

#include <Windows.h>
#include <iostream>
#include <string>
#include "Interfaces.h"

class DllManager
{
	typedef ProjInterface* (__cdecl* dll_factory)();
public:
	DllManager() {
		dll_handle = NULL;
		func_handle = NULL;
		cls = nullptr;
	};
	DllManager(std::string dllname) {
		dll_handle = NULL;
		func_handle = NULL;
		cls = nullptr;
		LoadDllClass(dllname);
	};
	~DllManager() {
		bool success = FreeLibrary(dll_handle);
		if (success)
			return;
		std::cerr << "Failed to unload dll\n";
		return;
	};

private:
	FARPROC fullLoad(std::string dllname, std::string funcname) {
		std::wstring dlltemp = std::wstring(dllname.begin(), dllname.end());
		LPCWSTR dllwide = dlltemp.c_str();
		dll_handle = LoadLibrary(dllwide);
		if (!dll_handle)
		{
			std::cerr << "Unable to load dll " << dllname << std::endl;
			return NULL;
		}
		func_handle = GetProcAddress(dll_handle, funcname.c_str());
		if (!func_handle)
		{
			std::cerr << "Unable to load factory function from dll " << dllname << std::endl;
			return NULL;
		}
		return func_handle;
	};

public:
	void LoadDllClass(std::string dllname) {
		// Factory function name is uniform across the DLLs
		fullLoad(dllname, "Create_ProjectsObj");
		dll_factory factory_func = reinterpret_cast<dll_factory>(func_handle);
		cls = factory_func();
	};

	ProjInterface* operator->() const {
		return cls;
	};

private:
	HINSTANCE dll_handle;
	FARPROC func_handle;
	ProjInterface* cls;
};