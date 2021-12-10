#include <stdio.h>
#include <vector>
#include <queue>
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
void Dijkstra();

const int maxn = 510;
int n, m, s, repairNumber, DIS, dis, pre[maxn], visited[maxn] = { 0 }, d[maxn], repair[maxn] = { 0 }, nex[maxn];
vector<Vertex> G[maxn];
std::priority_queue<Node> Q;

signed main()
{
	s = 1;
	scanf("%lld %lld %lld %lld", &n, &m, &repairNumber, &DIS);
	dis = DIS;
	for (int i = 1; i <= repairNumber; i++) {
		int temp;
		scanf("%lld", &temp);
		repair[temp] = 1;
	}
	for (int i = 1; i <= m; i++) {
		int u;
		scanf("%lld %lld %lld", &u, &vertex.u, &vertex.w);
		G[u].push_back(vertex);
	}
	Dijkstra();
	if (d[n] == 0x7fffffff) {
		printf("stuck");
	}
	else {
		printf("%lld", d[n]);
	}
	for (int i = 1; i < n; i++) {
		printf("%d", nex[i]);
	}

	return 0;
}
void InitialSingleSource()
{
	for (int i = 1; i <= n; i++) {
		d[i] = 2147483647;
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
			if (dis >= G[Now.u][i].w) {
				/*dis -= G[Now.u][i].w;*/
				if (repair[G[Now.u][i].u] == 1) {
					/*dis = DIS;*/
					Relax(Now.u, G[Now.u][i].u, G[Now.u][i].w);
				}
				else {
					Relax(Now.u, G[Now.u][i].u, G[Now.u][i].w);
				}
			}
			else {
				continue;
			}
		}
		for (int i = 0; i < G[Now.u].size(); i++) {
			if (nex[Now.u] == G[Now.u][i].u) {
				if (dis >= G[Now.u][i].w) {
					dis -= G[Now.u][i].w;
					if (repair[G[Now.u][i].u] == 1) {
						dis = DIS;
					}
				}
				break;
			}
		}
	}
}