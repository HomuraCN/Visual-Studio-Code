#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

struct Vertex {
	int u;
	int w;
}vertex;
struct Node {
	int u;
	int d;/*key*/
	bool operator <(const Node& x)const {
		return x.d < d;
	}
}node, Now;

void InitialSingleSource();
void Relax(int u, int v, int w);
void Dijkstra();

const int maxn = 1e3 + 10;
int n, m, s, t, K, pre[maxn], visited[maxn] = { 0 }, d[maxn];
vector<Vertex> G[maxn];
std::priority_queue<Node> Q;

int main() {
	scanf("%d %d %d", &n, &s, &t);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &K);
		for (int j = 1; j <= K; j++) {
			scanf("%d", &vertex.u);
			if (j == 1) {
				vertex.w = 0;
			}
			else {
				vertex.w = 1;
			}
			G[i].push_back(vertex);
		}
	}
	Dijkstra();
	if (d[t] == 0x3f3f3f3f) {
		printf("-1");
	}
	else {
		printf("%d", d[t]);
	}

	return 0;
}
void InitialSingleSource() {
	for (int i = 1; i <= n; i++) {
		d[i] = 0x3f3f3f3f;
		pre[i] = 0;
	}
	d[s] = 0;
}
void Relax(int u, int v, int w) {
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
void Dijkstra() {
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