#include <stdio.h>

const int maxn = 1e3 + 10;
int t, k;
int cnt = 0, ans[maxn];

int main() {
	for (int i = 1; i <= 1e10 && cnt <= 1000; i++) {
		if (i % 10 != 3 && i % 3 != 0) {
			ans[++cnt] = i;
		}
	}
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &k);
		printf("%d\n", ans[k]);
	}

	return 0;
}