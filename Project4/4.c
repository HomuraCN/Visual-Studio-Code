#include <stdio.h>

int main(void)
{
	float a, b, c, temp;

	printf("请依次输入三个实数:");
	scanf_s("%f, %f, %f", &a, &b, &c);

	if (a < b)
	{
		temp = a;
		a = b;
		b = temp;
	}
	if (b < c)
	{
		temp = b;
		b = c;
		c = temp;
		if (a < b)
		{
			temp = a;
			a = b;
			b = temp;
		}
	}
	
	printf("%f > %f > %f", a, b, c);

	return 0;
}