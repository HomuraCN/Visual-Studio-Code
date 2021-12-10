#include <stdio.h>
#include <vector>
using namespace std;

typedef struct Vertex
{
	int u;
	int w;
};

void InitialSingleSource();
void Relax(int u, int v, int w);
int BellmanFord();

int n, m, s, d[100010], pre[100010];
vector<Vertex> G[100010];
Vertex vertex;

int main()
{
	scanf("%d %d %d", &n, &m, &s);
	for (int i = 1; i <= m; i++) {
		int u;
		scanf("%d %d %d", &u, &vertex.u, &vertex.w);
		G[u].push_back(vertex);
	}
	BellmanFord();
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
		pre[v] = u;
	}
}
int BellmanFord()
{
	InitialSingleSource();
	for (int i = 1; i <= n - 1; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 0; k < G[j].size(); k++) {
				Relax(j, G[j][k].u, G[j][k].w);
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < G[i].size(); j++) {
			if (d[G[i][j].u] > d[i] + G[i][j].w) {
				return 0;
			}
		}
	}
	return 1;
}