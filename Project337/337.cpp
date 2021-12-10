#include <stdio.h>
#include <map>
#include <algorithm>
using namespace std;

typedef pair<int, int> pii;

const int maxn = 100010;
int n, m, cnt = 1, V[maxn] = { 0 }, flag[maxn];
map<pii, int> MAP;

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		if (u == v) {
			continue;
		}
		if (MAP[{u, v}] == 0 && MAP[{v, u}] == 0) {
			V[u]++, V[v]++;
			MAP[{u, v}] = 1;
			MAP[{v, u}] = 0;
		}
	}
	sort(V, V + n);
	for (int i = 1; i < n; i++) {
		if (V[i] != V[i - 1]) {
			cnt++;
		}
	}
	printf("%d", cnt);

	return 0;
}