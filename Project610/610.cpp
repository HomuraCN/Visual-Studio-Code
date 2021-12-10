#include <stdio.h>

const int maxn = 1e4 + 10;
int t, n, a[maxn];

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
		}
		if (a[n] == 0) {
			for (int i = 1; i <= n + 1; i++) {
				printf("%d ", i);
			}
			printf("\n");
			continue;
		}
		else if (a[1] != 0) {
			printf("%d ", n + 1);
			for (int i = 1; i <= n; i++) {
				printf("%d ", i);
			}
			printf("\n");
			continue;
		}
		else {
			int p = -1;
			for (int i = 1; i <= n; i++) {
				if (a[i] == 0 && a[i + 1] != 0) {
					p = i;
					break;
				}
			}
			if (p == -1) {
				printf("-1\n");
				continue;
			}
			else {
				for (int i = 1; i <= p; i++) {
					printf("%d ", i);
				}
				printf("%d ", n + 1);
				for (int i = p + 1; i <= n; i++) {
					printf("%d ", i);
				}
				printf("\n");
				continue;
			}
		}
	}

	return 0;
}