#include <stdio.h>
#include <math.h>

int Min(int x, int y);

int t, n, u, v, ans = 0x7fffffff, c[1000010];

int main()
{	
	scanf("%d", &t);
	for (int i = 1; i <= t; i++) {
		scanf("%d %d %d", &n, &u, &v);
		for (int j = 1; j <= n; j++) {
			scanf("%d", &c[j]);
		}
		for (int j = 2; j <= n; j++) {
			if (abs(c[j] - c[j - 1]) == 0) {
				ans = Min(ans, v + Min(u, v));
			}
			else if (abs(c[j] - c[j - 1]) > 1) {
				ans = 0;
			}
			else {
				ans = Min(ans, Min(u, v));
			}
		}
		printf("%d\n", ans);
		ans = 0x7fffffff;
	}

	return 0;
}
int Min(int x, int y)
{
	return x <= y ? x : y;
}