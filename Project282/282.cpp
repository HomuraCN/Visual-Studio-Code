#include <stdio.h>
#include <stack>/*Tarjian*/
#include <queue>/*Topo*/
#include <vector>/*Graph*/
using namespace std;

int Min(int x, int y);
int Max(int x, int y);
void Tarjian(int x);
void Topo();

int n, m, time = 0/*时间戳*/, total = 0/*强连通分量编号*/, cnt = 0, w[10010], step[10010], in[10010] = { 0 }, out[10010] = { 0 }, dfn[10010] = { 0 }, low[10010], visited[10010] = { 0 }, order[10010], W[10010] = { 0 }/*每个强连通分量的权值*/, ans[10010], dp[10010];
vector<int> G[10010], GSCC[10010], rdr[10010];
queue<int> Q;
stack<int> S;

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &w[i]);
	}
	for (int i = 1; i <= m; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		G[u].push_back(v);
	}

	for (int i = 1; i <= n; i++) {
		if (dfn[i] == 0) {
			Tarjian(i);
		}
	}
	for (int i = 1; i <= total; i++) {/*强连通分量图*/
		if (G[i].size() != 0 && order[i] != order[G[i][0]]) {
			GSCC[i].push_back(G[i][0]);
			in[G[i][0]]++;
			rdr[G[i][0]].push_back(i);
		}
	}
	Topo();
	for (int i = 1; i <= total; i++)
	{
		dp[ans[i]] = W[ans[i]];
		for (int j = 0; j < rdr[ans[i]].size(); j++) {
			dp[ans[i]] = Max(dp[ans[i]], dp[rdr[ans[i]][j]] + W[ans[i]]);
		}
	}
	int temp = 0;
	for (int i = 1; i <= total; i++) {
		temp = Max(temp, dp[i]);
	}
	printf("%d", temp);

	return 0;
}
void Tarjian(int x) {
	time++;
	dfn[x] = time, low[x] = time;
	S.push(x);
	visited[x] = 1;/*表明x在栈内*/
	for (int i = 0; i < G[x].size(); i++) {
		int Next = G[x][i];
		if (dfn[Next] == 0) {/*如果Next不在栈中?*/
			Tarjian(Next);
			low[x] = Min(low[x], low[Next]);
		}
		else if (visited[Next] == 1) {
			low[x] = Min(low[x], dfn[Next]);
		}
	}
	if (low[x] == dfn[x]) {
		total++;
		int TOP;
		do {
			TOP = S.top();
			S.pop();
			visited[TOP] = 0;/*将刚刚的栈顶元素从栈中移除*/
			order[TOP] = total;/*标记TOP在第几个强连通分量内*/
			W[total] += w[TOP];
		} while (TOP != x);
	}
}
void Topo() {
	for (int i = 1; i <= total; i++) {
		if (in[i] == 0) {
			step[i] = 1;
			Q.push(i);
		}
	}
	while (!Q.empty()) {
		int Now = Q.front();
		Q.pop();
		cnt++;
		ans[cnt] = Now;
		for (int i = 0; i < G[Now].size(); i++) {
			int Next = G[Now][i];
			in[Next]--;
			if (in[Next] == 0) {
				Q.push(Next);
			}
			step[Next] += step[Now];
		}
	}
}
int Min(int x, int y) {
	return x <= y ? x : y;
}
int Max(int x, int y) {
	return x >= y ? x : y;
}