#include <stdio.h>
#include <vector>
using namespace std;

void DFS(int u);

const int maxn = 1010;
int K, N, M, ans = 0, cow[110], visited[1010] = { 0 }, times[1010] = { 0 };
vector<int> G[maxn];

int main() {
	scanf("%d %d %d", &K, &N, &M);
	for (int i = 1; i <= K; i++) {
		scanf("%d", &cow[i]);
	}
	for (int i = 1; i <= M; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		G[u].push_back(v);
	}
	for (int i = 1; i <= K; i++) {
		for (int j = 1; j <= N; j++) {
			visited[j] = 0;
		}
		DFS(cow[i]);
	}
	for (int i = 1; i <= N; i++) {
		if (times[i] == K) {
			ans++;
		}
	}
	printf("%d", ans);

	return 0;
}
void DFS(int u) {
	times[u]++;
	visited[u] = 1;
	for (int i = 0; i < G[u].size(); i++) {
		int Next = G[u][i];
		if (visited[Next] == 0) {
			DFS(Next);
		}
	}
}