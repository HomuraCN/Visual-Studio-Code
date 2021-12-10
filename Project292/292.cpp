#include <stdio.h>

struct Set {
	int p, rank;
}set[10010];

void MakeSet();
int FindSet(int x);
void Union(int x, int y);
void LinkSet(int x, int y);

int N, M;

int main() {
	scanf("%d %d", &N, &M);
	MakeSet();
	for (int i = 1; i <= M; i++) {
		int X, Y, Z;
		scanf("%d %d %d", &Z, &X, &Y);
		if (Z == 1) {
			Union(X, Y);
		}
		else {
			if (FindSet(X) == FindSet(Y)) {
				printf("Y\n");
			}
			else {
				printf("N\n");
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