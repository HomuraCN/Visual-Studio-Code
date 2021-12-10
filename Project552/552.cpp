#include <stdio.h>
#define LL long long

typedef struct node {
	LL v, add, mul;
}NODE;

void buildTree(int root, int L, int R);
void pushDown(int root, int L, int R);
void updatemul(int root, int stdl, int stdr, int L, int R, LL k);
void updateadd(int root, int stdl, int stdr, int L, int R, LL k);
LL query(int root, int stdl, int stdr, int L, int R);

const int maxn = 1e5;
int n, m, p, a[maxn];
NODE st[maxn * 4];

int main() {
	scanf("%d %d %d", &n, &m, &p);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
	}
	buildTree(1, 1, n);
	while (m--) {
		int temp;
		scanf("%d", &temp);
		if (temp == 1) {
			int x, y;
			LL k;
			scanf("%d %d %lld", &x, &y, &k);
			updatemul(1, 1, n, x, y, k);
		}
		else if (temp == 2) {
			int x, y;
			LL k;
			scanf("%d %d %lld", &x, &y, &k);
			updateadd(1, 1, n, x, y, k);
		}
		else {
			int x, y;
			scanf("%d %d", &x, &y);
			printf("%lld\n", query(1, 1, n, x, y));
		}
	}

	return 0;
}
void buildTree(int root, int L, int R) {
	st[root].add = 0;
	st[root].mul = 1;
	if (L == R) {
		st[root].v = a[L];
	}
	else {
		int mid = (L + R) / 2;
		buildTree(root * 2, L, mid);
		buildTree(root * 2 + 1, mid + 1, R);
		st[root].v = st[root * 2].v + st[root * 2 + 1].v;
	}
	st[root].v %= p;
	return;
}
void pushDown(int root, int L, int R) {
	int mid = (L + R) / 2;
	st[root * 2].v = (st[root * 2].v * st[root].mul + st[root].add * (mid - L + 1)) % p;
	st[root * 2 + 1].v = (st[root * 2 + 1].v * st[root].mul + st[root].add * (R - mid)) % p;
	
	st[root * 2].mul = (st[root * 2].mul * st[root].mul) % p;
	st[root * 2 + 1].mul = (st[root * 2 + 1].mul * st[root].mul) % p;
	st[root * 2].add = (st[root * 2].add * st[root].mul + st[root].add) % p;
	st[root * 2 + 1].add = (st[root * 2 + 1].add * st[root].mul + st[root].add) % p;

	st[root].add = 0;
	st[root].mul = 1;
	return;
}
void updatemul(int root, int stdl, int stdr, int L, int R, LL k) {
	if (R < stdl || L > stdr) {
		return;
	}
	if (L <= stdl && R >= stdr) {
		st[root].v = (st[root].v * k) % p;
		st[root].mul = (st[root].mul * k) % p;
		st[root].add = (st[root].add * k) % p;
		return;
	}
	pushDown(root, stdl, stdr);
	int mid = (stdl + stdr) / 2;
	updatemul(root * 2, stdl, mid, L, R, k);
	updatemul(root * 2 + 1, mid + 1, stdr, L, R, k);
	st[root].v = (st[root * 2].v + st[root * 2 + 1].v) % p;
	return;
}
void updateadd(int root, int stdl, int stdr, int L, int R, LL k) {
	if (R < stdl || L > stdr) {
		return;
	}
	if (L <= stdl && R >= stdr) {
		st[root].add = (st[root].add + k) % p;
		st[root].v = (st[root].v + k * (stdr - stdl + 1)) % p;
		return;
	}
	pushDown(root, stdl, stdr);
	int mid = (stdl + stdr) / 2;
	updateadd(root * 2, stdl, mid, L, R, k);
	updateadd(root * 2 + 1, mid + 1, stdr, L, R, k);
	st[root].v = (st[root * 2].v + st[root * 2 + 1].v) % p;
	return;
}
LL query(int root, int stdl, int stdr, int L, int R) {
	if (R < stdl || L > stdr) {
		return 0;
	}
	if (L <= stdl && R >= stdr) {
		return st[root].v;
	}
	pushDown(root, stdl, stdr);
	int mid = (stdl + stdr) / 2;
	return (query(root * 2, stdl, mid, L, R) + query(root * 2 + 1, mid + 1, stdr, L, R)) % p;
}