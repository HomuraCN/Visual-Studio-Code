#include <stdio.h>
#define int long long

int T;

signed main() {
	scanf("%lld", &T);
	while (T--) {
		int N, A, B, bottleA = 0, bottleB = 0, drinkcnt = 0, leftA, leftB;
		scanf("%lld %lld %lld", &N, &A, &B);
		if (A <= B) {
			leftB = N;
			leftB -= (N / A) * A;
			drinkcnt += N - leftB;
			bottleA += drinkcnt;
			bottleB += N % A;
			drinkcnt = N;
		}
		else {
			leftA = N;
			leftA -= (N / B) * B;
			drinkcnt += N - leftA;
			bottleB += drinkcnt;
			bottleA += N % B;
			drinkcnt = N;
		}
		while (bottleA >= A || bottleB >= B) {
			if (bottleB >= B) {
				drinkcnt += bottleB / B;
				bottleA += bottleB / B;
				bottleB %= B;
			}
			if (bottleA >= A) {
				drinkcnt += bottleA / A;
				bottleB += bottleA / A;
				bottleA %= A;
			}
		}
		printf("%lld\n", drinkcnt);
	}

	return 0;
}