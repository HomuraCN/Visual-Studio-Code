#include <stdio.h>
#include <stack>
#include <vector>
using namespace std;

void Tarjan(int u);
void Compress();/*缩点*/
void DFS(int u);

const int maxn = 1e5 + 10;
int n, m, w[maxn];
int dfn[maxn], low[maxn], dfncnt = 0, in_stack[maxn] = { 0 };
int scc[maxn], sc = 0, sz[maxn] = { 0 };/*scc[i]->结点i属于的强连通分量的编号, sc->当前强连通分量的数量, sz[i]->编号为i的强连通分量的结点个数*/
vector<int> G[maxn], DAG[maxn];
stack<int> S;
int cnt;

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int v;
		scanf("%d", &v);
		G[i].push_back(v);
	}
	for (int i = 1; i <= n; i++) {
		if (dfn[i] == 0) {
			Tarjan(i);
		}
	}
	for (int i = 1; i <= n; i++) {
		if (sz[scc[i]] > 1) {
			printf("%d\n", sz[scc[i]]);
		}
		else {
			if (G[i][0] == i) {
				printf("1\n");
			}
			else {
				cnt = 0;
				DFS(i);
			}
		}
	}

	return 0;
}
void Tarjan(int u) {
	dfn[u] = low[u] = ++dfncnt;
	S.push(u);
	in_stack[u] = 1;
	for (int i = 0; i < G[u].size(); i++) {
		int v = G[u][i];
		if (dfn[v] == 0) {/*子结点没有被访问*/
			Tarjan(v);
			low[u] = min(low[u], low[v]);
		}
		else if (in_stack[v] == 1) {
			low[u] = min(low[u], dfn[v]);
		}
	}
	if (dfn[u] == low[u]) {
		sc++;
		int TOP;
		while ((TOP = S.top()) != u) {
			scc[TOP] = sc;
			sz[sc]++;
			in_stack[TOP] = 0;
			S.pop();
		}
		scc[TOP] = sc;
		sz[sc]++;
		in_stack[TOP] = 0;
		S.pop();
	}
}
void Compress() {
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < G[i].size(); j++) {
			int v = G[i][j];
			if (scc[i] != scc[v]) {
				DAG[scc[i]].push_back(scc[v]);
			}
		}
	}
}
void DFS(int u) {
	cnt++;
	int v = G[u][0];
	if (scc[v] > 0) {
		printf("%d\n", sz[scc[v]] + cnt);
	}
	else {
		DFS(v);
	}
}