#include <stdio.h>

void QuickSort(int num[], int left, int right);

int main()
{	
	int N, num[100010];

	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		scanf("%d", &num[i]);
	}

	QuickSort(num, 0, N - 1);

	for(int i = 0; i < N; i++)
	{
		printf("%d ", num[i]);
	}

	return 0;
}
/*¿ìÅÅ*/
void QuickSort(int num[], int left, int right)
{
	int i = left, j = right;
	int temp, pivot;

	pivot = num[(left + right) / 2];

	while (i <= j)
	{
		while (num[i] < pivot)
		{
			i++;
		}
		while (num[j] > pivot)
		{
			j--;
		}
		if (i <= j)
		{
			temp = num[i];
			num[i] = num[j];
			num[j] = temp;
			i++;
			j--;
		}
	}

	if (i < right)
	{
		QuickSort(num, i, right);
	}
	if (j > left)
	{
		QuickSort(num, left, j);
	}

}