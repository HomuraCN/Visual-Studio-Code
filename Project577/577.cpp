#include <stdio.h>

const int maxn = 8e2 + 5, MOD = 1e9 + 7;
int n, m, k, G[maxn][maxn];
int dp[maxn][maxn][20][2];

int main() {
	scanf("%d %d %d", &n, &m, &k);
	k++;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%d", &G[i][j]);
			dp[i][j][G[i][j]][0] = 1;
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			for (int delta = 0; delta < k; delta++) {
				dp[i][j][delta][0] = (dp[i][j][delta][0] + dp[i - 1][j][(delta - G[i][j] + k) % k][1] + dp[i][j - 1][(delta - G[i][j] + k) % k][1]) % MOD;
				dp[i][j][delta][1] = (dp[i][j][delta][1] + dp[i - 1][j][(delta + G[i][j] + k) % k][0] + dp[i][j - 1][(delta + G[i][j] + k) % k][0]) % MOD;
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			ans = (ans + dp[i][j][0][1]) % MOD;
		}
	}
	printf("%d", ans);

	return 0;
}