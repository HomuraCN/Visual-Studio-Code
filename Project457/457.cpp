#include <stdio.h>
#include <map>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

void DFS(int u);		/*欧拉路径*/

const int maxn = 510;
int n, m, start = 0x7fffffff, degree[maxn] = { 0 };		/*记录无向图中每个顶点的度数*/
vector<int> G[maxn];		/*存储图*/
stack<int> S;	/*存储路径*/
map<pair<int, int>, int> M;	/*存储某条边的数量*/

int main() {
	scanf("%d", &m);
	for (int i = 1; i <= m; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		n = max(max(n, u), v);		/*寻找最大结点*/
		start = min(min(start, u), v);	/*寻找最小结点*/
		G[u].push_back(v), G[v].push_back(u);
		degree[u]++, degree[v]++;
		M[{u, v}]++;
		M[{v, u}]++;
	}
	for (int i = 1; i <= n; i++) {
		sort(G[i].begin(), G[i].end());	/*由于要按照字典序输出，所以升序排列*/
	}

	int flag = 0;		/*判断是否是欧拉回路*/
	for (int i = start; i <= n; i++) {
		if (degree[i] % 2 == 0) {
			continue;
		}
		else {
			flag = 1;
			break;
		}
	}

	if (flag == 0) {
		DFS(start);
	}
	else {
		for (int i = start; i <= n; i++) {
			if (degree[i] % 2 == 1) {
				DFS(i);
				break;
			}
		}
	}
	while (!S.empty()) {
		printf("%d\n", S.top());
		S.pop();
	}

	return 0;
}
void DFS(int u) {
	for (int i = 0; i < G[u].size(); i++) {
		int v = G[u][i];
		if (M[{u, v}] > 0) {
			M[{u, v}]--;
			M[{v, u}]--;
			DFS(v);
		}
	}
	S.push(u);
}