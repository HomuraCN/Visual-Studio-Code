#include <stdio.h>
#include <stack>
#include <vector>
using namespace std;

void Tarjan(int u);
void Compress();/*缩点*/

const int maxn = 10010;
int n, m, w[maxn];
int dfn[maxn], low[maxn], dfncnt = 0, in_stack[maxn] = { 0 };
int scc[maxn], sc = 0, sz[maxn] = { 0 };/*scc[i]->结点i属于的强连通分量的编号, sc->当前强连通分量的数量, sz[i]->编号为i的强连通分量的结点个数*/
vector<int> G[maxn], DAG[maxn];
stack<int> S;

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		G[u].push_back(v);
	}
	for (int i = 1; i <= n; i++) {
		if (dfn[i] == 0) {
			Tarjan(i);
		}
	}
	printf("%d\n", sc);

	/*test*/
	Compress();
	for (int i = 1; i <= sc; i++) {
		for (int j = 0; j < DAG[i].size(); j++) {
			printf("%d ", DAG[i][j]);
		}
		printf("\n");
	}
	/*
		8 14
		1 2
		2 3
		2 5
		2 6
		3 4
		3 7
		4 3
		4 8
		5 1
		5 6
		6 7
		7 6
		7 8
		8 8
	*/

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