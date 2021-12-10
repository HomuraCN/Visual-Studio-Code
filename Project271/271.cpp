#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

struct Vertex
{
	int u;
	int w;
}vertex;
struct Node
{
	int u;
	int d;/*key*/
	bool operator <(const Node& x)const
	{
		return x.d < d;
	}
}node, Now;

void InitialSingleSource();
void Relax(int u, int v, int w);
void Dijkstra();

int n, m, s, pre[100010], visited[100010] = { 0 }, d[100010];
vector<Vertex> G[100010];
std::priority_queue<Node> Q;

int main()
{
	scanf("%d %d %d", &n, &m, &s);
	for (int i = 1; i <= m; i++) {
		int u;
		scanf("%d %d %d", &u, &vertex.u, &vertex.w);
		G[u].push_back(vertex);
	}
	Dijkstra();
	for (int i = 1; i <= n; i++) {
		printf("%d ", d[i]);
	}

	return 0;
}
void InitialSingleSource()
{
	for (int i = 1; i <= n; i++) {
		d[i] = 2147483647;
		pre[i] = 0;
	}
	d[s] = 0;
}
void Relax(int u, int v, int w)
{
	if (d[v] > d[u] + w)
	{
		d[v] = d[u] + w;
		if (visited[v] == 0)
		{
			node.u = v, node.d = d[v];
			Q.push(node);
		}
		pre[v] = u;
	}
}
void Dijkstra()
{
	InitialSingleSource();
	node.u = s, node.d = 0;
	Q.push(node);
	while (!Q.empty()) {
		Now = Q.top();
		Q.pop();
		if (visited[Now.u] == 1)
			continue;
		visited[Now.u] = 1;
		for (int i = 0; i < G[Now.u].size(); i++) {
			Relax(Now.u, G[Now.u][i].u, G[Now.u][i].w);
		}
	}
}