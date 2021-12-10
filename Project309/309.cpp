#include <stdio.h>
#include <math.h>
#define LL long long

const int maxn = 200010;
LL N, Q, S, T, B = 0;
LL a[maxn] = { 0 }, b[maxn] = { 0 };

int main() {
	scanf("%lld %lld %lld %lld", &N, &Q, &S, &T);
	for (int i = 1; i <= N + 1; i++) {
		scanf("%lld", &a[i]);
		b[i] = a[i] - a[i - 1];
	}
	for (int i = 1; i <= Q; i++) {
		LL x, y, z;
		scanf("%lld %lld %lld", &x, &y, &z);
		b[x + 1] += z, b[y + 2] -= z;
		for (int i = 1; i <= N + 1; i++) {
			a[i] = b[i] + a[i - 1];
		}
		/*for (int i = 1; i <= N + 1; i++) {
			printf("%d ", a[i]);
		}
		printf("\n");*/
		for (int i = 2; i <= N + 1; i++) {
			if (a[i - 1] < a[i]) {
				B -= S * abs(a[i - 1] - a[i]);
			}
			else if (a[i - 1] > a[i]) {
				B += T * abs(a[i - 1] - a[i]);
			}
		}
		printf("%lld\n", B);
		B = 0;
	}

	return 0;
}