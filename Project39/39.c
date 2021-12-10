#include <stdio.h>

int main()
{
	int x;

	scanf_s("%d", &x);

	if (x % 2 == 0 && x > 4 && x <= 12)
	{
		printf("1 1 0 0");
	}
	else if (x % 2 == 0 && x <= 4 && x > 12)
	{
		printf("0 1 1 0");
	}
	else if (x % 2 != 0 && x > 4 && x <= 12)
	{
		printf("0 1 1 0");
	}
	else if (x % 2 != 0 && x <= 4 && x > 12)
	{
		printf("0 0 0 1");
	}

	return 0;
}