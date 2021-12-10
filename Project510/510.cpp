#include <stdio.h>
#include <algorithm>
using namespace std;

const int maxn = 35;
int t, ans[maxn];

int main() {
	scanf("%d", &t);
	ans[0] = 1;
	for (int i = 1; i <= 30; i++) {
		ans[i] = 2 * ans[i - 1];
	}
	while (t--) {
		int n, flag = -1;
		scanf("%d", &n);
		for (int i = 0; i <= 30; i++) {
			if (ans[i] == n) {
				flag = i;
			}
		}
		if (flag != -1) {
			printf("%d\n", ans[flag] - 1);
			continue;
		}
		int* p = lower_bound(ans, ans + 31, n);
		printf("%d\n", *p / 2 - 1);
	}

	return 0;
}