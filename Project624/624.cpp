#include <stdio.h>

const int maxn = 1e2 + 10, maxk = 1e1 + 10, MOD = 1e8;
int n1, n2, k1, k2;
int dp[maxn][maxn][maxk][2];

int main() {
	scanf("%d %d %d %d", &n1, &n2, &k1, &k2);
	dp[0][1][1][1] = 1, dp[1][0][1][0] = 1;
	/*for (int i = 1; i <= n1; i++) {
		for (int j = 1; j <= n2; j++) {
			for (int k = 1; k <= k1; k++) {
				dp[i][j][k][0] = dp[i - 1][j][k - 1][0];
				dp[i][j][1][1] = (dp[i][j][1][1] + dp[i][j - 1][k][0]) % MOD;
			}
			for (int k = 1; k <= k2; k++) {
				dp[i][j][k][0] = dp[i][j - 1][k - 1][1];
				dp[i][j][1][0] = (dp[i][j][1][0] + dp[i - 1][j][k][1]) % MOD;
			}
		}
	}*/
	for (int i = 0; i <= n1; i++) {
		for (int j = 0; j <= n2; j++) {
			if (i - 1 >= 0) {
				for (int k = 2; k <= k1; k++) {
					dp[i][j][k][0] = dp[i - 1][j][k - 1][0];
				}
				for (int k = 1; k <= k2; k++) {
					dp[i][j][1][0] = (dp[i][j][1][0] + dp[i - 1][j][k][1]) % MOD;
				}
			}
			if (j - 1 >= 0) {
				for (int k = 2; k <= k2; k++) {
					dp[i][j][k][1] = dp[i][j - 1][k - 1][1];
				}
				for (int k = 1; k <= k1; k++) {
					dp[i][j][1][1] = (dp[i][j][1][1] + dp[i][j - 1][k][0]) % MOD;
				}
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= k1; i++) {
		ans = (ans + dp[n1][n2][i][0]) % MOD;
	}
	for (int i = 1; i <= k2; i++) {
		ans = (ans + dp[n1][n2][i][1]) % MOD;
	}
	printf("%d\n", ans);

	return 0;
}