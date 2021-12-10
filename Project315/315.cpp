#include <stdio.h>

int Min(int x, int y);

int main() {
	int T;
	scanf("%d", &T);
	for (int f = 1; f <= T; f++) {
		int n, a, b;
		double price2, price3;
		scanf("%d %d %d", &n, &a, &b);
		price2 = a / 2, price3 = b / 3;

		if (n <= 2) {
			printf("%d\n", Min(a, b));
			continue;
		}
		if (n == 3) {
			printf("%d\n", Min(Min(b, a * 2), a + b));
			continue;
		}

		if (price3 < price2) {
			if (n % 3 == 0) {
				printf("%d\n", b * (n / 3));
			}
			else if (n % 3 == 1) {
				int temp1 = (n / 3) * b + a, temp2 = ((n / 3) - 1) * b + a * 2;
				printf("%d\n", Min(temp1, temp2));
			}
			else if (n % 3 == 2) {
				printf("%d\n", (n / 3) * b + a);
			}
		}
		else if (price3 < price2) {
			if (n % 2 == 0) {
				printf("%d\n", a * (n / 2));
			}
			else if (n % 2 == 1) {
				int temp1 = (n / 2) * a + a, temp2 = ((n / 2) - 1) * a + b;
				printf("%d\n", Min(temp1, temp2));
			}
		}
	}

	return 0;
}
int Min(int x, int y) {
	return x <= y ? x : y;
}