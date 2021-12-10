#include <stdio.h>

typedef struct subarray
{
	int max_left;
	int max_right;
	int max_sum;
}SUBARRAY;

int main()
{
	int A[200010];

	return 0;
}

SUBARRAY FindMaxCrossingSubarray(int A[], int low, int mid, int high)
{
	SUBARRAY subarray;

	int left_sum = -999999, right_sum = -999999, sum = 0, max_left, max_right;
	for (int i = mid; i >= low; i--)
	{
		sum += A[i];
		if (sum > left_sum)
		{
			left_sum = sum;
			max_left = i;
		}
	}

	sum = 0;
	for (int i = mid + 1; i <= high; i++)
	{
		sum += A[i];
		if (sum > right_sum)
		{
			right_sum = sum;
			max_right = i;
		}
	}

	subarray.max_left = max_left, subarray.max_right = max_right, subarray.max_sum = left_sum + right_sum;

	return subarray;
}

SUBARRAY FindMaxSubarray(int A[], int low, int high)
{ 
	if (low == high)
	{
		return subarray;
	}
}