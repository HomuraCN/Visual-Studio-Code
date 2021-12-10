#include <stdio.h>
#include <string.h>

const int maxn = 110;
int n, sum = 0, a[maxn], dp[maxn][5005];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		sum += a[i];
	}
	memset(dp, 0, sizeof(dp));
	dp[0][0] = 1;/*一人到达那一人的分数*/
	for (int i = 1; i <= n; i++) {
		for (int j = i; j >= 1; j--) {
			for (int k = sum / 2; k >= a[i]; k--) {
				dp[j][k] = dp[j][k] || dp[j - 1][k - a[i]];
			}
		}
	}
	int ans;
	for (int i = 1; i <= sum / 2; i++) {
		if (dp[n / 2][i] == 1) {
			ans = i;
		}
	}
	printf("%d", ans);

	return 0;
}