#include <stdio.h>

int Min(int x, int y);
void FloydWarshall();

int N, M, Q, W[210][210];

int main() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i == j) {
				W[i][i] = 0;
			}
			else {
				W[i][j] = 1e9;/*��֤���ݹ����ͬʱ����ֹ�Ӻ�ʱ�������Ϊ���������´���*/
			}
		}
	}
	for (int i = 1; i <= M; i++) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		W[u][v] = w;
		W[v][u] = w;/*�����*/
	}
	FloydWarshall();
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (W[i][j] == 1e9) {
				printf("-1 ");
			}
			else {
				printf("%d ", W[i][j]);
			}
		}
		printf("\n");
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