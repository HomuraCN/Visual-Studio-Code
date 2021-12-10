#include <stdio.h>

int main(void)
{
	float C, F;

	printf("Please enter fahrenheit temperature :");
	scanf_s("%f", &F);

	C = 5.0 * (F - 32.0) / 9.0;

	printf("C = %.2f", C);
	
	return 0;
}