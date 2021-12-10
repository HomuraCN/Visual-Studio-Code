#include <stdio.h>
#include <algorithm>
using namespace std;

const int maxn = 5e3 + 10;

struct Size {
	int L, W;
}SIZE[maxn];

bool cmp(Size x, Size y) {
	if (x.L != y.L) {
		return x.L > y.L;
	}
	else {
		return x.W > y.W;
	}
}

int n, dp[maxn];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d %d", &SIZE[i].L, &SIZE[i].W);
	}
	sort(SIZE + 1, SIZE + 1 + n, cmp);
	for (int i = 1; i <= n; i++) {
		dp[i] = 1;
		for (int j = 1; j < i; j++) {
			if (SIZE[j].W < SIZE[i].W) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
	}
	int maxx = 0;
	for (int i = 1; i <= n; i++) {
		maxx = max(maxx, dp[i]);
	}
	printf("%d", maxx);

	return 0;
}