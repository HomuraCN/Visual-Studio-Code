#include <stdio.h>
#include <algorithm>
using namespace std;

int Min(int x, int y) {
	return x < y ? x : y;
}

const int maxn = 100010;
int t, n, a[maxn], b[maxn];

int main() {
	scanf("%d", &t);
	while (t--) {
		int negativeandzero = 0, positiveflag = 0, zero = 0, negative = 0, minn = 0x7fffffff, minnpositive = 0x7fffffff;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
			if (a[i] <= 0) {
				negativeandzero++;
				b[negativeandzero] = -a[i];
				if (a[i] == 0) {
					zero++;
				}
				if (a[i] < 0) {
					negative++;
				}
			}
			if (a[i] > 0) {
				positiveflag = 1; 
				minnpositive = Min(minnpositive, a[i]);
			}
		}
		sort(b + 1, b + 1 + negativeandzero);
		for (int i = negativeandzero; i >= 2; i--) {
			minn = Min(minn, b[i] - b[i - 1]);
		}
		if (positiveflag == 0) {
			printf("%d\n", negativeandzero);
		}
		else if (positiveflag == 1) {
			if (negative == 0) {
				printf("%d\n", zero + 1);
				continue;  
			}
			if (zero > 1) {
				printf("%d\n", negativeandzero);
			}  
			else if (zero <= 1) {
				if (minn < minnpositive) {
					printf("%d\n", negativeandzero);
				}
				else {
					printf("%d\n", negativeandzero + 1);
				}
			}
		}
	}

	return 0;
}