#include <stdio.h>

int Max(int x, int y) {
	return x > y ? x : y;
}

const int maxn = 100010;
int n, k, maxx = -0x7fffffff, sum[maxn];

int main() {
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; i++) {
		int temp;
		scanf("%d", &temp);
		sum[i] = sum[i - 1] + temp;
	}
	for (int i = k; i <= n; i++) {
		maxx = Max(maxx, sum[i] - sum[i - k]);
	}
	printf("%d\n", maxx);

	return 0;
}