#include <stdio.h>
#include <vector>
using namespace std;

const int maxn = 10010;
int c, n, m, d[maxn] = { 0 };
vector<int> G[maxn];

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	DFS(1, 0);/*������һ����ͨ�����޻�ͼ�У���������������ܵ������Զ��㣬һ���Ǹ�ͼֱ���Ķ˵�֮һ��*/
	d[c] = 0;
	DFS(c, 0);/*��һ��ֱ������һ��ֱ����Ϊ����ֱ����*/
	printf("%d", d[c]);

	return 0;
}
void DFS(int u, int from) {/*�����ԣ����ı�Ȩ����Ϊ�Ǹ�����*/
	for (int i = 0; i < G[u].size(); i++) {
		int v = G[u][i];
		if (v == from) {
			continue;
		}
		d[v] = d[u] + 1;
		if (d[v] > d[c]) {
			c = v;
		}
		DFS(v, u);
	}
}