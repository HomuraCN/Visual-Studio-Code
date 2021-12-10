#include <stdio.h>
#include <string.h>

const int maxn = 15, maxm = 25;
int t, n, m, k;
int flag;
char Map[maxn][maxm];
int visited[maxn][maxm];

int main() {
	scanf("%d", &t);
	while (t--) {
		memset(visited, 0, sizeof(visited));
		flag = 0;
		scanf("%d %d %d", &n, &m, &k);
		getchar();
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				scanf("%c", &Map[i][j]);
			}
			getchar();
		}
		/*for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				printf("%c", Map[i][j]);
			}
			printf("\n");
		}*/
		for (int i = n; i >= 1; i--) {
			for (int j = m; j >= 1; j--) {
				if (Map[i][j] == '*' && Map[i - 1][j - 1] == '*' && Map[i - 1][j + 1] == '*') { /*可能是stick的位置*/
					if (i - k < 1 || j - k < 1 || j + k > m) { /*越界*/
						continue;
					}
					else { /*不越界则标记*/
						visited[i][j] = 1;
						int cycle = 1;
						for (int h = i - 1; h >= 1; h --) {
							if (j - cycle < 1 || j + cycle > m) { /*越界*/
								break;
							}
							visited[h][j - cycle] = 1, visited[h][j + cycle] = 1;
							cycle++;
						}
					}
				}
			}
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (visited[i][j] == 0 && Map[i][j] == '*') {
					flag = 1;
				}
				if (visited[i][j] == 1 && Map[i][j] == '.') {
					if (Map[i - 1][j - 1] == '*' || Map[i - 1][j + 1] == '*') {
						flag = 1;
					}
				}
			}
		}
		if (flag == 1) {
			printf("NO\n");
		}
		else {
			printf("YES\n");
		}
	}

	return 0;
}