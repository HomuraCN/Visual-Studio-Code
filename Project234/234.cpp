#include <stdio.h>

void DFS(int X, int Y);

int M, N, X, Y, sum = 0, visited[25][25] = { 0 }, dy[8] = {0, 1, 0, -1, -1, 1, 1, -1}, dx[8] = {-1, 0, 1, 0, -1, -1, 1, 1};
char map[25][25];

int main()
{
	scanf("%d %d %d %d", &M, &N, &X, &Y);

	for (int i = 1; i <= M; i++)
	{
		scanf("%s", map[i] + 1);
	}
	for (int i = 0; i <= N + 1; i++)
	{
		map[0][i] = '.', map[M + 1][i] = '.';
	}
	for (int i = 0; i <= M + 1; i++)
	{
		map[i][0] = '.', map[i][N + 1] = '.';
	}

	visited[X][Y] = 1;
	DFS(X, Y);

	printf("%d", sum);

	return 0;
}
void DFS(int X, int Y)
{
	int Newx, Newy;

	for (int i = 0; i < 4; i++)
	{
		if (map[X + dx[i]][Y + dy[i]] == '.')
		{
			sum++;
		}
	}

	for (int i = 0; i < 8; i++)
	{
		Newx = X + dx[i], Newy = Y + dy[i];
		if (Newx >= 1 && Newx <= M && Newy >= 1 && Newy <= N && visited[Newx][Newy] == 0 && map[Newx][Newy] == 'X')
		{
			visited[Newx][Newy] = 1;
			DFS(Newx, Newy);
		}
	}
}