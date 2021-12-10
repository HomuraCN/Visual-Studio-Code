#include <stdio.h>

void Sand(int t);

const int maxn = 1010;
int t, s, n, up, down, time[maxn];

int main() {
	scanf("%d %d %d", &t, &s, &n);
	up = 0, down = s;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &time[i]);
	}
	time[0] = time[1];
	for (int i = 2; i <= n; i++) {
		Sand(time[i] - time[i - 1]);
	}
	Sand(t - time[n]);
	printf("%d", up);

	return 0;
}
void Sand(int t) {
	int temp;
	temp = up;
	up = down;
	down = temp;
	if (t > up) {
		up = 0;
		down = s;
	}
	else {
		up -= t;
		down += t;
	}
}