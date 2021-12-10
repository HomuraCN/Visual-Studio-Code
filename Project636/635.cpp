#include <stdio.h>
#define LL long long

const int MOD = 1000000007;
int t, n, m, k;
int m_minn;

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d %d", &n, &m, &k);
		if (m < n - 1) {
			printf("NO\n");
			continue;
		}
		m_minn = n / 2;
		int delta = (m - n) / 2;
		m_minn -= delta;
		if (m_minn < k - 1) {
			printf("YES\n");
		}
		else {
			printf("NO\n");
		}
	}

	return 0;
}