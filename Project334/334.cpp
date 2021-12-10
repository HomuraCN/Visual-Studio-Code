#include <stdio.h>
#include <vector>
using namespace std;

const int maxn = 510;
int m;
vector<int> G[maxn];

int main() {
	scanf("%d", &m);
	for (int i = 1; i <= m; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		G[u].push_back(v);
		G[v].push_back(u);
	}

	return 0;
}