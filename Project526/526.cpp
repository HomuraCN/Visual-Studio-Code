#include <stdio.h>
#include <string.h>
#define LL long long

LL Min(int x, int y) {
	return x < y ? x : y;
}

const int maxn = 55;
int n, m;
LL G[maxn][maxn];
bool dp[maxn][maxn][maxn];

int main() {
	scanf("%d %d", &n, &m);
	memset(dp, false, sizeof(dp));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			G[i][j] = 0x3f3f3f3f;
		}
	}
	for (int i = 1; i <= m; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		G[u][v] = 1;
		dp[u][v][0] = true;
	}
	for (int h = 1; h <= maxn; h++) {
		for (int k = 1; k <= n; k++) {
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= n; j++) {
					if (dp[i][k][h - 1] == true && dp[k][j][h - 1] == true) {
						dp[i][j][h] = true;
						G[i][j] = 1;
					}
				}
			}
		}
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				G[i][j] = Min(G[i][j], G[i][k] + G[k][i]);
			}
		}
	}
	printf("%lld", G[1][n]);

	return 0;
}