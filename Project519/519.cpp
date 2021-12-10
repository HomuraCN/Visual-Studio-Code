#include <stdio.h>

int Max(int x, int y) {
	return x > y ? x : y;
}

const int maxn = 1010;
int m, n, group = 0, groupcnt[maxn] = { 0 }, goodsindex[maxn][maxn], w[maxn], v[maxn], dp[maxn];

int main() {
	scanf("%d %d", &m, &n);
	for (int i = 1; i <= n; i++) {
		int temp;
		scanf("%d %d %d", &w[i], &v[i], &temp);
		groupcnt[temp]++;
		goodsindex[temp][groupcnt[temp]] = i;
		group = Max(group, temp);
	}
	for (int i = 1; i <= group; i++) {	/*组数(i)*/
		for (int j = m; j >= 0; j--) {	/*背包容量*/
			for (int k = 1; k <= groupcnt[i]; k++) { /*第i组的第k个物品*/
				if (j >= w[goodsindex[i][k]]) {
					dp[j] = Max(dp[j], dp[j - w[goodsindex[i][k]]] + v[goodsindex[i][k]]);
				}
			}
		}
	}
	printf("%d", dp[m]);

	return 0;
}