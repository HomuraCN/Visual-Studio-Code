#include <stdio.h>
#include <string.h>

typedef struct Brick {
	int goal;
	char flag;
}BRICK;

const int maxn = 2e2 + 10;
int t, n, m, k;
int dp[maxn][maxn][maxn];
BRICK bricks[maxn][maxn];

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d %d", &n, &m, &k);
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				scanf("%d", &bricks[i][j].goal);
				getchar();
				scanf("%c", &bricks[i][j].flag);
			}
		}
		/*for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				printf("%d %c ", bricks[i][j].goal, bricks[i][j].flag);
			}
			printf("\n");
		}*/
		for (int i = 1; i <= m; i++) {
			dp[n][i][k] = bricks[n][i].goal;
		}
		for (int i = n; i >= 1; i--) {
			for (int j = m; j >= 1; j--) {
				
			}
		}
	}

	return 0;
}