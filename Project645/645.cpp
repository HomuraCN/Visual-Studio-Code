#include <stdio.h>
#include <math.h>
#define LL long long

const int MOD = 1e9 + 7;
int t;
int n, k;
LL ans, temp;

int main() {
	scanf("%d", &t);
	while (t--) {
		ans = 0;
		temp = 1;
		scanf("%d %d", &n, &k);
		for (int i = 0; i <= 30; i++) {
			if ((k >> i) & 1) {
				ans = (ans + temp) % MOD;
			}
			temp = (temp * n) % MOD;
		}
		printf("%lld\n", ans);
	}

	return 0;
}