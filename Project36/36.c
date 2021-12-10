#include <stdio.h>

#define N 100

int main()
{
	int num[N];
	int count, sum = 0, i, j,n;

	scanf_s("%d", &n);

	for (count = 0; count <n; count++)
	{
		scanf_s("%d", &num[count]);
	}

	for (i = 1; i < n; i++)
	{
		for (j = 0; j < i; j++)
		{
			if (num[i] < num[j])
			{
				sum++;
			}
		}
	}

	printf("%d", sum);

	return 0;
}