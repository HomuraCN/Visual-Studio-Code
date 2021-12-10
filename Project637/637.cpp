#include <stdio.h>
#include <algorithm>
using namespace std;

const int maxn = 1e4 + 10;
int n;
int a[maxn], ls[maxn], index[maxn];
int cnt;

int main() {
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
		printf("%d ", index[i]);
	}

	return 0;
}