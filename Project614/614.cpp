#include <stdio.h>

const int maxn = 1e3;
int t, n, a[maxn];

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
		}
		int flag = 1;
		for (int i = 1; i <= n - 1; i++) {
			if (a[i] > a[i + 1]) {
				flag = 0;
			}
		}
		if (flag == 1) {
			printf("0\n");
			continue;
		}
		for (int i = 1; i <= 1e9; i++) {
			if (i % 2 == 1) {
				for (int j = 1; j <= n - 2; j++) {
					if (j % 2 == 1 && a[j] > a[j + 1]) {
						int temp;
						temp = a[j], a[j] = a[j + 1], a[j + 1] = temp;
					}
				}
			}
			else {
				for (int j = 2; j <= n - 1; j++) {
					if (j % 2 == 0 && a[j] > a[j + 1]) {
						int temp;
						temp = a[j], a[j] = a[j + 1], a[j + 1] = temp;
					}
				}
			}
			int flag = 1;
			for (int i = 1; i <= n - 1; i++) {
				if (a[i] > a[i + 1]) {
					flag = 0;
				}
			}
			if (flag == 1) {
				printf("%d\n", i);
				break;
			}
		}
	}

	return 0;
}