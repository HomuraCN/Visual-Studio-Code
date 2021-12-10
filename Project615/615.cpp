#include <stdio.h>
#include <algorithm>
#define LL long long
using namespace std;

typedef struct Cave {
	int a, len;
}CAVE;

bool cmp(CAVE x, CAVE y) {
	return x.a < y.a;
}

const int maxn = 1e5 + 10;
int t, n, k;
LL ans, delta;
CAVE cave[maxn];

int main() {
	scanf("%d", &t);
	while (t--) {
		delta = 0;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			cave[i].a = 0;
			scanf("%d", &k);
			for (int j = 1; j <= k; j++) {
				int temp;
				scanf("%d", &temp);
				cave[i].a = max(cave[i].a, temp - j + 2);
			}
			cave[i].len = k;
		}
		sort(cave + 1, cave + 1 + n, cmp);
		LL power = cave[1].a;
		for (int i = 1; i <= n - 1; i++) {
			if (power + cave[i].len < cave[i + 1].a) {
				delta += (LL)cave[i + 1].a - (power + cave[i].len);
				power = cave[i + 1].a;
			}
			else {
				power += cave[i].len;
			}
		}
		ans = cave[1].a + delta;
		printf("%lld\n", ans);
	}

	return 0;
}