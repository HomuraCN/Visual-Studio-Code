#include <stdio.h>
#include <math.h>
#include <algorithm>
#define LL long long
using namespace std;

const int maxn = 1e5 + 10;
int m, n;
LL money[maxn], pow_2[52], sectionmin[maxn][52];

int main() {
	pow_2[0] = 1;
	for (int i = 1; i <= 51; i++) {
		pow_2[i] = pow_2[i - 1] * 2;
	}
	scanf("%d %d", &m, &n);
	for (int i = 1; i <= m; i++) {
		scanf("%lld", &money[i]);
		sectionmin[i][0] = money[i];
	}
	for (int j = 1; j <= 51; j++) {
		for (int i = 1; i <= m; i++) {
 			if (i + pow_2[j] - 1<= m) {
				sectionmin[i][j] = min(sectionmin[i][j - 1], sectionmin[i + pow_2[j - 1]][j - 1]);
			}
		}
	}
	while (n--) {
		int l, r, k;
		scanf("%d %d", &l, &r);
		k = (int)log2(r - l + 1);
		printf("%lld ", min(sectionmin[l][k], sectionmin[r - pow_2[k] + 1][k]));
	}

	return 0;
}