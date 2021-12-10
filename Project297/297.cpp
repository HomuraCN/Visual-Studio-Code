#include <stdio.h>
#include <math.h>

int t, n;

int main() {
	scanf("%d", &t);
	for (int f = 1; f <= t; f++) {
		scanf("%d", &n);
		double a[110] = { 0 }, b[110] = { 0 };
		int tm[110] = { 0 }, Tzoulu[110] = { 0 }, Tdestination[110] = { 0 }, Twait[110] = { 0 }, timer = 0;
		for (int i = 1; i <= n; i++) {
			scanf("%lf %lf", &a[i], &b[i]);
		}
		for (int i = 1; i <= n; i++) {
			scanf("%d", &tm[i]);
			Tzoulu[i] = a[i] - b[i - 1] + tm[i];
		}
		for (int i = 1; i <= n; i++) {
			int temp;
			temp = (int)ceil((b[i - 1] - a[i - 1]) / 2);
			if (temp + Tdestination[i - 1] >= b[i - 1]) {
				Twait[i - 1] = temp;
			}
			else {
				Twait[i - 1] = b[i - 1] - Tdestination[i - 1];
			}
			Tdestination[i] = Tdestination[i - 1] + Twait[i - 1] + Tzoulu[i];
		}
		printf("%d\n", Tdestination[n]);
	}

	return 0;
}