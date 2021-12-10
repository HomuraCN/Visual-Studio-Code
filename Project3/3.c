#include <stdio.h>

int main()
{
	float mol = 2, den = 1, sum = 0, count, temp;

	for (count = 0; count <= 19; count++)
	{
		sum = sum + mol / den;
		temp = mol;
		mol = temp + den;
		den = temp;
	}

	printf("µü´úÖµÊÇ:%f", sum);

	return 0;
}