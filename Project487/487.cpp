#include <stdio.h>

int Max(int x, int y) {
	return x > y ? x : y;
}

const int maxn = 110;
int T, N, h[maxn], dp1[maxn], dp2[maxn];

int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &N);
		for (int i = 1; i <= N; i++) {
			scanf("%d", &h[i]);
		}
		/*正向：从左往右*/
		for (int i = 1; i <= N; i++) {
			dp1[i] = 1;
			for (int j = 1; j < i; j++) {
				if (h[j] < h[i]) {
					dp1[i] = Max(dp1[i], dp1[j] + 1);
				}
			}
		}
		/*反向：从右往左*/
		for (int i = N; i >= 1; i--) {
			dp2[i] = 1;
			for (int j = N; j > i; j--) {
				if (h[j] < h[i]) {
					dp2[i] = Max(dp2[i], dp2[j] + 1);
				}
			}
		}
		int ans1 = 0, ans2 = 0;
		for (int i = 1; i <= N; i++) {
			ans1 = Max(ans1, dp1[i]);
			ans2 = Max(ans2, dp2[i]);
		}
		printf("%d %d", ans1, ans2);
	}

	return 0;
}