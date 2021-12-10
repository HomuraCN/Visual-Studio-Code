#include <stdio.h>
#include <string.h>

const int maxn = 110;

int t, n, a[maxn], b[maxn];

int main() {
	scanf("%d", &t);
	while (t--) {
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
			b[i] = a[i] - a[i - 1];
		}
		if (a[1] != a[2] && a[1] != a[3]) {
			printf("1\n");
			continue;
		}
		b[1] = 0;
		for (int i = 1; i <= n; i++) {
			if (b[i] != 0) {
				printf("%d\n", i);
				break;
			}
		}
	}

	return 0;
}