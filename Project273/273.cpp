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
	bool operator <(const Node& x) const
	{
		return x.d < d;
	}
}node, Now;

void InitialSingleSource();
void Relax(int u, int v, int w);
void Dijkstra(vector<Vertex> G[]);

int n, m, s = 1, time = 0, pre[100010], visited[100010] = { 0 }, d[100010], U[100010], V[100010], W[100010];
vector<Vertex> G[100010], GT[100010];
std::priority_queue<Node> Q;

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; i++) {
		int u;
		scanf("%d %d %d", &u, &vertex.u, &vertex.w);
		U[i] = u, V[i] = vertex.u, W[i] = vertex.w;
		G[u].push_back(vertex);
		vertex.u = U[i];
		GT[V[i]].push_back(vertex);
	}
	Dijkstra(G);
	for (int i = 1; i <= n; i++) {
		time += d[i];
		visited[i] = 0;
	}
	Dijkstra(GT);
	for (int i = 1; i <= n; i++) {
		time += d[i];
	}

	printf("%d", time);

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
		if (!visited[v])
		{
			node.u = v, node.d = d[v];
			Q.push(node);
		}
		pre[v] = u;
	}
}
void Dijkstra(vector<Vertex> G[])
{
	InitialSingleSource();
	node.u = s, node.d = 0;
	Q.push(node);
	while (!Q.empty()) {
		Now = Q.top();
		Q.pop();
		if (visited[Now.u])
			continue;
		visited[Now.u] = 1;
		for (int i = 0; i < G[Now.u].size(); i++) {
			Relax(Now.u, G[Now.u][i].u, G[Now.u][i].w);
		}
	}
}