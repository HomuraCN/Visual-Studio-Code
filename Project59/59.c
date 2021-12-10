#include <stdio.h>

int main()
{
	int a[10], i;

	for (i = 0; i < 10; i++)
	{
		scanf_s("%d", &a[i]);
	}

	printf("%d", a[5]);

	return 0;
}