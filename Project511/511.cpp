#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;

int t;

int main() {
	scanf("%d", &t);
	while (t--) {
		int n, cnt = 0;
		string num;
		scanf("%d", &n);
		cin >> num;
		for (int i = 0; i < num.size(); i++) {
			if (num[i] == '0') {
				cnt++;
			}
		}
		if (cnt % 2 == 0) {/*¸ÄÅ¼Êý¸ö*/
			printf("BOB\n");
		}
		else {
			if (cnt == 1) {
				printf("BOB\n");
				continue;
			}
			else {
				printf("ALICE\n");
			}
		}
	}

	return 0;
}