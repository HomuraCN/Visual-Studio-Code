#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

typedef struct Section {
	int left, right;
}SECTION;

bool cmp(SECTION x, SECTION y);
bool cmpdown(int x, int y);

const int maxn = 5e3 + 10;
int n, K, dp[maxn][maxn], bigsection[maxn];
int head, tail, Q[maxn];
SECTION section[maxn], smallsection[maxn];

int main() {
	scanf("%d %d", &n, &K);
	for (int i = 1; i <= n; i++) {
		scanf("%d %d", &section[i].left, &section[i].right);
	}
	sort(section + 1, section + 1 + n, cmp);
	int tempmaxx = 0x7fffffff, cntsmall = 0, cntbig = 0;
	for (int i = n; i >= 1; i--) {
		if (section[i].right > tempmaxx) {
			bigsection[++cntbig] = section[i].right - section[i].left;
		}
		else {
			tempmaxx = section[i].right;
			smallsection[++cntsmall] = section[i];
		}
	}
	sort(bigsection + 1, bigsection + 1 + cntbig, cmpdown);
	reverse(smallsection + 1, smallsection + 1 + cntsmall);
	memset(dp, -1, sizeof(dp));
	dp[0][0] = 0;
	//(前i组，用了前j条线段 即：前j条线段的最优解)dp[i][j] = max(dp[i - 1][k] + section[k + 1].right - section[j].left);
	//枚举k，找第i-1组与第i组的分界线段，即：第i-1组的最后一条线段
	for (int i = 1; i <= K; i++) {
		head = 1, tail = 0;
		for (int j = 1; j <= cntsmall; j++) {
			/*if (smallsection[k + 1].right > smallsection[j].left ) {
				dp[i][j] = max(dp[i][j], dp[i - 1][k] + smallsection[k + 1].right - smallsection[j].left);
			}*/
			if (dp[i - 1][j - 1] > -1) {
				while (head <= tail && dp[i - 1][Q[tail]] + smallsection[Q[tail] + 1].right <= dp[i - 1][j - 1] + smallsection[j].right) {
					tail--;
				}
				Q[++tail] = j - 1;
			}
			while (head <= tail && smallsection[Q[head + 1]].right <= smallsection[j].left) {
				head++;
			}
			if (head <= tail) {
				dp[i][j] = dp[i - 1][Q[head]] + smallsection[Q[head] + 1].right - smallsection[j].left;
			}
		}
	}
	int ans = 0, sum = 0;
	for (int i = 0; i <= min(K, cntbig); i++) {
		sum += bigsection[i];
		if (dp[K - i][cntsmall] > -1) {
			ans = max(ans, dp[K - i][cntsmall] + sum);
		}
	}
	printf("%d", ans);

	return 0;
}
bool cmp(SECTION x, SECTION y) {
	if (x.left == y.left) {
		return x.right < y.right;
	}
	else {
		return x.left < y.left;
	}
}
bool cmpdown(int x, int y) {
	return x > y;
}