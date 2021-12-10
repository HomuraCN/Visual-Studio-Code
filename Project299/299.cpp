#include <stdio.h>

int Min(int x, int y);
void FloydWarshall();

int N, M, Q, W[1510][1510];

int main() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i == j) {
				W[i][i] = 0;
			}
			else {
				W[i][j] = 1e9;/*保证数据够大的同时，防止加和时数据溢出为负数，导致错误*/
			}
		}
	}
	for (int i = 1; i <= M; i++) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		u--, v--;
		W[u][v] = Min(W[u][v], -w);
	}
	FloydWarshall();
	if (W[0][N - 1] == 1e9) {
		printf("-1");
	}
	else {
		printf("%d", -W[0][N - 1]);
	}

	return 0;
}
void FloydWarshall() {
	for (int k = 0; k < N; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				W[i][j] = Min(W[i][j], W[i][k] + W[k][j]);
			}
		}
	}
}
int Min(int x, int y) {
	return x <= y ? x : y;
}