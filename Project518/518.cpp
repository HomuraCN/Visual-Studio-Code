#include <stdio.h>
#include <vector>
using namespace std;

typedef struct Edge {
	int v;
	int w;
}EDGE;

void DFS(int u);

const int maxn = 110;
int N, Q, flag[maxn], dp[maxn][maxn];
vector<EDGE> G[maxn];

int main() {
	scanf("%d %d", &N, &Q);
	for (int i = 1; i <= N - 1; i++) {
		int u, v, w;
		EDGE temp;
		scanf("%d %d %d", &u, &v, &w);
		temp.v = v, temp.w = w;
		G[u].push_back(temp);
		temp.v = u;
		G[v].push_back(temp);
	}
	DFS(1);
	printf("%d", dp[1][Q]);

	return 0;
}
void DFS(int u) {
	flag[u] = 1;
	for (int i = 0; i < G[u].size(); i++) {
		int v = G[u][i].v;
		if (flag[v]) {
			continue;
		}
		DFS(v);
		for (int j = Q; j >= 0; j--) {
			for (int k = 0; k <= j - 1; k++) {	/*u到v算一条枝条*/
				dp[u][j] = max(dp[u][j], dp[u][j - k - 1] + dp[v][k] + G[u][i].w);
			}
		}
	}
}