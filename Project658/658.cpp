#include <stdio.h>
#include <vector>
using namespace std;

bool DFS(int u, int c);

const int maxn = 1e5 + 10;

int n, m;
int color[maxn];
vector<int> G[maxn];

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	bool flag = true;
	for (int i = 1; i <= n; i++) {
		if (color[i] == 0) {
			if (DFS(i, 1) == false) {
				flag = false;
				break;
			}
		}
	}
	if (flag) {
		printf("Yes\n");
	}
	else {
		printf("No\n");
	}

	return 0;
}
bool DFS(int u, int c) {
	color[u] = c;
	for (int i = 0; i < G[u].size(); i++) {
		int v = G[u][i];
		if (color[v] == 0) {
			if (DFS(v, 3 - c) == false) {
				return false;
			}
		}
		else if (color[v] == c) {
			return false;
		}
	}
	return true;
}