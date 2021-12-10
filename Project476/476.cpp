#include <stdio.h>
#define LL long long

const int maxn = 2010;
int t, n;
LL a[maxn];

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			scanf("%lld", &a[i]);
		}
	}

	return 0;
}