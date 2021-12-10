#include <stdio.h>
#include <algorithm>
using namespace std;

const int maxn = 2e4 + 10, maxm = 1e5 + 10;

typedef struct Edge {
	int u, v, w;
}EDGE;
struct Set {
	int p, rank;
}set[maxn];

bool cmp(EDGE x, EDGE y) {
	return x.w > y.w;
}
void MakeSet();
int FindSet(int x);
void Union(int x, int y);
void LinkSet(int x, int y);

int N, M;
int enemy[maxn];
EDGE edge[maxm];

int main() {
	scanf("%d %d", &N, &M);
	MakeSet();
	for (int i = 1; i <= M; i++) {
		scanf("%d %d %d", &edge[i].u, &edge[i].v, &edge[i].w);
	}
	sort(edge + 1, edge + 1 + M, cmp);
	for (int i = 1; i <= M + 1; i++) {
		if (FindSet(edge[i].u) == FindSet(edge[i].v)) {
			printf("%d", edge[i].w);
			return 0;
		}
		else {
			if (enemy[edge[i].u] == 0) {
				enemy[edge[i].u] = edge[i].v;
			}
			else {
				Union(edge[i].v, enemy[edge[i].u]);
			}
			if (enemy[edge[i].v] == 0) {
				enemy[edge[i].v] = edge[i].u;
			}
			else {
				Union(edge[i].u, enemy[edge[i].v]);
			}
		}
	}

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