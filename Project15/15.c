#include <stdio.h>
#include <math.h>

int main()
{
	int a, b, c, delta;
	float X1, X2;

	printf("请依次输入一元二次方程的系数和常数:");
	scanf_s("%d %d %d", &a, &b, &c);

	delta = b * b - 4 * a * c;

	if (delta >= 0)
	{
		X1 = (-b - sqrt(delta)) / 2 * a;
		X2 = (-b + sqrt(delta)) / 2 * a;
		printf("该一元二次方程的两根是X1 = %.2f, X2 = %.2f", X1, X2);
	}
	else
	{
		printf("该一元二次方程无实根");
	}

	return 0;
}