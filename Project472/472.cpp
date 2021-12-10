#include <stdio.h>

void DFS(int P, int Q);

int T;

int main() {
	scanf("%d", &T);
	while (T--) {
		int P, Q;
		scanf("%d %d", &P, &Q);
		printf("%d/%d = ", P, Q);
		if (P % Q == 0) {
			printf("%d", P / Q);
			continue;
		}
		DFS(P, Q);
		printf("\n");
	}

	return 0;
}
void DFS(int P, int Q) {
	if (P % Q == 0) {
		printf("%d", P / Q);
		return;
	}
	else {
		int a = P / Q;
		printf("%d+1/", a);
		if (Q % (P - a * Q) != 0) {
			printf("{");
		}
		DFS(Q, P % Q);
		if (Q % (P - a * Q) != 0) {
			printf("}");
		}
	}
}