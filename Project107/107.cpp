#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	int matA[2][3], matB[3][2], matC[2][2];

	srand((unsigned)time(NULL));

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			matA[i][j] = rand() % 20;
		}
	}

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			matB[i][j] = rand() % 20;
		}
	}

	matC[0][0] = matA[0][0] * matB[0][0] + matA[0][1] * matB[1][0] + matA[0][2] * matB[2][0];
	matC[0][1] = matA[0][0] * matB[0][1] + matA[0][1] * matB[1][1] + matA[0][2] * matB[2][1];
	matC[1][0] = matA[1][0] * matB[0][0] + matA[1][1] * matB[1][0] + matA[1][2] * matB[2][0];
	matC[1][1] = matA[1][0] * matB[0][1] + matA[1][1] * matB[1][1] + matA[1][2] * matB[2][1];

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			printf("%d ", matC[i][j]);
		}
		printf("\n");
	}

	printf("=\n");

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			printf("%d ", matA[i][j]);
		}
		printf("\n");
	}

	printf("*\n");

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			printf("%d ", matB[i][j]);
		}
		printf("\n");
	}

	return 0;
}