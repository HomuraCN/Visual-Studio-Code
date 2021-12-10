#include <stdio.h>
#include <algorithm>
#define LL long long
using namespace std;

const int maxn = 1e5 + 10;
int t, n;
LL ans;

int main() {
	scanf("%d", &t);
	while (t--) {
		ans = 0;
		scanf("%d", &n);
		int tempL;
		scanf("%d", &tempL);
		for (int i = 2; i <= n; i++) {
			int tempR;
			scanf("%d", &tempR);
			ans = max(ans, (LL)tempL * tempR);
			tempL = tempR;
		}
		printf("%lld\n", ans);
	}

	return 0;
}