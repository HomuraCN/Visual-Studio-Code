#include <stdio.h>

int N, flag2, mine[21], hole[21][21], dp[21] = { 0 }, order[21] = { 0 };

int Dp(int i);
int Max(int x, int y);

int main()
{
	int max = 0;
	scanf("%d", &N);

	for (int i = 1; i <= N; i++)
	{
		scanf("%d", &mine[i]);
	}

	for (int i = 1; i <= N - 1; i++)
	{
		for (int j = i + 1; j <= N; j++)
		{
			scanf("%d", &hole[i][j]);
		}
	}

	dp[N] = mine[N];

	for (int i = N; i >= 1; i--)
	{
		max = Max(Dp(i), max);
	}

	printf("%d ", flag2);
	for (int i = 1; i <= N; i++)
	{
		if (order[i] > 0)
		{
			printf("%d ", order[i]);
		}
	}
	printf("\n");
	printf("%d", max);

	return 0;
}
int Dp(int i)
{
	int max = 0, flag = 0;
	if (dp[i] > 0)
	{
		return dp[i];
	}
	for (int j = i + 1; j <= N; j++)
	{
		if (hole[i][j] == 1)
		{
			if (max < dp[j])
			{
				max = dp[j];
				flag = j;
				flag2 = i;
			}
			/*max = Max(max, dp[j]);*/
		}
	}
	dp[i] = mine[i];
	dp[i] += max;
	order[i] = flag;
	return dp[i];
}
int Max(int x, int y)
{
	return x >= y ? x : y;
}