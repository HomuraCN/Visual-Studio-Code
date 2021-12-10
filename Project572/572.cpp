#include <stdio.h>
#include <string.h>
#include <queue>
#include <algorithm>
using namespace std;

typedef struct Section {
	int L = 0x7fffffff, R = 0;
}SECTION;

void DFS(int r, int c);
bool cmp(SECTION x, SECTION y) {
	if (x.L == y.L) {
		return x.R < y.R;
	}
	else {
		return x.L < y.L;
	}
}

const int maxn = 5e2 + 10;
int N, M, map[maxn][maxn];
bool visited[maxn][maxn], flag[maxn];
int dr[4] = {-1, 0, 1, 0}, dc[4] = {0, 1, 0, -1};
int now = 0;
queue<int> Q;
SECTION section[maxn];

int main() {
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	for (int i = 1; i <= M; i++) {
		memset(visited, false, sizeof(visited));
		now = i;
		DFS(1, i);
	}
	for (int i = 1; i <= M; i++) {
		if (flag[i] == true) {
			continue;
		}
		Q.push(i);
	}
	if (Q.empty()) {
		printf("1\n");
	}
	else {
		printf("0\n");
		int size = Q.size();
		printf("%d\n", size);
		return 0;
	}
	/*for (int i = 1; i <= M; i++) {
		printf("%d %d\n", section[i].L, section[i].R);
	}*/
	sort(section + 1, section + 1 + M, cmp);
	int maxx = 0, ans = 0;
	while (maxx < M) {
		int tempmax = maxx;
		for (int i = 1; i <= M; i++) {
			if (section[i].L == 0x7fffffff) {
				continue;
			}
			if (section[i].L <= maxx + 1) {
				tempmax = max(tempmax, section[i].R);
			}
		}
		maxx = tempmax;
		ans++;
	}
	printf("%d\n", ans);

	return 0;
}
void DFS(int r, int c) {
	if (r == N) {
		flag[c] = true;
		section[now].L = min(section[now].L, c);
		section[now].R = max(section[now].R, c);
	}
	visited[r][c] = true;
	for (int i = 0; i < 4; i++) {
		int newr = r + dr[i], newc = c + dc[i];
		if (visited[newr][newc] == false && newr >= 1 && newr <= N && newc >= 1 && newc <= M && map[newr][newc] < map[r][c]) {
			DFS(newr, newc);
		}
	}
}