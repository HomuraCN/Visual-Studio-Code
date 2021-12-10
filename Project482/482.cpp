#include <stdio.h>
#include <vector>
#include <string.h>
using namespace std;

typedef struct Mission {
	int start;
	int last;
	int end;
}MISSION;

const int maxn = 10010;
int n, k, dp[maxn];
MISSION m;
vector<int> mission[maxn];

int main() {
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= k; i++) {
		int p, t;
		scanf("%d %d", &p, &t);
		m.start = p;
		m.last = t;
		mission[m.start].push_back(m.last);
	}
	memset(dp, 0, sizeof(dp));
	for (int i = n; i >= 1; i--) {
		if (mission[i].size() == 0) {
			dp[i] = dp[i + 1] + 1;
		}
		else {
			for (int j = 0; j < mission[i].size(); j++) {
				dp[i] = max(dp[i], dp[i + mission[i][j]]);
			}
		}
	}
	printf("%d", dp[1]);

	return 0;
}