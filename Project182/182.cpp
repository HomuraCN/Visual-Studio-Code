#include <stdio.h>

int main()
{
	int n, m, x, y, flag[110], map[110][110] = { 0 }, point[110][4], key[110][2];

	scanf("%d %d %d %d", &n, &m, &x, &y);

	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			scanf("%d", &point[i][j]);
		}
	}

	for (int i = 0; i < y; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			scanf("%d", &key[i][j]);
		}
	}

	for (int i = 0; i < x; i++)
	{
		for (int j = point[i][0]; j <= point[i][2]; j++)
		{
			for (int k = point[i][1]; k <= point[i][3]; k++)
			{
				map[j][k]++;
				for (int h = 0; h < y; h++)
				{
					if (j == key[h][0] && k == key[h][1])
					{
						flag[h] = i + 1;
					}
				}
			}
		}
	}

	for (int i = 0; i < y; i++)
	{
		if (map[key[i][0]][key[i][1]] != 0)
		{
			printf("Y %d %d\n", map[key[i][0]][key[i][1]], flag[i]);
		}
		else
		{
			printf("N");
		}
	}

	return 0;
}