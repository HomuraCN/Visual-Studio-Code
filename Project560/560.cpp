#include <stdio.h>
#include <string.h>
#include <math.h>
#define LL long long

const int maxn = 1e5 + 10;
int t, len;
LL ans;
char str[maxn];

int main() {
	scanf("%d", &t);
	while (t--) {
		int flag = 1;
		ans = 1;
		char left, right;
		scanf("%d", &len);
		scanf("%s", str);
		left = right = str[0];
		for (int i = 1; i < len; i++) {
			if (str[0] == str[i]) {
				continue;
			}
			else {
				flag = 0;
			}
		}
		if (flag == 1) {
			ans = pow(2, len - 1);
			ans %= 1000000007;
			printf("%lld\n",  ans);
		}
		else {
			for (int i = 1; i < len; i++) {
				if (str[i] == left && left == right) {
					ans = (ans * 2) % 1000000007;
				}
				else {
					printf("%lld\n", ans);
					break;
				}
			}
		}
	}

	return 0;
}