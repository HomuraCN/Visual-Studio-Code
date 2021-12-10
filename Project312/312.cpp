#include <stdio.h>
#include <math.h>

int T, H, cnt;
long long a[35] = { 0 }, sum[35] = { 0 };

int main() {
	scanf("%d", &T);
	for (int i = 1; i <= 33; i++) {
		a[i] = pow(2, i - 1);
		sum[i] = sum[i - 1] + a[i];
	}
	for (int f = 1; f <= T; f++) {
		cnt = 0;
		scanf("%d", &H);
		while (H != 0) {
			for (int i = 1; i <= 33; i++) {
				if (H < sum[i]) {
					cnt += (i - 1);
					H -= sum[i - 1];
					if (H == a[i - 1]) {
						cnt += 1;
						H = 0;
						break;
					}
					i = 0;
					continue;
				}
				else if (H == sum[i]) {
					cnt += i;
					H -= sum[i];
					break;
				}
			}
		}
		printf("%d\n", cnt);
	}
	return 0;
}