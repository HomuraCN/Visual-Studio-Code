#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	int ranNumber1, ranNumber2, result, i, counter = 0;

	for (i = 0; i < 3; i++)
	{
		srand((unsigned)time(NULL));
		ranNumber1 = (rand() % 10) + 1;
		ranNumber2 = (rand() % 10) + 1;

		printf("%d + %d = ?\n", ranNumber1, ranNumber2);

		scanf_s("%d", &result);

		if (result == ranNumber1 + ranNumber2)
		{
			printf("Right!\n"); break;
		}
		else
		{
			counter++;
			printf("Wrong!\n");
		}

		if (counter == 3)
		{
			printf("You have made mistakes for three times!\n");
		}
	}
	
	return 0;
}