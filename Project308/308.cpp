#include <stdio.h>

int Min(int x, int y);

const int maxn = 5000010;
int n, p, a[maxn] = { 0 }, b[maxn] = { 0 }, min = 0x7fffffff;

int main() {
	scanf("%d %d", &n, &p);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		b[i] = a[i] - a[i - 1];
	}
	for (int i = 1; i <= p; i++) {
		int x, y, z;
		scanf("%d %d %d", &x, &y, &z);
		b[x] += z, b[y + 1] -=  z;
	}
	for (int i = 1; i <= n; i++) {
		a[i] = b[i] + a[i - 1];
		min = Min(min, a[i]);
	}
	printf("%d", min);

	return 0;
}
int Min(int x, int y) {
	return x <= y ? x : y;
}