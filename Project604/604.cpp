#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#define LL long long
using namespace std;

int t;
vector<string> S;

int main() {
	for (LL i = 1; i <= (LL)2e18; i *= 2) {
		S.push_back(to_string(i));
	}
	scanf("%d", &t);
	while (t--) {
		string str;
		cin >> str;
		int ans = str.length() + 1;
		for (int i = 0; i < S.size(); i++) {
			int tp = 0;
			int sp = 0;
			int taken = 0;
			while (sp < str.length() && tp < S[i].length()) {
				if (str[sp] == S[i][tp])
				{
					taken++;
					tp++;
				}
				sp++;
			}
			ans = min(ans, (int)str.length() + (int)S[i].length() - 2 * taken);
		}
		printf("%d\n", ans);
	}

	return 0;
}