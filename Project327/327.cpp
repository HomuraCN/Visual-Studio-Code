#include <stdio.h>
#include <iostream>
#include <string>
#include <stack>
#include <unordered_map>
#define LL long long
using namespace std;

void Calculate();

int M, N;
stack<LL> S;
unordered_map<string, LL> Map;

int main() {
	scanf("%d %d", &M, &N);
	for (int i = 1; i <= M; i++) {
		string str;
		LL temp;
		cin >> str >> temp;
		Map[str] = temp;
	}
	while (N--) {
		Calculate();
		LL sum = 0;
		while (!S.empty()) {
			sum += S.top();
			S.pop();
		}
		printf("%lld\n", sum);
	}

	return 0;
}
void Calculate() {
	string str;
	cin >> str;
	str += '#';/*×Ö·û´®Æ´½Ó£¬·ÀÖ¹Ô½½ç*/
	for (int i = 0; i < str.length(); i++) {
		if (str[i] >= 'A' && str[i] <= 'Z') {
			string temp = "";
			temp += str[i];
			if (str[i + 1] >= 'a' && str[i + 1] <= 'z') {
				temp += str[++i];
			}
			LL num = 0;
			while (str[i + 1] >= '0' && str[i + 1] <= '9') {
				num = num * 10 + str[++i] - '0';
			}
			if (num == 0) {
				num = 1;
			}
			S.push(num * Map[temp]);
		}
		else if (str[i] == '(') {
			S.push(-1);
		}
		else if (str[i] == ')') {
			LL sum = 0;
			while (S.top() != -1) {
				sum += S.top();
				S.pop();
			}
			S.pop();/*popµô-1*/
			LL num = 0;
			while (str[i + 1] >= '0' && str[i + 1] <= '9') {
				num = num * 10 + str[++i] - '0';
			}
			if (num == 0) {
				num = 1;
			}
			S.push(sum * num);
		}
	}
}