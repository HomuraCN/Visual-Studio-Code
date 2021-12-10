#include <stdio.h>

int main()
{
	int n, flag = 0;
	double x1, y1, x2, y2, k, b;
	char map[20][20];

	scanf("%d", &n);

	for (int i = 1; i <= n; i++)
	{
		scanf("%s", map[i] + 1);
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (map[i][j] == 'x' && flag == 0)
			{
				x1 = i, y1 = j;
				flag = 1;
			}
			else if (map[i][j] == 'x' && flag == 1)
			{
				x2 = i, y2 = j;
			}
			else if (map[i][j] == '1' && )
			{

			}
		}
	}

	if (x1 != x2)
	{
		k = (y1 - y2) / (x1 - x2);
		b = y1 - k * x1;
		/*y = kx + b*/
		if (k != 0 && b != 0)
		{
			printf("y=%.4lfx+%.4lf", k, b);
		}
		else if (k != 0 && b == 0)/*y = kx*/
		{
			printf("y=%.4lfx", k);
		}
		else if (k == 0 && b != 0)/*y = b*/
		{
			printf("y=%.4lf", b);
		}
	}
	else
	{
		printf("x=%.4lf", x1);
	}

	return 0;
}