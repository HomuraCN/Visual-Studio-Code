#include <stdio.h>

long long dp[10000010];

long long Max(long long x, long long y);

int main()
{
	long long t, m, v[10010], c[10010];

	scanf("%lld %lld", &t, &m);

	for (int i = 1; i <= m; i++)
	{
		scanf("%lld %lld", &c[i], &v[i]);
	}

	for (int i = 1; i <= m; i++)
	{
		for (int j = c[i]; j <= t; j++)
		{
			dp[j] = Max(dp[j], dp[j - c[i]] + v[i]);
		}
	}

	printf("%lld", dp[t]);

	return 0;
}

long long Max(long long x, long long y)
{
	return x >= y ? x : y;
}