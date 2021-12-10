#include <stdio.h>

int k, a[100][100010], n, m, p, cnt = 0, oier[100010] = { 0 };

int main()
{
	scanf("%d %d %d", &n, &m, &p);

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &k);
		for (int j = 0; j < k; j++)
		{
			scanf("%d", &a[i][j]);
			oier[a[i][j]]++;
		}
	}

	for (int i = 1; i <= m; i++)
	{
		if (oier[i] == p)
		{
			cnt++;
			oier[i] = -1;
		}
	}

	printf("%d\n", cnt);

	for (int i = 1; i <= m; i++)
	{
		if (oier[i] == -1)
		{
			printf("%d", i);
		}
	}

	return 0;
}