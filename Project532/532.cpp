#include <stdio.h>
#include <algorithm>
using namespace std;

int Gcd(int x, int y) {
	if (y == 0) {
		return x;
	}
	else {
		Gcd(y, x % y);
	}
}

const int maxn = 2e3 + 10;
int t, n, ans, cntou = 0, cntji = 0, cntjimei1 = 0, a[maxn];

int main() {
	scanf("%d", &t);
	while (t--) {
		ans = 0;
		cntou = 0;
		cntji = 0;
		cntjimei1 = 0;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			int temp;
			scanf("%d", &temp);
			if (temp % 2 == 0) {
				cntou++;
			}
			else {
				cntji++;
				if (temp != 1) {
					cntjimei1++;
					a[cntjimei1] = temp;
				}
			}
		}
		sort(a + 1, a + 1 + cntjimei1);
		for (int i = cntjimei1 + 1; i <= cntji; i++) {
			a[i] = 1;
		}
		for (int i = 1; i <= cntji - 1; i++) {
			for (int j = i + 1; j <= cntji; j++) {
				if (Gcd(a[i], 2 * a[j]) > 1) {
					ans++;
				}
			}
		}
		printf("%d\n", ans + (cntou * ((n - 1) + (n - cntou))) / 2);
	}

	return 0;
}