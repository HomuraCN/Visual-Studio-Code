#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;

void DFS(int u);

const int maxn = 6010;
int n, happydegree[maxn], dp[maxn][2], flag[maxn], indegree[maxn];
vector<int> G[maxn];

int main() {
	memset(flag, 0, sizeof(flag));
	memset(dp, 0, sizeof(dp));
	memset(indegree, 0, sizeof(indegree));
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &happydegree[i]);
		dp[i][1] = happydegree[i];
	}
	for (int i = 1; i <= n - 1; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		G[v].push_back(u);
		indegree[u]++;
	}
	int start;
	for (start = 1; start <= n; start++) {
		if (indegree[start] == 0) {
			break;
		}
	}
	DFS(start);
	printf("%d", max(dp[start][0], dp[start][1]));

	return 0;
}
void DFS(int u) {
	flag[u] = 1;
	for (int i = 0; i < G[u].size(); i++) {
		int v = G[u][i];
		if (flag[v]) {
			continue;
		}
		DFS(v);
		dp[u][1] += max(dp[v][0], dp[v][1]);
		dp[u][0] += max(dp[v][0], dp[v][1]);
	}
}