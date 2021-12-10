#include <stdio.h>

int main()
{
	int n, m, min = 400000, max = 0, num[3000];

	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &num[i]);
	}

	for (int j = 0; j <= n - m; j++)
	{
		if (num[j] + num[j + 1] + num[j + 2] < min)
		{
			min = num[j] + num[j + 1] + num[j + 2];
		}
	}

	printf("%d", min);

	return 0;
}