#include <stdio.h>

void QuickSort(int A[], int p, int r);
int Partition(int A[], int p, int r);

int main()
{
	int n, A[27610];

	scanf("%d", &n);

	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &A[i]);
	}

	QuickSort(A, 1, n);

	for (int i = 1; i <= n; i++)
	{
		printf("%d ", A[i]);
	}

	return 0;
}

void QuickSort(int A[], int p, int r)
{
	int q;

	if (p < r)
	{
		q = Partition(A, p, r);
		QuickSort(A, p, q - 1);
		QuickSort(A, q + 1, r);
	}
}

int Partition(int A[], int p, int r)
{
	int i = p - 1, x = A[r], temp;

	for (int j = p; j <= r - 1; j++)
	{
		if (A[j] <= x)
		{
			i++;
			temp = A[i];
			A[i] = A[j];
			A[j] = temp;
		}
	}

	temp = A[i + 1];
	A[i + 1] = A[r];
	A[r] = temp;

	return i + 1;
}