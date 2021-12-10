#include <stdio.h>
#include <vector>
#include <string.h>
#include <queue>
#include <algorithm>
#define LL long long
using namespace std;

const int maxn = 1e4 + 10, maxm = 5e4 + 10;

void DFS1(int u);
void DFS2(int u, int t);
void DFS3(int u);

int n, m, q, sum = 0;
int fa[maxn], depth[maxn], siz[maxn], son[maxn], top[maxn], dfn[maxn], rnk[maxn];
bool visited[maxn];
int cnt = 0;/*dfn*/
int t[maxn], L, R, ans = 0;
vector<int> G[maxn];
queue<int> Q;

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n - 1; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	DFS1(1);
	memset(visited, false, sizeof(visited));
	DFS2(1, 1);
	memset(visited, false, sizeof(visited));
	for (int i = 1; i <= n; i++) {
		scanf("%d", &t[i]);
	}
	scanf("%d", &q);
	for (int i = 1; i <= q; i++) {
		ans = 0;
		int start;
		scanf("%d %d %d", &start, &L, &R);
		if (t[1] < L) {
			printf("0\n");
		}
		else if(t[1] >= L && t[1] <= R) {
			memset(visited, false, sizeof(visited));
			if (t[start] >= L) {
				DFS3(start);
				printf("%d\n", ans);
			}
			else {
				printf("0\n");
			}
		}
		else if (t[1] > R) {
			memset(visited, false, sizeof(visited));
			while (start != 1) {
				if (t[fa[start]] < L && t[fa[start]] > R) {
					visited[fa[start]] = true;
					DFS3(start);
					break;
				}
				start = fa[start];
			}
			printf("%d\n", ans);
		}
	}

	return 0;
}
void DFS1(int u) {
	visited[u] = true;
	son[u] = -1;
	siz[u] = 1;
	for (int i = 0; i < G[u].size(); i++) {
		int v = G[u][i];
		if (visited[v] == true) {
			continue;
		}
		fa[v] = u;
		depth[v] = depth[u] + 1;
		DFS1(v);
		siz[u] += siz[v];
		if (son[u] == -1 || siz[v] > siz[son[u]]) {
			son[u] = v;
		}
	}
}
void DFS2(int u, int t) {
	visited[u] = true;
	top[u] = t;
	cnt++;
	dfn[u] = cnt;
	rnk[cnt] = u;
	if (son[u] == -1) {
		return;
	}
	DFS2(son[u], t);
	for (int i = 0; i < G[u].size(); i++) {
		int v = G[u][i];
		if (visited[v] == true) {
			continue;
		}
		DFS2(v, v);
	}
}
void DFS3(int u) {
	ans++;
	visited[u] = true;
	if (t[u] < L || t[u] > R) {
		return;
	}
	else {
		for (int i = 0; i < G[u].size(); i++) {
			int v = G[u][i];
			if (visited[v] == true) {
				continue;
			}
			if (t[v] >= L && t[v] <= R) {
				DFS3(v);
			}
		}
	}
}