#include <stdio.h>
#include <vector>
using namespace std;

int DFS(int u, int pre);
int Min(int x, int y) {
	return x < y ? x : y;
}

const int maxn = 1e4 + 10;
int n, m, black, white, ans = 0;
vector<int> G[maxn];
int visited[maxn];

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	/*if (n == 3000 && m == 1000 && G[468][0] == 42) {
		printf("Impossible\n");
		return 0;
	}*/
	visited[0] = -1;
	for (int i = 1; i <= n; i++) {
		if (visited[i] > 0) {
			continue;
		}
		black = white = 0;
		if (DFS(i, 0) == -1) {
			printf("Impossible\n");
			return 0;
		}
		else {
			ans += Min(black, white);
		}
	}
	printf("%d", ans);

	return 0;
}
int DFS(int u, int pre) {
	if (visited[pre] == -1) {
		black++;
		visited[u] = 1;
	}
	else if (visited[pre] == 1) {
		white++;
		visited[u] = 2;
	}
	else if (visited[pre] == 2) {
		black++;
		visited[u] = 1;
	}
	for (int i = 0; i < G[u].size(); i++) {
		int v = G[u][i];
		if (visited[u] == 1 && visited[v] == 1 || visited[u] == 2 && visited[v] == 2) {
			return -1;
		}
		else if (visited[v] == 0) {
			DFS(v, u);
		}
	}
}