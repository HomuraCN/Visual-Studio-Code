#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
#define int long long
using namespace std;

struct Vertex
{
	int u;
	int w;
}vertex;
struct Node
{
	int u;
	int d;/*key*/
	bool operator <(const Node& x)const
	{
		return x.d < d;
	}
}node, Now;

void InitialSingleSource();
void Relax(int u, int v, int w);
void FloydWarshall(int k);
int Min(int x, int y);
void Dijkstra();

const int maxn = 510;
int n, m, s, k = 1, repairNumber, DIS, dis, pre[maxn], visited[maxn] = { 0 }, d[maxn], repair[maxn] = { 0 }, nex[maxn], W[maxn][maxn];
vector<Vertex> G[maxn];
std::priority_queue<Node> Q;

signed main()
{
	s = 1;
	scanf("%lld %lld %lld %lld", &n, &m, &repairNumber, &DIS);
	dis = DIS;
	for (int i = 1; i <= repairNumber; i++) {
		scanf("%lld", &repair[i]);
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			W[i][j] = 0x3f3f3f3f3f;
		}
	}
	for (int i = 1; i <= m; i++) {
		int u;
		scanf("%lld %lld %lld", &u, &vertex.u, &vertex.w);
		W[u][vertex.u] = vertex.w;
		W[vertex.u][u] = vertex.w;
	}
	while (k <= n) {
		FloydWarshall(k);
		k++;
	}
	if (W[1][n] == 0x3f3f3f3f3f)
	{
		printf("stuck");
		return 0;
	}
	repair[repairNumber + 1] = 1, repair[repairNumber + 2] = n;
	repairNumber += 2;
	sort(repair + 1, repair + 1 + repairNumber);
	for (int i = 1; i <= repairNumber; i++) {
		for (int j = 1; j <= repairNumber; j++) {
			if (W[repair[i]][repair[j]] != 0x3f3f3f3f3f) {
				W[repair[i]][repair[j]] = 0x3f3f3f3f3f;
			}
		}
	}
	for (int i = 1; i <= repairNumber; i++) {
		for (int j = 1; j <= repairNumber; j++) {
			if (W[repair[i]][repair[j]] != 0x3f3f3f3f3f) {
				vertex.u = repair[j], vertex.w = W[repair[i]][repair[j]];
				G[repair[i]].push_back(vertex);
			}
		}
	}
	Dijkstra();
	if (d[n] == 0x3f3f3f3f3f) {
		printf("stuck");
	}
	else {
		printf("%lld", d[n]);
	}

	return 0;
}
void InitialSingleSource()
{
	for (int i = 1; i <= n; i++) {
		d[i] = 0x3f3f3f3f3f;
		pre[i] = 0;
	}
	d[s] = 0;
	nex[s] = 0;
}
void Relax(int u, int v, int w)
{
	if (d[v] > d[u] + w)
	{
		d[v] = d[u] + w;
		if (visited[v] == 0)
		{
			node.u = v, node.d = d[v];
			Q.push(node);
		}
		pre[v] = u;
		nex[u] = v;
	}
}
void FloydWarshall(int k) {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			W[i][j] = Min(W[i][j], W[i][k] + W[k][j]);
		}
	}
}
int Min(int x, int y) {
	return x <= y ? x : y;
}
void Dijkstra()
{
	InitialSingleSource();
	node.u = s, node.d = 0;
	Q.push(node);
	while (!Q.empty()) {
		Now = Q.top();
		Q.pop();
		if (visited[Now.u] == 1)
			continue;
		visited[Now.u] = 1;
		for (int i = 0; i < G[Now.u].size(); i++) {
			Relax(Now.u, G[Now.u][i].u, G[Now.u][i].w);
		}
	}
}