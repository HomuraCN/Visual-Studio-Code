#include <stdio.h>
#include <string.h>

const int maxn = 1100;
int n, dp[maxn], flag[maxn];

int main() {
	dp[0] = 1, dp[1] = 1;
	scanf("%d", &n);
	for (int i = 2; i <= n; i++) {
		memset(flag, 0, sizeof(flag));
		for (int k = 1; i - 2 * k >= 0; k++) {
			int temp = 2 * dp[i - k] - dp[i - 2 * k];
			flag[temp] = 1;
		}
		for (int j = 1; j <= 10 * n; j++) {
			if (flag[j] != 1) {
				dp[i] = j;
				break;
			}
		}
	}
	printf("%d", dp[n]);

	return 0;
}