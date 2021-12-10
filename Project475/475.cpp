#include <stdio.h>

const int maxn = 110;
int t, n, k, a[maxn];

int main() {
	scanf("%d", &t);
	while (t--) {
		int p = 1;
		scanf("%d %d", &n, &k);
		for (int i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
		}
		for (int i = 1; i <= k; i++) {
			if (p == n) {
				break;
			}
			a[n]++;
			while (a[p] <= 0) {
				p++;
			}
			a[p]--;
		}
		for (int i = 1; i <= n; i++) {
			printf("%d ", a[i]);
		}
		printf("\n");
	}

	return 0;
}