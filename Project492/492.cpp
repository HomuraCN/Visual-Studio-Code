#include <stdio.h>
#include <algorithm>
using namespace std;

const int maxn = 110;
int t, weight[maxn];

int main() {
	scanf("%d", &t);
	while (t--) {
		int n, x, sum = 0;
		scanf("%d %d", &n, &x);
		for (int i = 1; i <= n; i++) {
			scanf("%d", &weight[i]);
			sum += weight[i];
		}
		if (sum == x) {
			printf("NO\n");
		}
		else {
			if (sum < x) {
				printf("YES\n");
				for (int i = 1; i <= n; i++) {
					printf("%d ", weight[i]);
				}
				printf("\n");
			}
			else {
				int danger = -1, dangercnt = 0, temp = 0, index = 0;
				sort(weight + 1, weight + 1 + n);
				for (int i = 1; i <= n; i++) {
					temp += weight[i];
					if (temp == x) {
						if (dangercnt == 0) {
							index = i;
						}
						danger = weight[i];
						dangercnt++;
						temp -= weight[i];
					}
				}
				if (dangercnt == n - index + 1) {
					printf("NO\n");
				}
				else {
					printf("YES\n");
					temp = 0, dangercnt;
					for (int i = 1; i <= n; i++) {
						if (weight[i] == danger) {
							continue;
						}
						else {
							printf("%d ", weight[i]);
						}
					}
					for (int i = 1; i <= dangercnt; i++) {
						printf("%d ", danger);
					}
					printf("\n");
				}
			}
		}
	}

	return 0;
}