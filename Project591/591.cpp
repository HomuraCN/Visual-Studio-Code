#include <stdio.h>
#include <vector>
using namespace std;

void DFS(int u, int p);
int LCA(int x, int y);
int distance(int x, int y);
inline int read() {
	register int o = 0;
	register char c = getchar();
	while (c < '0' || c > '9') c = getchar();
	while (c >= '0' && c <= '9') o = (o << 3) + (o << 1) + (c & 15), c = getchar();
	return o;
}

const int maxn = 5e5 + 10;
int n, m;
int log_2[maxn], depth[maxn], fa[maxn][25];
bool visited[maxn];
vector<int> G[maxn];

int main() {
	n = read(), m = read();
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
		u = read(), v = read();
		G[u].push_back(v);
		G[v].push_back(u);
	}
	DFS(1, 0);
	for (int i = 1; i <= m; i++) {
		int a, b, c;
		a = read(), b = read(), c = read();
		int LCA1 = LCA(a, b), LCA2 = LCA(a, c), LCA3 = LCA(b, c);
		if (depth[LCA1] >= depth[LCA2] && depth[LCA1] >= depth[LCA3]) {
			int len1, len2, len3;
			len1 = distance(a, LCA1);
			len2 = distance(b, LCA1);
			len3 = distance(c, LCA1);
			printf("%d %d\n", LCA1, len1 + len2 + len3);
		}
		else if (depth[LCA2] >= depth[LCA1] && depth[LCA2] >= depth[LCA3]) {
			int len1, len2, len3;
			len1 = distance(a, LCA2);
			len2 = distance(b, LCA2);
			len3 = distance(c, LCA2);
			printf("%d %d\n", LCA2, len1 + len2 + len3);
		}
		else if (depth[LCA3] >= depth[LCA1] && depth[LCA3] >= depth[LCA2]) {
			int len1, len2, len3;
			len1 = distance(a, LCA3);
			len2 = distance(b, LCA3);
			len3 = distance(c, LCA3);
			printf("%d %d\n", LCA3, len1 + len2 + len3);
		}
	}

	return 0;
}
void DFS(int u, int p) {
	visited[u] = true;
	depth[u] = depth[p] + 1;
	fa[u][0] = p;
	for (int i = 1; i < 20; i++) {
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
	for (int i = 19; i >= 0; i--) {
		if (depth[fa[x][i]] >= depth[y]) x = fa[x][i];
	}
	if (x == y) {
		return x;
	}
	for (int i = 19; i >= 0; i--) {
		if (fa[x][i] != fa[y][i]) {
			x = fa[x][i], y = fa[y][i];
		}
	}
	return fa[x][0];
}
int distance(int x, int y) {
	return depth[x] + depth[y] - 2 * depth[LCA(x, y)];
}