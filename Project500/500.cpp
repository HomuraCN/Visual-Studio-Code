#include <stdio.h>

const int maxn = 1000010;
int n, dp[maxn];

int main() {
	scanf("%d", &n);
	dp[3] = 0, dp[4] = 1;
	for (int i = 5; i <= n; i++) {
		if (i % 2 == 0) {
			dp[i] = dp[i / 2] + 2;
		}
		else {
			dp[i] = dp[(i + 1) / 2] + 2;
		}
	}
	printf("%d", dp[n]);

	return 0;
}