#include <stdio.h>
#include <math.h>

int main()
{
	int N, counter = 0, score[1000][3], total[1000][1];

	scanf("%d", &N);

	for (int i = 0; i <= N; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			scanf("%d", &score[i][j]);
		}
	}

	for (int m = 0; m < N; m++)
	{
		total[m][0] = score[m][0] + score[m][1] + score[m][2];
	}

	for (int h = 0; h < N-1; h++)
	{
		for (int k = h+1; k < N; k++)
		{
			if (abs(score[h][0] - score[k][0]) <=5 && abs(score[h][1] - score[k][1]) <= 5 && abs(score[h][2] - score[k][2]) <= 5 && abs(total[h][0] - total[k][0]))
			{
				counter++;
			}
		}
	}

	printf("%d", counter);

	return 0;
}