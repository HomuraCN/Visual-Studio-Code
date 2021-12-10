#include <stdio.h>
#include <algorithm>
#define LL long long
using namespace std;

typedef struct segmentTree {
	int l, r;
	int sum;
	int add, mul;
}SEGMENTTREE;

void pushup(int u);
void calculate(SEGMENTTREE& u, int add, int mul);
void pushdown(int u);
void build(int u, int l, int r);
void modify(int u, int l, int r, int add, int mul);
int query(int u, int l, int r);

const int maxn = 1e5 + 10;

int n, m, p, op, x, y, k;
int a[maxn];
SEGMENTTREE st[maxn * 4];

int main() {
	scanf("%d %d %d", &n, &m, &p);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	build(1, 1, n);
	while (m--) {
		scanf("%d", &op);
		if (op == 1) {
			scanf("%d %d %d", &x, &y, &k);
			modify(1, x, y, 0, k);
		}
		else if (op == 2) {
			scanf("%d %d %d", &x, &y, &k);
			modify(1, x, y, k, 1);
		}
		else if (op == 3) {
			scanf("%d %d", &x, &y);
			printf("%d\n", query(1, x, y));
		}
	}

	return 0;
}
void pushup(int u) {
	st[u].sum = (st[u * 2].sum + st[u * 2 + 1].sum) % p;
}
void calculate(SEGMENTTREE& u, int add, int mul) {
	u.sum = ((LL)u.sum * mul + (LL)(u.r - u.l + 1) * add) % p;
	u.mul = ((LL)u.mul * mul) % p;
	u.add = ((LL)u.add * mul + add) % p;
}
void pushdown(int u) {
	calculate(st[u * 2], st[u].add, st[u].mul);
	calculate(st[u * 2 + 1], st[u].add, st[u].mul);
	st[u].add = 0;
	st[u].mul = 1;
}
void build(int u, int l, int r) {
	st[u].l = l, st[u].r = r;
	if (l == r) {
		st[u].sum = a[l];
		st[u].add = 0;
		st[u].mul = 1;
	}
	else {
		st[u].sum = 0;
		st[u].add = 0;
		st[u].mul = 1;
		int mid = (l + r) / 2;
		build(u * 2, l, mid);
		build(u * 2 + 1, mid + 1, r);
		pushup(u);
	}
}
void modify(int u, int l, int r, int add, int mul) {
	if (st[u].l >= l && st[u].r <= r) {
		calculate(st[u], add, mul);
	}
	else {
		pushdown(u);
		int mid = (st[u].l + st[u].r) / 2;
		if (l <= mid) {
			modify(u * 2, l, r, add, mul);
		}
		if (r > mid) {
			modify(u * 2 + 1, l, r, add, mul);
		}
		pushup(u);
	}
}
int query(int u, int l, int r) {
	if (st[u].l >= l && st[u].r <= r) {
		return st[u].sum;
	}
	else {
		pushdown(u);
		int mid = (st[u].l + st[u].r) / 2;
		int temp = 0;
		if (l <= mid) {
			temp = query(u * 2, l, r);
		}
		if (r > mid) {
			temp = (temp + query(u * 2 + 1, l, r)) % p;
		}
		return temp;
	}
}