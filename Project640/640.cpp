#include <stdio.h>
#include <algorithm>
#define LL long long
using namespace std;

const int maxn = 1e3 + 10;
LL t, n, H;
LL a[maxn];

int main() {
	scanf("%lld", &t);
	while (t--) {
		scanf("%lld %lld", &n, &H);
		for (int i = 1; i <= n; i++) {
			scanf("%lld", &a[i]);
		}
		sort(a + 1, a + 1 + n);
		LL ans = 0;
		ans = H / (a[n] + a[n - 1]);
		H -= (a[n] + a[n - 1]) * ans;
		if(H > 0){
			if (H - a[n] <= 0) {
				printf("%lld\n", ans * 2 + 1);
			}
			else {
				printf("%lld\n", ans * 2 + 2);
			}
		}
		else {
			printf("%lld\n", ans * 2);
		}
	}

	return 0;
}