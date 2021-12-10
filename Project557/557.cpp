#include <stdio.h>
#define LL long long

void buildTree(int root, int stdl, int stdr);
void pushDown(int root, int stdl, int stdr);
void updateChange(int root, int stdl, int stdr, int L, int R, int delta);
LL query(int root, int stdl, int stdr, int L, int R);
int euler(int n);

typedef struct Node {
	LL v, tag;
}NODE;

const int maxn = 3e5 + 10;
int t, n, m, p, a[maxn];
int l, r, x;
NODE st[maxn];

int main() {
	scanf("%d", &t);
	p = 1e9 + 7;
	while (t--) {
		scanf("%d %d", &n, &m);
		for (int i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
		}
		buildTree(1, 1, n);
		while (m--) {
			int op;
			scanf("%d", &op);
			if (op == 1) {
				scanf("%d %d", &l, &r);
				for (int i = l; i <= r; i++) {
					updateChange(1, 1, n, i, i, euler(a[i]));
				}
			}
			else if(op == 2){
				scanf("%d %d %d", &l, &r, &x);
				updateChange(1, 1, n, l, r, x);
			}
			else {
				scanf("%d %d", &l, &r);
				printf("%lld\n", query(1, 1, n, l, r));
			}
		}
	}

	return 0;
}
void buildTree(int root, int stdl, int stdr) {
	st[root].tag = 0;
	if (stdl == stdr) {
		st[root].v = a[stdl];
		st[root].v %= p;
		return;
	}
	int mid = (stdl + stdr) / 2;
	buildTree(root * 2, stdl, mid);
	buildTree(root * 2 + 1, mid + 1, stdr);
	st[root].v = st[root * 2].v + st[root * 2 + 1].v;
	st[root].v %= p;
	return;
}
void pushDown(int root, int stdl, int stdr) {
	int mid = (stdl + stdr) / 2;
	st[root * 2].v = (mid - stdl + 1) * st[root].tag;
	st[root * 2 + 1].v = (stdr - mid) * st[root].tag;

	st[root * 2].tag = st[root].tag;
	st[root * 2 + 1].tag = st[root].tag;

	st[root].tag = 0;
}
void updateChange(int root, int stdl, int stdr, int L, int R, int delta) {
	if (R < stdl || L > stdr) {
		return;
	}
	if (L <= stdl && R >= stdr) {
		st[root].v = (stdr - stdl + 1) * delta;
		st[root].tag = delta;
		return;
	}
	int mid = (stdl + stdr) / 2;
	pushDown(root, stdl, stdr);
	updateChange(root * 2, stdl, mid, L, R, delta);
	updateChange(root * 2 + 1, mid + 1, stdr, L, R, delta);
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
int euler(int n) {
	int res = n, a = n;
	for (int i = 2; i * i <= a; i++) {
		if (a % i == 0) {
			res = res / i * (i - 1);
			while (a % i == 0) a /= i;
		}
	}
	if (a > 1) res = res / a * (a - 1);
	return res;
}