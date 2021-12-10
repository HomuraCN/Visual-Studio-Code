#include <stdio.h>
#include <string.h>

int Max(int x, int y) {
	return x > y ? x : y;
}

const int maxn = 2010;
int n, a[maxn], dp[maxn][maxn];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			if (dp[i - 1][j - 1] + a[i] >= 0) {
				dp[i][j] = Max(dp[i - 1][j], dp[i - 1][j - 1] + a[i]);
			}
			else {
				dp[i][j] = dp[i - 1][j];
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		printf("%d ", dp[n][i]);
	}

	return 0;
}