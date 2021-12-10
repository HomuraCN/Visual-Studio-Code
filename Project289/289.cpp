#include <stdio.h>
#include <vector>
#include <stack>
using namespace std;

void Tarjan(int u);

const int maxn = 5010;
int N, M;
int dfn[maxn] = { 0 }, low[maxn] = { 0 }, dfncnt = 0, in_stack[maxn] = { 0 };
int scc[maxn], sz[maxn], sc = 0;
vector<int> G[maxn];
stack<int> S;

int main() {
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= M; i++) {
		int u, v, state;
		scanf("%d %d %d", &u, &v, &state);
		if (state == 1) {
			G[u].push_back(v);
		}
		else {
			G[u].push_back(v);
			G[v].push_back(u);
		}
	}
	for (int i = 1; i <= N; i++) {
		if (dfn[i] == 0) {
			Tarjan(i);
		}
	}
	int flag = 1;
	for (int i = 1; i <= sc; i++) {
		if (sz[flag] <= sz[i]) {
			flag = i;
		}
	}
	printf("%d\n", sz[flag]);
	for (int i = 1; i <= N; i++) {
		if (scc[i] == flag) {
			printf("%d ", i);
		}
	}

	return 0;
}
void Tarjan(int u) {
	dfn[u] = low[u] = ++dfncnt;
	in_stack[u] = 1;
	S.push(u);
	for (int i = 0; i < G[u].size(); i++) {
		int v = G[u][i];
		if (dfn[v] == 0) {
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