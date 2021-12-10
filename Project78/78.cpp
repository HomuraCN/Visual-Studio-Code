#include <stdio.h>
#define N 50

int main()
{
	int n, num[N], temp;

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &num[i]);
	}

	for (int m = 0; m < n; m++)
	{
		printf("%d ", num[m]);
	}

	printf("\n");

	for (int j = 0; j < n / 2; j++)
	{
		temp = num[j];
		num[j] = num[n - 1 - j];
		num[n - 1 - j] = temp;
	}

	for (int k = 0; k < n; k++)
	{
		printf("%d ", num[k]);
	}

	return 0;
}