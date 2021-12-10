#include <stdio.h>
#include <algorithm>
using namespace std;

const int maxn = 2e4 + 10;
int n;
int a[maxn], b[maxn];
int ans = 0;

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d %d", &a[i], &b[i]);
	}
	sort(a + 1, a + 1 + n);
	sort(b + 1, b + 1 + n);
	for (int i = 1; i <= n; i++) {
		ans += (b[i] - a[i]);
		if (i != n && a[i + 1] < b[i]) {
			ans -= (b[i] - a[i + 1]);
		}
	}
	printf("%d", ans);

	return 0;
}