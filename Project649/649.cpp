#include <stdio.h>
#define LL long long

int t;
LL n, x0;

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%lld %lld", &x0, &n);
		LL index = x0;
		/*
		for (int i = 1; i <= n; i++) {
			int now = index;
			if (index & 1) {
				index += i;
				printf("%d+%d=%lld\n", now, i, index);
			}
			else {
				index -= i;
				printf("%d-%d=%lld\n", now, i, index);
			}
		}
		printf("%lld\n", index);
		*/
		LL a, b, base;
		a = n / 4;
		b = n % 4;
		base = a * 4;
		if (!(index & 1)) {
			for (int i = 1; i <= b; i++) {
				if (i == 1) {
					index -= (base + 1);
				}
				else if (i == 2) {
					index += (base + 2);
				}
				else if (i == 3) {
					index += (base + 3);
				}
				else {
					index -= (base + 4);
				}
			}
			printf("%lld\n", index);
		}
		else {
			for (int i = 1; i <= b; i++) {
				if (i == 1) {
					index += (base + 1);
				}
				else if (i == 2) {
					index -= (base + 2);
				}
				else if (i == 3) {
					index -= (base + 3);
				}
				else {
					index += (base + 4);
				}
			}
			printf("%lld\n", index);
		}
	}

	return 0;
}