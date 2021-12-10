#include <stdio.h>

int main()
{
	int x, y, z, q, cube[21][21][21] = {0}, xx[20], yy[20], zz[20], sum = 0, left;

	scanf("%d %d %d", &x, &y, &z);
	scanf("%d", &q);

	for (int i = 1; i <= 2 * q; i++)
	{
		scanf("%d %d %d", &xx[i], &yy[i], &zz[i]);
	}

	for (int i = 1; i <= q; i++)
	{
		for (int j = xx[i]; j <= xx[i + 1]; j++)
		{
			for (int h = yy[i]; h <= yy[i + 1]; h++)
			{
				for (int k = zz[i]; k <= zz[i + 1]; k++)
				{
					cube[i][j][k] = 1;
					sum += cube[i][j][k];
				}
			}
		}
	}

	left = x * y * z - sum;

	printf("%d", left);

	return 0;
}