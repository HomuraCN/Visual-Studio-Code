#include <stdio.h>

int main()
{
	int R, C, K, a, b, count = 0, flag = 1;
	char map[102][102];

	scanf("%d %d %d", &R, &C, &K);

	for (int i = 1; i <= R; i++)
	{
		scanf("%s", map[i] + 1);
	}

	for (int i = 0; i <= C + 1; i++)
	{
		map[0][i] = '#';
		map[R + 1][i] = '#';
	}
	for (int i = 1; i <= R; i++)
	{
		map[i][0] = '#';
		map[i][C + 1] = '#';
	}

	for (int r = 1; r <= R; r++)
	{
		for (int c = 1; c <= C; c++)
		{
			if (map[r][c] == '.')
			{
				for (a = 1; a <= K - 1; a++)
				{
					if (map[r][c + a] != '.')
					{
						break;
					}
				}
				for (b = 1; b <= K - 1; b++)
				{
					if (map[r + b][c] != '.')
					{
						break;
					}
				}
				if (a == K)
				{
					count++;
				}
				if (b == K)
				{
					count++;
				}
			}
		}
	}

	if (K > 1)
	{
		printf("%d", count);
	}
	else if (K == 1)
	{
		printf("%d", count / 2);
	}

	return 0;
}