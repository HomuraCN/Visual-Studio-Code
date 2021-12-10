#include <stdio.h>

int t, a, b, c;

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d %d", &a, &b, &c);
		if (a > b) {
			int temp;
			temp = a, a = b, b = temp;
		}
		int delta = b - a;
		if (a > 2 * delta || b > 2 * delta || c > 2 * delta) {
			printf("-1\n");
			continue;
		}
		if (c <= delta) {
			printf("%d\n", c + delta);
		}
		else {
			printf("%d\n", c - delta);
		}
	}

	return 0;
}