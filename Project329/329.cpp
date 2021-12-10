#include <stdio.h>

int Max(int x, int y);

const int maxn = 510;
int n, G[maxn][maxn], dp[maxn][maxn];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			dp[i][j] = 0;
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &G[i][j]);
		}
	}
	for (int len = 1; len <= n; len++) {/*区间长度*/
		for (int start = 1; start <= n - len; start++) {/*左区间闭*/
			int end = start + len;/*右区间闭*/
			for (int cut = start; cut <= end; cut++) {/*断点*/
				dp[start][end] = Max(dp[start][end], dp[start + 1][cut - 1] + dp[cut + 1][end] + G[start][cut]);/*G[u][v]要有一般性，不能是有特殊位置关系的两条边*/
			}
		}
	}
	printf("%d", dp[1][n]);

	return 0;
}
int Max(int x, int y) {
	return x > y ? x : y;
}