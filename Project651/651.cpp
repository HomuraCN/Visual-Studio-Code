#include <stdio.h>
#include <algorithm>
#define LL long long
using namespace std;

const int maxn = 2e5 + 10;
int t, n;
LL a[maxn], B[maxn], R[maxn];
char str[maxn];

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			scanf("%lld", &a[i]);
		}
		getchar();
		scanf("%s", str + 1);
		int indexR = 0, indexB = 0;
		for (int i = 1; i <= n; i++) {
			if (str[i] == 'R') {
				R[++indexR] = a[i];
			}
			else {
				B[++indexB] = a[i];
			}
		}
		sort(R + 1, R + 1 + indexR);
		sort(B + 1, B + 1 + indexB);
		int flag = 1;
		for (int i = 1; i <= indexB; i++) {
			if (B[i] < i) {
				flag = 0;
				break;
			}
		}
		if (flag == 1) {
			for (int i = indexB + 1; i <= n; i++) {
				if (R[i - indexB] > i) {
					flag = 0;
					break;
				}
			}
		}
		if (flag == 1) {
			printf("YES\n");
		}
		else {
			printf("NO\n");
		}
	}

	return 0;
}