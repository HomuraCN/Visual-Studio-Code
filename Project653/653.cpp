#include <stdio.h>
#include <algorithm>
using namespace std;

void build(int u, int l, int r);
void pushup(int u);
int query(int u, int l, int r);
void modify(int u, int index, int delta);

const int maxn = 2e5 + 10;

struct segmentTree {
	int l, r;
	int v;
}st[maxn * 4];

int n;
int a[maxn];

int main() {
	scanf("%d", &n);
	build(1, 1, n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		modify(1, i, a[i]);
	}
	for (int i = 1; i <= n; i++) {
		printf("%d\n", query(1, i, i));
	}

	return 0;
}
void build(int u, int l, int r) {
	st[u].l = l, st[u].r = r;
	if (l == r) {
		return;
	}
	else {
		int mid = (l + r) / 2;
		build(u * 2, l, mid);
		build(u * 2 + 1, mid + 1, r);
	}
}
void pushup(int u) {
	st[u].v = max(st[u * 2].v, st[u * 2 + 1].v);
}
int query(int u, int l, int r) {
	if (st[u].l >= l && st[u].r <= r) {
		return st[u].v;
	}
	else {
		int mid = (st[u].l + st[u].r) / 2;
		int temp = -0x7fffffff;
		if (l <= mid) {
			temp = query(u * 2, l, r);
		}
		if (r > mid) {
			temp = max(temp, query(u * 2 + 1, l, r));
		}
		return temp;
	}
}
void modify(int u, int index, int delta) {
	if (st[u].l == index && st[u].r == index) {
		st[u].v = delta;
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