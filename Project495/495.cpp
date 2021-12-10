#include <stdio.h>

int Max(int x, int y) {
	return x > y ? x : y;
}

const int maxn = 55;
int n, m, k, map[maxn][maxn], ans[maxn][maxn];

int main() {
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	printf("%d %d\n", n - k + 1, m - k + 1);
	for (int i = 1; i <= n - k + 1; i++) {
		for (int j = 1; j <= m - k + 1; j++) {
			int maxx = 0;
			for (int h = i; h <= i + k - 1; h++) {
				for (int g = j; g <= j + k - 1; g++) {
					maxx = Max(maxx, map[h][g]);
				}
			}
			printf("%d ", maxx);
		}
		printf("\n");
	}

	return 0;
}