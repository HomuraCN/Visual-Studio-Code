#include <stdio.h>
#include <algorithm>
using namespace std;

const int maxn = 1010, maxm = 10010;

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

int n, m, k, sum = 0, counter = 0;

int main()
{
	scanf("%d %d %d", &n, &m, &k);

	for (int i = 1; i <= m; i++) {
		scanf("%d %d %d", &edge[i].u, &edge[i].v, &edge[i].w);
	}
	MstKruskal();
	printf("%d", sum);

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
	sort(edge + 1, edge + 1 + m, cmp);
	for (int i = 1; i <= m; i++) {
		if (counter == n - k) {
			return;
		}
		if (FindSet(edge[i].u) != FindSet(edge[i].v)) {
			counter++;
			sum += edge[i].w;
			Union(edge[i].u, edge[i].v);
		}
	}
}