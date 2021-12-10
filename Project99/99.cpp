#include <stdio.h>

int main()
{
	int N, chinese[1000], math[1000], english[1000], sum[1000], max = 0, flag;
	char name[1000][7];

	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		scanf("%s", name[i]);
		scanf("%d", &chinese[i]);
		scanf("%d", &math[i]);
		scanf("%d", &english[i]);
		sum[i] = chinese[i] + math[i] + english[i];
	}

	for (int i = 0; i < N; i++)
	{
		if (sum[i] > max)
		{
			max = sum[i];
			flag = i;
		}
	}

	printf("%s ", name[flag]);
	printf("%d %d %d", chinese[flag], math[flag], english[flag]);

	return 0;
}