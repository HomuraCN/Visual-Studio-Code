#include <stdio.h>
#include <string.h>

typedef struct Map {
	int value;
	int maxw;
	int minw;
}MAP;

int Min(int x, int y);

const int maxn = 110;
int n, maxw = 0, minw= 0x7fffffff, map[maxn][maxn];
MAP dp[maxn][maxn][4];

int main() {
	scanf("%d", &n);
	memset(map, 0, sizeof(map));
	memset(dp, 0x3f3f3f3f, sizeof(dp));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	dp[1][1][0].value = 0;
	dp[1][1][1].value = 0;
	dp[1][1][2].value = 0;
	dp[1][1][3].value = 0;
	maxw = map[1][1];
	minw = map[1][1];
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == 1 && j == 1) {
				continue;
			}
			for (int k = 0; k < 4; k++) {
				int flag;
				for (int h = 0; h < 4; h++) {
					if (dp[i - 1][j][h].value < dp[i][j][k].value) {
						flag = h;
						dp[i][j][k].value = dp[i - 1][j][h].value;
					}
				}
				maxw = Max(dp[i - 1][j][flag].maxw, map[i][j]);
				minw = Min(dp[i - 1][j][flag].minw, map[i][j]);
				if (i - 1 >= 1) {
					if (map[i - 1][j] > maxw) {
						maxw = map[i - 1][j];
					}
					if (map[i - 1][j] < minw) {
						minw = map[i - 1][j];
					}
					if (flag == 0) {
						flag = 1;
						dp[i][j] = maxw - minw;
					}
					else {
						dp[i][j] = Min(dp[i][j], maxw - minw);
					}
				}
				if (j + 1 <= n) {
					if (map[i][j + 1] > maxw) {
						maxw = map[i][j + 1];
					}
					if (map[i][j + 1] < minw) {
						minw = map[i][j + 1];
					}
					if (flag == 0) {
						flag = 1;
						dp[i][j] = maxw - minw;
					}
					else {
						dp[i][j] = Min(dp[i][j], maxw - minw);
					}
				}
				if (i + 1 <= n) {
					if (map[i + 1][j] > maxw) {
						maxw = map[i - 1][j];
					}
					if (map[i + 1][j] < minw) {
						minw = map[i + 1][j];
					}
					if (flag == 0) {
						flag = 1;
						dp[i][j] = maxw - minw;
					}
					else {
						dp[i][j] = Min(dp[i][j], maxw - minw);
					}
				}
				if (j - 1 >= 1) {
					if (map[i][j - 1] > maxw) {
						maxw = map[i - 1][j];
					}
					if (map[i][j - 1] < minw) {
						minw = map[i][j - 1];
					}
					if (flag == 0) {
						flag = 1;
						dp[i][j] = maxw - minw;
					}
					else {
						dp[i][j] = Min(dp[i][j], maxw - minw);
					}
				}
			}
		}
	}
	printf("%d", dp[n][n]);
	
	return 0;
}

int Min(int x, int y) {
	return x < y ? x : y;
}
int Max(int x, int y) {
	return x > y ? x : y;
}