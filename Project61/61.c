#include <stdio.h>

int main()
{
	int n, num = 0;

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		for (int j = 1; j < n + 1 - i; j++)
		{
			num++;
			printf("%02d", num);
			if (j % (n-i) == 0)
			{
				printf("\n");
			}
		}
	}

	return 0;
}