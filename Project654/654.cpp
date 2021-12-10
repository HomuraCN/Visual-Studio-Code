#include <stdio.h>
#include <algorithm>
using namespace std;

const int maxn = 2e5 + 10;

typedef struct segmentTree {
	int l, r;
	int sum;
	int lmax, rmax;
	int tmax;
}SEGMENTTREE;

void pushup(SEGMENTTREE& u, SEGMENTTREE& l, SEGMENTTREE& r);
void pushup(int u);
void build(int u, int l, int r);
void modify(int u, int index, int delta);
SEGMENTTREE query(int u, int l, int r);

int n, a[maxn];
SEGMENTTREE st[maxn * 4];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	build(1, 1, n);
	printf("%d\n", query(1, 1, n).tmax);
}
void pushup(SEGMENTTREE &u, SEGMENTTREE &l, SEGMENTTREE &r) {
	u.sum = l.sum + r.sum;
	u.lmax = max(l.lmax, l.sum + r.lmax);
	u.rmax = max(r.rmax, r.sum + l.rmax);
	u.tmax = max(max(l.tmax, r.tmax), l.rmax + r.lmax);
}
void pushup(int u) {
	pushup(st[u], st[u * 2], st[u * 2 + 1]);
}
void build(int u, int l, int r) { 
	st[u].l = l, st[u].r = r;
	if (st[u].l == st[u].r) {
		st[u].sum = a[l];
		st[u].lmax = a[l];
		st[u].rmax = a[l];
		st[u].tmax = a[l];
	}
	else {
		int mid = (l + r) / 2;
		build(u * 2, l, mid);
		build(u * 2 + 1, mid + 1, r);
		pushup(u);
	}
}
void modify(int u, int index, int delta) {
	if (st[u].l == index && st[u].r == index) {
		st[u].sum = delta;
		st[u].lmax = delta;
		st[u].rmax = delta;
		st[u].tmax = delta;
	}
	else {
		int mid = (st[u].l + st[u].r) / 2;
		if (index <= mid) {
			modify(u * 2, index, delta);
		}
		else {
			modify(u * 2 + 1, index, delta);
		}
		pushup(u);
	}
}
 SEGMENTTREE query(int u, int l, int r) {
	if (st[u].l >= l && st[u].r <= r) {
		return st[u];
	}
	else {
		int mid = (st[u].l + st[u].r) / 2;
		if (r <= mid) {
			return query(u * 2, l, r);
		}
		else if (l > mid) {
			return query(u * 2 + 1, l, r);
		}
		else {
			SEGMENTTREE left = query(u * 2, l, r);
			SEGMENTTREE right = query(u * 2 + 1, l, r);
			SEGMENTTREE ans;
			pushup(ans, left, right);
			return ans;
		}
	}
}