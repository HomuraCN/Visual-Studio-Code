#include <stdio.h>
#include <string>
#include <iostream>
#include <queue>
#include <stack>
using namespace std;

typedef struct Node {
	int x1, y1, x2, y2, step;
	char ch;
}NODE;

bool check1(int x1, int y1);
bool check2(int x2, int y2);
void BFS();
const int maxn = 22;
int dr1[4] = { 1, 0, 0, -1 }, dc1[4] = { 0, -1, 1, 0 }, dr2[4] = { 1, 0, 0, -1 }, dc2[4] = {0, 1, -1, 0};
char d[4] = {'D', 'L', 'R', 'U'}, map1[maxn][maxn], map2[maxn][maxn];
bool visited[maxn][maxn][maxn][maxn];
NODE dp[maxn][maxn][maxn][maxn];
queue<NODE> Q;
stack<char> S;


int main() {
	for (int i = 1; i <= 20; i++) {
		string s;
		getline(cin, s);
		for (int j = 0; j <= 40; j++) {
			if (j <= 19) {
				map1[i][j + 1] = s[j];
			}
			else if (j >= 21) {
				map2[i][j - 20] = s[j];
			}
		}
	}
	for (int i = 1; i < maxn; i++) {
		for (int j = 1; j < maxn; j++) {
			for (int k = 1; k < maxn; k++) {
				for (int h = 1; h < maxn; h++) {
					dp[i][j][k][h].step = 0x3f3f3f3f;
				}
			}
		}
	}
	/*for (int i = 1; i <= 20; i++) {
		for (int j = 1; j <= 20; j++) {
			printf("%c", map2[i][j]);
		}
		printf("\n");
	}*/
	BFS();

	return 0;
}
bool check1(int x1, int y1) {
	if (x1 >= 1 && x1 <= 20 && y1 >= 1 && y1 <= 20 && map1[x1][y1] == '.') {
		return true;
	}
	else {
		return false;
	}
}
bool check2(int x2, int y2) {
	if (x2 >= 1 && x2 <= 20 && y2 >= 1 && y2 <= 20 && map2[x2][y2] == '.') {
		return true;
	}
	else {
		return false;
	}
}
void BFS() {
	NODE temp;
	temp.x1 = 20, temp.y1 = 20, temp.x2 = 20, temp.y2 = 1;
	temp.step = 0;
	Q.push(temp);
	visited[temp.x1][temp.y1][temp.x2][temp.y2] = true;
	dp[20][20][20][1].step = 0;
	while (!Q.empty()) {
		NODE TOP = Q.front();
		Q.pop();
		for (int i = 0; i < 4; i++) {
			int NEWX1 = TOP.x1 + dr1[i], NEWY1 = TOP.y1 + dc1[i];
			int NEWX2 = TOP.x2 + dr2[i], NEWY2 = TOP.y2 + dc2[i];
			if (check1(NEWX1, NEWY1) == false) {
				NEWX1 = TOP.x1, NEWY1 = TOP.y1;
			}
			if (check2(NEWX2, NEWY2) == false) {
				NEWX2 = TOP.x2, NEWY2 = TOP.y2;
			}
			if (visited[NEWX1][NEWY1][NEWX2][NEWY2] == true) {
				continue;
			}
			if (dp[NEWX1][NEWY1][NEWX2][NEWY2].step > TOP.step + 1) {
				dp[NEWX1][NEWY1][NEWX2][NEWY2].step = TOP.step + 1;
				dp[NEWX1][NEWY1][NEWX2][NEWY2].x1 = TOP.x1;
				dp[NEWX1][NEWY1][NEWX2][NEWY2].y1 = TOP.y1;
				dp[NEWX1][NEWY1][NEWX2][NEWY2].x2 = TOP.x2;
				dp[NEWX1][NEWY1][NEWX2][NEWY2].y2 = TOP.y2;
				dp[NEWX1][NEWY1][NEWX2][NEWY2].ch = d[i];
				temp.x1 = NEWX1, temp.y1 = NEWY1, temp.x2 = NEWX2, temp.y2 = NEWY2;
				temp.step = TOP.step + 1;
				Q.push(temp);
				visited[NEWX1][NEWY1][NEWX2][NEWY2] = true;
			}
		}
	}
	int ans = dp[1][20][1][1].step;
	printf("%d\n", ans);
	map1[1][20] = 'A';
	map2[1][1] = 'A';
	int xx1, yy1, xx2, yy2;
	xx1 = dp[1][20][1][1].x1, yy1 = dp[1][20][1][1].y1, xx2 = dp[1][20][1][1].x2, yy2 = dp[1][20][1][1].y2;
	while (ans--) {
		S.push(dp[xx1][yy1][xx2][yy2].ch);
		map1[xx1][yy1] = 'A';
		map2[xx2][yy2] = 'A';
		xx1 = dp[xx1][yy1][xx2][yy2].x1, yy1 = dp[xx1][yy1][xx2][yy2].y1, xx2 = dp[xx1][yy1][xx2][yy2].x2, yy2 = dp[xx1][yy1][xx2][yy2].y2;
	}
	while (!S.empty()) {
		printf("%c", S.top());
		S.pop();
	}
	for (int i = 1; i <= 20; i++) {
		for (int j = 1; j <= 20; j++) {
			printf("%c", map1[i][j]);
		}
		printf("\n");
	}
	for (int i = 1; i <= 20; i++) {
		for (int j = 1; j <= 20; j++) {
			printf("%c", map2[i][j]);
		}
		printf("\n");
	}
}