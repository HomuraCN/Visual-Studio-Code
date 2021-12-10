#include <stdio.h>
#include <string.h>

int main()
{
	char num[99999], i = -1, N, Num[99999];

	do
	{
		i++;
		scanf("%c", &num[i]);
		if (num[i] == '\n')
		{
			N = i;
			break;
		}
	} while (1);

	strcpy(Num, num);

	for (int j = N+1; j <= (N * N + N - 1); j++)
	{
		scanf("%c", &Num[j]);
	}

	for (int k = 0; k < (N * N + N - 1); k++)
	{
		if (Num[k] == '\n')
		{
			continue;
		}
		if ()
		{

		}
	}

	return 0;
}