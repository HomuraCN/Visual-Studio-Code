#include <stdio.h>
#define LL long long

int t;
LL n;

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%lld", &n);
		printf("%lld %lld\n", -n + 1, n);
	}

	return 0;
}