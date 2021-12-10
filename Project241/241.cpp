#include <stdio.h>
#include <queue>
using namespace std;

void BFS();

int t, x, y, visited[100010] = { 0 }, step[100010] = { 0 };

int main()
{
	scanf("%d", &t);

	for (int i = 1; i <= t; i++)
	{
		scanf("%d %d", &x, &y);
		BFS();
		printf("%d\n", step[y]);
		for (int j = 1; j <= 100010; j++)
		{
			visited[j] = 0;
			step[j] = 0;
		}
	}

	return 0;
}
void BFS()
{
	int Now, New;
	queue<int> Q;
	visited[x] = 1;
	Q.push(x);
	while (!Q.empty())
	{
		Now = Q.front();
		Q.pop();
		for (int i = 0; i < 3; i++)
		{
			if (i == 0)
			{
				New = Now + 1;
				if (New >= 0 && New <= 100000 && visited[New] == 0)
				{
					visited[New] = 1;
					Q.push(New);
					step[New] = step[Now] + 1;
				}
			}
			if (i == 1)
			{
				New = Now - 1;
				if (New >= 0 && New <= 100000 && visited[New] == 0)
				{
					visited[New] = 1;
					Q.push(New);
					step[New] = step[Now] + 1;
				}
			}
			if (i == 2)
			{
				New = Now * 2;
				if (New >= 0 && New <= 100000 && visited[New] == 0)
				{
					visited[New] = 1;
					Q.push(New);
					step[New] = step[Now] + 1;
				}
			}
		}
		visited[Now] = 1;
	}
}