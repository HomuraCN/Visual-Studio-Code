#include <stdio.h>
#include <math.h>

int DFS(int R, int C, int cnt);
int Min(int x, int y);

int t, N, M, D, Sc, Sr, Pc, Pr, dr[4] = { -1, 0, 1, 0 }, dc[4] = {0, 1, 0, -1};
int map[35][35] = { 0 }, flag[35][35] = { 0 };

int main() {
	scanf("%d", &t);
	for (int f = 1; f <= t; f++) {
		int ans = 0x7fffffff;
		scanf("%d %d", &M, &N);
		scanf("%d %d", &Sc, &Sr);
		scanf("%d %d", &Pc, &Pr);
		scanf("%d", &D);
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				scanf("%d", &map[i][j]);
			}
		}
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				flag[i][j] = 0;
			}
		}
		ans = Min(DFS(Sr, Sc, 0), ans);
		printf("%d\n", ans);
	}

	return 0;
}
int DFS(int R, int C, int cnt) {
	flag[R][C] = 1;
	if (R == Pr && C == Pc) {
		return cnt;
	}
	else {
		for (int i = 0; i <= 3; i++) {
			int NextR = R + dr[i];
			int NextC = C + dc[i];
			if (flag[NextR][NextC] == 0 && NextR >= 1 && NextR <= N && NextC >= 1 && NextC <= M && abs(map[R][C] - map[NextR][NextC]) <= D) {
				DFS(NextR, NextC, cnt);
			}
			else if (flag[NextR][NextC] == 0 && NextR >= 1 && NextR <= N && NextC >= 1 && NextC <= M && abs(map[R][C] - map[NextR][NextC]) > D) {
				DFS(NextR, NextC, cnt + 1);
			}
		}
	}
}
int Min(int x, int y) {
	return x <= y ? x : y;
}