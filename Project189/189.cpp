#include <stdio.h>

long long FindMaxCrossingSubarray(int A[], int low, int mid, int high);
long long FindMaxSubarray(int A[], int low, int high);

int A[200010];

int main()
{
	int n;
	long long ans;

	scanf("%d", &n);

	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &A[i]);
	}

	ans = FindMaxSubarray(A, 1, n);

	printf("%lld", ans);

	return 0;
}

long long FindMaxCrossingSubarray(int A[], int low, int mid, int high)
{
	long long left_sum = -999999, right_sum = -999999, sum = 0, max_left, max_right;
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

	return left_sum + right_sum;
}

long long FindMaxSubarray(int A[], int low, int high)
{
	int left_sum, right_sum, cross_sum, mid;

	if (low == high)
	{
		return A[low];
	}
	else
	{
		mid = (low + high) / 2;
		left_sum = FindMaxSubarray(A, low, mid);
		right_sum = FindMaxSubarray(A, mid + 1, high);
		cross_sum = FindMaxCrossingSubarray(A, low, mid, high);
		if (left_sum >= right_sum && left_sum >= cross_sum)
		{
			return left_sum;
		}
		else if (right_sum >= left_sum && right_sum >= cross_sum)
		{
			return right_sum;
		}
		else
		{
			return cross_sum;
		}
	}
}