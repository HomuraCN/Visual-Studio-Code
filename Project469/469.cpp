#include <stdio.h>
#include <algorithm>
#include <string.h>
#define LL long long
using namespace std;

const int maxn = 2010;
int n, s[maxn];
LL dp[maxn][maxn];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &s[i]);
	}
	sort(s + 1, s + 1 + n);
	memset(dp, 0, sizeof(dp));
	for (int len = 1; len <= n; len++) {
		for (int i = 1; i + len <= n; i++) {
			int j = i + len;
			dp[i][j] = min(dp[i + 1][j], dp[i][j - 1]) + (s[j] - s[i]);
		}
	}
	printf("%lld", dp[1][n]);

	return 0;
}