#include <stdio.h>
#include <algorithm>
#include <math.h>
#define LL long long
using namespace std;

const int maxn = 31623 + 10;
int t, k, l, r;
LL n_2[maxn];

int main() {
	n_2[0] = 0;
	for (int i = 1; i <= maxn - 1; i++) {
		n_2[i] = (LL)i * i;
	}
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &k);
		int r = lower_bound(n_2, n_2 + maxn - 1, k) - n_2, c;
		if (k >= pow(r - 1, 2) + 1 && k <= r * (r - 1) + 1) {
			c = r;
		}
		else {
			c = r * r - k + 1;
		}
		if (k < r * (r - 1) + 1) {
			r = (k - pow(r - 1, 2));
		}
		printf("%d %d\n", r, c);
	}

	return 0;
}