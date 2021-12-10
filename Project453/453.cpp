#include <stdio.h>
#include <string.h>

int Max(int x, int y);

int N, M;
int weight[3410], value[3410], dp[12890];

int main() {
	scanf("%d %d", &N, &M);
	memset(dp, 0, sizeof(dp));
	for (int i = 1; i <= N; i++) {
		scanf("%d %d", &weight[i], &value[i]);
	}
	for (int i = 1; i <= N; i++) {
		for (int j = M; j >= weight[i]; j--) {
			dp[j] = Max(dp[j], dp[j - weight[i]] + value[i]);
		}
	}
	printf("%d", dp[M]);

	return 0;
}
int Max(int x, int y) {
	return x > y ? x : y;
}