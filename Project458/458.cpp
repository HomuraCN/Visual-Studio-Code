#include <stdio.h>
#include <string.h>
#include <iostream>
#include <string>
using namespace std;

int Min(int x, int y) {
	return x < y ? x : y;
}

const int maxn = 1000010;

int ans = 0x7fffffff, dp[maxn], flag = 0, sum = 0;
string a;

int main() {
	cin >> a;
	for (int i = 0; i < a.length(); i++) {
		sum += (a[i] - '0');
	}
	if (sum == 0) {
		printf("0");
		return 0;
	}
	for (int i = 0; i < a.length(); i++) {
		if (a[i] == '0') {
			a[i] = '1';
			flag = 1;
		}
		else {
			continue;
		}
		ans = 0x7fffffff;
		memset(dp, 0, sizeof(dp));
		for (int j = 1; j < a.length(); j++) {
			if (a[j] == '0' && a[j - 1] == '1') {
				dp[j] = dp[j - 1] + 1;
			}
			else {
				dp[j] = dp[j - 1];
			}
			if (j == a.length() - 1 && a[j] == '1') {
				dp[j]++;
			}
		}
		ans = Min(ans, dp[a.length() - 1]);
		a[i] = '0';
	}
	if (flag == 0) {
		printf("1");
		return 0;
	}
	
	/*for (int i = 0; i < a.length(); i++) {
		ans = Min(dp[i][a.length() - 1], ans);
	}*/
	printf("%d", ans);

	return 0;
}