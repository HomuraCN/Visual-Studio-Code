#include <stdio.h>
#include <string>
#include <iostream>
#include <map>
using namespace std;

string WORD_to_word(string str);

int n, ans = 0;
map<string, bool> sword;
map<string, bool> visited;

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		string str;
		cin >> str;
		sword[WORD_to_word(str)] = true;
	}
	getchar();
	string str;
	getline(cin, str);
	for (int i = 0; i < str.size(); i++) {
		if (str[i] > 'A' && str[i] < 'Z') {
			str[i] += 32;
		}
	}
	string temp;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '.' || str[i] == ' ' || str[i] == ',') {
			if (sword[temp] == true && visited[temp] == false) {
				visited[temp] = true;
				ans++;
			}
			temp = "";
			if (str[i] == '.') {
				visited.clear();
			}
		}
		else {
			temp += str[i];
		}
	}
	printf("%d", ans);

	return 0;
}
string WORD_to_word(string str) {
	for (int i = 0; i < str.size(); i++) {
		if (str[i] > 'A' && str[i] < 'Z') {
			str[i] += 32;
		}
	}
	return str;
}