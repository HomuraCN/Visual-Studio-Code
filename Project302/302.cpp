#include <stdio.h>

int Size(int x1, int y1, int x2, int y2);
int Max(int x, int y);

const int maxn = 130;
int n, map[maxn][maxn], sum[maxn][maxn] = { 0 }, max = 0;

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + map[i][j];
		}
	}
	for (int x1 = 1; x1 <= n; x1++) {
		for (int y1 = 1; y1 <= n; y1++) {
			for (int x2 = 1; x2 <= n; x2++) {
				for (int y2 = 1; y2 <= n; y2++) {
					if (x1 <= x2 && y1 <= y2) {
						max = Max(max, Size(x1, y1, x2, y2));
					}
				}
			}
		}
	}
	printf("%d", max);

	return 0;
}
int Size(int x1, int y1, int x2, int y2) {
	return sum[x2][y2] - sum[x1 - 1][y2] - sum[x2][y1 - 1] + sum[x1 - 1][y1 - 1];
}
int Max(int x, int y) {
	return x >= y ? x : y;
}