#include <stdio.h>

int Parent(int i);
int Left(int i);
int Right(int i);
void MaxHeapify(int A[], int i);
void BuildMaxHeap(int A[], int n);
void HeapSort(int A[], int n);

int heap_size;

int main()
{
	int n, A[1000];

	scanf("%d", &n);

	heap_size = n;

	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &A[i]);
	}

	HeapSort(A, n);

	for (int i = 1; i <= n; i++)
	{
		printf("%d ", A[i]);
	}

	return 0;
}

int Parent(int i)
{
	return i / 2;
}
int Left(int i)
{
	return 2 * i;
}
int Right(int i)
{
	return 2 * i + 1;
}

void MaxHeapify(int A[], int i)
{
	int temp, left = Left(i), right = Right(i), max;
	if (left <= heap_size && A[i] < A[left])
	{
		max = left;
	}
	else
	{
		max = i;
	}

	if (right <= heap_size && A[max] < A[right])
	{
		max = right;
	}

	if (max != i)
	{
		temp = A[i];
		A[i] = A[max];
		A[max] = temp;
		MaxHeapify(A, max);
	}
}

void BuildMaxHeap(int A[], int n)
{
	for (int i = n / 2; i >= 1; i--)
	{
		MaxHeapify(A, i);
	}
}

void HeapSort(int A[], int n)
{
	int temp;

	BuildMaxHeap(A, n);

	for (int i = n; i >= 2; i--)
	{
		temp = A[1];
		A[1] = A[i];
		A[i] = temp;
		heap_size--;
		MaxHeapify(A, 1);
	}
}