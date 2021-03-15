/*
Binary grid colouring
*/

#include "pch.h"

int f(int a)
{
	int out = 1;
	while (a > 1)
		out *= a--;
	return out;

}

int AchooseB(int A, int B)
{
	return f(A) / (f(B) * f(A - B));
}

void Obj::Project741Calc(const int n)
{
	double out = 0;
	for (int k = 0; k <= n; k++)
	{
		out += pow(-1, k) * AchooseB(n, k) * AchooseB(n, k) * pow(2, k) * f(2 * n - 2 * k);
	}
	//out *= pow(4, -n);

	std::cout << "Calculation of f(" << n << ") gives " << out << std::endl;
}