#include <stdio.h>
#include <string.h>
using namespace std;

int Max(int x, int y);

int m, n;
int value[10010], weight[10010], dp[100010];

int main() {
	scanf("%d %d", &m, &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d %d", &value[i], &weight[i]);
	}
	memset(dp, 0, sizeof(dp));
	for (int i = 1; i <= n; i++) {
		for (int j = weight[i]; j <= m; j++) {
			dp[j] = Max(dp[j], dp[j - weight[i]] + value[i]);
		}
	}
	printf("%d", dp[m]);

	return 0;
}
int Max(int x, int y) {
	return x > y ? x : y;
}