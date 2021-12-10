#include <stdio.h>

int BuildTree(int id, int L, int R);

const int maxn = 2e5 + 10;
int t, n, tot, A[maxn];

int main() {
	scanf("%d", &t);
	while (t--) {
		tot = 0;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			scanf("%d", &A[i]);
		}
		int ans = BuildTree(1, 1, n);
		printf("%d\n", ans);
	}

	return 0;
}
int BuildTree(int id, int L, int R) {
	tot++;
	id = tot;
	if (L == R) {
		return tot;
	}
	if (R - L == 1) {
		BuildTree(id, L, L);
		BuildTree(id, R, R);
	}
	else {
		int B;
		if ((R - L) % 3 != 0) {
			B = L + (R - L) / 3;
		}
		else {
			B = L + (R - L) / 3 - 1;
		}
		int C = (B + R) / 2;
		BuildTree(id, L, B);
		BuildTree(id, B + 1, C);
		BuildTree(id, C + 1, R);
	}
}