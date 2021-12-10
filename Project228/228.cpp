#include <stdio.h>
#include <queue>
using namespace std;

typedef struct Point
{
	int x;
	int y;
}POINT;

void BFS();

int N, M, visited[310][310] = { 0 }, step[310][310] = { 0 }, dx[4] = { -1, 0, 1, 0 }, dy[4] = { 0, 1, 0, -1 };
char map[310][310];
POINT Start, Now, Next;

int main()
{
	scanf("%d %d", &N, &M);

	for (int i = 1; i <= N; i++)
	{
		scanf("%s", map[i] + 1);
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			if (map[i][j] == '@')
			{
				Start.x = i, Start.y = j;
				i = N + 1;
				break;
			}
		}
	}

	BFS();

	return 0 - 0;
}
void BFS()
{
	queue<POINT> Q;
	visited[Start.x][Start.y] = 1;
	Q.push(Start);
	while (!Q.empty())
	{
		Now = Q.front();
		Q.pop();
		for (int i = 0; i < 4; i++)
		{
			Next.x = Now.x + dx[i], Next.y = Now.y + dy[i];
			if (map[Next.x][Next.y] == '=')
			{
				printf("%d", step[Now.x][Now.y] + 1);
				return;
			}
			if (Next.x >= 1 && Next.x <= N && Next.y >= 1 && Next.y <= M && visited[Next.x][Next.y] == 0 && map[Next.x][Next.y] != '#')
			{
				if (map[Next.x][Next.y] >= 'A' && map[Next.x][Next.y] <= 'Z')
				{
					for (int j = 1; j <= N; j++)
					{
						for (int k = 1; k <= M; k++)
						{
							if (map[j][k] == map[Next.x][Next.y])
							{
								visited[j][k] = 1;
								step[j][k] = step[Now.x][Now.y] + 1;
								Next.x = j, Next.y = k;
								Q.push(Next);
								j = N + 1;
								break;
							}
						}
					}
				}
				else
				{
					visited[Next.x][Next.y] = 1;
					step[Next.x][Next.y] = step[Now.x][Now.y] + 1;
					Q.push(Next);
				}
			}
		}
		visited[Now.x][Now.y] = 1;
	}
}