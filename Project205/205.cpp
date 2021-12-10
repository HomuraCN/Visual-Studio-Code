#include <stdio.h>

int max = 0, r, dp[1010][1010];

int main()
{
	scanf("%d", &r);

	for (int i = 0; i <= r; i++)
	{
		for (int j = 0; j <= r; j++)
		{
			dp[i][j] = 0;
		}
	}

	for (int i = 1; i <= r; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			scanf("%d", &dp[i][j]);
		}
	}

	for (int i = 1; i <= r; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			if (dp[i - 1][j] >= dp[i - 1][j - 1])
			{
				dp[i][j] += dp[i - 1][j];
			}
			else
			{
				dp[i][j] += dp[i - 1][j - 1];
			}
		}
	}

	for (int i = 1; i <= r; i++)
	{
		if (max < dp[r][i])
		{
			max = dp[r][i];
		}
	}

	printf("%d", max);

	return 0;
}