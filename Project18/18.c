#include <stdio.h>

int main()
{
	int a = 1, b = 2, c = 3, d = 4, x;
	
	a += b * c;
	d -= c % b;
	c *= a + b;

	printf("%d %d %d", a, b, c);

	return 0;
}