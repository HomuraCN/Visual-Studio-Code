#include <stdio.h>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
typedef pair<int, int>pii;
const int maxn = 100010;
int n, m, cnt = 1, V[maxn] = { 0 }, flag[maxn] = { 0 };
vector<int> G[maxn];
map<pii,int> M;

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		if (u == v) {
			continue;
		}
		if (M[{u, v}]++) {

		}
		G[u].push_back(v);
		G[v].push_back(u);
	}
	for (int i = 0; i < n; i++) {
		if (G[i].size() == 0) {
			continue;
		}
		sort(G[i].begin(), G[i].end());
		for (int j = 0; j < G[i].size(); j++) {
			if (G[i].size() == 1) {
				V[G[i][j]]++;
				continue;
			}
			if (j == G[i].size() - 1) {
				if (G[i][j] != G[i][j - 1]) {
					V[G[i][j]]++;
					break;
				}
				else {
					break;
				}
			}
			if (G[i][j] != G[i][j + 1]) {
				if (flag[G[i][j] == 1) {
					
				}
				V[G[i][j]]++;
			}
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