#include <stdio.h>

int main(void)
{
	const float oz_to_g = 28.350;
	float oz, g;

	printf("�����밻˾������");
	scanf_s("%f", &oz);

	g = oz * oz_to_g;

	printf("%.2f��˾ = %.2f��", oz, g);

	return 0;
}