#include <stdio.h>
#include <string.h>
#define LL long long

LL GetPrime(int n);
LL Max(LL x, LL y);

const int maxn = 1010;
LL cnt = 0, dp[maxn], prime[1000], visit[1000] = { 0 };

int main()
{
	int n;
	memset(dp, 0, sizeof(dp));
	dp[0] = 1;
	scanf("%d", &n);
	cnt = GetPrime(n);
	for (int i = 0; i < cnt; i++) {
		for (int j = prime[i]; j <= n; j++) {
			dp[j] = Max(dp[j], dp[j] + dp[j - prime[i]]);
		}
	}
	printf("%lld", dp[n]);

	return 0;
}
LL GetPrime(int n)
{
	int cnt = 0;
	for (int i = 2; i <= n; i++)
	{
		if (visit[i] == 0)
		{
			prime[cnt++] = i;
		}
		for (int j = 0; j < cnt && i * prime[j] <= n; j++)
		{
			visit[i * prime[j]] = 1;
			if (i % prime[j] == 0)
			{
				break;
			}
		}
	}
	return cnt;
}
LL Max(LL x, LL y) {
	return x > y ? x : y;
}