#include <stdio.h>
#include <math.h>

char str[99999999];

int main()
{
	int i = -1, W = 0, L = 0;

	while (1)
	{
		i++;
		scanf("%c", &str[i]);
		if (str[i] == '\n')
		{
			i--;
		}
		if (str[i] == 'E')
		{
			if (i == 0)
			{
				printf("0:0\n");
				printf("\n");
				printf("0:0");
				return 0;
			}
			break; /*i - 1的值是非E的最后字符下标, i的值是非E字符的个数*/
		}
	}

	for (int j = 0; j < i; j++)
	{
		if (str[j] == 'W')
		{
			W++;
		}
		else
		{
			L++;
		}

		if ((L == 11 && W <= 9) || (W == 11 && L <= 9) || j == i - 1)
		{
			printf("%d:%d\n", W, L);
			W = 0, L = 0;
		}
		else
		{
			if (abs(W - L) == 2 && ((W >= 12 && L >= 10) || (L >= 12 && W >= 10)))
			{
				printf("%d:%d\n", W, L);
				W = 0, L = 0;
			}
		}
	}

	printf("\n");
	W = 0, L = 0;

	for (int j = 0; j < i; j++)
	{
		if (str[j] == 'W')
		{
			W++;
		}
		else
		{
			L++;
		}

		if ((L == 21 && W <= 19) || (W == 21 && L <= 19) || j == i - 1)
		{
			printf("%d:%d", W, L);
			printf("\n");
			W = 0, L = 0;
		}
		else
		{
			if (abs(W - L) == 2 && ((W >= 22 && L >= 20) || (L >= 22 && W >= 20)))
			{
				printf("%d:%d\n", W, L);
				W = 0, L = 0;
			}
		}
	}

	return 0;
}