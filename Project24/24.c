#include <stdio.h>
#include <math.h>

int main()
{
	typedef int Number;
	typedef double Num;
	typedef float Time;

	Number d = 1000, p = 100;
	Num r = 0.0545;
	Time m;

	m = log10(p / (p - d * r)) / log10(1 + r);

	printf("%2.f", m);

	return 0;
}