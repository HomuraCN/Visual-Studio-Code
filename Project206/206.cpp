#include <stdio.h>

int main()
{
	int R, C, height[110][110], int dp[110][110];

	scanf("%d %d", &R, &C);

	for (int i = 1; i <= R; i++)
	{
		for (int j = 1; j <= C; j++)
		{
			scanf("%d", &height[i][j]);
		}
	}

	for (int i = 0; i <= R; i++)
	{
		for (int j = 0; j <= C; j++)
		{
			dp[i][j] = 0;
		}
	}



	return 0;
}
int Length(int height[][110], int dp[][110], int i, int j)
{

	if (dp[i][j] > 0)
	{
		return dp[i][j];
	}
	else
	{
		if (height[i][j - 1] < height[i][j])
		{
			max = Length();
		}
	}
}