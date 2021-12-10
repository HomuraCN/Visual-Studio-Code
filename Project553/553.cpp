#include <stdio.h>
#include <algorithm>
using namespace std;

const int maxn = 5010, maxm = 200010;

struct Set {
	int rank;
	int p;
}set[maxn];
struct Edge {
	int u, v, w;
}edge[maxm];

int GCD(int num1, int num2)
{
	if (num1 % num2 == 0)
		return num2;
	else return  GCD(num2, num1 % num2);
}
int LCM(int a, int b)
{
	int lcm;
	lcm = a * b / GCD(a, b);
	return lcm;
}

void MakeSet();
int FindSet(int x);
void Union(int x, int y);
void Link(int x, int y);
void MstKruskal();
bool cmp(Edge x, Edge y);

int n, t, sum = 0;

int main()
{
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (int i = 2; i <= n; i++) {
			for (int j = 2; j <= n; j++) {
				edge[(i - 2) * (n - 1) + (j - 1)].u = i;
				edge[(i - 2) * (n - 1) + (j - 1)].v = j;
				edge[(i - 2) * (n - 1) + (j - 1)].w = LCM(i, j);
			}
		}
		MstKruskal();
		printf("%d\n", sum);
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
	sort(edge + 1, edge + 1 + (n - 1) * (n - 1), cmp);
	for (int i = 1; i <= (n - 1) * (n - 1); i++) {
		if (FindSet(edge[i].u) != FindSet(edge[i].v)) {
			sum += edge[i].w;
			Union(edge[i].u, edge[i].v);
		}
	}
}