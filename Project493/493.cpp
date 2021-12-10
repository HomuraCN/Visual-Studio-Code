#include <stdio.h>
#include <math.h>

int isSqure(int x);

int t, n;

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		if (n % 2 == 0 && isSqure(n / 2)) {
			printf("YES\n");
		}
		else if (n % 4 == 0 && isSqure(n / 4)) {
			printf("YES\n");
		}
		else {
			printf("NO\n");
		}
	}

	return 0;
}
int isSqure(int x) {
	int temp = sqrt(x);
	if (temp * temp == x) {
		return 1;
	}
	else {
		return 0;
	}
}