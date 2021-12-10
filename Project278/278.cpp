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
			W[i][j] = 1e9;/*��֤���ݹ����ͬʱ����ֹ�Ӻ�ʱ�������Ϊ���������´���*/
		}
	}
	for (int i = 0; i < N; i++) {
		W[i][i] = 0;
	}
	for (int i = 1; i <= M; i++) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		W[u][v] = w;
		W[v][u] = w;/*�����*/
	}
	scanf("%d", &Q);
	for (int i = 1; i <= Q; i++) {
		int U, V, T;
		scanf("%d %d %d", &U, &V, &T);
		while (t[k] <= T && k < N) {/*�Ե����ϵ�dp, �Ż�ʱ��(������·�����ظ�����)*/
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