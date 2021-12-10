#include <stdio.h>
#include <queue>
using namespace std;

int M, map[310][310], flag[310][310] = { 0 }, sx, sy, st, time[310][310] = { 0 };
int dx[5] = {0, 0, 0, 1, -1}, dy[5] = {0, 1, -1, 0, 0};
int Judge(int x)
{
	if (x == -1)
	{
		return 999999;
	}
	else 
	{
		return x;
	}
}
int main()
{
	scanf("%d", &M);
	for (int i = 0; i < 305; i++)
	{
		for (int j = 0; j < 305; j++)
		{
			map[i][j] = -1;
		}
	}

	for (int i = 1; i <= M; i++) 
	{
		scanf("%d %d %d", &sx, &sy, &st);
		for (int j = 0; j < 4; j++) 
		{
			if (sx + dx[j] >= 0 && sy + dy[j] >= 0 && (map[sx + dx[j]][sy + dy[j]] == -1 || map[sx + dx[j]][sy + dy[j]] > st))
			{
				map[sx + dx[j]][sy + dy[j]] = st;
			}
		}
	}
	queue<int> q[2];
	flag[0][0] = 1;
	q[0].push(0); 
	q[1].push(0);

	while (!q[0].empty()) 
	{
		int x = q[0].front(), y = q[1].front();
		q[0].pop(), q[1].pop();

		int s = time[x][y] + 1;
		if (map[x][y] == -1) 
		{
			printf("%d", s);
			return 0;
		}
		for (int i = 1; i <= 4; i++) 
		{
			int Newx = x + dx[i], Newy = y + dy[i];
			if (Newx >= 0 && Newy >= 0 && s < Judge(map[Newx][Newy]) && flag[Newx][Newy] == 0) 
			{
				q[0].push(Newx), q[1].push(Newy);
				flag[Newx][Newy] = 1;
				time[Newx][Newy] = s;
			}
		}
	}
	printf("-1");
	return 0;
}