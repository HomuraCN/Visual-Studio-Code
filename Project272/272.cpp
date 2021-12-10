#include <stdio.h>
#include <math.h>

int Min(int x, int y);

int c, t, n, u, v, cnt = 0, ans = 9999, C[1000010];

int main()
{
	scanf("%d", &t);
	for (int i = 1; i <= t; i++) {
		scanf("%d %d %d", &n, &u, &v);
		for (int i = 1; i <= n; i++) {
			scanf("%d", &c);
			C[i] = c;
		}
		if (n == 2 && C[1] == C[2]) {
			printf("%d\n", u + v);
			continue;
		}
		else if (n == 2 && C[1] != C[2]) {
			if (abs(C[1] - C[2]) >= 2) {
				printf("0\n");
				continue;
			}
			else {
				printf("%d\n", Min(u, v));
				continue;
			}
		}
		for (int i = 3; i <= n; i++) {
			if (C[i] == C[i - 1] && C[i] == C[i - 2]) {
				ans = Min(ans, u + v);
			}
			else if (abs(C[i] - C[i - 1]) == 1 && abs(C[i] - C[i - 2]) == 1) {
				if (C[i - 1] == C[i - 2]) {
					ans = Min(ans, Min(u, v));
				}
				else {
					ans = 0;
				}
			}
			else if (abs(C[i] - C[i - 1]) == 1 && abs(C[i] - C[i - 2]) == 2 || abs(C[i] - C[i - 1]) == 2 && abs(C[i] - C[i - 2]) == 1) {
				if (abs(C[i] - C[i - 1] == 1)) {
					ans = Min(ans, Min(u, v));
				}
				else {
					ans = 0;
				}
			}
		}
		printf("%d\n", ans);
	}

	return 0;
}
int Min(int x, int y)
{
	return x <= y ? x : y;
}