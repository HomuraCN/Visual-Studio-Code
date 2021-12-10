#include <stdio.h>
#include <vector>
#define LL long long
using namespace std;

void mergeDp(int i, int j);
LL Max(LL x, LL y);

const int maxn = 1e2 + 10;
int T, n;
LL a[maxn][maxn], b[maxn][maxn];
vector<pair<LL, LL>> dp[maxn][maxn];

int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				scanf("%lld", &a[i][j]);
			}
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				scanf("%lld", &b[i][j]);
			}
		}
		/*T�����ݣ����vector*/
		for (int i = 0; i <= n; i++) {
			for (int j = 0; j <= n; j++) {
				dp[i][j].clear();
			}
		}
		dp[1][1].push_back(make_pair(a[1][1], b[1][1]));
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (i == 1 && j == 1) {
					continue;
				}
				else if (i == 1) {
					for (int k = 0; k < dp[i][j - 1].size(); k++) {
						dp[i][j].push_back(dp[i][j - 1][k]);
						dp[i][j][k].first += a[i][j];
						dp[i][j][k].second += b[i][j];
					}
				}
				else if (j == 1) {
					for (int k = 0; k < dp[i - 1][j].size(); k++) {
						dp[i][j].push_back(dp[i - 1][j][k]);
						dp[i][j][k].first += a[i][j];
						dp[i][j][k].second += b[i][j];
					}
				}
				else {
					mergeDp(i, j);
				}
			}
		}
		LL ans = -0x7fffffff;
		for (int k = 0; k < dp[n][n].size(); k++) {
			ans = Max(ans, dp[n][n][k].first * dp[n][n][k].second);
		}
		printf("%lld\n", ans);
	}

	return 0;
}
void mergeDp(int i, int j) {
	int siz1 = dp[i - 1][j].size(), siz2 = dp[i][j - 1].size();
	int p1 = 0, p2 = 0; /*vector�±��0��ʼ*/
	while (p1 < siz1 && p2 < siz2) {
		/*�����ܹ������Ž��״̬: dp[i][j][p].first < dp[i][j][p].first && dp[i][j][p].second < dp[i][j][p].second*/
		/*������������������⣬ö�����п��ܹ������Ž�����*/
		/*��p1ת��*/
		if (dp[i - 1][j][p1].first < dp[i][j - 1][p2].first) {
			if (dp[i - 1][j][p1].second > dp[i][j - 1][p2].second) {
				dp[i][j].push_back(dp[i - 1][j][p1]);
			}
			p1++;
		}/*��p2ת��*/
		else if (dp[i][j - 1][p2].first < dp[i - 1][j][p1].first) {
			if (dp[i][j - 1][p2].second > dp[i - 1][j][p1].second) {
				dp[i][j].push_back(dp[i][j - 1][p2]);
			}
			p2++;
		}
		else if (dp[i - 1][j][p1].first == dp[i][j - 1][p2].first) {
			/*��p1ת��*/
			if (dp[i - 1][j][p1].second >= dp[i][j - 1][p2].second) {
				dp[i][j].push_back(dp[i - 1][j][p1]);
			}/*��p2ת��*/
			else if (dp[i - 1][j][p1].second < dp[i][j - 1][p2].second) {
				dp[i][j].push_back(dp[i][j - 1][p2]);
			}
			p1++, p2++;
		}
	}
	/*ת��p1, p2��ʣ�µ��������*/
	while (p1 < siz1) {
		dp[i][j].push_back(dp[i - 1][j][p1++]);
	}
	while (p2 < siz2) {
		dp[i][j].push_back(dp[i][j - 1][p2++]);
	}
	for (int k = 0; k < dp[i][j].size(); k++) {
		dp[i][j][k].first += a[i][j];
		dp[i][j][k].second += b[i][j];
	}
}
LL Max(LL x, LL y) {
	return x > y ? x : y;
}