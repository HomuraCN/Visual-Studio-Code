#include <stdio.h>
#include <string.h>
#include <queue>
#include <vector>
using namespace std;

const int maxn = 1e3 + 10;
int n, m;
int isstop[maxn], stopcnt = 0, stopstation[maxn], haslinked[maxn][maxn];
int indegree[maxn];
int step[maxn];
queue<int> Q;
vector<int> G[maxn];

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; i++) {
		stopcnt = 0;
		memset(isstop, 0, sizeof(isstop));
		int tempnum;
		scanf("%d", &tempnum);
		for (int j = 1; j <= tempnum; j++) {
			int temp;
			scanf("%d", &temp);
			stopstation[++stopcnt] = temp;
			isstop[temp] = 1;
		}
		for (int i = stopstation[1]; i <= stopstation[stopcnt]; i++) {
			if (isstop[i] == 0) {
				for (int j = 1; j <= stopcnt; j++) {
					if (haslinked[i][stopstation[j]] == 0) {
						G[i].push_back(stopstation[j]);
						haslinked[i][stopstation[j]] = 1;
						indegree[stopstation[j]]++;
					}
				}
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		if (indegree[i] == 0) {
			Q.push(i);
			step[i] = 1;
		}
	}
	while (!Q.empty()) {
		int u = Q.front();
		Q.pop();
		for (int i = 0; i < G[u].size(); i++) {
			int v = G[u][i];
			indegree[v]--;
			step[v] = step[u] + 1;
			if (indegree[v] == 0) {
				Q.push(v);
			}
		}
	}
	int maxx = 0;
	for (int i = 1; i <= n; i++) {
		maxx = max(maxx, step[i]);
	}
	printf("%d", maxx);

	return 0;
}