#include <stdio.h>
#include <string.h>
#include <stack>
#include <vector>
#include <queue>
using namespace std;

void Tarjan(int u);
int Check();

const int maxn = 30;
int n, m;
int indegree[maxn], intemp[maxn];
int dfn[maxn], low[maxn], dfncnt = 0, in_stack[maxn] = { 0 };
int scc[maxn], sc = 0, sz[maxn] = { 0 };/*scc[i]->结点i属于的强连通分量的编号, sc->当前强连通分量的数量, sz[i]->编号为i的强连通分量的结点个数*/
int step[maxn];
stack<int> S;
vector<int> G[maxn];
queue<int> Q, ans;

int main() {
	int circle = 0;
	scanf("%d %d", &n, &m);
	while(m--) {
		circle++;
		memset(dfn, 0, sizeof(dfn));
		memset(low, 0, sizeof(low));
		memset(in_stack, 0, sizeof(in_stack));
		memset(scc, 0, sizeof(scc));
		memset(sz, 0, sizeof(sz));
		memset(intemp, 0, sizeof(intemp));
		memset(step, 0, sizeof(step));
		char str[5];
		scanf("%s", str);
		G[str[0] - 'A' + 1].push_back(str[2] - 'A' + 1);
		indegree[str[2] - 'A' + 1]++;
		intemp[str[2] - 'A' + 1]++;
		for (int i = 1; i <= n; i++) {
			if (dfn[i] == 0) {
				Tarjan(i);
			}
		}
		/*矛盾*/
		if (sc < n) {
			printf("Sorted sequence cannot be determined.");
			return 0;
		}
		
		for (int i = 1; i <= n; i++) {
			if (indegree[i] == 0) {
				Q.push(i);
				ans.push(i);
				step[i] = 1;
			}
		}
		while (!Q.empty()) {
			int u = Q.front();
			Q.pop();
			if (!Check()) {
				printf("Inconsistency found after %d relations.", circle);
				return 0;
			}
			for (int i = 1; i < G[u].size(); i++) {
				int v = G[u][i];
				indegree[v]--;
				step[v] = step[u] + 1;
				if (indegree[v] == 0) {
					Q.push(v);
					ans.push(v);
				}
			}
		}
		int maxx = 0;
		for (int i = 1; i <= n; i++) {
			maxx = max(maxx, step[i]);
		}
		if (maxx == n) {
			printf("Sorted sequence determined after %d relations: ", circle);
			while (!ans.empty()) {
				printf("%c", (char)(ans.front() + 'A' - 1));
				ans.pop();
			}
		}
		
		for (int i = 1; i <= n; i++) {
			indegree[i] = intemp[i];
		}
		while (!ans.empty()) {
			ans.pop();
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
int Check() {
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (indegree[i] == 0) {
			cnt++;
		}
	}
	if (cnt > 1) {
		return 0;
	}
	else if (cnt == 1) {
		return 1;
	}
}