#pragma once
#include <chrono>
#include <iostream>

class Timer
{
public:
	void StartTimer() { start = std::chrono::high_resolution_clock::now(); };
	void EndTimer() {
		finish = std::chrono::high_resolution_clock::now();
		diff = finish - start;
		std::cout << "\n" << "Time to complete task (seconds): " << diff.count() << "\n";
	};
private:
	std::chrono::steady_clock::time_point start;
	std::chrono::steady_clock::time_point finish;

	std::chrono::duration<double> diff;
};