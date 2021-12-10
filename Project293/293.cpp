#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;

int t, n, k, a[100010], counter = 0;
double AA, BB;

int main() {
	scanf("%d", &t);
	for (int i = 1; i <= t; i++) {
		scanf("%d %d", &n, &k);
		for (int j = 1; j <= n; j++) {
			scanf("%d", &a[j]);
		}
		while (k--) {
			sort(a + 1, a + 1 + n + counter);
			int A, B = a[n + counter], FLAG = 0;
			for (int j = 1; j <= n - 1 + counter; j++) {
				if (a[j + 1] - a[j] >= 2) {
					A = a[j] + 1;
					FLAG = 1;
					break;
				}
			}
			if (FLAG == 0) {
				if (a[1] == 0) {
					A = B + 1;
				}
				else {
					A = 0;
				}
			}
			AA = A * 1.0, BB = B * 1.0;
			int ans = ceil((AA + BB) / 2), flag = 0, cnt = 1;
			for (int j = 1; j <= n + counter; j++) {
				if (ans == a[j]) {
					flag = 1;
				}
				if (a[j] != a[j + 1] && j <= n - 1 + counter) {
					cnt++;
				}
			}
			if (flag == 0) {
				counter++;
				a[n + counter] = ans;
			}
		}
		printf("%d\n", n + counter);
		counter = 0;
	}

	return 0;
}