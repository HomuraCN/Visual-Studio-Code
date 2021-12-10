#include <stdio.h>
#include <string.h>

int Min(int x, int y);

const int maxm = 2010, maxn = 2010;
int N, M, day[maxm][maxn], dp[maxm][maxn] = { 0 };

int main() {
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= M; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%d", &day[i][j]);
		}
	}
	memset(dp, 0, sizeof(dp));
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (j == 1) {
				dp[i][j] = Min(dp[i - 1][j], dp[i - 1][M]) + day[j][i];
			}
			else {
				dp[i][j] = Min(dp[i - 1][j], dp[i - 1][j - 1]) + day[j][i];
			}
		}
	}
	int ans = 0x7fffffff;
	for (int i = 1; i <= M; i++) {
		ans = Min(ans, dp[N][i]);
	}
	printf("%d", ans);

	return 0;
}
int Min(int x, int y) {
	return x < y ? x : y;
}