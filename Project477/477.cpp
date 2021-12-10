#include <stdio.h>

int Max(int x, int y) {
	return x > y ? x : y;
}

const int maxn = 110, maxweight = 200010;
int n, a, W = 0, weight[maxn], value[maxn], dp[maxweight], position = 0;

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a);
		W += a;
		weight[i] = a;
		value[i] = a;
	}
	if (W % 2 == 1) {
		printf("0\n");
	}
	else {
		W /= 2;
		for (int i = 1; i <= n; i++) {
			for (int j = W; j >= weight[i]; j--) {
				dp[j] = Max(dp[j], dp[j - weight[i]] + value[i]);
			}
		}
		if (dp[W] == W) {
			while (1) {
				for (int i = 1; i <= n; i++) {
					if (value[i] % 2 == 1) {
						printf("1\n");
						printf("%d\n", i);
						return 0;
					}
				}
				for (int i = 1; i <= n; i++) {
					value[i] /= 2;
				}
			}
		}
		else {
			printf("0\n");
		}
	}

	return 0;
}