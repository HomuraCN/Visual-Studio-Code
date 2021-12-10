#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void DFS(int u);
int query();

const int maxn = 1e3 + 10;
int n;
int visited[maxn], Euler[(int)1e6 + 10];
int cnt = 0, ans = 0;
vector<int> G[maxn];
vector<int> q;

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n - 1; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	DFS(1);
	for (int i = 1; i <= n; i++) {
		q.push_back(i);
	}
	ans = query();
	int l = 1, r = cnt, res;
	while (l < r - 1) {
		int mid = (l + r) / 2;
		for (int i = 1; i <= mid; i++) q.push_back(Euler[i]);
		int now = query();
		if (now == ans) {
			r = mid;
		}
		else {
			l = mid;
		}
	}
	cout << "! " << Euler[l] << " " << Euler[r] << endl;

	return 0;
}
void DFS(int u) {
	visited[u] = 1;
	Euler[++cnt] = u;
	for (int i = 0; i < G[u].size(); i++) {
		int v = G[u][i];
		if (visited[v] == 1) {
			continue;
		}
		DFS(v);
		Euler[++cnt] = u;
	}
}
int query() {
	sort(q.begin(), q.end());
	q.erase(unique(q.begin(), q.end()), q.end());
	cout << "? " << (int)q.size() << " ";
	for (int i = 0; i < q.size(); i++) {
		cout << q[i] << " ";
	}
	cout << endl;
	q.clear();
	int ans;
	cin >> ans;
	return ans;
}