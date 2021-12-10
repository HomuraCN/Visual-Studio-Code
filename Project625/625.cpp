#include <stdio.h>
#include <map>
#include <algorithm>
using namespace std;

const int maxn = 1e6 + 10;

int n, k, num, ans;
int a[maxn];
map<int, int>b;

int main() {
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		b[a[i]]++;
	}
	sort(a + 1, a + 1 + n);
	ans = n;
	num = unique(a + 1, a + 1 + n) - (a + 1);
	for (int i = 1; i <= num; i++) {
		if (a[i] <= a[i - 1] + k) {
			ans -= b[a[i - 1]];
		}
	}
	printf("%d", ans);
	return 0;
}