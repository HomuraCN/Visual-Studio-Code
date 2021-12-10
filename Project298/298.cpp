#include <stdio.h>

int t, n, a[200010], flag[200010] = { 0 };

int main() {
	scanf("%d", &t);
	for (int f = 1; f <= t; f++) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
		}
		for (int i = 1; i <= n; i++) {
			if (a[i] == 0) {
				continue;
			}
			else {
				if (i >= a[i]) {
					for (int j = i - a[i] + 1; j <= i; j++) {
						flag[j] = 1;
					}
				}
				else {
					for (int j = 1; j <= i; j++) {
						flag[j] = 1;
					}
				}
			}
		}
		for (int i = 1; i <= n; i++) {
			if (flag[i]) {
				printf("1 ");
				flag[i] = 0;
			}
			else {
				printf("0 ");
			}
		}
		printf("\n");
	}

	return 0;
}