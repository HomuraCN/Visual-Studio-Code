#include <stdio.h>
#include <algorithm>
using namespace std;

typedef struct Query {
	int l, r;
	int index;
}QUERY;

int lowBit(int x);
void add(int num[], int x, int delta);
int getPreSum(int num[], int x);
bool cmp(QUERY x, QUERY y) {
	return x.r < y.r;
}

const int maxn = 1e6 + 10;
int n, m, s, a[maxn], ac[maxn];
int pos[maxn];
int ans[maxn];
QUERY query[maxn];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	scanf("%d", &m);
	for (int i = 1; i <= m; i++) {
		scanf("%d %d", &query[i].l, &query[i].r);
		query[i].index = i;
	}
	sort(query + 1, query + 1 + m, cmp);
	s = 1;
	for (int i = 1; i <= m; i++) {
		for (int j = s; j <= query[i].r; j++) {
			if (pos[a[j]] != 0) {
				add(ac, pos[a[j]], -1);
			}
			add(ac, j, 1);
			pos[a[j]] = j;
		}
		s = query[i].r + 1;
		ans[query[i].index] = getPreSum(ac, query[i].r) - getPreSum(ac, query[i].l - 1);
	}
	for (int i = 1; i <= m; i++) {
		printf("%d\n", ans[i]);
	}

	return 0;
}
int lowBit(int x) {
	return x & -x;
}
void add(int num[], int x, int delta) {
	while (x <= n) {
		num[x] += delta;
		x += lowBit(x);
	}
}
int getPreSum(int num[], int x) {
	int sum = 0;
	while (x >= 1) {
		sum += num[x];
		x -= lowBit(x);
	}
	return sum;
}