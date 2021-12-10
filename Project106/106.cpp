#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	int D6st, D6nd, sum[5000] = { 0 };
	double two = 0, seven = 0, twelve = 0;

	srand((unsigned)time(NULL));

	for (int i = 0; i < 5000; i++)
	{
		D6st = rand() % 6 + 1;
		D6nd = rand() % 6 + 1;
		sum[i] = D6st + D6nd;
	}

	for (int j = 0; j < 5000; j++)
	{
		if (sum[j] == 2)
		{
			two++;
		}
		if (sum[j] == 7)
		{
			seven++;
		}
		if (sum[j] == 12)
		{
			twelve++;
		}
	}

	two /= 5000;
	seven /= 5000;
	twelve /= 5000;

	printf("%.2lf %.2lf %.2lf", two, seven, twelve);

	return 0;
}