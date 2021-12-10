#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

void DFS(int currentpos, int selectcnt);

const int maxn = 22;
int n, m, ans = 0;
int a[maxn];
bool visited[maxn], dp[2021];

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	DFS(1, 0);
	printf("%d", ans);

	return 0;
}
void DFS(int currentpos, int selectcnt) {
	//剪枝1
	if (selectcnt > n - m) {
		return;
	}
	if (selectcnt == n - m) {
		ans = 0;
		memset(dp, false, sizeof(dp));
		//dp[i][j]: 前i个砝码，能不能称量出质量j
		//dp[i][0] = true
		for (int i = 1; i <= n; i++) {
			if (visited[i] == false) {
				continue;
			}
			dp[0] = true;
			for (int j = 100 * n; j >= a[i]; j--) {
				dp[j] = dp[j - a[i]] || dp[j];
			}
		}
		int cnt = 0;
		for (int i = 1; i <= 100 * n; i++) {
			if (dp[i] == true) {
				cnt++;
			}
		}
		ans = max(ans, cnt);
	}
	if (currentpos == n) {
		return;
	}
	//选pos
	visited[currentpos] = true;
	DFS(currentpos + 1, selectcnt + 1);
	//不选pos
	visited[currentpos] = false;
	DFS(currentpos + 1, selectcnt);
}