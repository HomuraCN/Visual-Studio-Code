#include <stdio.h>

int main()
{
	int T, M, dp[101][1001] = { 0 }, v[101], w[101];

	scanf("%d %d", &T, &M);

	for (int i = 1; i <= M; i++)
	{
		scanf("%d %d", &v[i], &w[i]);
	}

	for (int i = 1; i <= M; i++)
	{
		for (int j = 1; j <= T; j++)
		{
			if (j < v[i])
			{
				dp[i][j] = dp[i - 1][j];
			}
			else
			{
				dp[i][j] = dp[i - 1][j] > dp[i - 1][j - v[i]] + w[i]? dp[i - 1][j] : dp[i - 1][j - v[i]] + w[i];
			}
		}
	}

	printf("%d", dp[M][T]);

	return 0;
}