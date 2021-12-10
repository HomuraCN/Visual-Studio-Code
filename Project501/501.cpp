#include <stdio.h>
#include <vector>
using namespace std;

typedef struct Mineral {
	int start;
	int end;
	int type;
	int value;
}MINERAL;

const int maxm = 110, maxn = 10010, maxe = 15011;
int m, n, price[maxm], dp[maxe], lasttime = 0;
vector<MINERAL> mineral[maxe];
MINERAL mtemp;

int main() {
	scanf("%d %d", &m, &n);
	for (int i = 1; i <= m; i++) {
		scanf("%d", &price[i]);
	}
	for (int i = 1; i <= n; i++) {
		scanf("%d %d %d", &mtemp.start, &mtemp.end, &mtemp.type);
		mtemp.value = price[mtemp.type] * (mtemp.end - mtemp.start);
		mineral[mtemp.start].push_back(mtemp);
		lasttime = max(lasttime, mtemp.end);
	}
	for (int i = lasttime; i >= 1; i--) {
		dp[i] = dp[i + 1];
		if (mineral[i].size() != 0) {
			for (int j = 0; j < mineral[i].size(); j++) {
				dp[i] = max(dp[i], dp[mineral[i][j].end] + mineral[i][j].value);
			}
		}
	}
	printf("%d", dp[1]);

	return 0;
}