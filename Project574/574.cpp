#include <stdio.h>
#include <string.h>
#include <vector>
#define LL long long
using namespace std;

void DFS(int start, int u, int kindcnt);
LL F1(int i);
LL F2(int i);

const int maxn = 2e3 + 10, MOD1 = 1e9 + 7, MOD2 = 1e9 + 9;
int t, n;
LL xpow_n1[maxn], xpow_n2[maxn];
int A[maxn][maxn];
int type[maxn];
bool visited[maxn];
bool pathkind[maxn];
vector<int> gr[maxn];

int main() {
	xpow_n1[0] = xpow_n2[0] = 1;
	for (int i = 1; i <= 2000; i++) {
		xpow_n1[i] = (xpow_n1[i - 1] * 19560929) % MOD1;
		xpow_n2[i] = (xpow_n2[i - 1] * 19560929) % MOD2;
	}
	/*for (int i = 1; i <= 2000; i++) {
		printf("%lld\n", xpow_n2[i]);
	}*/
	scanf("%d", &t);
	while (t--) {
		for (int i = 1; i <= n; i++) {
			gr[i].clear();
		}
		scanf("%d", &n);
		for (int i = 2; i <= n; i++) {
			int v;
			scanf("%d", &v);
			gr[i].push_back(v);
			gr[v].push_back(i);
		}
		for (int i = 1; i <= n; i++) {
			scanf("%d", &type[i]);
		}
		for (int i = 1; i <= n; i++) {
			memset(visited, false, sizeof(visited));
			memset(pathkind, false, sizeof(pathkind));
			pathkind[type[i]] = true;
			DFS(i, i, 1);
		}
		/*for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				printf("%d", A[i][j]);
			}
			printf("\n");
		}*/
		for (int i = 1; i <= n; i++) {
			printf("%lld %lld\n", F1(i), F2(i));
		}
	}

	return 0;
}
void DFS(int start, int u, int kindcnt) {
	A[start][u] = kindcnt;
	visited[u] = 1;
	for (int i = 0; i < gr[u].size(); i++) {
		int v = gr[u][i];
		if (visited[v] == 0) {
			if (pathkind[type[v]] == false) {
				pathkind[type[v]] = true;
				DFS(start, v, kindcnt + 1);
				pathkind[type[v]] = false;
			}
			else {
				DFS(start, v, kindcnt);
			}
		}
	}
}
LL F1(int i) {
	LL ans = 0;
	for (int j = 1; j <= n; j++) {
		ans = (ans + (A[i][j] * xpow_n1[j - 1]) % MOD1) % MOD1;
	}
	return ans;
}
LL F2(int i) {
	LL ans = 0;
	for (int j = 1; j <= n; j++) {
		ans = (ans + (A[i][j] * xpow_n2[j - 1]) % MOD2) % MOD2;
	}
	return ans;
}