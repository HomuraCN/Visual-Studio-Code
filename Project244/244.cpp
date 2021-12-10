#include <stdio.h>

typedef struct Path
{
	int r;
	int c;
}PATH;

void DFS(int R, int C, int cnt);

int count = 0, m, n, mazz[15][15] = { 0 }, visited[15][15] = { 0 }, dr[4] = { 0, -1, 0, 1 }, dc[4] = { -1, 0, 1, 0 };
PATH start, end, path[50000];

int main()
{	
	scanf("%d %d", &m, &n);
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			scanf("%d", &mazz[i][j]);
		}
	}
	scanf("%d %d", &start.r, &start.c);
	scanf("%d %d", &end.r, &end.c);

	visited[start.r][start.c] = 1;/*起点要标记*/

	DFS(start.r, start.c, 1);

	if (count == 0)
	{
		printf("-1");
	}

	return 0;
}
void DFS(int R, int C, int cnt)
{
	int Newr, Newc;
	if (R == end.r && C == end.c)
	{
		count++;
		printf("(%d,%d)->", start.r, start.c);
		for (int i = 1; i < cnt; i++)
		{
			if (i == cnt - 1)
			{
				printf("(%d,%d)\n", path[i].r, path[i].c);
			}
			else
			{
				printf("(%d,%d)->", path[i].r, path[i].c);
			}
		}
		return;
	}
	else
	{
		for (int i = 0; i < 4; i++)
		{
			Newr = R + dr[i], Newc = C + dc[i];
			if (visited[Newr][Newc] == 0 && mazz[Newr][Newc] == 1 && Newr >= 1 && Newr <= m && Newc >= 1 && Newc <= n)
			{
				path[cnt].r = Newr;
				path[cnt].c = Newc;
				visited[Newr][Newc] = 1;
				DFS(Newr, Newc, cnt + 1);
				visited[Newr][Newc] = 0;
			}
		}
	}
}