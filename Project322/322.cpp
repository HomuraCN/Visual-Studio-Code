#include <stdio.h>
#include <math.h>

struct District{
	int sumA = 0, sumB = 0;
}district[1010];

int P, D, cnt = 0;
double WA = 0, WB = 0;

int main() {
	scanf("%d %d", &P, &D);
	for (int i = 1; i <= P; i++) {
		int qu, tempA, tempB;
		scanf("%d", &qu);
		scanf("%d %d", &tempA, &tempB);
		cnt += (tempA + tempB);
		district[qu].sumA += tempA, district[qu].sumB += tempB;
	}
	for (int i = 1; i <= D; i++) {
		if (district[i].sumA > district[i].sumB) {
			int wa, wb;
			wb = district[i].sumB, wa = district[i].sumA - ((district[i].sumA + district[i].sumB) / 2 + 1);
			printf("A %d %d\n", wa, wb);
			WA += wa, WB += wb;
		}
		else {
			int wa, wb;
			wa = district[i].sumA, wb = district[i].sumB - ((district[i].sumA + district[i].sumB) / 2 + 1);
			printf("B %d %d\n", wa, wb);
			WA += wa, WB += wb;
		}
	}
	printf("%.10lf\n", fabs(WA - WB) / cnt);

	return 0;
}