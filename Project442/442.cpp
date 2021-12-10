#include <stdio.h>
#include <string.h>

int Max(int x, int y);

const int maxn = 30010;
int N, m, v[30], w[30], dp[30][maxn];

int main() {
	scanf("%d %d", &N, &m);
	for (int i = 1; i <= m; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		v[i] = x * y;
		w[i] = x;
	}
	memset(dp, 0, sizeof(dp));
	for (int i = 1; i <= m; i++) {
		for (int j = N; j >= w[i]; j--) {
			dp[i][j] = Max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
		}
	}
	printf("%d", dp[m][N]);

	return 0;
}
int Max(int x, int y) {
	return x > y ? x : y;
}