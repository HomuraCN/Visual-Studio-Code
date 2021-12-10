#include <stdio.h>
#include <vector>
#include <queue>
#include <string.h>
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

const int maxn = 20 + 10, maxm = 1e2 + 10;
int n, m, s, k, e, temp;
int pre[maxn], visited[maxn], d[maxn];
int p, a, b;
int contpass[maxm][maxn], dis[maxm][maxm], ban[maxn];
vector<Vertex> G[maxn];
std::priority_queue<Node> Q;

int main() {
	s = 1;
	scanf("%d %d %d %d", &n, &m, &k, &e);
	for (int i = 1; i <= e; i++) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		vertex.u = v, vertex.w = w;
		G[u].push_back(vertex);
		vertex.u = u;
		G[v].push_back(vertex);
	}
	scanf("%d", &temp);
	for (int i = 1; i <= temp; i++) {
		scanf("%d %d %d", &p, &a, &b);
		for (int j = a; j <= b; j++) {
			contpass[j][p] = 1;
		}
	}
	for (int i = 1; i <= n; i++) {
		memset(ban, 0, sizeof(visited));
		for (int j = i; j <= n; j++) {
			for (int k = i; k <= j; k++) {
				for (int h = 1; h <= m; h++) {
					if (contpass[k][h] == 1) {
						ban[h] = 1;
					}
				}
				Dijkstra();
				dis[i][j] = d[m];
			}
		}
	}

	return 0;
}
void InitialSingleSource() {
	memset(visited, 0, sizeof(visited));
	for (int i = 1; i <= n; i++) {
		d[i] = 0x7fffffff;
		pre[i] = 0;
	}
	d[s] = 0;
}
void Relax(int u, int v, int w) {
	if (d[v] > d[u] + w) {
		d[v] = d[u] + w;
		if (!visited[v]) {
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
		if (visited[Now.u]) {
			continue;
		}
		visited[Now.u] = 1;
		for (int i = 0; i < G[Now.u].size(); i++) {
			int v = G[Now.u][i].u, w = G[Now.u][i].w;
			if (ban[v] == 1) {
				continue;
			}
			Relax(Now.u, v, w);
		}
	}
}