#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;

typedef struct Trash {
	int T, H, F;
}TRASH;

int Max(int x, int y) {
	return x > y ? x : y;
}
bool cmp(TRASH x, TRASH y) {
	return x.T < y.T;
}

const int maxn = 110;
int D, G;
TRASH trash[maxn];
int dp[maxn][maxn]; //dp[i][j] 前i个垃圾，高度为j时的生命值。dp[i][j] -> 堆：dp[i - 1][j - trash[i].H], 吃：dp[i - 1][j] + trash[i].F

int main() {
	scanf("%d %d", &D, &G);
	for (int i = 1; i <= G; i++) {
		scanf("%d %d %d", &trash[i].T, &trash[i].H, &trash[i].F);
	}
	sort(trash + 1, trash + 1+ G, cmp);
	memset(dp, -1, sizeof(dp));
	dp[0][0] = 10;
	for (int i = 1; i <= G; i++) {
		for (int j = 1; j <= D; j++) {
			if (j + trash[i].H >= D && dp[i - 1][j] >= trash[i + 1].T - trash[i].T) {
				printf("%d", trash[i].T);
				return 0;
			}
			/*堆*/
			if (dp[i - 1][j - trash[i].H] >= trash[i + 1].T - trash[i].T) {
				dp[i][j] = Max(dp[i][j], dp[i - 1][j - trash[i].H] - (trash[i].T - trash[i - 1].T));
			}
			/*吃*/
			if (dp[i - 1][j] >= trash[i].T - trash[i - 1].T) {
				dp[i][j] = Max(dp[i][j], dp[i - 1][j] - (trash[i].T - trash[i - 1].T) + trash[i].F);
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= G; i++) {
		ans = Max(ans, dp[i][0] + trash[i].F);
	}
	printf("%d", ans);

	return 0;
}