#include <stdio.h>

int Min(int x, int y) {
	return x < y ? x : y;
}

const int maxn = 110;
int t, n, a[maxn];

int main() {
	scanf("%d", &t);
	while (t--) {
		int minn = 0x7fffffff, cnt = 0;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
			minn = Min(minn, a[i]);
		}
		for (int i = 1; i <= n; i++) {
			if (minn == a[i]) {
				cnt++;
			}
		}
		if (cnt == n) {
			printf("0\n");
		}
		else {
			printf("%d\n", n - cnt);
		}
	}

	return 0;
}