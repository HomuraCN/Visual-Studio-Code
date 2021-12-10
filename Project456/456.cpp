#include <stdio.h>
#include <iostream>
#include <string>
#include <stack>
using namespace std;

typedef struct Set {
	int rank;
	int p;
}SET;

void MakeSet();
int FindSet(int x);
void Union(int x, int y);
void Link(int x, int y);
void DFS(int u);

const int maxn = 150;

int n, start = 0, G[maxn][maxn], degree[maxn] = { 0 };
SET set[maxn];
stack<int> S;

int main() {
	scanf("%d", &n);
	MakeSet();
	for (int i = 1; i <= n; i++) {
		int u, v;
		string str = "";
		cin >> str;
		u = str[0], v = str[1];
		G[u][v]++, G[v][u]++; /*����ÿ��������ĸ�ԣ�������ĸ����������㣬���������֮�佨�������*/
		degree[u]++, degree[v]++;
		Union(u, v);
	}
	int cnt = 0;
	for (int i = 65; i <= 122; i++) {
		if (degree[i] >= 1 && set[i].p == i) { /*���鼯�жϸ�����ͼ�Ƿ���ͨ*/
			cnt++;
		}
	}
	if (cnt != 1) {
		printf("No Solution");
		return 0;
	}
	int flag = 0, count = 0;/*flag�жϸ�ͼ�Ƿ���ŷ����·��count�ж϶�Ϊ�������ĸ���*/
	for (int i = 65; i <= 122; i++) {
		if (degree[i] % 2 == 1) {
			count++;
			if (flag == 0) {
				start = i;
				flag = 1;
			}
		}
	}
	if (flag == 0) {
		for (int i = 65; i <= 122; i++) {
			if (degree[i] > 0) {
				start = i;
				break;
			}
		}
	}
	if (count > 0 && count != 2) {		/*����ͼŷ��·���ж�*/
		printf("No Solution");
		return 0;
	}
	DFS(start);
	while (!S.empty()) {
		printf("%c", S.top());
		S.pop();
	}

	return 0;
}
void MakeSet() {
	for (int i = 65; i <= 122; i++) {
		set[i].p = i;
		set[i].rank = 0;
	}
}
int FindSet(int x) {
	if (x != set[x].p) {
		set[x].p = FindSet(set[x].p);
	}
	return set[x].p;
}
void Union(int x, int y) {
	Link(FindSet(set[x].p), FindSet(set[y].p));
}
void Link(int x, int y)/*���Ⱥϲ�*/ {
	if (set[x].rank > set[y].rank) {
		set[y].p = x;
	}
	else {
		set[x].p = y;
		if (set[x].rank == set[y].rank) {
			set[y].rank++;
		}
	}
}
void DFS(int u) {
	for (int i = 65; i <= 122; i++) {
		if (G[u][i] > 0) {
			G[u][i]--;
			G[i][u]--;
			DFS(i);
		}
	}
	S.push(u);
}