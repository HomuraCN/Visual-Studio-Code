#include <stdio.h>
#include <math.h>
#define LL long long

int t;

int main() {
	scanf("%d", &t);
	while (t--) {
		LL n, m, x, c, r, ans;
		scanf("%lld %lld %lld", &n, &m, &x);
		/*if (n == 1 && m == 1 && x == 1) {
			printf("1\n");
			continue;
		}*/
		if (x % n != 0) {
			c = x / n + 1;
		}
		else {
			c = x / n;
		}
		if (x % n == 0) {
			r = n;
		}
		else {
			r = x % n;
		}
		ans = (r - 1) * m + c;
		printf("%lld\n", ans);
	}

	return 0;
}