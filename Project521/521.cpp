#include <stdio.h>

void Turn();
void Mirror();

const int maxn = 1010;
int n, q, map[maxn][maxn], cnt1 = 0, cnt2 = 0;

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	scanf("%d", &q);
	while (q--) {
		int op;
		scanf("%d", &op);
		if (op == 1) {
			cnt1++;
		}
		else {
			cnt2++;
		}
	}
	if (cnt1 % 2 == 1) {
		Turn();
	}
	if (cnt2 % 2 == 1) {
		Mirror();
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			printf("%d ", map[i][j]);
		}
		printf("\n");
	}

	return 0;
}
void Turn() {
	if (n % 2 == 0) {
		for (int i = 1; i <= n / 2; i++) {
			for (int j = 1; j <= n; j++) {
				map[i][j] ^= map[n - i + 1][n - j + 1];
				map[n - i + 1][n - j + 1] ^= map[i][j];
				map[i][j] ^= map[n - i + 1][n - j + 1];
			}
		}
	}
	else {
		for (int i = 1; i <= n / 2; i++) {
			for (int j = 1; j <= n; j++) {
				map[i][j] ^= map[n - i + 1][n - j + 1];
				map[n - i + 1][n - j + 1] ^= map[i][j];
				map[i][j] ^= map[n - i + 1][n - j + 1];
			}
		}
		for (int j = 1; j <= n / 2; j++) {
			map[n / 2 + 1][j] ^= map[n / 2 + 1][n - j + 1];
			map[n / 2 + 1][n - j + 1] ^= map[n / 2 + 1][j];
			map[n / 2 + 1][j] ^= map[n / 2 + 1][n - j + 1];
		}
	}
}
void Mirror() {
	for (int i = 1; i <= n / 2; i++) {
		for (int j = 1; j <= n; j++) {
			map[i][j] ^= map[n - i + 1][j];
			map[n - i + 1][j] ^= map[i][j];
			map[i][j] ^= map[n - i + 1][j];
		}
	}
}