#include <stdio.h>

const int maxn = 1e3 + 10;
int w, b;
double dp[maxn][maxn];

int main() {
	scanf("%d %d", &w, &b);
	for (int j = 0; j <= b; j++) {
		dp[0][j] = 0;
	}
	for (int i = 1; i <= w; i++) {
		dp[i][0] = 1;
	}
	for (int i = 1; i <= w; i++) {
		for (int j = 1; j <= b; j++) {
			dp[i][j] += 1.0 * i / (i + j);
			if (j >= 3) {
				dp[i][j] += 1.0 * j / (i + j) * (j - 1) / (i + j - 1) * (j - 2) / (i + j - 2) * dp[i][j - 3];
			}
			if (i >= 1 && j >= 2) {
				dp[i][j] += 1.0 * j / (i + j) * (j - 1) / (i + j - 1) * i / (i + j - 2) * dp[i - 1][j - 2];
			}
		}
	}
	printf("%.10lf", dp[w][b]);

	return 0;
}