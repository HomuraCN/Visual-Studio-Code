#include <stdio.h>
#include <string.h>
#define LL long long

int Min(int x, int y) {
	return x < y ? x : y;
}

void DFS(int u);

const int maxn = 20;
int n, weight = 0x7fffffff, flag[maxn], ans = 0x7fffffff;
LL p[maxn][maxn], origin[maxn][maxn];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		memset(flag, 0, sizeof(flag));
		for (int j = 1; j <= n; j++) {
			scanf("%lld", &origin[i][j]);
		}
	}
		for (int f = 1; f <= n; f++) {

			for (int y = 1; y <= n; y++) {
				for (int u = 1; u <= n; u++) {
					p[y][u] = origin[y][u];
				}
			}
			
			for (int h = 1; h <= n; h++) {
				for (int g = 1; g <= n; g++) {
					if (h == g) {
						continue;
					}
					p[f][h] = 0, p[f][g] *= 2;
						for (int i = 1; i <= n; i++) {
							memset(flag, 0, sizeof(flag));
							weight = 0;
							DFS(i);
							ans = Min(ans, weight);
						}
				}
			}
		}
	printf("%d", ans);

	return 0;
}
void DFS(int u) {
	flag[u] = 1;
	for (int i = 1; i <= n; i++) {/*后一个结点走向*/
		if (flag[i]) {
			continue;
		}
		DFS(i);
		weight += p[u][i];
	}
}