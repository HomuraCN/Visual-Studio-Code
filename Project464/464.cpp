#include <stdio.h>
#include <string.h>

int Min(int x, int y) {
	return x < y ? x : y;
}
int Max(int x, int y) {
	return x > y ? x : y;
}

const int maxn = 210;

int ans, N, a[maxn], dp[maxn][maxn], sum[maxn];

int main() {
	scanf("%d", &N);
	memset(dp, 0, sizeof(dp));
	memset(sum, 0, sizeof(sum));
	for (int i = 1; i <= N; i++) {
		scanf("%d", &a[i]);
		a[i + N] = a[i];
	}
	for (int i = 1; i <= 2 * N; ++i) { 
		sum[i] = sum[i - 1] + a[i];
	}
	for (int len = 2; len <= N; len++) {
		for (int i = 1; i <= 2 * N - 1; i++) {
			int j = len + i - 1;
			dp[i][j] = 0x7fffffff;
			for (int k = i; k < j && k <= 2 * N - 1; k++) {
				dp[i][j] = Min(dp[i][j], dp[i][k] + dp[k + 1][j] + (sum[j] - sum[i - 1]));
			}
		}
	}
	ans = 0x7fffffff;
	for (int i = 1; i <= N; i++) {
		ans = Min(ans, dp[i][N + i - 1]);
	}
	printf("%d\n", ans);
	memset(dp, 0, sizeof(dp));
	for (int len = 1; len <= N; len++) {
		for (int i = 1; i <= 2 * N - 1; i++) {
			int j = len + i - 1;
			for (int k = i; k < j && k <= 2 * N - 1; k++) {
				dp[i][j] = Max(dp[i][j], dp[i][k] + dp[k + 1][j] + (sum[j] - sum[i - 1]));
			}
		}
	}
	ans = 0;
	for (int i = 1; i <= N; i++) {
		ans = Max(ans, dp[i][N + i - 1]);
	}
	printf("%d\n", ans);

	return 0;
}