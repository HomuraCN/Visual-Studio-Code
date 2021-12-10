#include <stdio.h>
#include <string.h>

int t, a[2010], flag[2010];

int main() {
	scanf("%d", &t);
	while (t--) {
		int n;
		memset(a, 0, sizeof(a));
		memset(flag, 0, sizeof(flag));
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
			if (a[i] & 1) {
				flag[i] = 1;
				printf("%d ", a[i]);
			}
		}
		for (int j = 1; j <= n; j++) {
			if (flag[j] == 0) {
				printf("%d ", a[j]);
			}
			else {
				continue;
			}
		}
		printf("\n");
	}

	return 0;
}