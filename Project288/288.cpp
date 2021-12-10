#include <stdio.h>
#include <stack>
#include <vector>
using namespace std;

void Tarjan(int u);

const int maxn = 10010;
int n, m, w[maxn];
int dfn[maxn], low[maxn], dfncnt = 0, in_stack[maxn] = { 0 };
int scc[maxn], sc = 0, sz[maxn] = { 0 };/*scc[i]->节点i属于的强连通分量的编号, sc->当前强连通分量的数量*/
vector<int> G[maxn];
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
	int flag[maxn] = { 0 };
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < G[i].size(); j++) {
			int Next = G[i][j];
			if (scc[i] != scc[Next]) {
				flag[scc[i]] = 1;
				break;
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= sc; i++) {
		if (flag[i] == 0) {
			if (ans != 0) {
				printf("0");
				return 0;
			}
			ans = i;
		}
	}
	printf("%d", sz[ans]);

	return 0;
}
void Tarjan(int u) {
	dfn[u] = low[u] = ++dfncnt;
	S.push(u);
	in_stack[u] = 1;
	for (int i = 0; i < G[u].size(); i++) {
		int v = G[u][i];
		if (dfn[v] == 0) {/*子节点没有被访问*/
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