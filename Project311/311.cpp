#include <stdio.h>
#include <vector>
using namespace std;

int n, m, ans = 0, dist1[maxn] = { 0 }, dist2[maxn] = { 0 };
const int maxn = 100010;
vector<int> G[maxn];

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	DFS(1, 0);
	printf("%d", ans);

	return 0;
}
void DFS(int u, int from) {
	dist1[u] = 0, dist2[u] = 0;
	for (int i = 0; i < G[u].size(); i++) {
		int v = G[u][i];
		if (v == from) {
			continue;
		}
		int temp = dist1[v] + 1;
		if (temp > dist1[u]) {/*树的边权可以为实整数*/
			dist2[u] = dist1[u];
			dist1[u] = temp;
		}
		else if (temp > dist2[u]) {
			dist2[u] = temp;
		}
	}
	ans = Max(ans, dist1[u] + dist2[u]);
}
int Max(int x, int y) {
	return x >= y ? x : y;
}