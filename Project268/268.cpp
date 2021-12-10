#include <stdio.h>
#include <queue>
#include <vector>
#define MOD 80112002
using namespace std;

void BFS();

int n, m, ans = 0, in[5010] = { 0 }, out[5010] = { 0 }, step[5010] = { 0 };
vector<int> G[5010];
queue<int> Q;

int main()
{
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= m; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		G[u].push_back(v);
		in[v]++;
		out[u]++;
	}
	for (int i = 1; i <= n; i++) {
		if (in[i] == 0) {
			step[i] = 1;
			Q.push(i);
		}
	}
	BFS();
	for (int i = 1; i <= n; i++) {
		if (out[i] == 0) {
			ans = (ans + step[i]) % MOD;
		}
	}

	printf("%d", ans);

	return 0;
}
void BFS()
{
	while (!Q.empty())
	{
		int Now = Q.front(), Next;
		Q.pop();
		for (int v = 0; v < G[Now].size(); v++) {
			Next = G[Now][v];
			in[Next]--;
			if (in[Next] == 0) {
				Q.push(Next);
			}
			step[Next] = (step[Next] + step[Now]) % MOD;
		}
	}
}