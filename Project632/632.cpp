#include <stdio.h>

int t, a, b;

int main() {
	/*int ans = 0;
	for (int i = 1; i <= 100; i++) {
		ans ^= i;
		printf("^%d : %d\n", i, ans);
	}*/
	scanf("%d", &t);
	while (t--) {
		int flag = -1, xorsum;
		scanf("%d %d", &a, &b);
		flag = (a - 1) % 4;
		if (flag == 0) {
			xorsum = a - 1;
		}
		else if (flag == 1) {
			xorsum = 1;
		}
		else if (flag == 2) {
			xorsum = a;
		}
		else {
			xorsum = 0;
		}
		if (xorsum == b) {
			printf("%d\n", a);
		}
		else if (xorsum != b && (xorsum ^ b) != a) {
			printf("%d\n", a + 1);
		}
		else {
			printf("%d\n", a + 2);
		}
	}

	return 0;
}