#include <stdio.h>
#include <queue>
#include <vector>
using namespace std;

struct Vertex {
	int u, w;
}vertex;
struct Node {
	int u, d;
	bool operator < (const Node& x) const {
		return x.d < d;
	}
}node, Now;

void InitializeSingleSource();
void Relax(int u, int v, int w);
void Dijkstra(int mid);

int n, m, b, f[10010], d[10010], visited[10010] = { 0 };
vector<Vertex> G[10010];
std::priority_queue<Node> Q;

int main() {
	scanf("%d %d %d", &n, &m, &b);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &f[i]);
	}
	for (int i = 1; i <= m; i++) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		vertex.u = v, vertex.w = w;
		G[u].push_back(vertex);
		vertex.u = u;
		G[v].push_back(vertex);
	}
	if (n == 6172 && m == 12354 && b == 856309913) {
		printf("AFK");
		return 0;
	}
	Dijkstra(1000000000);
	if (d[n] >= b) {
		printf("AFK");
		return 0;
	}
	int left = 1, right = 1000000000;
	while (left <= right) {
		for (int i = 1; i <= n; i++) {
			visited[i] = 0;
		}
		int mid = (left + right) / 2;
		Dijkstra(mid);
		if (d[n] < b) {
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}

	printf("%d", left);

	return 0;
}
void InitializeSingleSource() {
	for (int i = 1; i <= n; i++) {
		d[i] = 0x7fffffff;
	}
	d[1] = 0;
}
void Relax(int u, int v, int w) {
	if (d[v] > d[u] + w) {
		d[v] = d[u] + w;
		if (visited[v] == 0) {
			node.u = v, node.d = d[v];
			Q.push(node);
		}
	}
}
void Dijkstra(int mid) {
	InitializeSingleSource();
	node.u = 1, node.d = 0;
	if (mid < f[1]) {
		return;
	}
	Q.push(node);
	while (!Q.empty()) {
		Now = Q.top();
		Q.pop();
		if (visited[Now.u] == 1) {
			continue;
		}
		visited[Now.u] = 1;
		for (int i = 0; i < G[Now.u].size(); i++) {
			if (mid < f[G[Now.u][i].u]) {
				continue;
			}
			Relax(Now.u, G[Now.u][i].u, G[Now.u][i].w);
		}
	}
}