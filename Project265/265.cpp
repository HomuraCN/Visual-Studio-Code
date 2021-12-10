#include <stdio.h>

int Min(int x, int y);

int T, N, S, temp, left, right, ans = 2147483647, sum[100010] = { 0 };

int main()
{
	scanf("%d", &T);

	for (int i = 1; i <= T; i++)
	{
		scanf("%d %d", &N, &S);
		for (int j = 1; j <= N; j++)
		{
			scanf("%d", &temp);
			sum[j] = sum[j - 1] + temp;
		}
		for (int k = 1; k <= N; k++)
		{
			left = k, right = N;
			while (left <= right)
			{
				int mid = (left + right) / 2;
				if (sum[mid] - sum[k] >= S)
				{
					right = mid - 1;
					ans = Min(ans, mid - k);
				}
				else if (sum[mid] - sum[k] < S)
				{
					left = mid + 1;
				}
			}
		}
		if (ans == 2147483647)
		{
			printf("0\n");
		}
		else
		{
			printf("%d\n", ans);
		}
		ans = 2147483647;
	}

	return 0;
}
int Min(int x, int y)
{
	return x <= y ? x : y;
}