#include <stdio.h>

const int maxn = 1000010;
int n, k, ans[maxn];

int main() {
	scanf("%d %d", &n, &k);
	if (k == 0) {
		printf("-1");
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		ans[i] = i;
	}
	for (int i = 1; i <= k - 1; i++) {
		ans[i]++;
	}
	ans[k] = 1;
	for (int i = 1; i <= n - 1; i++) {
		printf("%d ", ans[i]);
	}
	printf("%d", ans[n]);

	return 0;
}