#include <stdio.h>

void DFS(int u);

const int maxn = 110;
int n, m, sccnt = 0;
int G[maxn][maxn], visited[maxn];

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		G[u][v] = G[v][u] = 1;
	}
	for (int i = 1; i <= n; i++) {
		if (visited[i] == 1) {
			continue;
		}
		sccnt++;
		DFS(i);
	}
	if (sccnt % 2 == 1 && m % 2 == 1) {
		printf("Bob\n");
	}
	else {
		printf("Alice\n");
	}

	return 0;
}
void DFS(int u) {
	visited[u] = 1;
	for (int i = 1; i <= n; i++) {
		int check = G[u][i];
		if (check == 0) {
			continue;
		}
		if (visited[i] == 1) {
			continue;
		}
		DFS(i);
	}
}