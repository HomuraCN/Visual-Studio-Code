#include <stdio.h>
#include <math.h>
#include <algorithm>
#define LL long long
using namespace std;

const int maxn = 5e3 + 10, maxm = 5000 * 5000;

typedef struct Point {
	double x, y;
}POINT;
struct Set {
	int rank;
	int p;
}set[maxn];
struct Edge {
	int u, v, w;
}edge[maxm];

void MakeSet();
int FindSet(int x);
void Union(int x, int y);
void Link(int x, int y);
void MstKruskal();
bool cmp(Edge x, Edge y);
LL Distance(int x1, int y1, int x2, int y2) {
	return pow(x1 - x2, 2) + pow(y1 - y2, 2);
}

int n, sum = 0, edge_cnt = 0, ans = 0, t;
POINT point[maxn];

int main() {
	scanf("%d", &t);
	while (t--) {
		edge_cnt = 0;
		ans = 0;
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%lf %lf", &point[i].x, &point[i].y);
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (i == j) {
					continue;
				}
				edge[++edge_cnt].u = i;
				edge[edge_cnt].v = j;
				edge[edge_cnt].w = Distance(point[i].x, point[i].y, point[j].x, point[j].y);
			}
		}
		MstKruskal();
		printf("%d\n", ans);
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
	sort(edge + 1, edge + 1 + edge_cnt, cmp);
	for (int i = 1; i <= edge_cnt; i++) {
		if (FindSet(edge[i].u) != FindSet(edge[i].v)) {
			ans = max(edge[i].w, ans);
			sum += edge[i].w;
			Union(edge[i].u, edge[i].v);
		}
	}
}