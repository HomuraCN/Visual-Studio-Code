#include <stdio.h>
#include <math.h>
#include <stack>
#include <vector>
#include <queue>
using namespace std;

typedef struct Edge {
	int v;
	int w;
	double e;
}EDGE;
struct Vertex
{
	int u;
	int w;
}vertex;
struct node {
	int u, v, w;
	double x;
	bool operator <(const node x) const { 
		return w < x.w;
	}
};

void spfa();
void Tarjan(int u);
void Compress();

const int maxn = 8e4 + 10;
int n, m, s;
int dfn[maxn], low[maxn], dfncnt = 0, in_stack[maxn];
int scc[maxn], sc = 0, sz[maxn];
int sccw[maxn];
int pre[maxn], visited[maxn] = { 0 }, d[maxn];
vector<EDGE> G[maxn];
vector<struct Vertex>DAG[maxn];
stack<int> S;

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; i++) {
		int u, v, originw;
		double e;
		EDGE temp;
		scanf("%d %d %d %lf", &u, &v, &originw, &e);
		temp.v = v, temp.w = originw, temp.e = e;
		G[u].push_back(temp);
	}
	scanf("%d", &s);
	for (int i = 1; i <= n; i++) {
		if (dfn[i] == 0) {
			Tarjan(i);
		}
	}
	Compress();
	s = scc[s];
	spfa();
	int ans = -100;
	for (int i = 1; i <= sc; i++) {
			ans = max(ans, d[i]);
	}
	printf("%d", ans);

	return 0;
}
void Tarjan(int u) {
	dfn[u] = low[u] = ++dfncnt;
	S.push(u);
	in_stack[u] = 1;
	for (int i = 0; i < G[u].size(); i++) {
		int v = G[u][i].v;
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
void Compress() {
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < G[i].size(); j++) {
			int v = G[i][j].v;
			if (scc[i] != scc[v]) {
				vertex.u= scc[v], vertex.w = G[i][j].w;
				DAG[scc[i]].push_back(vertex);
			}
			else {
				int sum = 0;
				do {
					sum += G[i][j].w;
					G[i][j].w *= G[i][j].e;
				} while (G[i][j].w != 0);
				sccw[scc[i]] += sum;
			}
		}
	}
}
void spfa() {
	for (int i = 1; i <= n; i++) d[i] = -0x7fffffff;
	d[s] = sccw[s];
	queue<node> q;
	q.push({ s, 0, d[s], 0.0 });
	while (!q.empty()) {
		node tmp = q.front();
		visited[tmp.u] = 0;
		for (int i = 0; i < DAG[tmp.u].size(); i++) {
			int vv = DAG[tmp.u][i].u;
			if (d[vv] < d[tmp.u] + DAG[tmp.u][i].w + sccw[vv]) {
				d[vv] = d[tmp.u] + DAG[tmp.u][i].w + sccw[vv];
				if (!visited[vv]) {
					visited[vv] = 1;
					q.push({ vv, 0, 0, 0 });
				}
			}
		}
		q.pop();
	}
}