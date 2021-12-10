#include <stdio.h>

int Min(int x, int y) {
	return x < y ? x : y;
}

void MakeSet();
int FindSet(int x);

const int maxn = 2e5 + 10;
int n, m, p, u, v, cnt = 0x7fffffff, temp;
int set[maxn];

int main() {
	scanf("%d", &n);
	MakeSet();
	for (int i = 1; i <= n; i++) {
		scanf("%d", &u);
		temp = 0;
		if (FindSet(u) == i) {
			cnt = Min(cnt, temp);
		}
		else {
			set[i] = u;
		}
	}
	printf("%d", cnt);

	return 0;
}
void MakeSet() {
	for (int i = 1; i <= n; i++) {
		set[i] = i;
	}
}
int FindSet(int x) {
	temp++;
	if (x == set[x]) {
		return x;
	}
	else {
		return FindSet(set[x]);
	}
}