#include <stdio.h>
#include <vector>
using namespace std;

const int maxn = 10010;
int c, n, m, d[maxn] = { 0 };
vector<int> G[maxn];

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	DFS(1, 0);/*定理：在一个连通无向无环图中，以任意结点出发所能到达的最远结点，一定是该图直径的端点之一。*/
	d[c] = 0;
	DFS(c, 0);/*从一个直径到另一个直径即为树的直径。*/
	printf("%d", d[c]);

	return 0;
}
void DFS(int u, int from) {/*局限性：树的边权必须为非负数。*/
	for (int i = 0; i < G[u].size(); i++) {
		int v = G[u][i];
		if (v == from) {
			continue;
		}
		d[v] = d[u] + 1;
		if (d[v] > d[c]) {
			c = v;
		}
		DFS(v, u);
	}
}