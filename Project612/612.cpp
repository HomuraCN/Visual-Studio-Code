#include <stdio.h>
#include <math.h>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn = 1e3 + 10, maxm = 200010;

struct City {
	int x, y, p;
}city[maxn];
struct Set {
	int rank, p;
}set[maxn];
struct Edge {
	int u, v;
	double w;
}edge[maxm], edge_select[maxn];

void MakeSet();
int FindSet(int x);
void Union(int x, int y);
void Link(int x, int y);
void MstKruskal();
bool cmp(Edge x, Edge y);
double distance(int x1, int y1, int x2, int y2) {
	return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}
void DFS(int u);

int t, n, m, edge_cnt, sum = 0;
bool visited[maxn];
int A, B;
int maxx;
double ans;
vector<int> G[maxn];

int main() {
	scanf("%d", &t);
	while (t--) {
		memset(visited, false, sizeof(visited));
		m = 0, edge_cnt = 0, ans = 0;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			scanf("%d %d %d", &city[i].x, &city[i].y, &city[i].p);
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (i == j) {
					continue;
				}
				edge[++m].u = i, edge[m].v = j, edge[m].w = distance(city[i].x, city[i].y, city[j].x, city[j].y);
			}
		}
		MstKruskal();
		for (int i = 1; i <= edge_cnt; i++) {
			A = 0;
			B = sum - edge_select[i].w;
			visited[edge_select[i].v] = true;
			maxx = 0;
			DFS(edge_select[i].u);
			A += maxx;
			maxx = 0;
			DFS(edge_select[i].v);
			A += maxx;
			ans = max(ans, 1.0 * A / 1.0 * B);
		}
		printf("%lf\n", ans);
	}

	return 0;
}
void MakeSet()
{
	for (int i = 1; i <= n; i++) {
		set[i].p = i;
		set[i].rank = 0;
	}
}
int FindSet(int x)
{
	if (x != set[x].p) {
		set[x].p = FindSet(set[x].p);
	}
	return set[x].p;
}
void Union(int x, int y)
{
	Link(FindSet(set[x].p), FindSet(set[y].p));
}
void Link(int x, int y)/*°´ÖÈºÏ²¢*/
{
	if (set[x].rank > set[y].rank) {
		set[y].p = x;
	}
	else {
		set[x].p = y;
		if (set[x].rank == set[y].rank) {
			set[y].rank++;
		}
	}
}
bool cmp(Edge x, Edge y) {
	return x.w < y.w;
}
void MstKruskal() {
	MakeSet();
	sort(edge + 1, edge + 1 + m, cmp);
	for (int i = 1; i <= m; i++) {
		if (FindSet(edge[i].u) != FindSet(edge[i].v)) {
			edge_select[++edge_cnt].u = edge[i].u, edge_select[edge_cnt].v = edge[i].v, edge_select[edge_cnt].w = edge[i].w;
			G[edge[i].u].push_back(edge[i].v);
			G[edge[i].v].push_back(edge[i].u);
			sum += edge[i].w;
			Union(edge[i].u, edge[i].v);
		}
	}
}
void DFS(int u) {
	visited[u] = true;
	for (int i = 0; i < G[u].size(); i++) {
		int v = G[u][i];
		if (visited[v] == true) {
			continue;
		}
		maxx = max(maxx, city[v].p);
		DFS(v);
	}
}