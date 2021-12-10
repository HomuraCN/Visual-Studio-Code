#include <stdio.h>
#include <algorithm>
using namespace std;

const int maxn = 3e3 + 10;
int N, A[maxn], B[maxn], dp[maxn][maxn];

int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &A[i]);
	}
	for (int i = 1; i <= N; i++) {
		scanf("%d", &B[i]);
	}
	for (int i = 1; i <= N; i++) {
		int maxv = 1;
		for (int j = 1; j <= N; j++) {
			dp[i][j] = max(dp[i][j], dp[i - 1][j]);
			if (A[i] > B[j]) {
				maxv = max(maxv, dp[i - 1][j] + 1);
			}
			if (A[i] == B[j]) {
				dp[i][j] = max(dp[i][j], maxv);
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= N; i++) {
		ans = max(ans, dp[N][i]);
	}
	printf("%d", ans);

	return 0;
}