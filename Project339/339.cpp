#include <stdio.h>
#define int long long

int Gcd(int x, int y);
int t, n, temp, ans;

signed main() {
	scanf("%lld", &t);
	while (t--) {
		scanf("%lld", &n);
		while (1) {
			temp = n;
			int sum = 0;
			while (1) {
				sum += temp % 10;
				temp /= 10;
				if (temp == 0) {
					break;
				}
			}
			ans = Gcd(n, sum);
			if (ans == 1) {
				n++;
			}
			else {
				printf("%lld\n", n);
				break;
			}
		}
	}

	return 0;
}
int Gcd(int x, int y) {
	if (x % y == 0) {
		return y;
	}
	else {
		return Gcd(y, x % y);
	}
}