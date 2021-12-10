#include <stdio.h>
#define LL long long

LL BinPow(LL a, LL b);
void CalculateFact();
LL C(int n, int m);
LL Lucas(LL n, LL m);

const int maxn = 1e6 + 10, MOD = 1e9 + 7;
LL n, a, b, q, fact[maxn], infact[maxn];

int main() {
	scanf("%lld", &n);
	CalculateFact();
	LL ans = 1;
	for (int i = 1; i <= n - 1; i++) {
		ans = ans * Lucas(n - 1, i) % MOD;
	}
	printf("%lld", ans);

	return 0;
}
LL BinPow(LL a, LL b) {
	if (b == 0) {
		return 1 % MOD;
	}
	LL ans = 1;
	while (b > 0) {
		if (b & 1) {
			ans = ans * a % MOD;
		}
		a = a * a % MOD;
		b >>= 1;
	}
	return ans;
}
void CalculateFact() {
	fact[0] = infact[0] = 1;
	for (int i = 1; i <= n; i++) {
		fact[i] = fact[i - 1] * i % MOD;
	}
	for (int i = 1; i <= n; i++) {
		infact[i] = infact[i - 1] * BinPow(i, MOD - 2) % MOD;
	}
}
LL C(int n, int m) {
	return fact[n] * infact[m] % MOD * infact[n - m] % MOD;
}
LL Lucas(LL n, LL m) {
	if (m == 0) {
		return 1;
	}
	else {
		return (C(n % MOD, m % MOD) * Lucas(n  / MOD, m / MOD)) % MOD;
	}
}