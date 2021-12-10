#include <stdio.h>

int main()
{
	int mat[101][101] = {0}, x[101], y[101], o[101], p[101], n, m, k, tempx, tempy, tempo, tempp, counter = 0;

	scanf("%d %d %d", &n, &m, &k);

	for (int i = 0; i < m; i++)
	{
		scanf("%d %d", &x[i], &y[i]);
		tempx = x[i];
		tempy = y[i];
		for (int j = tempx - 2; j <= tempx + 2; j++)
		{
			if(j >= 1 && j <= n && tempy >= 1 && tempy <= n)
			{
				mat[j][tempy] = 1;
			}
		}
		for (int k = tempx - 1; k <= tempx + 1; k++)
		{
			if (k >= 1 && k <= n && tempy + 1>= 1 && tempy + 1<= n)
			{
				mat[k][tempy + 1] = 1;
			}
			if (k >= 1 && k <= n && tempy - 1 >= 1 && tempy - 1 <= n)
			{
				mat[k][tempy - 1] = 1;
			}
		}
		if (tempx >= 1 && tempx <= n && tempy + 2 >= 1 && tempy + 2 <= n)
		{
			mat[tempx][tempy + 2] = 1;
		}
		if (tempx >= 1 && tempx <= n && tempy - 2 >= 1 && tempy - 2 <= n)
		{
			mat[tempx][tempy - 2] = 1;
		}
	}

	for (int a = 0; a < k; a++)
	{
		scanf("%d %d", &o[a], &p[a]);
		tempo = o[a];
		tempp = p[a];
		for (int b = tempo - 2; b <= tempo + 2; b++)
		{
			if (b >= 1 && b <= n && tempp >= 1 && tempp <= n)
			{
				mat[b][tempp] = 1;
			}
			if (b >= 1 && b <= n && tempp + 1>= 1 && tempp + 1<= n)
			{
				mat[b][tempp + 1] = 1;
			}
			if (b >= 1 && b <= n && tempp - 1 >= 1 && tempp - 1 <= n)
			{
				mat[b][tempp - 1] = 1;
			}
			if (b >= 1 && b <= n && tempp + 2 >= 1 && tempp + 2 <= n)
			{
				mat[b][tempp + 2] = 1;
			}
			if (b >= 1 && b <= n && tempp - 2 >= 1 && tempp - 2 <= n)
			{
				mat[b][tempp - 2] = 1;
			}
		}
	}

	for (int h = 1; h <= n; h++)
	{
		for (int g = 1; g <= n; g++)
		{
			if (mat[h][g] == 0)
			{
				counter++;
			}
		}
	}

	printf("%d", counter);

	return 0;
}