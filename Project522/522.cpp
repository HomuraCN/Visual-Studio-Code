#include <stdio.h>
#define LL long long

const int maxn = 10000010;
int n, x, flagmin = 0x7fffffff, length = 0x7fffffff;
LL sum[maxn];

int main() {
	scanf("%d %d", &n, &x);
	for (int i = 1; i <= n; i++) {
		LL temp;
		scanf("%lld", &temp);
		sum[i] = sum[i - 1] + temp;
	}
	int left = 0, right = n, mid = 0;
	while (left <= right) {
		int flag = 0;
		mid = (left + right) / 2;	/*mid -> Çø¼älength*/
		for (int i = 1; i <= n - mid + 1; i++) {
			if (sum[i + mid - 1] - sum[i - 1] >= x) {
				flag = 1;
				if (mid < length) {
					flagmin = i;
					length = mid;
				}
				break;
			}
		}
		if (flag == 1) {
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}
	printf("%d %d", flagmin, flagmin + length - 1);

	return 0;
}