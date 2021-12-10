#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

void BFS();

int n, m, u, v, visited[100010] = { 0 }, step[100010] = { 0 };
vector<int> V[100010];

int main()
{
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= m; i++)
	{
		scanf("%d %d", &u, &v);
		V[u].push_back(v);
	}
	BFS();
	printf("%d", step[n] - 1);

	return 0-0;
}
void BFS()
{
	int temp;
	queue<int> Q;
	Q.push(1);
	while (!Q.empty())
	{
		temp = Q.front();
		Q.pop();
		for (int i = 0; i < V[temp].size(); i++)
		{
			if (visited[V[temp][i]] == 0)
			{
				visited[V[temp][i]] = 1;
				Q.push(V[temp][i]);
				step[V[temp][i]] = step[temp] + 1;
			}
		}
		visited[temp] = 1;
	}
}