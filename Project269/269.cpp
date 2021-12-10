#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

int Max(int x, int y);
void BFS();

int n, ans = 0, temp, in[10010] = { 0 }, out[10010] = { 0 }, len[10010], dp[10010] = { 0 };
vector<int> G[10010];
queue<int> Q;

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d %d", &temp, &len[i]);
		scanf("%d", &temp);
		while (temp != 0) {
			G[temp].push_back(i);
			in[i]++;
			out[temp]++;
			scanf("%d", &temp);
		}
	}
	for (int i = 1; i <= n; i++) {
		if (in[i] == 0) {
			dp[i] = len[i];
			Q.push(i);
		}
	}
	BFS();
	for (int i = 1; i <= n; i++) {
		ans = Max(ans, dp[i]);
	}

	printf("%d", ans);

	return 0;
}
int Max(int x, int y)
{
	return x >= y ? x : y;
}
void BFS()
{
	while (!Q.empty()) {
		int Now = Q.front(),  Next;
		Q.pop();
		for (int v = 0; v < G[Now].size(); v++) {
			Next = G[Now][v];
			in[Next]--;
			if (in[Next] == 0) {
				Q.push(Next);
			}
			dp[Next] = Max(dp[Next], dp[Now] + len[Next]);
		}
	}
}