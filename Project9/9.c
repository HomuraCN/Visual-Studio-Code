#include <stdio.h>

int main(void)
{
	float a, b, c;

	printf("enter three numbers");
	scanf_s("%f, %f, %f", &a, &b, &c);

	printf("average = %.2f", (a+b+c) / 3.0);

	return 0;
}