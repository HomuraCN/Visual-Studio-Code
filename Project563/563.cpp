#include <stdio.h>
#include <string.h>

const int maxn = 2e5 + 10;
int t, n;
bool morevisited[maxn] = { false };
int a[maxn], cnt[maxn] = { 0 };

int main() {
	scanf("%d", &t);
	while (t--) {
		memset(morevisited, false, sizeof(morevisited));
		memset(cnt, 0, sizeof(cnt));
		int n, k, flag = 0, morecoun = 0, lesscoun;
		scanf("%d %d", &n, &k);
		for (int i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
			cnt[a[i]]++;
			if (cnt[a[i]] >= k) {
				morevisited[a[i]] = true;
				cnt[a[i]] = k;
				morecoun++;
			}
		}
		lesscoun = n - morecoun;
		lesscoun /= k;
		lesscoun *= k;
		for (int i = 1; i <= n; i++) {
			if (morevisited[a[i]] == true) {
				if (cnt[a[i]] <= 0) {
					printf("0 ");
				}
				else {
					printf("%d ", cnt[a[i]]--);
				}
			}
			else if (morevisited[a[i]] == false && lesscoun > 0) {
				flag++;
				printf("%d ", flag);
				lesscoun--;
				flag %= k;
			}
		}
		printf("\n");
	}

	return 0;
}