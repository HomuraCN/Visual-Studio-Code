#include <stdio.h>
#include <vector>
#include <algorithm>
#define LL long long
using namespace std;

const int maxn = 1e4 + 10, maxm = 5e4 + 10;

typedef struct Node {
	LL minn, l, r;
}NODE;
struct Set {
	int rank;
	int p;
}set[maxn];
struct Edge {
	int u, v, w;
}edge[maxm];
struct Vertex {
	int v, w;
}vertex;

void MakeSet();
int FindSet(int x);
void Union(int x, int y);
void Link(int x, int y);
void MstKruskal();
bool cmp(Edge x, Edge y);
LL query(int root, int L, int R);

int n, m, q, sum = 0;
int fa[maxn], depth[maxn], siz[maxn], son[maxn], top[maxn], dfn[maxn], rnk[maxn];
bool visited[maxn];
int cnt = 0;/*dfn*/
int a[maxn];
vector<Vertex> G[maxn];
NODE st[maxn * 4];

int main() {
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= m; i++) {
		scanf("%d %d %d", &edge[i].u, &edge[i].v, &edge[i].w);
	}
	MstKruskal();
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < G[i].size(); j++) {
			int u = i, v = G[i][j].v, w = G[i][j].w;
			if (depth[u] < depth[v]) {
				int temp;
				temp = u, u = v, v = temp;
			}
			a[dfn[u]] = w;
		}
	}
	scanf("%d", &q);
	for (int i = 1; i <= q; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		printf("%d\n", query(1, u, v));
	}

	return 0;
}
void MakeSet() {
	for (int i = 1; i <= n; i++) {
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
	Link(FindSet(set[x].p), FindSet(set[y].p));
}
void Link(int x, int y) {
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
bool cmp(Edge x, Edge y) {
	return x.w > y.w;
}
void MstKruskal() {
	MakeSet();
	sort(edge + 1, edge + 1 + m, cmp);
	for (int i = 1; i <= m; i++) {
		if (FindSet(edge[i].u) != FindSet(edge[i].v)) {
			sum += edge[i].w;
			Union(edge[i].u, edge[i].v);
			vertex.v = edge[i].v, vertex.w = edge[i].w;
			G[edge[i].u].push_back(vertex);
			vertex.v = edge[i].u;
			G[edge[i].v].push_back(vertex);
		}
	}
}
void DFS1(int u) {
	visited[u] = true;
	son[u] = -1;
	siz[u] = 1;
	for (int i = 0; i < G[u].size(); i++) {
		int v = G[u][i].v;
		if (visited[v] == true) {
			continue;
		}
		fa[v] = u;
		depth[v] = depth[u] + 1;
		DFS1(v);
		siz[u] += siz[v];
		if (son[u] == -1 || siz[v] > siz[son[u]]) {
			son[u] = v;
		}
	}
}
void DFS2(int u, int t) {
	visited[u] = true;
	top[u] = t;
	cnt++;
	dfn[u] = cnt;
	rnk[cnt] = u;
	if (son[u] == -1) {
		return;
	}
	DFS2(son[u], t);
	for (int i = 0; i < G[u].size(); i++) {
		int v = G[u][i].v;
		if (visited[v] == true) {
			continue;
		}
		DFS2(v, v);
	}
}
LL Min(LL x, LL y) {
	return x < y ? x : y;
}
void pushUp(int root) {
	st[root].minn = Min(st[root * 2].minn, st[root * 2 + 1].minn);
}
void buildTree(int root, int L, int R) {
	st[root].l = L, st[root].r = R;
	if (L == R) {
		st[root].minn = a[L];
	}
	else {
		int mid = (L + R) / 2;
		buildTree(root * 2, L, mid);
		buildTree(root * 2 + 1, mid + 1, R);
		pushUp(root);
	}
}
LL query(int root, int stdl, int stdr, int L, int R) {
	if (st[root].l >= L && st[root].r <= R) {
		return st[root].minn;
	}
	int ans = 0x7fffffff;
	int mid = (st[root].l + st[root].r) / 2;
	if (mid >= L) {
		ans = Min(ans, query(root * 2, L, R));
	}
	if (mid < R) {
		ans = Min(ans, query(root * 2 + 1, L, R));
	}
	return ans;
}