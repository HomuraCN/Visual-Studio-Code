#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct Time
{
	int u, t;
};

bool cmp(Time x, Time y);
void DFS(vector<int> Graph[], int u);

int N, M, time, cnt = 0, ans, visited[100010] = { 0 }, belong[100010], A[100010];
Time d[100010] = { 0 }, f[100010] = { 0 };
vector<int> G[100010], GT[100010];

int main()
{
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= M; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		G[u].push_back(v);
		GT[v].push_back(u);
	}
	time = 0;/*时间戳初始化*/
	for (int i = 1; i <= N; i++) {
		if (visited[i] == 0) {
			DFS(G, i);
		}
	}
	time = 0;
	for (int i = 1; i <= N; i++) {
		visited[i] = 0;
	}
	sort(f + 1, f + 1 + N, cmp);
	for (int i = 1; i <= N; i++) {
		if (visited[f[i].u] == 0)
		{
			ans = i;
			cnt++;
			belong[i] = cnt;
			DFS(GT, f[i].u);
			A[cnt] = ans;
		}
	}

	for (int i = 1; i <= N; i++) {
		printf("%d ", A[belong[i]]);
	}

	return 0;
}
int Max(int x, int y)
{
	return x >= y ? x : y;
}
bool cmp(Time x, Time y)
{
	return x.t >= y.t;
}
void DFS(vector<int> Graph[], int u)
{
	time++;
	d[u].t = time;
	d[u].u = u;
	visited[u] = 1;/*涂灰*/
	for (int v = 0; v < Graph[u].size(); v++) {
		if (visited[Graph[u][v]] == 0) {
			ans = Max(ans, Graph[u][v]);
			belong[Graph[u][v]] = cnt;
			DFS(Graph, Graph[u][v]);
		}
	}
	visited[u] = 1;/*涂黑*/
	time++;
	f[u].t = time;
	f[u].u = u;
}