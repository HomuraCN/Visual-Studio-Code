#include <stdio.h>

long long step[30][30];

int main()
{
	int n, m, map[30][30] = { 0 }, x, y;

	scanf("%d %d %d %d", &n, &m, &x, &y);

	map[x][y] = 1;
	map[x - 1][y - 2] = 1, map[x - 1][y + 2] = 1, map[x - 2][y - 1] = 1, map[x - 2][y + 1] = 1;
	map[x + 1][y - 2] = 1, map[x + 1][y + 2] = 1, map[x + 2][y - 1] = 1, map[x + 2][y + 1] = 1;

	for (int i = 0; i <= m; i++)
	{
		step[0][i] = 1;
	}
	for (int j = 0; j <= n; j++)
	{
		step[j][0] = 1;
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (map[i][j] == 1)
			{
				step[i][j] = 0;
			}
			else
			{
				step[i][j] = step[i - 1][j] + step[i][j - 1];
			}
		}
	}

	printf("%llu", step[n][m]);

	return 0;
}