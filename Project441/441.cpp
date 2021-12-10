#include <stdio.h>

int Max(int x, int y);

const int maxn = 100010;
int N, ans = -0x7fffffff, p[maxn], dp[maxn];

int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &p[i]);
		dp[i] = p[i];
	}
	for (int i = 2; i <= N; i++) {
		dp[i] = Max(dp[i], dp[i - 1] + p[i]);
		ans = Max(dp[i], ans);
	}
	printf("%d", ans);

	return 0;
}
int Max(int x, int y) {
	return x > y ? x : y;
}