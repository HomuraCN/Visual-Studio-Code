#include <stdio.h>
#define LL long long

LL Max(LL x, LL y) {
	return x > y ? x : y;
}
LL Min(LL x, LL y) {
	return x < y ? x : y;
}

const int maxn = 100010, MOD = 998244353;
LL n, a[maxn], b[maxn], c[maxn] = { 0 }, suma = 0, sumb = 0;

int main() {
	scanf("%lld", &n);
	for (int i = 0; i < n; i++) {
		scanf("%lld", &a[i]);
		if (i == 0) {
			continue;
		}
		suma = (suma + a[i]) % MOD;
	}
	for (int i = 0; i < n; i++) {
		scanf("%lld", &b[i]);
		if (i == 0) {
			continue;
		}
		sumb = (sumb + b[i]) % MOD;
	}
	c[0] = (suma * sumb) % MOD;
	/*for (int i = 1; i < n; i++) {
		for (int j = 1; j < n; j++) {
			c[0] += (a[i] * b[j]) % MOD;
		} 
	}*/
	/*for (int j = 0; j < n; j++) {
		if (j == 1) {
			continue;
		}
		c[1] = (c[1] + (a[0] * b[j]) % MOD) % MOD;
		c[1] = (c[1] + (a[j] * b[0]) % MOD) % MOD;
	}*/
	for (int i = 2; i < n; i++) {
		c[1] = (c[1] + (a[0] * b[i]) % MOD) % MOD;
	}
	for (int i = 2; i < n; i++) {
		c[1] = (c[1] + (a[i] * b[0]) % MOD) % MOD;
	}
	c[1] = (c[1] + (a[0] * b[0]) % MOD) % MOD;
	c[2] = (c[2] + (a[0] * b[1]) % MOD + (a[1] * b[0]) % MOD) % MOD;
	for (int i = 0; i < n; i++) {
		printf("%lld ", c[i] % MOD);
	}

	return 0;
}