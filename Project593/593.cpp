#include <stdio.h>
#include <vector>
using namespace std;

typedef struct Vertex {
	int u;
	int w;
};

void InitialSingleSource();
void Relax(int u, int v, int w);
int BellmanFord();

const int maxn = 5e3 + 10;
int n, m, s, d[100010], pre[100010];
vector<Vertex> G[100010];
Vertex vertex;

int main() {
	s = 0;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; i++) {
		int op, a, b, c;
		scanf("%d", &op);
		if (op == 1) {
			scanf("%d %d %d", &a, &b, &c);
			vertex.u = b, vertex.w = -c;
			G[a].push_back(vertex);
		}
		else if (op == 2) {
			scanf("%d %d %d", &a, &b, &c);
			vertex.u = a, vertex.w = c;
			G[b].push_back(vertex);
		}
		else {
			scanf("%d %d", &a, &b);
			vertex.u = b, vertex.w = 0;
			G[a].push_back(vertex);
			vertex.u = a, vertex.w = 0;
			G[b].push_back(vertex);
		}
	}
	for (int i = 1; i <= n; i++) {
		vertex.u = i, vertex.w = 0;
		G[0].push_back(vertex);
	}
	if (BellmanFord() == 1) {
		printf("Yes\n");
	}
	else {
		printf("No\n");
	}

	return 0;
}
void InitialSingleSource() {
	for (int i = 1; i <= n; i++) {
		d[i] = 0x7fffffff;
		pre[i] = 0;
	}
	d[s] = 0;
}
void Relax(int u, int v, int w) {
	if (d[v] > d[u] + w) {
		d[v] = d[u] + w;
		pre[v] = u;
	}
}
int BellmanFord() {
	InitialSingleSource();
	for (int i = 0; i <= n - 1; i++) {
		for (int j = 0; j <= n; j++) {
			for (int k = 0; k < G[j].size(); k++) {
				Relax(j, G[j][k].u, G[j][k].w);
			}
		}
	}
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j < G[i].size(); j++) {
			if (d[G[i][j].u] > d[i] + G[i][j].w) {
				return 0;
			}
		}
	}
	return 1;
}