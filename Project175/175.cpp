#include <stdio.h>

int F[1010][300] = { 0 };

int main()
{
	int m, n, length = 1;
	F[1][1] = 1, F[2][1] = 1, F[3][1] = 2;

	scanf("%d %d", &m, &n);

	for (int i = 4; i <= n - m + 1; i++)
	{
		for (int j = 1; j <= length; j++)
		{
			F[i][j] = F[i - 1][j] + F[i - 2][j];
		}
		for (int j = 1; j <= length; j++)
		{
			if (F[i][j] > 9)
			{
				F[i][j + 1] += F[i][j] / 10;
				F[i][j] %= 10;
			}
			if (F[i][length + 1] != 0)
			{
				length++;
			}
		}
	}

	for (int i = length; i > 0; i--)
	{
		printf("%d", F[n - m + 1][i]);
	}

	return 0;
}