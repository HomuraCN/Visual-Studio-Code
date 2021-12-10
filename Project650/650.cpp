#include <stdio.h>
#include <algorithm>
#define LL long long
using namespace std;

const int maxn = 2e5 + 10;
int t, n;
LL a[maxn];

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			scanf("%lld", &a[i]);
		}
		sort(a + 1, a + 1 + n);
		LL maxx = a[1];
		for (int i = 2; i <= n; i++) {
			maxx = max(maxx, a[i] - a[i - 1]);
		}
		printf("%lld\n", maxx);
	}

	return 0;
}