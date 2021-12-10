#include <stdio.h>
#include <math.h>
#include <algorithm>
#define LL long long
using namespace std;

const int maxn = 3e5 + 10;
int n;
LL ans = 0, a[maxn];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
	}
	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; i++) {
		ans += abs(i - a[i]);
	}
	printf("%lld\n", ans);

	return 0;
}