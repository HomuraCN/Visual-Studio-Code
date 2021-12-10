#include <stdio.h>
#include <iostream>
#include <map>
#include <stack>
#include <queue>
#include <string>
using namespace std;

int T;
string str, hand[20], STR[40] = { "1w", "2w", "3w", "4w", "5w", "6w", "7w", "8w", "9w", "1b", "2b", "3b", "4b", "5b", "6b", "7b", "8b", "9b", "1s", "2s", "3s", "4s", "5s", "6s", "7s", "8s", "9s", "1z", "2z", "3z", "4z", "5z", "6z", "7z" };
stack<string> S;
queue<string> Q;
map<string, int> Map;

int main() {
	scanf("%d", &T);
	while (T--) {
		cin >> str;
		for (int i = 1; i <= 14; i++) {
			string temp1 = "";
			temp1 += str[i * 2 - 1 - 1];
			temp1 += str[i * 2 - 1];
			hand[i] = temp1;
			Map[temp1] = 1;
		}
		/*特判自摸*/
		int flag1 = 0, count = 0;
		for (int h = 1; h <= 14; h++) {
			count++;
			if (S.empty()) {/*栈为空的时候，无条件压栈*/
				S.push(hand[h]);
				continue;
			}
			if (S.top() == hand[h]) {/*栈不为空 && 判断刻子*/
				S.push(hand[h]);
				h++;
				if (S.top() != hand[h] && flag1 == 0) { /*判断对子*/
					flag1 = 1;
				}
				else if (S.top() == hand[h]) {
					S.push(hand[h]);
					h++;
				}
				while (!S.empty()) {
					Q.push(S.top());
					S.pop();
				}
			}
			else if ((hand[h][0] - S.top()[0]) == 1) {/*栈不为空 && 判断顺子*/
				S.push(hand[h]);
				h++;
				if ((hand[h][0] - S.top()[0]) == 1) {
					S.push(hand[h]);
					h++;
				}
				while (!S.empty()) {
					Q.push(S.top());
					S.pop();
				}
			}
			h--;
			if (count > 20) {
				while (!S.empty()) {
					S.pop();
				}
				break;
			}
		}
		if (Q.size() == 14) {
			printf("Tsumo!");
			return 0;
		}
		/*平常模拟*/
		for (int i = 1; i <= 14; i++) {/*切哪张牌*/
			if (Map[STR[i - 1]] == 0) {
				continue;
			}
			for (int j = 1; j <= 14; j++) {/*听哪张牌STR[j]*/
				for (int k = 1; k <= 14; k++) {/*放的位置*/
					int cnt = 0;
					for (int h = 1; h <= 14; h++) {
						int flag = 0;/*flag 0 : 初始, 1 ：刻子， 2 ：顺子____________cnt :对子数量*/
						for (int z = 1; z <= 3; z++) {
							if (S.empty()) {
								if (h == k) {
									S.push(STR[j - 1]);
								}
								else {
									if (hand[h] == STR[i - 1]) {
										h++;
									}
									S.push(hand[h]);
									h++;
								}
							}
							else {
								if (h == k) {/*插入*/
									if (z == 2 && S.top() != STR[j - 1] && flag == 1) {
										z = 3;
										cnt++;
										if (cnt > 1) {
											h = 14;
										}
									}
									else if (S.top() == STR[j - 1] && (flag == 0 || flag == 1)) {
										S.push(STR[j - 1]);
										flag = 1;
									}
									else if ((STR[j - 1][0] - S.top()[0]) == 1 && (flag == 0 || flag == 2)) {
										S.push(STR[j - 1]);
										flag = 2;
									}
									else {
										h = 14;
										z = 3;
									}
								}
								else {
									if (z == 2 && S.top() != hand[h] && flag == 1) {
										if (hand[h] == STR[i - 1]) {
											h++;
										}
										z = 3;
										cnt++;
										if (cnt > 1) {
											h = 14;
										}
									}
									else if (S.top() == hand[h] && (flag == 0 || flag == 1)) {
										if (hand[h] == STR[i - 1]) {
											h++;
										}
										S.push(hand[h]);
										flag = 1;
									}
									else if ((STR[j - 1][0] - S.top()[0]) == 1 && (flag == 0 || flag == 2)) {
										if (hand[h] == STR[i - 1]) {
											h++;
										}
										S.push(hand[h]);
										flag = 2;
									}
									else {
										h = 14;
										z = 3;
									}
								}
							}
						}
						while (!S.empty()) {
							Q.push(S.top());
							S.pop();
						}
					}
				}
				if (Q.size() == 14) {
					string ans = "";
					printf("%s ", STR[i - 1]);
					printf("%s", STR[j - 1]);
				}
			}/*听那张牌*/
		}
	}

	return 0;
}