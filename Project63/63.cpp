#include <stdio.h>

int main()
{
	int L, sum = 2, counter = 1;

	scanf("%d", &L);

	printf("2\n");

	for (int i = 3; ; i++)
	{
		for (int j = 2; j < i; j++)
		{
			if (i % j == 0 || sum > L)
			{
				break;
			}
			if (sum < L && j == i - 1)
			{

				sum += i;
				if (sum <= L)
				{
					printf("%d\n", i);
					counter++;
				}
				else
				{
					break;
				}
			}
		}
		if (sum > L)
		{
			break;
		}
	}

	printf("%d\n", counter);

	return 0;
}