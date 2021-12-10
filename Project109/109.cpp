#include <stdio.h>

void Move(char map[][12], int num[]);

int main(void)
{
	char map[12][12];
	int F[3] = { 0 }, C[3] = { 0 }, counter = 0;

	for (int i = 0; i < 12; i++)
	{
		map[0][i] = '*', map[11][i] = '*';
	}

	for (int i = 0; i < 12; i++)
	{
		map[i][0] = '*', map[i][11] = '*';
	}

	for (int i = 1; i <= 10; i++)
	{
		for (int j = 1; j <= 10; j++)
		{
			scanf(" %c", &map[i][j]);
			if (map[i][j] == 'F')
			{
				F[1] = i, F[2] = j;
			}
			if (map[i][j] == 'C')
			{
				C[1] = i, C[2] = j;
			}
		}
	}

	while (!(F[1] == C[1] && F[2] == C[2]))
	{
		Move(map, F);
		Move(map, C);
		counter++;
		if (counter == 99999)
		{
			printf("0");
			return 0-0;
		}
	}

	printf("%d", counter);

	return 0-0;
}
/*F&CÒÆ¶¯*/
void Move(char map[][12], int num[])
{
	if (num[0] == 0)
	{
		if (map[num[1] - 1][num[2]] == '*')
		{
			num[0] = 1;
		}
		else
		{
			num[1]--;
		}
	}
	else if (num[0] == 1)
	{
		if (map[num[1]][num[2] + 1] == '*')
		{
			num[0] = 2;
		}
		else
		{
			num[2]++;
		}
	}
	else if (num[0] == 2)
	{
		if (map[num[1] + 1][num[2]] == '*')
		{
			num[0] = 3;
		}
		else
		{
			num[1]++;
		}
	}
	else if (num[0] == 3)
	{
		if (map[num[1]][num[2] - 1] == '*')
		{
			num[0] = 0;
		}
		else
		{
			num[2]--;
		}
	}
}