#include <stdio.h>

int Gcd(int x, int y);

int T, N, M, p, q, edge[210][210] = { 0 };

int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &N);
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				edge[i][j] = 0;
			}
		}
		scanf("%d", &M);
		for (int i = 1; i <= M; i++) {
			int u, v;
			scanf("%d %d", &u, &v);
			edge[u][v] = 1, edge[v][u] = 1;
		}
		p = 0, q = 0;
		for (int i = 1; i <= N; i++) {
			for (int j = i + 1; j <= N; j++) {
				for (int k = j + 1; k <= N; k++) {
					if (edge[i][j] && edge[i][k] && edge[j][k]) {
						p++;
					}
				}
			}
		}
		p *= 3;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (i == j)
					continue;
				for (int k = j + 1; k <= N; k++) {
					if (i == k)
						continue;
					if (edge[i][j] && edge[i][k]) {
						q++;
					}
				}
			}
		}
		if (p == 0) {
			printf("0/1\n");
			continue;
		}
		int temp = Gcd(p, q);
		p /= temp, q /= temp;
		printf("%d/%d\n", p, q);
	}

	return 0;
}
int Gcd(int x, int y) {
	if (x % y == 0) {
		return y;
	}
	else {
		return Gcd(y, x % y);
	}
}