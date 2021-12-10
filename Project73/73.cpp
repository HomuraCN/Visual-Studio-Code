#include <stdio.h>

int main()
{
	int num[1000], max = 0, min = 10, n, sum =0;
	float point;

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &num[i]);
		sum += num[i];
	}

	for (int j = 0; j < n; j++)
	{
		if (num[j] > max)
		{
			max = num[j];
		}
	}

	for (int k = 0; k < n; k++)
	{
		if (num[k] < min)
		{
			min = num[k];
		}
	}

	sum = sum - min - max;

	point = 1.0 * sum / (n - 2);

	printf("%.2f", point);

	return 0;
}