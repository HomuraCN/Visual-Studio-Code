#include <stdio.h>
#include <algorithm>
#define LL long long
using namespace std;

typedef struct Group {
	int left, right;
}GROUP;

const int maxn = 2e5 + 10;
int n, k, x, left, right, ans = 0, groupcnt = 0, need[maxn], a[maxn];
GROUP group[maxn];

int main() {
	scanf("%d %d %d", &n, &k, &x);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	sort(a + 1, a + 1 + n);
	a[n + 1] = 0x7fffffff;
	left = 1;
	for (int i = 1; i <= n; i++) {
		if (a[i + 1] - a[i] > x) {
			groupcnt++;
			group[groupcnt].left = a[left];
			group[groupcnt].right = a[i];
			left = i + 1;
		}
	}
	for (int i = 1; i <= groupcnt - 1; i++) {
		need[i] = (group[i + 1].left - group[i].right) / x;
	}
	sort(need + 1, need + groupcnt);
	ans = groupcnt;
	for (int i = 1; i <= groupcnt; i++) {
		if (k - need[i] < 0) {
			break;
		}
		k -= need[i];
		ans--;
	}
	printf("%d", ans);

	return 0;
}