#include <stdio.h>

void GetPrime(int n);

int n, prime[100000010], visit[100000010] = { 0 }, dp[][];

int main() {
	scanf("%d", &n);
	GetPrime(n);

	for (int i = 1; i <= q; i++) {
		scanf("%d", &k);
		printf("%d\n", prime[k - 1]);
	}

	return 0;
}
void GetPrime(int n) {
	int cnt = 0;
	for (int i = 2; i <= n; i++) {
		if (visit[i] == 0) {
			prime[cnt++] = i;
		}
		for (int j = 0; j < cnt && i * prime[j] <= n; j++) {
			visit[i * prime[j]] = 1;
			if (i % prime[j] == 0) {
				break;
			}
		}
	}
}