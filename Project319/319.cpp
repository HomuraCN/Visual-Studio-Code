#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <map>
using namespace std;

typedef long long ll;

int n, m, tp;
string str;
map<string, ll> M;

ll getint() {
	ll r = 0;
	while (tp < str.size() && (str[tp] >= '0' && str[tp] <= '9')) r = r * 10 + str[tp++] - '0';
	if (r == 0) r = 1;
	return r;
}

ll get() {
	string s;
	s += str[tp++];
	while (tp < str.size() && (str[tp] >= 'a' && str[tp] <= 'z')) s += str[tp++];
	return M[s] * getint();
}

ll dfs() {
	ll res = 0, r = 0;
	while (tp < str.size()) {
		if (str[tp] == ')') {
			tp++;
			return res * getint();
		}
		if (str[tp] == '(') {
			tp++;
			res += dfs();
		}
		else
			res += get();
	}
	return res;
}

int main() {
	//freopen("0.txt", "r", stdin);
	ios::sync_with_stdio(false);
	string s; int x;
	cin >> m >> n;
	while (m--) {
		cin >> s >> x;
		M[s] = x;
	}
	while (n--) {
		cin >> str;
		tp = 0;
		cout << dfs() << endl;
	}
	return 0;
}