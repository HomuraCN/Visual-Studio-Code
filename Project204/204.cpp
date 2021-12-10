#include <stdio.h>

int X[100010], Y[100010], c[1010][1010];

void Lcs_Length(int X[], int Y[], int n);

int main()
{
	int n;

	scanf("%d", &n);

	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &X[i]);
	}
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &Y[i]);
	}

	Lcs_Length(X, Y, n);

	printf("%d", c[n][n]);

	return 0;
}
void Lcs_Length(int X[], int Y[], int n)
{
	for (int i = 1; i <= n; i++)
	{
		c[i][0] = 0;
	}
	for (int j = 0; j <= n; j++)
	{
		c[0][j] = 0;
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (X[i] == Y[j])
			{
				c[i][j] = c[i - 1][j - 1] + 1;
			}
			else if (c[i - 1][j] >= c[i][j - 1])
			{
				c[i][j] = c[i - 1][j];
			}
			else
			{
				c[i][j] = c[i][j - 1];
			}
		}
	}
}