#include <stdio.h>

int Max(int x, int y)
{
	return x >= y ? x : y;
}

int main()
{
	int n, a, b;
	unsigned long long C[55][55], ans = 0;

	scanf("%d %d %d", &n, &a, &b);

	for (int i = 0; i <= n + Max(a, b); i++)
	{
		C[i][0] = 1;
		C[i][i] = 1;
	}

	for (int i = 2; i <= n + Max(a, b); i++)
	{
		for (int j = 1; j <= i; j++)
		{
			C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
		}
	}

	for (int i = 0; i <= a; i++)
	{
		for (int j = 0; j <= b; j++)
		{
			ans += C[n + i - 1][n - 1] * C[n + j - 1][n - 1];
		}
	}

	printf("%lld", ans);

	return 0;
}