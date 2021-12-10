#include <stdio.h>

typedef struct Set {
	int rank;
	int p;
}SET;

void MakeSet();
int FindSet(int x);
void Union(int x, int y);
void Link(int x, int y);

int n, m, u, v;
SET set[5010];

int main()
{
	while (1) {
		int sum = 0;
		scanf("%d", &n);
		if (n == 0) {
			return 0;
		}
		scanf("%d", &m);
		MakeSet();
		for (int i = 1; i <= m; i++) {
			scanf("%d %d", &u, &v);
			Union(v, u);
		}
		for (int i = 1; i <= n; i++) {
			if (set[i].p == i) {
				sum++;
			}
		}
		printf("%d\n", sum - 1);
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