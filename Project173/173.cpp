#include <stdio.h>

long long num[1000000];

int main()
{
	long long n, temp;

	scanf("%lld", &n);

	for (int i = 0; i < n; i++)
	{
		scanf("%lld", &num[i]);
	}

	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - 1 - i; j++)
		{
			if (num[j] > num[j + 1])
			{
				temp = num[j];
				num[j] = num[j + 1];
				num[j + 1] = temp;
			}
		}
	}

	long long sum = num[0] * (n - 1);

	for (int i = 1; i < n; i++)
	{
		sum += num[i] * (n - i);
	}

	printf("%lld", sum);

	return 0;
}