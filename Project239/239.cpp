#include <stdio.h>
#include <queue>
using namespace std;

typedef struct Point
{
	int r;
	int c;
}POINT;

void BFS();

int n, m, a, b, visited[510][510] = { 0 }, step[510][510] = { 0 }, dr[4] = { -1, 0, 1, 0 }, dc[4] = { 0, 1, 0, -1 };
POINT point[100010], master[100010];

int main()
{
	scanf("%d %d %d %d", &n, &m, &a, &b);
	for (int i = 1; i <= a; i++)
	{
		scanf("%d %d", &point[i].r, &point[i].c);
		visited[point[i].r][point[i].c] = 1;
	}
	for (int i = 1; i <= b; i++)
	{
		scanf("%d %d", &master[i].r, &master[i].c);
	}

	BFS();

	for (int i = 1; i <= b; i++)
	{
		printf("%d\n", step[master[i].r][master[i].c]);
	}

	return 0-0;
}
void BFS()
{
	POINT Now, New;
	queue<POINT>Q;
	for (int i = 1; i <= a; i++)
	{
		Q.push(point[i]);
	}
	while (!Q.empty())
	{
		Now = Q.front();
		Q.pop();
		for (int i = 0; i < 4; i++)
		{
			New.r = Now.r + dr[i];
			New.c = Now.c + dc[i];
			if (New.r >= 1 && New.r <= n && New.c >= 1 && New.c <= m && visited[New.r][New.c] == 0)
			{
				visited[New.r][New.c] = 1;
				step[New.r][New.c] = step[Now.r][Now.c] + 1;
				Q.push(New);
			}
		}
		visited[Now.r][Now.c] = 1;
	}
}