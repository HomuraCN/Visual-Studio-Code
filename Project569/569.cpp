#include <stdio.h>
#include <algorithm>
#define LL long long
using namespace std;

const int maxn = 62;
int t;
LL n, k, pow_2[maxn];

int main() {
	pow_2[0] = 1;
	for (int i = 1; i <= 61; i++) {
		pow_2[i] = pow_2[i - 1] * 2;
	}
	scanf("%d", &t);
	while (t--) {
		scanf("%lld %lld", &n, &k);
		if (k == 1) {
			printf("%lld\n", n * 2 - 1);
		}
		else {
			int pos = upper_bound(pow_2, pow_2 + 1 + 61, (n - 1) / (k - 1)) - pow_2;
			printf("%lld\n", pow_2[pos] * 2 - 3 * pow_2[pos - 1]);
		}
	}

	return 0;
}