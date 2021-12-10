#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;

const int maxn = 1000010;

string a;
int flag = 0;
int cnt = 0, sum[maxn] = { 0 };

int main() {
	cin >> a;
	for (int i = 0; i < a.length(); i++) {
		sum[i + 1] = sum[i + 1 - 1] + (a[i] - '0');
	}
	if (sum[a.length()] == 1) {
		printf("0");
		return 0;
	}
	if ((a[0] == '1' && a[1] == '0') || (a[a.length() - 1] == '1' && a[a.length() - 2] == '0')) {
		flag = 1;
	}
	for (int i = 1; i <= a.length(); i++) {
		if (i >= 3 && (a[i - 1] == '1' && a[i - 2] == '0' && a[i - 3] == '1') || (i >= 3 && a[i - 1] == '0' && a[i - 2] == '1' && a[i - 3] == '0')) {
			flag = 1;
		}
		if (sum[i] - sum[i - 1] == 0) {
			if (i >= 2 && a[i - 2] == '1') {
				cnt++;
			}
		}
		if (i == a.length() && a[i - 1] == '1') {
			cnt++;
		}
	}
	if (flag == 1) {
		printf("%d", cnt - 1);
	}
	else {
		printf("%d", cnt);
	}

	return 0;
}