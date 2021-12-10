#include <stdio.h>
#include <algorithm>
#define LL long long
using namespace std;

const int maxn = 110, MOD = 998244353;
int n, w[maxn];
double p[maxn], dp[maxn];
LL sumw = 0;

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &w[i]);
		sumw += w[i];
	}
	for (int i = 1; i <= n; i++) {
		p[i] = 1.0 * w[i] / sumw;
	}
	dp[0] = 0, dp[1] += p[1] * 1 * 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j < i; j++) {
			dp[i] = max((double)dp[i], (dp[j] + (double)i * i) * p[i]);
		}
	}
	printf("%lf\n", dp[n]);

	return 0;
}