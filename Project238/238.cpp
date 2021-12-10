#include <stdio.h>

int Volume, Weight, N, calorie[55], weight[55], volume[55], bag[450][450];

int Max(int x, int y);

int main()
{
	scanf("%d %d", &Volume, &Weight);
	scanf("%d", &N);

	for (int i = 1; i <= N; i++)
	{
		scanf("%d %d %d", &volume[i], &weight[i], &calorie[i]);
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = Weight; j >= weight[i]; j--)
		{
			for (int k = Volume; k >= volume[i]; k--)
			{
				bag[j][k] = Max(bag[j - weight[i]][k - volume[i]] + calorie[i], bag[j][k]);
			}
		}
	}

	printf("%d", bag[Weight][Volume]);

	return 0;
}
int Max(int x, int y)
{
	return x >= y ? x : y;
}