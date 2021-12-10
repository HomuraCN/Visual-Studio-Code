#include <stdio.h>

long long Max(long long x, long long y);

long long n, x, lose[1010], win[1010], use[1010], dp[1010];

int main()
{
	scanf("%lld %lld", &n, &x);

	for (int i = 1; i <= n; i++)
	{
		scanf("%lld %lld %lld", &lose[i], &win[i], &use[i]);
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = x; j >= use[i]; j--)
		{
			dp[j] = Max(dp[j] + lose[i], dp[j - use[i]] + win[i]);
		}
		for (int k = use[i] - 1; k >= 0; k--)
		{
			dp[k] = dp[k] + lose[i];
		}
	}

	printf("%lld", 5 * dp[x]);

	return 0;
}

long long Max(long long x, long long y)
{
	return x >= y ? x : y;
}