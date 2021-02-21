#pragma once

#include <Windows.h>
#include <iostream>
#include <string>

class DllManager
{
public:
	DllManager() {
		dll_handle = NULL;
		func_handle = NULL;
	};
	~DllManager() {
		bool success = FreeLibrary(dll_handle);
		if (success)
			return;
		std::cerr << "Failed to unload dll\n";
		return;
	};

	FARPROC LoadFunction(std::string dllname, std::string funcname) {
		std::wstring dlltemp = std::wstring(dllname.begin(), dllname.end());
		LPCWSTR dllwide = dlltemp.c_str();
		dll_handle = LoadLibrary(dllwide);
		if (!dll_handle)
		{
			std::cerr << "Unable to load dll";
			return NULL;
		}
		func_handle = GetProcAddress(dll_handle, funcname.c_str());
		return func_handle;
	};

private:
	HINSTANCE dll_handle;
	FARPROC func_handle;
};