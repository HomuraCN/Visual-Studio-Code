#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
using namespace std;

const int maxn = 410;
int t, n, map[maxn][maxn], r[maxn], c[maxn];

int main() {
	scanf("%d", &t);
	while (t--) {
		memset(map, 0, sizeof(map));
		memset(r, 0, sizeof(r));
		memset(c, 0, sizeof(c));
		scanf("%d", &n);
		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			string str = "";
			cin >> str;
			for (int j = 1; j <= n; j++) {
				if (str[j - 1] == '*') {
					r[++cnt] = i;
					c[cnt] = j;
					map[i][j] = 1;
				}
			}
		}
		if (r[1] != r[2] && c[1] != c[2]) {
			map[r[1]][c[2]] = 1;
			map[r[2]][c[1]] = 1;
		}
		else {
			if (r[1] == r[2]) {
				if (r[1] - 1 >= 1) {
					map[r[1] - 1][c[1]] = 1;
					map[r[1] - 1][c[2]] = 1;
				}
				else {
					map[r[1] + 1][c[1]] = 1;
					map[r[1] + 1][c[2]] = 1;
				}
			}
			else if (c[1] == c[2]) {
				if (c[1] - 1 >= 1) {
					map[r[1]][c[1] - 1] = 1;
					map[r[2]][c[1] - 1] = 1;
				}
				else {
					map[r[1]][c[1] + 1] = 1;
					map[r[2]][c[1] + 1] = 1;
				}
			}
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (map[i][j]) {
					printf("*");
				}
				else {
					printf(".");
				}
			}
			printf("\n");
		}
	}

	return 0;
}