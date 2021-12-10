#include <stdio.h>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;

typedef struct segmentTree {
	int l, r;
	int sum;
	int flag;
}SEGMENTTREE;

void DFS1(int u, int father, int depth);
void DFS2(int u, int t);
void pushup(int u);
void pushdown(int u);
void build(int u, int l, int r);
void modify(int u, int l, int r, int flag);
int query(int u, int l, int r);
void modify_path(int u, int v, int flag);
int query_path(int u, int v);
void modify_tree(int u, int flag);
int query_tree(int u);

const int maxn = 1e5 + 10;
int n, q, x, cnt = 0;
int a[maxn], newa[maxn];
int sz[maxn], dep[maxn], fa[maxn], top[maxn], son[maxn], id[maxn];
char op[15];
vector<int> G[maxn];
SEGMENTTREE st[maxn * 4];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n - 1; i++) {
		int u;
		scanf("%d", &u);
		u++;
		G[u].push_back(i + 1);
	}
	DFS1(1, -1, 1);
	DFS2(1, 1);
	build(1, 1, n);
	scanf("%d", &q);
	while (q--) {
		scanf("%s %d", op, &x);
		x++;
		if (!strcmp(op, "install")) {
			int t = query(1, 1, n);
			modify_path(1, x, 1);
			printf("%d\n", st[1].sum - t);
		}
		else
		{
			int t = query(1, 1, n);
			modify_tree(x, 0);
			printf("%d\n", t - st[1].sum);
		}
	}
	
	return 0;
}
void DFS1(int u, int father, int depth) {
	dep[u] = depth, sz[u] = 1, fa[u] = father;
	for (int i = 0; i < G[u].size(); i++) {
		int v = G[u][i];
		if (v == father) {
			continue;
		}
		DFS1(v, u, depth + 1);
		sz[u] += sz[v];
		if (sz[son[u]] < sz[v]) {
			son[u] = v;
		}
	}
}
void DFS2(int u, int t) {
	cnt++;
	id[u] = cnt, top[u] = t, newa[cnt] = a[u];
	if (son[u] == 0) {
		return;
	}
	DFS2(son[u], t);
	for (int i = 0; i < G[u].size(); i++) {
		int v = G[u][i];
		if (v == fa[u] || v == son[u]) {
			continue;
		}
		DFS2(v, v);
	}
}
void pushup(int u) {
	st[u].sum = (st[u * 2].sum + st[u * 2 + 1].sum);
}
void pushdown(int u) {
	if (st[u].flag != -1) {
		st[u * 2].sum = (st[u * 2].r - st[u * 2].l + 1) * st[u].flag;
		st[u * 2 + 1].sum = (st[u * 2 + 1].r - st[u * 2 + 1].l + 1) * st[u].flag;
		st[u * 2].flag = st[u].flag;
		st[u * 2 + 1].flag = st[u].flag;
		st[u].flag = -1;
	}
}
void build(int u, int l, int r) {
	st[u].l = l, st[u].r = r, st[u].flag = -1;
	if (l == r) {
		st[u].sum = newa[l];
		return;
	}
	int mid = (l + r) / 2;
	build(u * 2, l, mid);
	build(u * 2 + 1, mid + 1, r);
	pushup(u);
}
void modify(int u, int l, int r, int flag) {
	if (st[u].l >= l && st[u].r <= r) {
		st[u].sum = (st[u].r - st[u].l + 1) * flag;
		st[u].flag = flag;
		return;
	}
	else {
		pushdown(u);
		int mid = (st[u].l + st[u].r) / 2;
		if (l <= mid) {
			modify(u * 2, l, r, flag);
		}
		if (r > mid) {
			modify(u * 2 + 1, l, r, flag);
		}
		pushup(u);
	}
}
int query(int u, int l, int r) {
	if (st[u].l >= l && st[u].r <= r) {
		return st[u].sum;
	}
	pushdown(u);
	int mid = (st[u].l + st[u].r) / 2;
	int temp = 0;
	if (l <= mid) {
		temp = (temp + query(u * 2, l, r));
	}
	if (r > mid) {
		temp = (temp + query(u * 2 + 1, l, r));
	}
	return temp;
}
void modify_path(int u, int v, int flag) {
	while (top[u] != top[v]) {
		if (dep[top[u]] < dep[top[v]]) {
			swap(u, v);
		}
		modify(1, id[top[u]], id[u], flag);
		u = fa[top[u]];
	}
	if (dep[u] < dep[v]) {
		swap(u, v);
	}
	modify(1, id[v], id[u], flag);
}
int query_path(int u, int v) {
	int temp = 0;
	while (top[u] != top[v]) {
		if (dep[top[u]] < dep[top[v]]) {
			swap(u, v);
		}
		temp = (temp + query(1, id[top[u]], id[u]));
		u = fa[top[u]];
	}
	if (dep[u] < dep[v]) {
		swap(u, v);
	}
	temp = (temp + query(1, id[v], id[u]));
	return temp;
}
void modify_tree(int u, int flag) {
	modify(1, id[u], id[u] + sz[u] - 1, flag);
}
int query_tree(int u) {
	return query(1, id[u], id[u] + sz[u] - 1);
}