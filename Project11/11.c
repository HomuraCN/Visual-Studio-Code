#include <stdio.h>

int main(void)
{
	int math_score[10];
	int i;
	float average, sum = 0;

	for (i = 0; i < 10; i++)
	{
		scanf_s("%d", &math_score[i]);
		sum = sum + math_score[i];
	}

	average = sum / 10.0;

	printf("average = %.2f", average);

	return 0;
}