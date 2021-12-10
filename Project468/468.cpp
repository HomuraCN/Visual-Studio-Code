#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int t, n, flag = 0;

int main() {
	scanf("%d", &t);
	while (t--) {
		vector<int> T, M;
		string str;
		scanf("%d", &n);
		cin >> str;
		for (int i = 0; i < n; i++) {
			if (str[i] == 'T') {
				T.push_back(i);
			}
			else {
				M.push_back(i);
			}
		}
		if (M.size() * 2 != T.size()) {
			printf("NO\n");
			continue;
		}
		for (int i = 0; i < M.size(); i++) {
			if (M[i] < T[i] || M[i] > T[i + M.size()]) {
				flag = 1;
				printf("NO\n");
				break;
			}
		}
		if (flag == 1) {
			flag = 0;
		}
		else {
			printf("YES\n");
		}
	}

	return 0;
}