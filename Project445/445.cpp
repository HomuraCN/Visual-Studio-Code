#include <stdio.h>
#include <string.h>

int Max(int x, int y);

int capicityWKY, capicityLW, m, n, T, value[5010], weight[5010], time[5010], dp[5010];

int main() {
	scanf("%d %d", &capicityWKY, &capicityLW);
	scanf("%d %d", &m, &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &time[i]);
	}
	for (int i = 1; i <= m; i++) {
		int num;
		scanf("%d %d", &num, &value[i]);
		weight[i] = (time[num] * capicityLW) / capicityWKY;
	}
	scanf("%d", &T);
	memset(dp, 0, sizeof(dp));
	for (int i = 1; i <= m; i++) {
		for (int j = T; j >= weight[i]; j--) {
			dp[j] = Max(dp[j], dp[j - weight[i]] + value[i]);
		}
	}
	printf("%d", dp[T]);

	return 0;
}
int Max(int x, int y) {
	return x > y ? x : y;
}