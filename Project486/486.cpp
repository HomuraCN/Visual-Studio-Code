#include <stdio.h>

int Max(int x, int y) {
	return x > y ? x : y;
}

const int maxn = 1000010;
int n, a[maxn], dp[maxn];
char str[maxn];

int main() {
	scanf("%d", &n);
	scanf("%s", str + 1);
	for (int i = 1; i <= n; i++) {
		a[i] = str[i];
	}
	for (int i = 1; i <= n; i++) {
		dp[i] = 1;
		for (int j = 1; j < i; j++) {
			if (a[j] < a[i]) {
				dp[i] = Max(dp[i], dp[j] + 1);
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		ans = Max(ans, dp[i]);
	}
	printf("%d", n - ans);

	return 0;
}