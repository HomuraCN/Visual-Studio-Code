#include <stdio.h>
#include <vector>
using namespace std;

void init();
int DFS1(int u);
void DFS2(int u);

const int maxn = 1e5 + 10;
int t, n, a[maxn];
int visited[maxn];
int subtree_max_weight[maxn];
int start, minn, cnt;
vector<int> G[maxn];

int main() {
	scanf("%d", &t);
	while (t--) {
		init();
		scanf("%d", &n);
		for (int i = 1; i <= n - 1; i++) {
			int u, v;
			scanf("%d %d", &u, &v);
			G[u].push_back(v);
			G[v].push_back(u);
		}
		for (int i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
			if (minn > a[i]) {
				minn = a[i];
				start = i;
			}
		}
		DFS1(start);
		memset(visited, 0, sizeof(visited));
		DFS2(start);
		printf("%d\n", cnt);
	}

	return 0;
}
void init() {
	cnt = 0;
	minn = 0x7fffffff;
	start = -1;
	memset(visited, 0, sizeof(visited));
	for (int i = 1; i <= n; i++) {
		G[i].clear();
	}
}
int DFS1(int u) { /*Ô¤´¦Àísubtree_max_weight*/
	int maxx = a[u];
	visited[u] = 1;
	for (int i = 0; i < G[u].size(); i++) {
		int v = G[u][i];
		if (visited[v] == 1) {
			continue;
		}
		int temp = DFS1(v);
		if (maxx < temp) {
			maxx = temp;
		}
	}
	subtree_max_weight[u] = maxx;
	return subtree_max_weight[u];
}
void DFS2(int u) {
	visited[u] = 1;
	int max_min = -1, max_min_flag = -1;
	if (!G[u].empty()) {
		if (visited[G[u][0]] == 0 && max_min < subtree_max_weight[G[u][0]]) {
			max_min = subtree_max_weight[G[u][0]];
			max_min_flag = G[u][0];
		}
	}
	for (int i = 1; i < G[u].size(); i++) {
		int v = G[u][i];
		if (visited[v] == 1) {
			continue;
		}
		if (max_min > subtree_max_weight[v]) {
			max_min = subtree_max_weight[v];
			max_min_flag = v;
		}
	}
	if (max_min_flag != -1) {
		cnt++;
		DFS2(max_min_flag);
	}
	if (max_min != -1) {
		subtree_max_weight[u] = max_min;
	}
}