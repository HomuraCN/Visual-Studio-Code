#include <stdio.h>
#include <vector>
using namespace std;

struct Edge {
	int v;
	int w;
}edge;

void DFS(int u);

const int maxn = 3e3 + 10;
int N, M, money[maxn], flag[maxn], dp[maxn][maxn], sum = 0;
vector<Edge> G[maxn];

int main() {
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N - M; i++) {
		int K;
		scanf("%d", &K);
		for (int i = 1; i <= K; i++) {
			scanf("%d %d", &edge.v, &edge.w);
			G[i].push_back(edge);
		}
	}
	for (int i = 1; i <= M; i++) {
		scanf("%d", &money[i]);
		sum += money[i];
	}
	DFS(1);
	for (int i = M; i >= 1; i--) {
		if (dp[1][i] >= 0) {
			printf("%d", i);
			break;
		}
	}

	return 0;
}
void DFS(int u) {
	flag[u] = 1;
	if (u > N - M) {
		dp[u][1] = money[u];
	}
	for (int i = 0; i < G[u].size(); i++) {	/*选u的某个儿子*/
		int v = G[u][i].w;
		if (flag[v]) {
			continue;
		}
		DFS(v);
		for (int j = M; j > 0; j--) {	/*选几个用户——背包容量*/
			for (int k = 1; k <= j; k++) {	/*当前组选几个*/
				dp[u][j] = max(dp[u][j], dp[u][j - k] + dp[v][k] - G[u][i].w);
			}
		}
	}
}