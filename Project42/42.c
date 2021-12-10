#include <stdio.h>

int main()
{
	int inClass[7], outClass[7], totalTime[7];
	int i, j, Day = 0, max = 0;
	for (i = 0; i < 7; i++)
	{
		scanf_s("%d %d", &inClass[i], &outClass[i]);
		totalTime[i] = inClass[i] + outClass[i];
	}

	for (j = 6; j >= 0; j--)
	{
		if (totalTime[j] > 8)
		{
			if(totalTime[j] > max)
			max = totalTime[j];
			Day = j + 1;
		}
	}

	printf("%d", Day);

	return 0;
}