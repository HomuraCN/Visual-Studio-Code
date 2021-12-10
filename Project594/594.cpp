#include <stdio.h>
#include <algorithm>
using namespace std;

const int maxn = 1e3 + 10, maxm = 1e5 + 10;

typedef struct Edge {
	int u, v, t;
}EDGE;
struct Set {
	int p, rank;
}set[maxn];

void MakeSet();
int FindSet(int x);
void Union(int x, int y);
void LinkSet(int x, int y);
bool cmp(EDGE x, EDGE y) {
	return x.t < y.t;
}

int N, M, cnt;
EDGE edge[maxm];

int main() {
	scanf("%d %d", &N, &M);
	cnt = N;
	MakeSet();
	for (int i = 1; i <= M; i++) {
		scanf("%d %d %d", &edge[i].u, &edge[i].v, &edge[i].t);
	}
	sort(edge + 1, edge + 1 + M, cmp);
	for (int i = 1; i <= M; i++) {
		if (FindSet(edge[i].u) != FindSet(edge[i].v)) {
			Union(edge[i].u, edge[i].v);
			cnt--;
		}
		if (cnt == 1) {
			printf("%d\n", edge[i].t);
			return 0;
		}
	}
	printf("-1\n");

	return 0;
}
void MakeSet() {
	for (int i = 1; i <= N; i++) {
		set[i].p = i;
		set[i].rank = 0;
	}
}
int FindSet(int x) {
	if (x != set[x].p) {
		set[x].p = FindSet(set[x].p);
	}
	return set[x].p;
}
void Union(int x, int y) {
	LinkSet(FindSet(x), FindSet(y));
}
void LinkSet(int x, int y) {
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