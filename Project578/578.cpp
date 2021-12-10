#include <stdio.h>
#include <vector>
using namespace std;

void DFS(int u);

const int maxn = 1e3 + 10;
int n, dp[maxn][5];
bool visited[maxn];
vector<int> G[maxn];

int main() {
	scanf("%d", &n);
	for (int i = 2; i <= n; i++) {
		int v;
		scanf("%d", &v);
		G[i].push_back(v);
		G[v].push_back(i);
	}
	DFS(1);
	printf("%d", dp[1][2]);

	return 0;
}
void DFS(int u) {
	visited[u] = 1;
	dp[u][0] = 1;
	dp[u][3] = 0;
	dp[u][4] = 0;
	int cnt = 0;
	for (int i = 0; i < G[u].size(); i++) {
		int v = G[u][i];
		if (visited[v] == 1) {
			continue;
		}
		visited[v] = 1;
		DFS(u);
		visited[v] = 0;
		dp[u][0] += dp[v][4];
		dp[u][3] += dp[v][2];
		dp[u][4] += dp[v][3];
		cnt++;
	}
	if (cnt == 0) {
		dp[u][1] = dp[u][2] = 1;
	}
	else {
		dp[u][1] = dp[u][2] = 0x7ffffff;
		for (int i = 0; i < G[u].size(); i++) {
			int v1 = G[u][i];
			if (visited[v1] == 1) {
				continue;
			}
			int DP0 = dp[v1][0], DP1 = dp[v1][1];
			for (int j = 0; j < G[u].size(); j++) {
				int v2 = G[u][j];
				if (visited[v2] == 1) {
					continue;
				}
				DP0 += dp[v2][3];
				DP1 += dp[v2][2];
			}
			dp[u][1] = min(dp[u][1], DP0);
			dp[u][2] = min(dp[u][2], DP1);
		}
	}
	for (int i = 1; i <= 4; i++) {
		dp[u][i] = min(dp[u][i - 1], dp[u][i]);
	}
}