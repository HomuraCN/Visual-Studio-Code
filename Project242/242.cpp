#include <stdio.h>
#include <queue>
using namespace std;

int ansmax[1000010], ansmin[1000010];

int main()
{
	int n, k, a, max = -2147483648, min = 2147483647;
	queue<int> Q, q;

	scanf("%d %d", &n, &k);

	for (int i = 1; i <= k; i++)
	{
		scanf("%d", &a);
		Q.push(a);
	}

	for (int i = 1; i <= n - k + 1; i++)
	{
		max = -2147483648, min = 2147483647;
		for (int j = 1; j <= k; j++)
		{
			if (max <= Q.front())
			{
				max = Q.front();
			}
			if (min >= Q.front())
			{
				min = Q.front();
			}
			q.push(Q.front());
			Q.pop();
		}
		for (int h = 1; h <= k; h++)
		{
			Q.push(q.front());
			q.pop();
		}
		ansmax[i] = max;
		ansmin[i] = min;
		if (i < n - k + 1)
		{
			scanf("%d", &a);
			Q.pop();
			Q.push(a);
		}
		else
		{
			break;
		}
	}

	for (int i = 1; i <= n - k + 1; i++)
	{
		printf("%d ", ansmin[i]);
	}
	printf("\n");
	for (int i = 1; i <= n - k + 1; i++)
	{
		printf("%d ", ansmax[i]);
	}

	return 0;
}