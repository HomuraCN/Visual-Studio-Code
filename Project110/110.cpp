#include <stdio.h>

int main(void)
{
	int n, num[101], counter;

	scanf("%d", &n);

	counter = n - 1;

	for (int i = 0; i <= n; i++)
	{
		scanf("%d", &num[i]);
	}

	printf("%dx^%d", num[0], n);

	for (int i = 1; i < n - 1; i++)
	{
		if (num[i] == 0)
		{
			counter--;
			continue;
		}
		if (num[i] < 0)
		{
			if (num[i] != -1)
			{
				printf("%dx^%d", num[i], counter);
				counter--;
			}
			else
			{
				printf("-x^%d", counter);
				counter--;
			}
		}
		else if (num[i] > 0)
		{
			if (num[i] != 1)
			{
				printf("+%dx^%d", num[i], counter);
				counter--;
			}
			else
			{
				printf("+x^%d", counter);
				counter--;
			}
		}
	}

	if (num[n - 1] > 0)
	{
		printf("+%dx", num[n - 1]);
	}
	else if (num[n - 1] < 0)
	{
		printf("%dx", num[n - 1]);
	}

	if (num[n] > 0)
	{
		printf("+%d", num[n]);
	}
	else if (num[n] < 0)
	{
		printf("%d", num[n]);
	}

	return 0;
}