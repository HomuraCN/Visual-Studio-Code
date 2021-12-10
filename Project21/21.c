#include <stdio.h>

int main()
{
	int i = 123;
	float f = 3.45;
	double d = 8.2;
	f = i;
	d = f;
	i = f;

	printf("f = %f\n", f);
	printf("d = %f\n", f);
	printf("i = %d\n", i);

	return 0;
}