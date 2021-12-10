#include <stdio.h>
#include <queue>
using namespace std;

typedef struct point
{
	int x;
	int y;
}POINT;
POINT House, Now, Next;

void BFS(int x, int y);

int n, m, board[410][410] = { 0 }, flag[410][410] = { 0 };

int main()
{
	int x, y, special_judge = -1;

	scanf("%d %d %d %d", &n, &m, &x, &y);

	BFS(x, y);

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (flag[i][j] == 0)
			{
				printf("%-5d", special_judge);
			}
			else
			{
				printf("%-5d", board[i][j]);
			}
		}
		printf("\n");
	}

	return 0;
}
void BFS(int x, int y)
{
	int dx[8] = {1, 2, 2, 1, -1, -2, -2, -1}, dy[8] = {2, 1, -1, -2, -2, -1, 1, 2};
	queue<POINT> Q;

	House.x = x;
	House.y = y;

	flag[House.x][House.y] = 1;
	Q.push(House);

	while (!Q.empty())
	{
		Now = Q.front();
		Q.pop();
		for (int i = 0; i < 8; i++)
		{
			if (Now.x + dx[i] >= 1 && Now.x + dx[i] <= n && Now.y + dy[i] >= 1 && Now.y + dy[i] <= m && flag[Now.x + dx[i]][Now.y + dy[i]] == 0)
			{
				Next.x = Now.x + dx[i], Next.y = Now.y + dy[i];
				flag[Next.x][Next.y] = 1; /*Í¿Îª»ÒÉ«*/
				board[Next.x][Next.y] = board[Now.x][Now.y] + 1;
				Q.push(Next);
			}
		}
		flag[Now.x][Now.y] = 1;
	}
}