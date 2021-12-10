#include <stdio.h>

int main()
{
	int N, M, W = 0, B = 0, R = 0, count = 0, color = 0;
	char flag[50][50];

	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++)
	{
		scanf("%s", flag[i]);
	}

	for (int i = 0; i < N; i++)
	{
		if (color == 0 && i == 0)
		{
			for (int j = 0; j < M; j++)
			{
				if (flag[i][j] != 'W')
				{
					count++;
				}
			}
		}
		if (color == 0 && i != 0)
		{
			for (int j = 0; j < M; j++)
			{
				switch (flag[i][j])
				{
				case 'W': W++; break;
				case 'B': B++; break;
				case 'R': R++; break;
				default: W += 0;
				}
			}
			if (N - i > 2)
			{
				if (W >= B)
				{
					count += M - W;
					W = 0, B = 0, R = 0;
				}
				else if (B > W)
				{
					count += M - B;
					W = 0, B = 0, R = 0;
				}
			}
			else
			{
				color++;
				W = 0, B = 0, R = 0;
			}
		}
		if (color == 1)
		{
			for (int j = 0; j < M; j++)
			{
				switch (flag[i][j])
				{
				case 'W': W++; break;
				case 'B': B++; break;
				case 'R': R++; break;
				default: W += 0;
				}
			}
			if (N - i > 1)
			{
				if (B >= R)
				{
					count += M - B;
					W = 0, B = 0, R = 0;
				}
				else if (R > B)
				{
					count += M - R;
					W = 0, B = 0, R = 0;
				}
			}
			else
			{
				color++;
				W = 0, B = 0, R = 0;
			}
		}
		if (color == 2)
		{
			for (int j = 0; j < M; j++)
			{
				switch (flag[i][j])
				{
				case 'W': W++; break;
				case 'B': B++; break;
				case 'R': R++; break;
				default: W += 0;
				}
			}
			count += M - R;
			W = 0, B = 0, R = 0;
		}
	}

	printf("%d", count);

	return 0;
}