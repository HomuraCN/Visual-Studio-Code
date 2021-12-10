#include <stdio.h>
#define LL long long

typedef struct node {
	LL v, XOR;
}NODE;

void buildTree(int root, int L, int R);
void pushDown(int root, int L, int R);
void updateXOR(int root, int stdl, int stdr, int L, int R);
LL query(int root, int stdl, int stdr, int L, int R);

const int maxn = 2e5 + 10;
int n, m, p = 0x7fffffff, a[maxn];
char str[maxn];
NODE st[maxn * 4];

int main() {
	scanf("%d %d", &n, &m);
	scanf("%s", str + 1);
	for (int i = 1; i <= n; i++) {
		a[i] = str[i] - '0';
	}
	buildTree(1, 1, n);
	while (m--) {
		int op;
		scanf("%d", &op);
		if (op == 0) {
			int l, r;
			scanf("%d %d", &l, &r);
			updateXOR(1, 1, n, l, r);
		}
		else {
			int l, r;
			scanf("%d %d", &l, &r);
			printf("%lld\n", query(1, 1, n, l, r));
		}
	}

	return 0;
}
void buildTree(int root, int L, int R) {
	st[root].XOR = 0;
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
	if (st[root].XOR ==	1) {
		int mid = (R + L) / 2;
		st[root * 2].v = (mid - L + 1) - st[root * 2].v;
		st[root * 2 + 1].v = (R - mid) - st[root * 2 + 1].v;

		st[root * 2].XOR ^= st[root].XOR;
		st[root * 2 + 1].XOR ^= st[root].XOR;

		st[root].XOR = 0;
		return;
	}
}
void updateXOR(int root, int stdl, int stdr, int L, int R) {
	if (R < stdl || L > stdr) {
		return;
	}
	if (L <= stdl && R >= stdr) {
		st[root].XOR ^= 1;
		st[root].v = (stdr - stdl + 1) - st[root].v;
		return;
	}
	pushDown(root, stdl, stdr);
	int mid = (stdl + stdr) / 2;
	updateXOR(root * 2, stdl, mid, L, R);
	updateXOR(root * 2 + 1, mid + 1, stdr, L, R);
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