#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <stack>
#include <queue>
using namespace std;

string encrypt(pair<string, string> p);

int t;
int visited[26];
string temp;
stack<char> S;
queue<char> Q;

int main() {
	scanf("%d", &t);
	while (t--) {
		int ordercnt = 0, sum = 0;
		string str;
		string order;
		cin >> str;
		memset(visited, false, sizeof(visited));
		for (int i = str.length() - 1; i >= 0; i--) {
			if (visited[str[i] - 'a'] == 0) {
				S.push(str[i]);
			}
			visited[str[i] - 'a']++;
		}
		while (!S.empty()) {
			char TOP = S.top();
			S.pop();
			ordercnt++;
			order.push_back(TOP);
		}
		/*for (int i = 1; i <= ordercnt; i++) {
			printf("%c\n", order[i]);
		}*/
		int flag = 0;
		for (int i = 0; i < ordercnt; i++) {
			if (visited[order[i] - 'a'] % (i + 1) == 0) {
				sum += visited[order[i] - 'a'] / (i + 1);
				continue;
			}
			else {
				flag = 1;
			}
		}
		string origin;
		if (flag != 1) {
			for (int i = 1; i <= sum; i++) {
				Q.push(str[i - 1]);
			}
			while (!Q.empty()) {
				origin.push_back(Q.front());
				Q.pop();
			}
			pair<string, string> p;
			p.first = origin, p.second = order;
			temp = encrypt(p);
		}
		if (temp != str) {
			flag = 1;
		}
		if (flag != 1) {
			cout << origin;
			printf(" ");
			cout << order;
			printf("\n");
		}
		else {
			printf("-1\n");
		}
	}

}
string encrypt(pair<string, string> p)	{
	string result = p.first;
	for (auto c : p.second) {
		string temp;
		for (auto d : p.first) {
			if (d != c) {
				temp.push_back(d);
				result.push_back(d);
			}
		}
		p.first = temp;
	}
	return result;
}