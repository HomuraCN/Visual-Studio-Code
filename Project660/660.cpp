#include <stdio.h>
#include <vector>
#include <string.h>
using namespace std;

bool find(int u);

const int maxn = 5e2 + 10;

int n, m, ans = 0;
int st[maxn], match[maxn];
vector<int> G[maxn];

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		int temp, v;
		scanf("%d", &temp);
		for (int j = 1; j <= temp; j++) {
			scanf("%d", &v);
			G[i].push_back(v);
		}
	}
	for (int i = 1; i <= n; i++) {
		memset(st, 0, sizeof(st));
		if (find(i)) {
			ans++;
		}
	}
	printf("%d\n", ans);

	return 0;
}
bool find(int u) {
	for (int i = 0; i < G[u].size(); i++) {
		int v = G[u][i];
		if (st[v] == 0) {
			st[v] = 1;
			if (match[v] == 0 || find(match[v])) {
				match[v] = u;
				return true;
			}
		}
	}
	return false;
}