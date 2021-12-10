#include <stdio.h>
#include <vector>
#include <string.h>
using namespace std;

void initialize();
int DFS(int u);

const int maxn = 2e5 + 10;
int t, n, k;
int xorsum, cnt, flag;
int a[maxn], visited[maxn];
vector<int> G[maxn];

int main() {
	scanf("%d", &t);
	while (t--) {
		initialize();
		scanf("%d %d", &n, &k);
		for (int i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
			xorsum ^= a[i];
		}
		for (int i = 1; i <= n - 1; i++) {
			int u, v;
			scanf("%d %d", &u, &v);
			G[u].push_back(v);
			G[v].push_back(u);
		}
		DFS(1);
		if (xorsum == 0 || (cnt >= 3 && k >= 3)) {
			printf("YES\n");
		}
		else {
			printf("NO\n");
		}
	}

	return 0;
}
void initialize() {
	memset(visited, 0, sizeof(visited));
	for (int i = 1; i <= n; i++) {
		G[i].clear();
	}
	xorsum = 0;
	cnt = 0;
	flag = 0;
}
int DFS(int u) {
	int xorsumtemp = a[u];
	visited[u] = 1;
	for (int i = 0; i < G[u].size(); i++) {
		int v = G[u][i];
		if (visited[v] == 1) {
			continue;
		}
		xorsumtemp ^= DFS(v);
	}
	if (xorsumtemp == xorsum) {
		cnt++;
		xorsumtemp = 0;
	}
	return xorsumtemp;
}