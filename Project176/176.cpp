#include <stdio.h>

long long F[101][10001] = { 0 }, costValue[101];

int main()
{
	int N, M;

	scanf("%d %d", &N, &M);

	for (int i = 1; i <= N; i++)
	{
		scanf("%lld", &costValue[i]);
	}

	for (int i = 1; i <= N; i++)
	{
		for(int j = 1; j <= M; j++)
		{
			if (j > costValue[i])
			{
				F[i][j] = F[i - 1][j] + F[i - 1][j - costValue[i]];
			}
			if (j == costValue[i])
			{
				F[i][j] = F[i - 1][j] + 1;
			}
			if (j < costValue[i])
			{
				F[i][j] = F[i - 1][j];
			}
		}
	}

	printf("%d", F[N][M]);

	return 0;
}