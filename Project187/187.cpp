#include <stdio.h>

void Merge(int A[], int p, int q, int r);
void MergeSort(int A[], int p, int r);

int n, A[114514];

int main()
{
	scanf("%d", &n);

	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &A[i]);
	}

	MergeSort(A, 1, n);

	for (int i = 1; i <= n; i++)
	{
		printf("%d ", A[i]);
	}

	return 0;
}

void Merge(int A[], int p, int q, int r)
{
	int len1 = q - p + 1, len2 = r - (q + 1) + 1;

	int A1[100011], A2[100011];

	for (int i = 1; i <= len1; i++)
	{
		A1[i] = A[p + i - 1];
	}
	for (int i = 1; i <= len2; i++)
	{
		A2[i] = A[q + i];
	}

	A1[len1 + 1] = 99999999, A2[len2 + 1] = 99999999;

	int j = 1, k = 1;

	for (int i = p; i <= r; i++)
	{
		if (A1[j] <= A2[k])
		{
			A[i] = A1[j];
			j++;
		}
		else if (A1[j] > A2[k])
		{
			A[i] = A2[k];
			k++;
		}
	}

	return;
}

void MergeSort(int A[], int p, int r)
{
	if (p >= r)
	{
		return;
	}
	else if(p < r)
	{
		int q = (p + r) / 2;

		MergeSort(A, p, q);
		MergeSort(A, q + 1, r);
		Merge(A, p, q, r);

		return;
	}
}