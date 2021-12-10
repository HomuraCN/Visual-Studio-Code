#include <stdio.h>

int main()
{
	int first, second;

	for (second = 1; second < 10; second++)
	{
		for (first = 1; first <= second; first++)
		{
			printf("%d * %d = %-5d", first, second, first * second);
		}
		printf("\n");
	}

	return 0;
}