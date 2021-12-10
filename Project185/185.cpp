#include <stdio.h>

/*≤Â»Î≈≈¡–(…˝–Ú)*/
/*
int main()
{
	int A[6] = {3, 8, 5, 6, 7, 4};

	for (int i = 1; i < 6; i++)
	{
		int key = A[i];

		int j = i - 1;

		while (A[j] > key && j >= 0)
		{
			A[j + 1] = A[j];
			j--;
		}

		A[j + 1] = key;
	}

	for (int i = 0; i < 6; i++)
	{
		printf("%d", A[i]);
	}

	return 0;
}
*/

/*≤Â»Î≈≈–Ú(Ωµ–Ú)*/
/*
int main()
{
	int A[6] = { 3, 8, 5, 6, 7, 4 };

	for (int i = 1; i < 6; i++)
	{
		int key = A[i];

		int j = i - 1;

		while (A[j] < key && j >= 0)
		{
			A[j + 1] = A[j];
			j--;
		}
		
		A[j + 1] = key;
	}

	for (int i = 0; i < 6; i++)
	{
		printf("%d", A[i]);
	}

	return 0;
}
*/