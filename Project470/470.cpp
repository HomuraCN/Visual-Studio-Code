#include <stdio.h>
#include <string>
#include <iostream>
#include <string.h>
using namespace std;

int T;

int main() {
	scanf("%d", &T);
	while (T--) {
		int cnt1 = 0, cnt2 = 0, cnt3 = 0;
		string str = "", temp = "";
		while (getline(cin, temp)) {
			if ((temp[0] == '=' && temp[1] == '=' && temp[2] == '=' && temp[3] == '=' && temp[4] == '=')) {
				break;
			}
			else {
				cnt1++;
				str += temp;
			}
			temp = "";
		}
		for (int i = 0; i < temp.size(); i++)
		{
			if (temp[i] == ' ' && i) {
				cnt2++;
			}
		}
		if (temp.size()) cnt2++;
		cnt3 = str.size();
		printf("%d %d %d\n", cnt1, cnt2, cnt3);
	}
}