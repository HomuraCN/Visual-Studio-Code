#include <stdio.h>
#include <vector>
using namespace std;

void DFS(int u, int p);
int LCA(int x, int y);

const int maxn = 5e5 + 10;
int n, m, s;
int log_2[maxn], depth[maxn], fa[maxn][25];
bool visited[maxn];
vector<int> G[maxn];

int main() {
	scanf("%d %d %d", &n, &m, &s);
	for (int i = 1; i <= 1900; ++i) {
		log_2[i] = log_2[i - 1] + (1 << log_2[i - 1] == i);
	}
	for (int i = 1; i <= 1900; i++) {
		log_2[i]--;
	}
	/*for (int i = 1; i <= 1900; ++i) {
		printf("%d\n", log_2[i]);
	}*/
	for (int i = 1; i <= n - 1; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	DFS(s, 0);
	for (int i = 1; i <= m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		printf("%d\n", LCA(a, b));
	}

	return 0;
}
void DFS(int u, int p) {
	visited[u] = true;
	depth[u] = depth[p] + 1;
	fa[u][0] = p;
	for (int i = 1; i <= log_2[depth[u]] + 1; i++) {
		fa[u][i] = fa[fa[u][i - 1]][i - 1];
	}
	for (int i = 0; i < G[u].size(); i++) {
		int v = G[u][i];
		if (visited[v] == true) {
			continue;
		}
		DFS(v, u);
	}
}
int LCA(int x, int y) {
	if (depth[x] < depth[y]) {
		int temp;
		temp = x, x = y, y = temp;
	}
	while (depth[x] > depth[y]) {
		x = fa[x][log_2[depth[x] - depth[y]]];
	}
	if (x == y) {
		return x;
	}
	for (int i = log_2[depth[x]]; i >= 0; i--) {
		if (fa[x][i] != fa[y][i]) {
			x = fa[x][i], y = fa[y][i];
		}
	}
	return fa[x][0];
}