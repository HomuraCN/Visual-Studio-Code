#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;

typedef struct Node {
	int x, y;
}NODE;

void BFS();

const int maxn = 35;
int n, startx = -1, starty = -1, map[maxn][maxn], flag[maxn][maxn];
int dx[4] = { 0, 1, 0, -1 }, dy[4] = {1, 0, -1 , 0};

int main() {
	memset(flag, 0, sizeof(flag));
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	for (int i = 0; i <= n + 1; i++) {
		map[0][i] = 0;
		map[n + 1][i] = 0;
		map[i][0] = 0;
		map[i][n + 1] = 0;
	}
	BFS();
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (map[i][j] == 0 && flag[i][j] == 0) {
				map[i][j] = 2;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			printf("%d ", map[i][j]);
		}
		printf("\n");
	}

	return 0;
}
void BFS() {
	queue<NODE> Q;
	NODE temp;
	temp.x = 0, temp.y = 0;
	Q.push(temp);
	while (!Q.empty()) {
		NODE now = Q.front();
		Q.pop();
		for (int i = 0; i < 4; i++) {
			int nex = now.x + dx[i], ney = now.y + dy[i];
			if (nex >= 0 && nex <= n + 1 && ney >= 0 && ney <= n + 1 && flag[nex][ney] == 0) {
				if (map[nex][ney] == 0) {
					temp.x = nex, temp.y = ney;
					Q.push(temp);
					flag[nex][ney] = 1;
				}
			}
		}
	}
}