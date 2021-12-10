#include <stdio.h>

typedef struct project
{
	int id;
	int time;
}PROJECT;

int main()
{
	PROJECT pro[21][21];

	int m, n, machine[21][10000] = { 0 }, last_time[21] = { 0 }, step[21] = { 0 }, order[500], test = 0, max = 0;

	scanf("%d %d", &m, &n);

	for (int i = 1; i <= m * n; i++)
	{
		scanf("%d", &order[i]);
	}

	for (int j = 1; j <= n; j++)
	{
		for (int k = 1; k <= m; k++)
		{
			scanf("%d", &pro[j][k].id);
		}
	}

	for (int j = 1; j <= n; j++)
	{
		for (int k = 1; k <= m; k++)
		{
			scanf("%d", &pro[j][k].time);
		}
	}

	/*°´order°²ÅÅ*/
	for (int i = 1; i <= m * n; i++)
	{
		int test = 0;
		step[order[i]]++;
		for (int j = last_time[order[i]] + 1; ; j++)
		{
			if (machine[pro[order[i]][step[order[i]]].id][j] != 1)
			{
				test++;
			}
			else
			{
				test = 0;
			}
			if (test == pro[order[i]][step[order[i]]].time)
			{
				for (int k = j - pro[order[i]][step[order[i]]].time + 1; k <= j; k++)
				{
					machine[pro[order[i]][step[order[i]]].id][k] = 1;
				}
				last_time[order[i]] = j;
				break;
			}
		}
	}

	for (int i = 1; i < 21; i++)
	{
		if (last_time[i] > max)
		{
			max = last_time[i];
		}
	}

	printf("%d", max);

	return 0;
}