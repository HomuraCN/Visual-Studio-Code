#include <stdio.h>

int Max(int x, int y);

int main()
{
	int S, v[1010] = { 0 }, w[1010], dp[1010] = { 0 };

	scanf("%d", &S);

	for (int i = 1; i <= S / 2; i++)
	{
		for (int j = 2; i * j <= S; j++)
		{
			v[i * j] += i;
		}
	}

	for (int i = 1; i <= S; i++)
	{
		w[i] = i;
	}

	for (int i = 1; i <= S; i++)
	{
		for (int j = w[i]; j <= S; j++)
		{
			dp[j] = Max(dp[j], dp[j - w[i]] + v[i]);
		}
	}

	printf("%d", dp[S]);

	return 0;
}
int Max(int x, int y)
{
	return x >= y ? x : y;
}