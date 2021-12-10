#include <stdio.h>
#include <math.h>

int main(void)
{
	int a, n, sum = 0, sum1 = 0, sum2 = 0, sum3 = 0, sum4 = 0, sum5 = 0;

	printf("Enter the value of a and n:\n");
	scanf_s("%d %d", &a, &n);

	
	for (n = 1; n < 6; n++)
	{
		sum5 += a * pow(10, n - 1);
	}
	for (n = 1; n < 5; n++)
	{
		sum4 += a * pow(10, n - 1);
	}
	for (n = 1; n < 4; n++)
	{
		sum3 += a * pow(10, n - 1);
	}
	for (n = 1; n < 3; n++)
	{
		sum2 += a * pow(10, n - 1);
	}
	for (n = 1; n < 2; n++)
	{
		sum1 += a * pow(10, n - 1);
	}

	sum = sum1 + sum2 + sum3 + sum4 + sum5;
	
	printf("sum = %d + %d + %d + %d + %d = %d\n", sum1, sum2, sum3, sum4, sum5, sum);

	return 0;
}