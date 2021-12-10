#include <stdio.h>

int main()
{
	int m, f, k, price, count = 1;

	for ( m = 0; m < 17; m++)
	{
		for (f = 0; f < 26; f++)
		{
			for (k = 0; k < 51; k++)
			{
				price = m * 3 + f * 2 + k * 1;
				if (price == 50)
				{
					count++;
					printf("{%2d,%2d,%2d}", m, f, k);
					if (count % 6 == 0)
					{
						printf("\n");
					}
				}
			}
		}
	}

	return 0;
}