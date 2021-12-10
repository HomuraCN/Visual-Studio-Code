#include <stdio.h>

void DFS(int r, int c);

int R, C, flagr, flagc, max, sum = 0, map[45][45], visited[45][45] = { 0 }, dr[4] = { -1, 0, 1, 0 }, dc[4] = { 0, 1, 0, -1 };

int main()
{
	scanf("%d %d", &R, &C);

	for (int i = 1; i <= R; i++)
	{
		for (int j = 1; j <= C; j++)
		{
			scanf("%d", &map[i][j]);
		}
	}

	max = map[1][1];
	visited[1][1] = 1;
	DFS(1, 1);

	return 0;
}
void DFS(int r, int c)
{
	int Newr, Newc;
	sum += max;
	max = 0;
	if (r == R && c == C)
	{
		printf("%d", sum);
		return;
	}
	for (int i = 0; i < 4; i++)
	{
		Newr = r + dr[i], Newc = c + dc[i];
		if (Newr >= 1 && Newr <= R && Newc >= 1 && Newc <= C && visited[Newr][Newc] == 0)
		{
			if (max < map[Newr][Newc])
			{
				max = map[Newr][Newc];
				flagr = Newr, flagc = Newc;
			}
		}
	}
	visited[flagr][flagc] = 1;
	DFS(flagr, flagc);
}