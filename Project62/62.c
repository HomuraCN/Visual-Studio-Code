#include <stdio.h>

int main()
{
	int N;
	unsigned long long S = 0;

	scanf("%d", &N);

	for (int i = 1; i < N+1; i++)
	{
		S += Factorial(i);
	}

	printf("%llu", S);

	return 0;
}

/*½×³Ë*/
int Factorial(int N)
{
	int fac = 1;

	for (int i = 1; i < N + 1; i++)
	{
		fac *= i;
	}

	return fac;
}