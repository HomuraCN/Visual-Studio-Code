#include <stdio.h>

const int maxn = 1e2 + 10;
int t, n;

int main() {
	scanf("%d", &t);
	while (t--) {
		int temp;
		scanf("%d", &n);
		scanf("%d", &temp);
		int ans = temp;
		for (int i = 2; i <= n; i++) {
			scanf("%d", &temp);
			ans &= temp;
		}
		printf("%d\n", ans);
	}

	return 0;
}