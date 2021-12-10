#include <stdio.h>

long long Max(long long x, long long y);

const int maxn = 1000010;
long long n, k, max = 0, map[maxn], sum[maxn] = { 0 };

int main() {
	scanf("%lld %lld", &n, &k);
	for (int i = 1; i <= n - 1; i++) {
		scanf("%lld", &map[i]);
	}
	for (int i = 1; i <= n - 1; i++) {
		sum[i] = sum[i - 1] + map[i];
	}
	for (int i = k; i <= n - 1; i++) {
		max = Max(max, sum[i] - sum[i - k]);
	}
	printf("%lld", sum[n - 1] - max);

	return 0;
}
long long Max(long long x, long long y) {
	return x >= y ? x : y;
}