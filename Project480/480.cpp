#include <stdio.h>
#include <map>
#include <string>
#include <string.h>
#include <iostream>
using namespace std;

int T;

int main() {
	scanf("%d", &T);
	while (T--) {
		int S, N, cnt = 0, flag = 0;
		map<string, int> Map;
		map<string, int>::iterator iter;
		scanf("%d %d", &S, &N);
		for (int i = 1; i <= S; i++) {
			int num;
			string str;
			cin >> str;
			scanf("%d", &num);
			Map[str] = num;
		}
		for (int i = 1; i <= N; i++) {
			for (iter = Map.begin(); iter != Map.end(); iter++) {
				iter->second--;
			}
			int num;
			scanf("%d", &num);
			for (int j = 1; j <= num; j++) {
				string str;
				cin >> str;
				Map[str]++;
			}
		}
		for (iter = Map.begin(); iter != Map.end(); iter++) {
			if(iter->second > 0){
				cnt++;
			}
		}
		if (cnt == 0) {
			printf("Need to be lucky\n");
		}
		else {
			printf("%d\n", cnt);
		}
	}

	return 0;
}