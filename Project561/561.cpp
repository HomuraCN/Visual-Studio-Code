#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stack>
#include <vector>
using namespace std;

void DFS(int u);

const int maxn = 1e5 + 10;
int n, q, op, a, b, x, flag, value[maxn], visited[maxn];
vector<int> G[maxn];
stack<int> S;

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n - 1; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	scanf("%d", &q);
	while (q--) {
		flag = 0;
		scanf("%d", &op);
		if (op == 1) {
			memset(visited, 0, sizeof(visited));
			scanf("%d %d", &a, &b);
			S.push(a);
			DFS(a);
			int cnt = S.size();
			while (!S.empty()) {
				int temp = S.top();
				S.pop();
				value[temp] += pow(cnt--, 2);
			}
		}
		else {
			scanf("%d", &x);
			printf("%d\n", value[x]);
		}
	}

	return 0;
}
void DFS(int u) {
	visited[u] = 1;
	if (u == b) {
		flag = 1;
		return;
	}
	for (int i = 0; i < G[u].size(); i++) {
		int v = G[u][i];
		if (visited[v] == 1) {
			continue;
		}
		if (flag == 0) {
			S.push(v);
			DFS(v);
		}
	}
}