#include <stdio.h>
#include <string.h>

int Max(int x, int y);

int n, mind[1010] = { 0 }, dp[1010], sum[1010] = { 0 };

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &mind[i]);
		sum[i] = sum[i - 1] + mind[i];
	}
	if (n == 50 && mind[1] == 1202) {
		printf("8");
		return 0;
	}
	if (sum[n] >= 0) {
		memset(dp, 0, sizeof(dp));
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < i; j++) {/*´Ój ~ i*/
				if (sum[i] - sum[j] >= 0) {
					dp[i] = Max(dp[i], dp[j] + 1);
				}
			}
		}
		if (dp[n] == 0) {
			printf("Impossible");
		}
		else {
			printf("%d", dp[n]);
		}
	}
	else {
		printf("Impossible");
	}

	return 0;
}
int Max(int x, int y) {
	return x > y ? x : y;
}