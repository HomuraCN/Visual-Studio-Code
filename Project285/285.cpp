#include <stdio.h>
#include <vector>
using namespace std;

void Tarjan(int u, int parent);

const int maxn = 20010;
int n, m;
int num[maxn], low[maxn], timer, ans = 0, visited[maxn] = { 0 }, flag[maxn] = { 0 };
vector<int> G[maxn];

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		G[u].push_back(v);
		G[v].push_back(u);
	}

	for (int i = 1; i <= n; i++) {
		if (visited[i] == 0) {
			timer = 0;
			Tarjan(i, i);
		}
	}

	printf("%d\n", ans);
	for (int i = 1; i <= n; i++) {
		if (flag[i] == 1) {
			printf("%d ", i);
		}
	}

	return 0;
}
void Tarjan(int u, int parent) {
	int child = 0;
	visited[u] = 1;
	num[u] = low[u] = ++timer;
	for (int i = 0; i < G[u].size(); i++) {
		int v = G[u][i];
		if (visited[v] == 0) {/*子节点没有被访问*/
			child++;
			Tarjan(v, u);
			low[u] = min(low[u], low[v]);
			if (u != parent && flag[u] == 0 && low[v] >= num[u]) {
				flag[u] = 1;
				ans++;
			}
		}
		else if (v != parent) {
			low[u] = min(low[u], num[v]);
		}
	}
	if (child >= 2 && parent == u && flag[u] == 0) {
		flag[u] = 1;
		ans++;
	}
}