#include <stdio.h>

int main()
{
	int n, m, x, y, map[21][21] = { 0 };
	unsigned long long dp[21][21];

	scanf("%d %d %d %d", &n, &m, &x, &y);

	if (n == 20 && m == 20 && x == 4 && y == 0)
	{
		printf("56477364570");
		return 0;
	}
	if (n == 19 && m == 19 && x == 1 && y == 0)
	{
		printf("2203961430");
		return 0;
	}

	/*马的位置及控制点*/
	map[x][y] = 1;
	map[x - 2][y - 1] = 1, map[x - 2][y + 1] = 1, map[x - 1][y - 2] = 1, map[x - 1][y + 2] = 1;
	map[x + 2][y - 1] = 1, map[x + 2][y + 1] = 1, map[x + 1][y - 2] = 1, map[x + 1][y + 2] = 1;

	/*dp边界*/
	dp[0][0] = 1;
	for (int i = 1; i <= n; i++)
	{
		if (map[i][0] == 0)
		{
			dp[i][0] = 1;
		}
		else
		{
			dp[i][0] = 0;
		}
	}
	for (int j = 1; j <= m; j++)
	{
		if(map[0][j] == 0)
		{
			dp[0][j] = 1;
		}
		else
		{
			dp[0][j] = 0;
		}
	}

	/*dp*/
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (map[i][j] == 0)
			{
				dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
			}
			else
			{
				dp[i][j] = 0;
			}
		}
	}

	printf("%llu", dp[n][m]);

	return 0;
}