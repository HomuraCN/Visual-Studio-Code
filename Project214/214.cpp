#include <stdio.h>

int Parent(int i);
int Left(int i);
int Right(int i);
void MinHeapify(long long A[], int i);
void BuildMinHeap(long long A[], int n);
int HeapExtractMin(long long A[]);
void HeapIncreaseKey(long long A[], int i, int key);
void MinHeapInsert(long long A[], int key);
void BuildMinQueueHeap(long long A[], int n);

int heap_size;
long long ans = 0;
long long A[10010];

int main()
{
	int n;

	scanf("%d", &n);

	for (int i = 1; i <= n; i++)
	{
		scanf("%lld", &A[i]);
	}

	BuildMinQueueHeap(A, n);
	/*合并n - 1次果子*/
	for (int i = 1; i <= n - 1; i++)
	{
		long long temp1, temp2;
		temp1 = HeapExtractMin(A);
		temp2 = HeapExtractMin(A);
		ans += temp1 + temp2;
		MinHeapInsert(A, temp1 + temp2);
	}

	printf("%lld", ans);

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

void MinHeapify(long long A[], int i)
{
	int temp, left = Left(i), right = Right(i), min;
	if (left <= heap_size && A[i] > A[left])
	{
		min = left;
	}
	else
	{
		min = i;
	}

	if (right <= heap_size && A[min] > A[right])
	{
		min = right;
	}

	if (min != i)
	{
		temp = A[i];
		A[i] = A[min];
		A[min] = temp;
		MinHeapify(A, min);
	}
}

void BuildMinHeap(long long A[], int n)
{
	for (int i = n / 2; i >= 1; i--)
	{
		MinHeapify(A, i);
	}
}

int HeapExtractMin(long long A[])
{
	int min;
	if (heap_size < 1)
	{
		printf("error");
		return 0;
	}
	min = A[1];
	A[1] = A[heap_size];
	heap_size--;
	MinHeapify(A, 1);
	return min;
}

void HeapIncreaseKey(long long A[], int i, int key)
{
	int temp;
	if (key < A[i])
	{
		printf("error");
		return;
	}
	A[i] = key;
	while (i > 1 && A[Parent(i)] > A[i])
	{
		temp = A[i];
		A[i] = A[Parent(i)];
		A[Parent(i)] = temp;
		i = Parent(i);
	}
}

void MinHeapInsert(long long A[], int key)
{
	heap_size++;
	A[heap_size] = -1;
	HeapIncreaseKey(A, heap_size, key);
}

void BuildMinQueueHeap(long long A[], int n)
{
	heap_size = 1;
	for (int i = 2; i <= n; i++)
	{
		MinHeapInsert(A, A[i]);
	}
}