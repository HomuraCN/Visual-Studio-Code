#include <stdio.h>
#include <algorithm>
using namespace std;

const int maxn = 2e5 + 10;
int t, n, x;
int a[maxn], b[maxn];

int main() {
	scanf("%d", &t);
	while (t--) {
		int flag = 1;
		scanf("%d %d", &n, &x);
		for (int i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
			b[i] = a[i];
		}
		sort(b + 1, b + 1 + n);
		for (int i = n - x + 1; i <= x; i++) {
			if (b[i] != a[i]) {
				flag = 0;
			}
		}
		if (flag == 1) {
			printf("YES\n");
		}
		else {
			printf("NO\n");
		}
	}

	return 0;
}