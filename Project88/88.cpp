#include <stdio.h>

int main()
{
	int n, m[10][10] = {0}, x = 1, y = 0, num = 1;

	scanf("%d", &n);

	while (num <= n*n)
	{
		/*������*/
		while (y < n && !m[x][y + 1])
		{
			m[x][++y] = num;
			num++;
		}
		/*������*/
		while (x < n && !m[x + 1][y])
		{
			m[++x][y] = num;
			num++;
		}
		/*������*/
		while (y > 1 && !m[x][y - 1])
		{
			m[x][--y] = num;
			num++;
		}
		/*������*/
		while (x > 1 && !m[x - 1][y])
		{
			m[--x][y] = num;
			num++;
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j  = 1; j <= n; j++)
		{
			printf("%3d", m[i][j]);
		}
		printf("\n");
	}

	return 0;
}