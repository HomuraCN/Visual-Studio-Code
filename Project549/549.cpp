#include <stdio.h>

int lowBit(int x);
void add(int num[], int x, int delta);
int getPreSum(int num[], int x);

const int maxn = 5e5 + 10;
int n, m, a[maxn], ac[maxn];

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		add(ac, i, a[i]);
	}
	/*
		printf("%d\n", getPreSum(ac, 5) - getPreSum(ac, 2));
		printf("%d\n", getSum(3, 5));
	*/
	while (m--) {
		int temp, x, y, k;
		scanf("%d", &temp);
		if (temp == 1) {
			scanf("%d %d", &x, &k);
			add(ac, x, k);
		}
		else {
			scanf("%d %d", &x, &y);
			printf("%d\n", getPreSum(ac, y) - getPreSum(ac, x - 1));
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
int getPreSum(int num[], int x) {
	int sum = 0;
	while (x >= 1) {
		sum += num[x];
		x -= lowBit(x);
	}
	return sum;
}