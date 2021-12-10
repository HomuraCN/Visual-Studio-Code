#include <stdio.h>
#include <math.h>

int r, a, b, h;

int main() {
	scanf("%d %d %d %d", &r, &a, &b, &h);
	if (2 * r < b) {
		printf("Drop");
	}
	else {
		double ans;
		ans = (b * h - 2 * pow(h * h + 0.5 * (a - b) * 0.5 * (a - b), 0.5) * r) / (b - a);
		printf("Stuck\n");
		printf("%lf\n", ans);
	}
}