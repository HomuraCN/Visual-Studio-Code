#include <stdio.h>
#include <vector>
using namespace std;

const int maxn = 300010;
int n, m, x, asphalt[maxn];
vector<int> G[maxn];

int main() {
	scanf("%d %d %d", &n, &m, &x);
	for (int i = 1; i <= m; i++) {
		scanf("%d", &asphalt[i]);
	}
	for (int i = 1; i <= m; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		G[u].push_back(v);
		G[v].push_back(u);
	}

	return 0;
}