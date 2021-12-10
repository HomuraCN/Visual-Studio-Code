#include <stdio.h>
#include <vector>
#include <stack>
#include <queue>
#define LL long long
using namespace std;

typedef struct Edge {
	int v;
	int index;
}EDGE;

void DFS(int u);

const int maxn = 300010;
LL n, m, x, sum = 0, asphalt[maxn], flag[maxn] = { 0 };
vector<EDGE> G[maxn];
stack<int> S;
queue<int> Q;

int main() {
	scanf("%lld %lld %lld", &n, &m, &x);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &asphalt[i]);
		sum += asphalt[i];
	}
	for (int i = 1; i <= m; i++) {
		int u, v;
		EDGE edge;
		scanf("%lld %lld", &u, &v);
		edge.index = i;
		edge.v = v;
		G[u].push_back(edge);
		edge.v = u;
		G[v].push_back(edge);
	}
	if (sum < (n - 1) * x) {
		printf("NO\n");
		return 0;
	}
	else {
		printf("YES\n");
	}
	DFS(1);
	while (!Q.empty()) {
		printf("%d\n", Q.front());
		Q.pop();
	}
	while (!S.empty()) {
		printf("%d\n", S.top());
		S.pop();
	}

	return 0;
}
void DFS(int u) {
	flag[u] = 1;
	for (int i = 0; i < G[u].size(); i++) {
		EDGE edge = G[u][i];
		if (flag[edge.v] == 1) {
			continue;
		}
		DFS(edge.v);
		if (asphalt[u] + asphalt[edge.v] >= x) {
			asphalt[u] += asphalt[edge.v] - x;
			Q.push(edge.index);
		}
		else {
			S.push(edge.index);
		}
	}
}