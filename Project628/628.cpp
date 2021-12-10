#include <stdio.h>

const int maxn = 1e6 + 10;
int t, n, flag1, flag2, flag3, flag4, ansl, ansr;

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		/*for (int i = 1; i <= n; i++) {
			flag1 = i;
			if (3 * (2 * flag1 - 1) + 1 > n) {
				break;
			}
		}*/
		flag1 = (n+2) / 6 + 1;
		if (n & 1) {
			flag2 = (n / 2) + 1;
			ansl = flag2 - flag1 + 1;
		}
		else {
			flag2 = n / 2;
			ansl = flag2 - flag1 + 1;
		}
		if (n & 1) {
			flag3 = n;
			flag4 = (n + 1) / 2;
			ansr = flag3 - flag4 + 1;
		}
		else {
			flag3 = n;
			flag4 = (n + 2) / 2;
			ansr = flag3 - flag4 + 1;
		}
		printf("%d\n", ansl + ansr);
	}

	return 0;
}