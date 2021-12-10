#include <stdio.h>

int Max(int x, int y);

int ans = -2147483648, ansx, ansy, N, M, C, map[1010][1010], dp[1010][1010] = { 0 };

int main()
{
	scanf("%d %d %d", &N, &M, &C);

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			scanf("%d", &map[i][j]);
		}
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + map[i][j];
		}
	}

	for (int i = 1; i <= N - C + 1; i++)
	{
		for (int j = 1; j <= M - C + 1; j++)
		{
			int ii = i + C - 1, jj = j + C - 1;
			if (ans <= dp[ii][jj] - dp[ii][j - 1] - dp[i - 1][jj] + dp[i - 1][j - 1])
			{
				ansx = i, ansy = j;
				ans = dp[ii][jj] - dp[ii][j - 1] - dp[i - 1][jj] + dp[i - 1][j - 1];
			}
		}
	}

	printf("%d %d", ansx, ansy);

	return 0;
}
int Max(int x, int y)
{
	return x >= y ? x : y;
}