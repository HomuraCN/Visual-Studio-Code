#include <stdio.h>

int main()
{
	int inClass[8], outClass[8], totalTime[8];
	int i, j, a, b, temp;

	for (i = 0; i < 7; i++)
	{
		scanf_s("%d %d", &inClass[i], &outClass[i]);
	}
	for (j = 0; j < 7; j++)
	{
		totalTime[j] = inClass[j] + outClass[j];
	}

	for (a = 0; a < 6; a++)
	{
		for (b = 0; b < 6 - a; b++)
		{
			if (totalTime[b] > totalTime[b+1])
			{
				temp = totalTime[b+1];
				totalTime[b + 1] = totalTime[b];
				totalTime[b] = temp;
			}
		}
	}

	printf("%d", totalTime[6]);

	return 0;
}