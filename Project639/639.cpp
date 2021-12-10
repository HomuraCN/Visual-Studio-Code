#include <stdio.h>
#include <string.h>
#include <algorithm>
#define LL long long
using namespace std;

int lowbit(int x);
void add(int x, int delta);
int getSum(int x);

const int maxn = 2e5 + 10;
int t, n, a[maxn];
int tr[maxn], ls[maxn], index[maxn];
int cnt = 0;
LL ans;

int main() {
	scanf("%d", &t);
	while (t--) {
		ans = 0;
		memset(tr, 0, sizeof(tr));
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
			ls[i] = a[i];
		}
		sort(ls + 1, ls + 1 + n);
		cnt = unique(ls + 1, ls + 1 + n) - ls - 1;
		for (int i = 1; i <= n; i++) {
			index[i] = lower_bound(ls + 1, ls + 1 + cnt, a[i]) - ls;
		}
		for (int i = 1; i <= n; i++) {
			int temp1 = getSum(index[i] - 1), temp2 = getSum(n) - getSum(index[i]);
			if (temp1 <= temp2) {
				ans += temp1;
			}
			else {
				ans += temp2;
			}
			add(index[i], 1);
		}
		printf("%lld\n", ans);
	}

	return 0;
}
int lowbit(int x) {
	return x & -x;
}
void add(int x, int delta) {
	while (x <= n) {
		tr[x] += delta;
		x += lowbit(x);
	}
}
int getSum(int x) {
	int ans = 0;
	while (x >= 1) {
		ans += tr[x];
		x -= lowbit(x);
	}
	return ans;
}