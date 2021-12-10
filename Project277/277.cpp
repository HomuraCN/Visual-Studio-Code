#include <stdio.h>
#include <vector>
#include <stdio.h>
using namespace std;

struct Vertex
{
	int u;
	char ch;
}vertex;

int flag = 0, n, m, u, v, visited[200010] = { 0 };
char op, k, ans[100010];
vector<Vertex> G[200010];

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; i++) {
		getchar();
		scanf("%c", &op);
		if (op == '+') {

			scanf("%d %d %c", &u, &vertex.u, &vertex.ch);
			G[u].push_back(vertex);
		}
		else if (op == '-') {
			scanf("%d %d", &u, &v);
			for (int j = 0; j < G[u].size(); j++) {
				if (G[u][j].u == v) {
					G[u].erase(G[u] + j * sizeof(Vertex));
				}
			}
		}
		else if (op == '?') {
			scanf("%d", &k);
			for (int i = 1; i <= n; i++) {
				flag = 0;
				DFS(i, 0);
				if (flag == 0) {
					printf("NO\n");
				}
			}
		}
	}

	return 0;
}
void DFS(int u, int cnt)
{
	if (cnt == 2 * (k + 1)) {
		printf("YES\n");
		flag = 1;
		return;
	}
	for (int i = 0; i < G[u].size(); i++) {
		if (visited[G[u][i].u] == 0) {
			visited[G[u][i].u] = 1;
			if (ans[cnt] != G[u][i].ch) {
				ans[cnt++] = G[u][i].ch;
			}
			else {
				return;
			}
			DFS(G[u][i].u, cnt + 1);
			visited[G[u][i].u] = 0;
		}
	}
}