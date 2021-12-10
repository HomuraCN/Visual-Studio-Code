#include <stdio.h>

int Min(int x, int y);
int Max(int x, int y);

int n, m, max = 0, map[1510][1510], dp[1510][1510][2] = { 0 };

int main()
{
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			scanf("%d", &map[i][j]);
			if (map[i][j] == 0)
			{
				dp[i][j][0] = Min(Min(dp[i - 1][j][1], dp[i][j - 1][1]), dp[i - 1][j - 1][0]) + 1;
				max = Max(max, dp[i][j][0]);
			}
			else
			{
				dp[i][j][1] = Min(Min(dp[i - 1][j][0], dp[i][j - 1][0]), dp[i - 1][j - 1][1]) + 1;
				max = Max(max, dp[i][j][1]);
			}
		}
	}

	printf("%d", max);

	return 0;
}
int Min(int x, int y)
{
	return x <= y ? x : y;
}
int Max(int x, int y)
{
	return x >= y ? x : y;
}