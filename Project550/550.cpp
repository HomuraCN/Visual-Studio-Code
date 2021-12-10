#include <stdio.h>
#define int long long

int lowBit(int x);
void add(int num[], int x, int delta);
void addSection(int L, int R, int delta);
int getPreSum(int num[], int x);
int getSum(int L, int R);

const int maxn = 5e5 + 10;
int n, m, a[maxn], ac[maxn];
int dif1[maxn], dif2[maxn], difsumc1[maxn], difsumc2[maxn]; /* dif1: ²î·ÖÊý×é£¬dif2: dif1[i] * i */

signed main() {
	scanf("%lld %lld", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
		add(ac, i, a[i]);
	}
	for (int i = 1; i <= n; i++) {
		if (i == 1) {
			dif1[i] = a[i];
		}
		else {
			dif1[i] = a[i] - a[i - 1];
		}
		dif2[i] = dif1[i] * i;
		add(difsumc1, i, dif1[i]);
		add(difsumc2, i, dif2[i]);
	}
	/*
		for (int i = 1; i <= n; i++) {
			printf("%d ", getSum(i, i));
		}
		printf("\n");
	*/
	while (m--) {
		int temp, x, y, k;
		scanf("%lld", &temp);
		if (temp == 1) {
			scanf("%lld %lld %lld", &x, &y, &k);
			addSection(x, y, k);
		}
		else {
			scanf("%lld", &x);
			printf("%lld\n", getSum(x, x));
		}
	}

	return 0;
}
int lowBit(int x) {
	return x & -x;
}
void add(int num[], int x, int delta) {
	while (x <= n) {
		num[x] += delta;
		x += lowBit(x);
	}
}
void addSection(int L, int R, int delta) {
	add(difsumc1, L, delta);
	add(difsumc1, R + 1, -delta);
	add(difsumc2, L, delta * L);
	add(difsumc2, R + 1, -delta * (R + 1));
}
int getPreSum(int num[], int x) {
	int sum = 0;
	while (x >= 1) {
		sum += num[x];
		x -= lowBit(x);
	}
	return sum;
}
int getSum(int L, int R) {
	return (R + 1) * getPreSum(difsumc1, R) - L * getPreSum(difsumc1, L - 1) - (getPreSum(difsumc2, R) - getPreSum(difsumc2, L - 1));
}