#include <stdio.h>
#include <iostream>
#include <string.h>
#define int long long
using namespace std;

int Gcd(int x, int y) {
	if (x % y == 0) {
		return y;
	}
	else {
		return Gcd(y, x % y);
	}
}
int Lcm(int x, int y)
{
	return x * y / Gcd(x, y);
}

const int maxn = 1e3 + 10;
int n, m, a[maxn], num[maxn];

signed main() {
	/*printf("%d\n", Lcm(Lcm(2, 4), 8));*/
	while(cin>>n>>m) {
		for (int i = 1; i <= n; i++) {
			scanf("%lld", &a[i]);
		}
		int lcm = a[1];
		for (int i = 2; i <= n; i++) {
			lcm = Lcm(a[i], lcm);
		}
		/*printf("%d\n", lcm);*/
		int lcm_sum = 0;
		for (int i = 1; i <= n; i++) {
			num[i] = lcm / a[i];
			lcm_sum += num[i];
		}
		if (m % lcm_sum == 0) {
			printf("Yes\n");
			for (int i = 1; i < n; i++) {
				printf("%lld ", (num[i] * m) / lcm_sum);
			}
			printf("%lld\n", (num[n] * m) / lcm_sum);
		}
		else {
			printf("No\n");
		}
	}

	return 0;
}