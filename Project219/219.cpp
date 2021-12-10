#include <stdio.h>

void DFS(int x, int y);

int cnt = 0, N, M, dx[8] = { 0, 1, 1, 1, 0, -1, -1, -1 }, dy[8] = { 1, 1, 0, -1, -1, -1, 0, 1 };
char map[110][110];

int main()
{
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++)
	{
		scanf("%s", map[i]);
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (map[i][j] == 'W')
			{
				DFS(i, j);
				cnt++;
			}
		}
	}

	printf("%d", cnt);

	return 0;
}
void DFS(int x, int y)
{
	int Newx, Newy;
	map[x][y] = '.';
	for (int i = 0; i < 8; i++)
	{
		Newx = x + dx[i];
		Newy = y + dy[i];
		if (Newx >= 0 && Newx < N && Newy >= 0 && Newy < M && map[Newx][Newy] == 'W')
		{
			map[x][y] = '.';
			DFS(Newx, Newy);
		}
	}
}