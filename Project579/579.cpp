#include <stdio.h>
#include <string.h>
#include <math.h>

int Min(int x, int y) {
	return x < y ? x : y;
}
int Max(int x, int y) {
	return x > y ? x : y;
}

const int maxn = 52;
int n, c, pos[maxn], power[maxn], power_sum[maxn];
int dp[maxn][maxn][2];

int main() {
	scanf("%d %d", &n, &c);
	for (int i = 1; i <= n; i++) {
		scanf("%d %d", &pos[i], &power[i]);
		power_sum[i] = power_sum[i - 1] + power[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			dp[i][j][0] = dp[i][j][1] = 0x3f3f3f3f;
		}
	}
	dp[c][c][0] = dp[c][c][1] = 0;
	for (int j = c; j <= n; j++) {
		for (int i = j - 1; i >= 1; i--) {
			dp[i][j][0] = Min( dp[i + 1][j][0] + abs(pos[i] - pos[i + 1]) * (power_sum[i] + (power_sum[n] - power_sum[j]) ), 
									    dp[i + 1][j][1] + abs(pos[i] - pos[j]) * (power_sum[i] + (power_sum[n] - power_sum[j]) ) );
			dp[i][j][1] = Min( dp[i][j - 1][1] + abs(pos[j] - pos[j - 1]) * (power_sum[i - 1] + (power_sum[n] - power_sum[j - 1]) ), 
									    dp[i][j - 1][0] + abs(pos[j] - pos[i]) * (power_sum[i - 1] + (power_sum[n] - power_sum[j - 1]) ) );
		}
	}
	printf("%d", Min(dp[1][n][0], dp[1][n][1]));

	return 0;
}