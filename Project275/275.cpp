#include <stdio.h>
#include <queue>
#include <vector>
using namespace std;

void BFS();

int N, M, MOD = 100003, visited[1000010] = { 0 }, step[1000010] = { 0 }, cnt[1000010] = { 0 };
vector<int> G[1000010];
queue<int> Q;

int main()
{
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= M; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		if (u != v) {
			G[u].push_back(v);
			G[v].push_back(u);/*ÎÞÏòÍ¼*/
		}
	}
	BFS();
	for (int i = 1; i <= N; i++) {
		printf("%d\n", cnt[i]);
	}

	return 0;
}
void BFS()
{
	cnt[1] = 1;
	Q.push(1);
	visited[1] = 1;
	while (!Q.empty()) {
		int Now = Q.front();
		Q.pop();
		for (int i = 0; i < G[Now].size(); i++) {
			int Next = G[Now][i];
			if (visited[Next] == 0) {
				visited[Next] = 1;
				step[Next] = step[Now] + 1;
				cnt[Next] = (cnt[Next] + cnt[Now]) % MOD;
				Q.push(Next);
			}
			else if (visited[Next] == 1 && step[Next] == step[Now] + 1) {
				cnt[Next] = (cnt[Next] + cnt[Now]) % MOD;
			}
		}
		visited[Now] = 1;
	}
}