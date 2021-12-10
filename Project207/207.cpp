#include <stdio.h>

int R, C, height[110][110], rec[110][110] = { 0 };

int Rec(int i, int j);
int Max(int x, int y);

int main()
{
	int max = 0;

	scanf("%d %d", &R, &C);

	for (int i = 1; i <= R; i++)
	{
		for (int j = 1; j <= C; j++)
		{
			scanf("%d", &height[i][j]);
		}
	}

	for (int i = 1; i <= R; i++)
	{
		for (int j = 1; j <= C; j++)
		{
			max = 	Max(Rec(i, j), max);
		}
	}

	printf("%d", max);

	return 0;
}
int Rec(int i, int j)
{
	if (rec[i][j] > 0)
	{
		return rec[i][j];
	}
	rec[i][j] = 1;
	if (height[i][j] > height[i][j - 1] && i >= 1 && i <= R && j - 1>= 1 && j - 1<= C)
	{
		rec[i][j] = Max(Rec(i, j - 1) + 1, rec[i][j]);
	}
	if (height[i][j] > height[i][j + 1] && i >= 1 && i <= R && j + 1 >= 1 && j + 1<= C)
	{
		rec[i][j] = Max(Rec(i, j + 1) + 1, rec[i][j]);
	}
	if (height[i][j] > height[i + 1][j] && i + 1>= 1 && i + 1<= R && j >= 1 && j <= C)
	{
		rec[i][j] = Max(Rec(i + 1, j) + 1, rec[i][j]);
	}
	if (height[i][j] > height[i - 1][j] && i - 1>= 1 && i - 1<= R && j >= 1 && j <= C)
	{
		rec[i][j] = Max(Rec(i - 1, j) + 1, rec[i][j]);
	}

	return rec[i][j];
}
int Max(int x, int y)
{
	return x >= y ? x : y;
}