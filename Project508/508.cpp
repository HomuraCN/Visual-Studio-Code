#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;

const int maxn = 100010;
int n = 0, height[maxn], dp1[maxn], dp2[maxn];

int main() {
	while (cin>>height[n]) {
		n++;
	}
	for (int i = 0; i < n; i++) {
		dp1[i] = 1;
		for (int j = 0; j < i; j++) {
			if (height[i] <= height[j]) {
				dp1[i] = max(dp1[i], dp1[j] + 1);
			}
		}
	}
	int maxx = 0;
	for (int i = 0; i < n; i++) {
		maxx = max(maxx, dp1[i]);
	}
	printf("%d\n", maxx);
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		int j = 0;
		while (j < cnt && dp2[j] < height[i]) {
			j++;
		}
		dp2[j] = height[i];
		if (j >= cnt) {
			cnt++;
		}
	}
	printf("%d\n", cnt);

	return 0;
}