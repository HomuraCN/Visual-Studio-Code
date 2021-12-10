#include <stdio.h>
#include <algorithm>
#define ULL unsigned long long
using namespace std;

const int max2 = 64, max3 = 1e6 + 10;
int t;
ULL n, pow_3[max3], pow_2[max2];

int main() {
	scanf("%d", &t);
	pow_2[0] = 1;
	for (int i = 1; i <= 60; i++) {
		pow_2[i] = 2 * pow_2[i - 1];
	}
	/*printf("%lld", pow_2[60]);*/
	for (int i = 1; i <= 1000001; i++) {
		pow_3[i] = (ULL)i * i * i;
	}
	/*printf("%lld", pow_3[1000000]);*/
	while (t--) {
		scanf("%llu", &n);
		/*for (int i = 1; i <= n; i++) {
			for (int j = i; j <= n; j++) {
				if ((i * i + j * j) % ((i * j) + 1) == 0) {
					printf("x = %d y = %d bei = %d\n", i, j, (i * i + j * j) / ((i * j) + 1));
				}
			}
		}*/
		int lim = upper_bound(pow_3 + 1, pow_3 + 1 + 1000001, n) - pow_3 - 1;
		/*printf("%lld", pow_3[lim]);*/
		ULL ans = 0;
		ans += lim;
		/*printf("%lld\n", ans);*/
		for (int i = 2; i <= lim; i++) {
			ULL bei = (ULL)i * i, last, now;
			last = 0, now = i * bei - last;
			last = i;
			if ((ULL)now * bei - last > n) {
				break;
			}
			do {
				/*printf("%lld\n", now);*/
				now = now * bei - last;
				last = (now + last) / bei;
				ans++;
			} while (now <= n);
			ans--;
		}
		printf("%llu", ans);
	}

	return 0;
}