#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#pragma GCC optimize(s)
using namespace std;

typedef struct Node {
	int parent;
	int deep = 0;
}NODE;

void DFS(int u, int L, int d, int count);

inline int read() {
	int s = 0, w = 1;
	char ch = getchar();
	while (ch < '0' || ch>'9') { if (ch == '-')w = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') s = s * 10 + ch - '0', ch = getchar();
	return s * w;
}

const int maxn = 300010;
int N, Q, maxx = 0, cnt = 0;
string s, str, temp;
vector<int> G[maxn];
NODE node[maxn];

int main() {
	/*scanf("%d %d", &N, &Q);*/
	N = read();
	Q = read();
	str += ' ';
	cin >> s;
	str += s;
	node[1].deep = 1;
	G[1].push_back(1);
	for (int i = 1; i <= N - 1; i++) {
		int p, u;
		/*scanf("%d", &p);*/
		p = read();
		u = i + 1;
		node[u].parent = p;
		node[u].deep = node[p].deep + 1;
		G[node[u].deep].push_back(u);
		maxx = max(maxx, node[u].deep);
	}
	int X, L;
	while (Q--) {
		temp = "";
		/*scanf("%d %d", &X, &L);*/
		X = read();
		L = read();
		for (int i = 1; i <= L; i++) {
			temp += str[X];
			X = node[X].parent;
		}
		for (int length = L; length <= maxx; length++) {
			for (int i = 0; i < G[length].size(); i++) {
				int v = G[length][i];
				DFS(v, L, L, 0);
			}
		}
		printf("%d\n", cnt);
		cnt = 0;
	}

	return 0;
}
void DFS(int u, int L, int d, int count) {
	if (count == L) {
		cnt++;
		return;
	}
	if (str[u] == temp[L-d]) {
		DFS(node[u].parent, L, d - 1, count + 1);
	}
	else {
		return;
	}
}