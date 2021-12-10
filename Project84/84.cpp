#include <stdio.h>

int main()
{
	int matrix[40][40] = {0}, N, K = 1, r, c, count = 0;

	scanf("%d", &N);

	r = 1;
	c = (N + 1) / 2;

	while (K <= N * N)
	{
		matrix[r][c] = K;

		if (K % N == 0)
		{
			r++;
			if (r == N+1)
			{
				r = 1;
			}
		}
		else
		{
			r--;
			c++;
		}
		if (r == 0)
		{
			r = N;
		}
		if (c == N+1)
		{
			c = 1;
		}

		K++;
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			printf("%d ", matrix[i][j]);
		}
		printf("\n");
	}

	return 0;
}