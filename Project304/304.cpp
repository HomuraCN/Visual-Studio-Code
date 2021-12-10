#include <stdio.h>
#include <algorithm>
using namespace std;

const int maxn = 110;
int t;

int main() {
	scanf("%d", &t);
	for (int f = 1; f <= t; f++) {
		int n, a[maxn], times[maxn] = { 0 };
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
		}
        sort(a + 1, a + 1 + n);
		for (int i = 1; i <= n; i++) {
			if (i == 1) {
				printf("%d ", a[i]);
				continue;
			}
			if (a[i] == a[i - 1]) {
				times[a[i]]++;
				continue;
			}
			printf("%d ", a[i]);
		}
		for (int i = 1; i <= n; i++) {
			if (times[i] != 0) {
				while (times[i]--) {
					printf("%d ", i);
				}
			}
		}
		printf("\n");
	}

	return 0;
}