#include <stdio.h>

int Min(int x, int y);
void FloydWarshall(int T);

int N, M, Q, k = 0, t[210], W[210][210];

int main() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		scanf("%d", &t[i]);
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			W[i][j] = 1e9;/*保证数据够大的同时，防止加和时数据溢出为负数，导致错误*/
		}
	}
	for (int i = 0; i < N; i++) {
		W[i][i] = 0;
	}
	for (int i = 1; i <= M; i++) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		W[u][v] = w;
		W[v][u] = w;/*无向边*/
	}
	scanf("%d", &Q);
	for (int i = 1; i <= Q; i++) {
		int U, V, T;
		scanf("%d %d %d", &U, &V, &T);
		while (t[k] <= T && k < N) {/*自底向上的dp, 优化时间(减少子路径的重复计算)*/
			FloydWarshall(k);
			k++;
		}
		if (t[U] > T || t[V] > T) {
			printf("-1\n");
		}
		else {
			if (W[U][V] == 1e9) {
				printf("-1\n");
			}
			else {
				printf("%d\n", W[U][V]);
			}
		}
	}

	return 0;
}
void FloydWarshall(int k) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			W[i][j] = Min(W[i][j], W[i][k] + W[k][j]);
		}
	}
}
int Min(int x, int y) {
	return x <= y ? x : y;
}