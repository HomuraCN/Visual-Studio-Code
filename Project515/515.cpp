#include <stdio.h>
#include <string.h>
#include <vector>
#include <math.h>
using namespace std;

typedef struct Edge {
	int v;
};

void DFS(int u, int last);

const int maxn = 100010;
int t, n, sum = 0, weightL[maxn], weightR[maxn], flag[maxn];
vector<int> G[maxn];

int main() {
	scanf("%d", &t);
	while (t--) {
		sum = 0;
		memset(flag, 0, sizeof(flag));
		scanf("%d", &n);
		for (int i = 1; i <= maxn; i++) {
			G[i].clear();
		}
		for (int i = 1; i <= n; i++) {
			scanf("%d %d", &weightL[i], &weightR[i]);
		}
		for (int i = 1; i <= n - 1; i++) {
			int u, v;
			scanf("%d %d", &u, &v);
			G[u].push_back(v);
			G[v].push_back(u);
		}
		DFS(1, 0);
		printf("%d\n", sum);
	}

	return 0;
}
void DFS(int u, int last) {
	int choose;
	flag[u] = 1;
	if (u != 1) {
		if (abs(last - weightL[u]) > abs(last - weightR[u])) {
			choose = weightL[u];
		}
		else {
			choose = weightR[u];
		}
		sum += abs(last - choose);
	}
	else {
		choose = max(  max( abs(weightL[u] - weightL[G[u][0]]), abs(weightL[u] - weightR[G[u][0]]) ), max( abs(weightR[u] - weightL[G[u][0]]) , abs(weightR[0] - weightR[G[u][0]]) ) );
	}
	for (int i = 0; i < G[u].size(); i++) {
		int next = G[u][i];
		if (flag[next] == 0) {
			DFS(next, choose);
		}
	}
}