#include <stdio.h>
#define LL long long

LL quickPow(LL a, LL b);
void initInfact();
LL C(LL n, LL m);

const int maxn = 2e5 + 10, MOD = 1e9 + 7;
int t, n, k;
LL fact[maxn], infact[maxn];

int main() {
	initInfact();
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &n, &k);
		if (n & 1) {
			int ans = 1;
			for (int i = 1; i <= (n + 1) / 2; i++) {
				ans = (ans + C(n, 2 * (LL)i - 1)) % MOD;
			}
			printf("%d\n", quickPow(ans, k));
		}
		else {
			int ans = 0, p1 = 0, p2 = 0;
			for (int i = 2; i <= n; i += 2) {
				p1 = (p1 + C(n, i)) % MOD;
			}
			for (int i = 1; i <= n; i += 2) {
				p2 = (p2 + C(n, i)) % MOD;
			}
			for (int i = 1; i <= k; i++) {
				ans = (ans + (LL)p2 * quickPow(p1, (LL)k - i) % MOD * quickPow(quickPow(2, (LL)i - 1), n) % MOD) % MOD;
			}
			printf("%d\n", (quickPow(quickPow(2, k), n) - ans + MOD) % MOD);
		}
	}

	return 0;
}
LL quickPow(LL a, LL b) {
	LL result = 1;
	while (b) {
		if (b & 1) {
			result = (result * a) % MOD;
		}
		a = (a * a) % MOD;
		b >>= 1;
	}
	return result;
}
void initInfact() {
	fact[0] = infact[0] = 1;
	for (int i = 1; i < maxn; i++) {
		fact[i] = fact[i - 1] * i % MOD;
	}
	infact[maxn - 1] = quickPow(fact[maxn - 1], MOD - 2);
	for (int i = maxn - 2; i >= 1; i--) {
		infact[i] = infact[i + 1] * ((LL)i + 1) % MOD;
	}
}
LL C(LL n, LL m) {
	return fact[n] * infact[m] % MOD * infact[n - m] % MOD;
}