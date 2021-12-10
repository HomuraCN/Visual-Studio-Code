#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;

const int maxn = 1010, maxm = 500550;

struct Set {
	int rank;
	int p;
}set[maxn];
struct Edge {
	int u, v;
	double w;
}edge[maxm];
struct Point {
	double x, y;
}point[maxn];

void MakeSet();
int FindSet(int x);
void Union(int x, int y);
void Link(int x, int y);
void MstKruskal();
bool cmp(Edge x, Edge y);
double Distance(double x1, double y1, double x2, double y2);
double Max(double x, double y);

int n, k, cnt = 0, counter = 0;
double ans = 0;

int main()
{
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; i++) {
		scanf("%lf %lf", &point[i].x, &point[i].y);
	}
	for (int i = 1; i <=n; i++) {
		for (int j = i + 1; j <= n; j++) {
			cnt++;
			edge[cnt].u = i, edge[cnt].v = j, edge[cnt].w = Distance(point[i].x, point[i].y, point[j].x, point[j].y);
		}
	}
	MstKruskal();

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
bool cmp(struct Edge x, struct Edge y) {
	return x.w < y.w;
}
void MstKruskal() {
	MakeSet();
	sort(edge + 1, edge + 1 + cnt, cmp);
	for (int i = 1; i <= cnt; i++) {
		if (FindSet(edge[i].u) != FindSet(edge[i].v)) {
			counter++;
			if (counter == n - k + 1) {
				printf("%.2lf", edge[i].w);
				return;
			}
			Union(edge[i].u, edge[i].v);
		}
	}
}
double Distance(double x1, double y1, double x2, double y2) {
	return sqrt(pow(abs(x1 - x2), 2) + pow(abs(y1 - y2), 2));
}
double Max(double x, double y) {
	return x >= y ? x : y;
}