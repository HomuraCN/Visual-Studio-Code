#include <stdio.h>
#include <string>
#include <stack>
#include <iostream>
using namespace std;

void Deal();

int minn = 0, flag = 0, ans = 0, cnt = 0, word[130] = { 0 };
string str;
stack<int> S;

int main() {
	cin >> str;
	for (int i = 0; i < str.size(); i++) {
		word[str[i]]++;
	}
	Deal();
	if (flag == 1) {
		ans = 1;
		if (cnt > 0) {
			ans += (cnt - 1);
			printf("%d", ans);
		}
		else {
			printf("%d", ans);
		}
	}
	else {
		printf("%d", cnt);
	}

	return 0;
}
void Deal() {
	for (int i = 97; i <= 122; i++) {
		if (word[i] % 2 == 0) {
			if (word[i] == 0) {
				continue;
			}
			flag = 1;
		}
		else {
			cnt++;/*odd*/
		}
	}
}