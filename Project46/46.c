#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	float correctRate, ranNumber1, ranNumber2, result, i, answer, score, right = 0, wrong = 0;
	int j;
	char op[5] = {0, 1, 2, 3};
	char operate;

	for (i = 0; i < 10; i++)
	{
		srand((unsigned)time(NULL));
		ranNumber1 = rand() % 10 + 10.0;
		ranNumber2 = rand() % 10 + 10.0;
		j = op[rand() % 4];
		switch (j)
		{
		case 0: result = ranNumber1 + ranNumber2; break;
		case 1: result = ranNumber1 - ranNumber2; break;
		case 2: result = ranNumber1 * ranNumber2; break;
		case 3: result = ranNumber1 / ranNumber2; break;
		}
		switch (j)
		{
		case 0: operate = '+'; break;
		case 1: operate = '-'; break;
		case 2: operate = '*'; break;
		case 3: operate = '/'; break;
		}

		printf("%f %c %f = ?\n", ranNumber1, operate, ranNumber2);

		scanf_s("%f", &answer);

		if (answer == result)
		{
			printf("Right!\n");
			right++;
		}
		else
		{
			printf("Wrong!\n");
			wrong++;
		}
	}

	score = 100 - wrong * 10;
	correctRate = right / 10.0;

	printf("Your score(s) : %f\nYour correctrate : %.2f\n", score, correctRate);

	return 0;
}